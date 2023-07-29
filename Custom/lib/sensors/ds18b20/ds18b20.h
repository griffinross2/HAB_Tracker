/*
 * ds18b20.h
 *
 *  Created on: Jul 16, 2023
 *      Author: griff
 */

#ifndef DS18B20_H
#define DS18B20_H

#include "sensors/data.h"
#include "common/status.h"
#include "peripherals/one-wire/one-wire.h"

Status ds18b20_init(OneWireDevice* device);
TempProbe ds18b20_read(OneWireDevice* device);

#endif /* DS18B20_H */
