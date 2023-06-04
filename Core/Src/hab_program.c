/*
 * hab_program.c
 *
 *  Created on: Jun 2, 2023
 *      Author: griff
 */

#include <math.h>

#include <board.h>
#include <hab_timer.h>
#include <lib/common/status.h>
#include <lib/gps/max_m10s.h>
#include <lib/peripherals/gpio/gpio.h>
#include <lib/sensors/data.h>
#include <lib/sensors/iis2mdc/iis2mdc.h>
#include <lib/sensors/lsm6dsox/lsm6dsox.h>
#include <lib/sensors/ms5637/ms5637.h>
#include "main.h"
#include "aprs/APRS.h"

BitFIFO aprs_fifo;
APRSPacket aprs_packet = {
		.dest     = "APRS",
		.callsign = "KN4UIR-11",
		.digi     = "WIDE1-1,WIDE2-1",
};

GPS_Fix_TypeDef fix = {0};

float last_lat = NAN;
float last_lon = NAN;

void fill_packet(APRSPacket* packet, float lat, float lon, int hdg, int spd_kt, int alt_ft);

void hab_program()
{
	aprs_packet.info = malloc(1);
	APRS_init();

	gpio_write(PIN_PB4, GPIO_HIGH);
	DELAY(500);
	gpio_write(PIN_PB4, GPIO_LOW);
	DELAY(500);

	fill_packet(&aprs_packet, fix.lat, fix.lon, (int) fix.hdg, (int) (fix.ground_speed * 1.944), (int) (fix.height_msl * 3.281));
	APRS_encode(&aprs_fifo, &aprs_packet);
	APRS_send(&aprs_fifo);
}

void fill_packet(APRSPacket* packet, float lat, float lon, int hdg, int spd_kt, int alt_ft)
{
	free(packet->info);
	if(isnan(last_lat) || isnan(last_lon))
	{
		size_t info_size = snprintf(0, APRS_MAX_INFO, "@0000.00N\\0000.00W..../...");
		packet->info = malloc(info_size + 1);
		sprintf(packet->info, "@0000.00N\\0000.00W..../...");
	}
	else
	{
		float lat_min = abs(lat - (int) lat) * 60;
		float lon_min = abs(lon - (int) lon) * 60;
		char lat_dir = lat > 0 ? 'N' : 'S';
		char lon_dir = lon > 0 ? 'E' : 'W';
		size_t info_size = snprintf(0, APRS_MAX_INFO, "@%2.2d%05.2f%c/%2.2d%05.2f%cO%03d/%03d/A=%06d",
				(int) lat, lat_min, lat_dir, (int) lon, lon_min, lon_dir,
				hdg, spd_kt, alt_ft);
		packet->info = malloc(info_size + 1);
		sprintf(packet->info, "@%2.2d%05.2f%c/%2.2d%05.2f%cO%03d/%03d/A=%06d",
				(int) lat, lat_min, lat_dir, (int) lon, lon_min, lon_dir,
				hdg, spd_kt, alt_ft);
	}
}
