#ifndef ONEWIRE_H
#define ONEWIRE_H

#include <stddef.h>
#include <stdint.h>

#include "../../common/status.h"
#include "main.h"

#define ONEWIRE_MAX_LEN 128

extern UART_HandleTypeDef huart1;

typedef enum {
	ONEWIRE_SPEED_INVALID = 0,
	ONEWIRE_SPEED_9600 = 9600,
    ONEWIRE_SPEED_115200 = 115200,
} OneWireSpeed;

typedef struct {
    OneWireSpeed reset_speed;
    OneWireSpeed normal_speed;
} OneWireDevice;

Status onewire_reset(OneWireDevice *device);

Status onewire_readwrite(OneWireDevice *device, uint8_t *buf, size_t len);

void onewire_tx_callback();

void onewire_rx_callback();

#endif // ONEWIRE_H
