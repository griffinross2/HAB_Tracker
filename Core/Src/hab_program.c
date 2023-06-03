/*
 * hab_program.c
 *
 *  Created on: Jun 2, 2023
 *      Author: griff
 */

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

void hab_program()
{
	gpio_write(PIN_PB4, GPIO_HIGH);
	DELAY(500);
	gpio_write(PIN_PB4, GPIO_LOW);
	DELAY(500);
}
