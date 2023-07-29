#include "lsm6dsox.h"

#include <string.h>

#include "math.h"
#include "hab_timer.h"
#include "stdio.h"

Lsm6dsoxAccelRange g_current_accel_range = LSM6DSOX_XL_RANGE_16_G;
Lsm6dsoxGyroRange g_current_gyro_range = LSM6DSOX_G_RANGE_2000_DPS;

Status lsm6dsox_init(I2cDevice* device) {
	uint8_t buf[2];

	// Read WHO_AM_I register to confirm we're connected
	buf[0] = LSM6DSOX_WHO_AM_I;
	if (i2c_write(device, buf, 1) != STATUS_OK) {
		return STATUS_ERROR;
	}
	if (i2c_read(device, buf, 1) != STATUS_OK) {
		return STATUS_ERROR;
	}
	if (buf[0] != 0x6C) {
		return STATUS_ERROR;
	}

	// Perform configuration
	buf[0] = LSM6DSOX_CTRL3_C;
	buf[1] = 0x85;  // Reset
	if (i2c_write(device, buf, 2) != STATUS_OK) {
		return STATUS_ERROR;
	}

	// Disable I3C and DEN value
	buf[0] = LSM6DSOX_CTRL9_XL;
	buf[1] = 0x02;
	if (i2c_write(device, buf, 2) != STATUS_OK) {
		return STATUS_ERROR;
	}

	// Enable and configure the accel to 16g range and 6.66khz rate
	buf[0] = LSM6DSOX_CTRL1_XL;
	buf[1] = LSM6DSOX_XL_RANGE_16_G | LSM6DSOX_XL_RATE_6_66_KHZ;
	if (i2c_write(device, buf, 2) != STATUS_OK) {
		return STATUS_ERROR;
	}

	// Enable and configure the gyro to 2000dps range and 6.66khz rate
	buf[0] = LSM6DSOX_CTRL2_G;
	buf[1] = LSM6DSOX_G_RANGE_2000_DPS | LSM6DSOX_G_RATE_6_66_KHZ;
	if (i2c_write(device, buf, 2) != STATUS_OK) {
		return STATUS_ERROR;
	}

	return STATUS_OK;
}

Accel lsm6dsox_read_accel(I2cDevice* device) {
    Accel result;

    // Read all 6 registers at once
    uint8_t rx_buf[6];
    rx_buf[0] = LSM6DSOX_OUT_A;
    if (i2c_write(device, rx_buf, 1) != STATUS_OK) {
    	result.accelX = NAN;
		result.accelY = NAN;
		result.accelZ = NAN;
		return result;
	}
    if (i2c_read(device, rx_buf, 6) != STATUS_OK) {
        result.accelX = NAN;
        result.accelY = NAN;
        result.accelZ = NAN;
        return result;
    }

    // Convert unsigned 8-bit halves to signed 16-bit numbers
    int16_t acc_x_raw = ((int16_t)(((uint16_t)rx_buf[1] << 8) | rx_buf[0]));
    int16_t acc_y_raw = ((int16_t)(((uint16_t)rx_buf[3] << 8) | rx_buf[2]));
    int16_t acc_z_raw = ((int16_t)(((uint16_t)rx_buf[5] << 8) | rx_buf[4]));

    // Convert data to units of g
    float conversion_factor = 0;
    switch (g_current_accel_range) {
        case LSM6DSOX_XL_RANGE_2_G:
            conversion_factor = 0.061;
            break;
        case LSM6DSOX_XL_RANGE_4_G:
            conversion_factor = 0.122;
            break;
        case LSM6DSOX_XL_RANGE_8_G:
            conversion_factor = 0.244;
            break;
        case LSM6DSOX_XL_RANGE_16_G:
            conversion_factor = 0.488;
            break;
    }

    float acc_x = ((float)acc_x_raw * conversion_factor) / 1000;
    float acc_y = ((float)acc_y_raw * conversion_factor) / 1000;
    float acc_z = ((float)acc_z_raw * conversion_factor) / 1000;

    result.accelX = acc_x;
    result.accelY = acc_y;
    result.accelZ = acc_z;

    return result;
}

Gyro lsm6dsox_read_gyro(I2cDevice* device) {
    Gyro result;

    // Read all 6 registers at once
    uint8_t rx_buf[6];
    rx_buf[0] = LSM6DSOX_OUT_G;
	if (i2c_write(device, rx_buf, 1) != STATUS_OK) {
		result.gyroX = NAN;
		result.gyroY = NAN;
		result.gyroZ = NAN;
		return result;
	}
	if (i2c_read(device, rx_buf, 6) != STATUS_OK) {
		result.gyroX = NAN;
		result.gyroY = NAN;
		result.gyroZ = NAN;
		return result;
	}

    // Convert unsigned 8-bit halves to signed 16-bit numbers
    int16_t g_x_raw = (int16_t)(((uint16_t)rx_buf[1] << 8) | rx_buf[0]);
    int16_t g_y_raw = (int16_t)(((uint16_t)rx_buf[3] << 8) | rx_buf[2]);
    int16_t g_z_raw = (int16_t)(((uint16_t)rx_buf[5] << 8) | rx_buf[4]);

    // Convert data to units of dps
    float conversion_factor = 0;
    switch (g_current_gyro_range) {
        case LSM6DSOX_G_RANGE_125_DPS:
            conversion_factor = 4.375;
            break;
        case LSM6DSOX_G_RANGE_250_DPS:
            conversion_factor = 8.75;
            break;
        case LSM6DSOX_G_RANGE_500_DPS:
            conversion_factor = 17.5;
            break;
        case LSM6DSOX_G_RANGE_1000_DPS:
            conversion_factor = 35.0;
            break;
        case LSM6DSOX_G_RANGE_2000_DPS:
            conversion_factor = 70.0;
            break;
    }

    float g_x = ((float)g_x_raw * conversion_factor) / 1000;
    float g_y = ((float)g_y_raw * conversion_factor) / 1000;
    float g_z = ((float)g_z_raw * conversion_factor) / 1000;

    result.gyroX = g_x;
    result.gyroY = g_y;
    result.gyroZ = g_z;

    return result;
}

Status lsm6dsox_config_accel(I2cDevice* device, Lsm6dsoxAccelDataRate rate,
                             Lsm6dsoxAccelRange range) {
    uint8_t tx_buf[2];
    tx_buf[0] = LSM6DSOX_CTRL1_XL;
    tx_buf[1] = rate | range;

    // Configure the accelerometer to the specified range and measurement rate
    if (i2c_write(device, tx_buf, 2) != STATUS_OK) {
        return STATUS_ERROR;
    }

    uint8_t rx_buf = LSM6DSOX_CTRL1_XL;

    if (i2c_write(device, &rx_buf, 1) != STATUS_OK) { // Verify the settings
        return STATUS_ERROR;
    }

	if (i2c_read(device, &rx_buf, 1) != STATUS_OK) {
		return STATUS_ERROR;
	}

    if ((rx_buf & 0xF0) != rate) {
        return STATUS_ERROR;
    }
    if ((rx_buf & 0x0C) != range) {
        return STATUS_ERROR;
    }
    g_current_accel_range = range;

    return STATUS_OK;
}

Status lsm6dsox_config_gyro(I2cDevice* device, Lsm6dsoxGyroDataRate rate,
                            Lsm6dsoxGyroRange range) {

    uint8_t tx_buf[2];
	tx_buf[0] = LSM6DSOX_CTRL2_G;
	tx_buf[1] = rate | range;
	if (range == LSM6DSOX_G_RANGE_125_DPS) {
		tx_buf[1] |= 0x02;
	}

	// Configure the gyroscope to the specified range and measurement rate
	if (i2c_write(device, tx_buf, 2) != STATUS_OK) {
		return STATUS_ERROR;
	}

    uint8_t rx_buf = LSM6DSOX_CTRL2_G;

	if (i2c_write(device, &rx_buf, 1) != STATUS_OK) { // Verify the settings
		return STATUS_ERROR;
	}

	if (i2c_read(device, &rx_buf, 1) != STATUS_OK) {
		return STATUS_ERROR;
	}

    if ((rx_buf & 0xF0) != rate) {
        return STATUS_ERROR;
    }
    if (range != LSM6DSOX_G_RANGE_125_DPS) {
        if ((rx_buf & 0x0C) != range) {
            return STATUS_ERROR;
        }
    } else {
        if (!(rx_buf & 0x02)) {
            return STATUS_ERROR;
        }
    }

    g_current_gyro_range = range;

    return STATUS_OK;
}
