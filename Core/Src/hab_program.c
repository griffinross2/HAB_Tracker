/*
 * hab_program.c
 *
 *  Created on: Jun 2, 2023
 *      Author: griff
 */

#include "hab_program.h"
#include <math.h>
#include <stdlib.h>

#include <board.h>
#include <hab_timer.h>
#include <lib/common/status.h>
#include <lib/gps/max_m10s.h>
#include <lib/peripherals/gpio/gpio.h>
#include <lib/sensors/data.h>
#include <fatfs/sd.h>
#include <lib/sensors/iis2mdc/iis2mdc.h>
#include <lib/sensors/lsm6dsox/lsm6dsox.h>
#include <lib/sensors/ms5637/ms5637.h>
#include <lib/sensors/ds18b20/ds18b20.h>
#include "aprs/APRS.h"
#include "subghz_phy_app.h"
#include "radio.h"

#define TARGET_INTERVAL	250  // ms
#define LOG_FIFO_LEN 	256
#define PIN_BLUE		PIN_PB4
#define PIN_YELLOW		PIN_PB3
#define PIN_PROG		PIN_PH3

const uint64_t LOGGING_TIMEOUT = (1000 * 60 * 60 * 8);

BitFIFO aprs_fifo;
APRSPacket aprs_packet = {
		.dest     = "APRS",
		.callsign = "KN4UIR-11",
		.digi     = "WIDE1-1,WIDE2-1",
};
static char comment[128];

volatile uint8_t radio_in_use = 0; // 0 - idle, 1 - primary (APRS), 2 - secondary (LoRa)
extern volatile LoraState lora_state;

volatile uint64_t radio_timer = 0;

volatile static struct {
    SensorData queue[LOG_FIFO_LEN];
    size_t ridx;  // Next index that will be read from
    size_t widx;  // Next index that will be written to
    // ridx == widx -> FIFO is empty
    // (ridx == widx - 1) mod LOG_FIFO_LEN -> FIFO is full
} fifo;

static I2cDevice s_mag_conf = {
    .address = 0x1E,
    .clk = I2C_SPEED_FAST,
    .periph = P_I2C1,
};
static I2cDevice s_baro_conf = {
    .address = 0x76,
    .clk = I2C_SPEED_FAST,
    .periph = P_I2C1,
};
static I2cDevice s_gps_conf = {
    .address = 0x42,
    .clk = I2C_SPEED_FAST,
    .periph = P_I2C2,
};
static I2cDevice s_imu_conf = {
	.address = 0x6A,
	.clk = I2C_SPEED_FAST,
    .periph = P_I2C1,
};
static SpiDevice s_sd_conf = {
    .clk = SPI_SPEED_1MHz,
    .cpol = 0,
    .cpha = 0,
    .cs = 0,
    .periph = P_SPI1,
};
static OneWireDevice s_temp_conf = {
    .normal_speed = ONEWIRE_SPEED_115200,
	.reset_speed = ONEWIRE_SPEED_9600,
};

volatile SensorData last_sensor_data;
volatile uint8_t sensor_log_paused = 0;
volatile uint8_t error_flag = 0;

GPS_Fix_TypeDef fix = {0};

float last_lat = NAN;
float last_lon = NAN;

void fill_packet(APRSPacket* packet, int hour, int min, int sec, float lat, float lon, int hdg, int spd_kt, int alt_ft, char* comment);
void tx_sensor_lora(SensorData* data);
void tx_gps_lora(GPS_Fix_TypeDef* fix, float lat, float lon);
void init_sensor_timer();

void hab_init()
{
	DELAY(2000);

	SubghzApp_Init();
	aprs_packet.info = malloc(APRS_MAX_INFO + 1);
	APRS_init();
	BitFIFO_init(&aprs_fifo, malloc(APRS_FIFO_BYTES), APRS_FIFO_BYTES);

	// Initialize temperature probe
	if (ds18b20_init(&s_temp_conf) == STATUS_OK) {
		printf("Temperature probe initialization successful\n");
	} else {
		printf("Temperature probe initialization failed\n");
		error_flag = 1;
	}

	// Initialize magnetometer
	if (iis2mdc_init(&s_mag_conf, IIS2MDC_ODR_50_HZ) == STATUS_OK) {
		printf("Magnetometer initialization successful\n");
	} else {
		printf("Magnetometer initialization failed\n");
		error_flag = 1;
	}

	// Initialize barometer
	if (ms5637_init(&s_baro_conf) == STATUS_OK) {
		printf("Barometer initialization successful\n");
	} else {
		printf("Barometer initialization failed\n");
		error_flag = 1;
	}

	// Initialize IMU
	if (lsm6dsox_init(&s_imu_conf) == STATUS_OK) {
		printf("IMU initialization successful\n");
	} else {
		printf("IMU initialization failed\n");
		error_flag = 1;
	}

	if (lsm6dsox_config_accel(&s_imu_conf, LSM6DSOX_XL_RATE_208_HZ,
							  LSM6DSOX_XL_RANGE_4_G) == STATUS_OK) {
		printf("IMU accel range set successfully\n");
	} else {
		printf("IMU accel configuration failed\n");
		error_flag = 1;
	}

	if (lsm6dsox_config_gyro(&s_imu_conf, LSM6DSOX_G_RATE_208_HZ,
							 LSM6DSOX_G_RANGE_500_DPS) == STATUS_OK) {
		printf("IMU gyro range set successfully\n");
	} else {
		printf("IMU gyro configuration failed\n");
		error_flag = 1;
	}

	// Initialize GPS
	if (max_m10s_init(&s_gps_conf) == STATUS_OK) {
		printf("GPS initialization successful\n");
	} else {
		printf("GPS initialization failed\n");
		error_flag = 1;
	}

	// Initialize SD card
	if (sd_init(&s_sd_conf) == STATUS_OK) {
		printf("SD card initialization successful\n");
	} else {
		printf("SD card initialization failed\n");
		error_flag = 1;
	}

	// Enable heater
	gpio_write(PIN_PB8, GPIO_HIGH);

	init_sensor_timer();

	gpio_write(PIN_BLUE, GPIO_HIGH);
	DELAY(500);
	gpio_write(PIN_BLUE, GPIO_LOW);
	DELAY(500);

}

void hab_loop()
{
	// Radio loop
	if(MILLIS() - radio_timer > 90000)
	{
		radio_timer = MILLIS();

		// Send APRS Packet
		sprintf(comment, "%03.0f:%03.0f:%05.1f",
				last_sensor_data.baro.temperature, last_sensor_data.temp.temperature, last_sensor_data.baro.pressure);
		fill_packet(&aprs_packet, fix.hour, fix.min, fix.sec,
					last_lat, last_lon,
					(int) fix.hdg, (int) (fix.ground_speed * 1.944), (int) (fix.height_msl * 3.281),
					comment);
		//fill_packet(&aprs_packet, 12, 0, 0,
		//		35.225, -80.841667,
		//		0, 0, 200,
		//		comment);
		BitFIFO_reinit(&aprs_fifo);
		APRS_encode(&aprs_fifo, &aprs_packet);
		APRS_send(&aprs_fifo);

		DELAY(5000);

		tx_gps_lora(&fix, last_lat, last_lon);

		// Save the SD periodically just in case
		sd_deinit();
		sd_reinit();
	}

	// Indicate start of SD write
	gpio_write(PIN_BLUE, GPIO_HIGH);

	// Save FIFO to SD card
	uint32_t entries_read = 0;
	while (fifo.ridx != fifo.widx) {
		sd_write_sensor_data(&fifo.queue[fifo.ridx]);
		if (fifo.ridx == LOG_FIFO_LEN - 1) {
			fifo.ridx = 0;
		} else {
			fifo.ridx += 1;
		}
		entries_read += 1;
		if (entries_read == LOG_FIFO_LEN) {
			break;
		}
	}

	// Read and log GPS data
	if (max_m10s_poll_fix(&s_gps_conf, &fix) == STATUS_OK) {
		if(!isnan(fix.lat) && !isnan(fix.lon) && fix.fix_valid)
		{
			last_lat = fix.lat;
			last_lon = fix.lon;
		}
		sd_write_gps_data(MILLIS(), &fix);
	}

	// Indicate end of SD write
	gpio_write(PIN_BLUE, GPIO_LOW);

	// If PROG switch is set or time limit exceeded, unmount SD card and wait
	if (MILLIS() > LOGGING_TIMEOUT)
	{
		gpio_write(PIN_BLUE, GPIO_HIGH);
		if(!sensor_log_paused)
		{
			sd_deinit();
		}
		sensor_log_paused = 1;
	}
	else if (gpio_read(PIN_PROG)) {
		sensor_log_paused = 1;
		sd_deinit();

		gpio_write(PIN_BLUE, GPIO_HIGH);
		while (gpio_read(PIN_PROG)) {}
		gpio_write(PIN_BLUE, GPIO_LOW);

		sd_reinit();
		sensor_log_paused = 0;
	}

	// Set error light
	if(!fix.fix_valid || error_flag)
	{
		gpio_write(PIN_YELLOW, GPIO_HIGH);
	}
	else
	{
		gpio_write(PIN_YELLOW, GPIO_LOW);
	}

	DELAY(1000);
}

void fill_packet(APRSPacket* packet, int hour, int min, int sec, float lat, float lon, int hdg, int spd_kt, int alt_ft, char* cmt)
{
	if(isnan(lat) || isnan(lon))
	{
		lat = 0.0F;
		lon = 0.0F;
	}
	float lat_min = fabs(lat - (int) lat) * 60;
	float lon_min = fabs(lon - (int) lon) * 60;
	char lat_dir = lat > 0 ? 'N' : 'S';
	char lon_dir = lon > 0 ? 'E' : 'W';
	snprintf(packet->info, APRS_MAX_INFO, "@%02d%02d%02dh%02d%05.2f%c/%03d%05.2f%cO%03d/%03d/A=%06d%s\n",
			hour, min, sec,
			abs(lat), lat_min, lat_dir, abs(lon), lon_min, lon_dir,
			hdg, spd_kt, alt_ft, cmt);
}

void tx_sensor_lora(SensorData* data)
{
	if(lora_state == TX)
	{
		return;
	}
	lora_state = TX;

	if (radio_in_use == 1)
	{
		return;
	}
	radio_in_use = 2;

	char sensor_str[244];
	sprintf(sensor_str,
			"%05.2f%05.2f%05.2f"	// IMU acceleration
			"%07.2f%07.2f%07.2f"   	// IMU rotation
			"%06.2f%07.2f"        	// Barometer
			"%06.4f%06.4f%06.4f",  	// Magnetometer

			data->accel.accelX, data->accel.accelY, data->accel.accelZ,     //
			data->gyro.gyroX, data->gyro.gyroY, data->gyro.gyroZ,           //
			data->baro.temperature, data->baro.pressure,                    //
			data->mag.magX, data->mag.magY, data->mag.magZ                 	//
	);

	char sensor_msg[255];
	sprintf(sensor_msg, "$#%.3u%s", strlen(sensor_str), sensor_str);

	gpio_write(PIN_PB5, GPIO_LOW);
	DELAY(5);

	Radio.Send((uint8_t*)sensor_msg, strlen(sensor_msg) + 1);
}

void tx_gps_lora(GPS_Fix_TypeDef* fix, float lat, float lon)
{
	if(lora_state == TX)
	{
		return;
	}
	lora_state = TX;

	if (radio_in_use == 1)
	{
		return;
	}
	radio_in_use = 2;

	char gps_str[244];
	int32_t lat_int = lat * 10000000;
	int32_t lon_int = lon * 10000000;
	int32_t height_int = fix->height_msl * 10;
	int16_t vel_north_int = fix->vel_north * 10;
	int16_t vel_east_int = fix->vel_east * 10;
	int16_t vel_down_int = fix->vel_down * 10;

	int gps_msg_len = sprintf(gps_str,	// All LSB first
			"%c%c%c%c%c%c"				// Datetime - 8-bit unsigned ints (year starts at 1980)
			"%c%c%c%c"					// Lat - 1/10000000 signed 32-bit number
			"%c%c%c%c"					// Lon - 1/10000000 signed 32-bit number
			"%c%c%c"     				// Alt - 1/10 m 24-bit signed number
			"%c%c"						// Vel - 1/10 m/s, 16-bit signed number
			"%c%c"						// "								"
			"%c%c"     					// "                                "
			"%c"                 		// Num Sats
			"%c",                		// Valid

			(uint8_t) (fix->year - 1980), fix->month, fix->day, fix->hour, fix->min, fix->sec,
			(uint8_t) lat_int, (uint8_t) (lat_int >> 8), (uint8_t) (lat_int >> 16), (uint8_t) (lat_int >> 24),
			(uint8_t) lon_int, (uint8_t) (lon_int >> 8), (uint8_t) (lon_int >> 16), (uint8_t) (lon_int >> 24),
			(uint8_t) height_int, (uint8_t) (height_int >> 8), (uint8_t) (height_int >> 16),
			(uint8_t) vel_north_int, (uint8_t) (vel_north_int >> 8),
			(uint8_t) vel_east_int, (uint8_t) (vel_east_int >> 8),
			(uint8_t) vel_down_int, (uint8_t) (vel_down_int >> 8),
			fix->num_sats,
			fix->fix_valid
	);
	char gps_msg[255];
	int gps_hdr_len = sprintf(gps_msg, "$@%.3u", gps_msg_len);
	memcpy(gps_msg + gps_hdr_len, gps_str, gps_msg_len);

	gpio_write(PIN_PB5, GPIO_LOW);
	DELAY(5);

	Radio.Send((uint8_t*) gps_msg, gps_hdr_len + gps_msg_len);
}

void init_sensor_timer() {
	HAL_LPTIM_Counter_Start_IT(&hlptim1, TARGET_INTERVAL * 125);
}

void sensor_irq() {
    Accel current_accel = lsm6dsox_read_accel(&s_imu_conf);
    Gyro current_gyro = lsm6dsox_read_gyro(&s_imu_conf);

	SensorData log = {
		.timestamp = MILLIS(),
		.accel = current_accel,
		.gyro = current_gyro,
		.mag = iis2mdc_read(&s_mag_conf),
		.baro = ms5637_read(&s_baro_conf, OSR_256),
		.temp = ds18b20_read(&s_temp_conf),
	};
	last_sensor_data = log;

	if(sensor_log_paused)
	{
		return;
	}

    if (!((fifo.widx == fifo.ridx - 1) ||
          (fifo.ridx == 0 && fifo.widx == LOG_FIFO_LEN - 1))) {
        // FIFO is not full
        fifo.queue[fifo.widx] = log;
        if (fifo.widx == LOG_FIFO_LEN - 1) {
            fifo.widx = 0;
        } else {
            fifo.widx += 1;
        }
    }
}
