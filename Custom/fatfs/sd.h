#ifndef SD_H
#define SD_H

#include <stdint.h>

#include "lib/sensors/data.h"
#include "lib/gps/max_m10s.h"
#include "lib/peripherals/spi/spi.h"
#include "lib/common/status.h"

Status sd_spi_init(SpiDevice* device);

Status sd_init(SpiDevice* device);

Status sd_reinit();

Status sd_deinit();

Status sd_flush();

Status sd_write_sensor_data(volatile SensorData* dat);

Status sd_write_gps_data(uint64_t timestamp, volatile GPS_Fix_TypeDef* fix);

#endif  // SD_H
