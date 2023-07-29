/*
 * ds18b20.c
 *
 *  Created on: Jul 16, 2023
 *      Author: griff
 */

#include "ds18b20.h"
#include "stdio.h"
#include "math.h"
#include "hab_timer.h"

Status ds18b20_init(OneWireDevice* device)
{
	uint8_t buf[ONEWIRE_MAX_LEN];
	uint8_t len = 0;

	// Reset Sequence
	if(onewire_reset(device) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Write skip ROM 0xCC
	buf[0] = 0xCC;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Write write scratchpad 0x4E
	buf[0] = 0x4E;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Write scratchpad data
	buf[0] = 0; buf[1] = 0; buf[2] = 0x1F;
	len = 3;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Reset Sequence
	if(onewire_reset(device) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Write skip ROM 0xCC
	buf[0] = 0xCC;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Write read scratchpad 0xBE
	buf[0] = 0xBE;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Read scratchpad
	uint8_t crc_reg = 0;
	buf[0] = 0xFF;
	buf[1] = 0xFF;
	buf[2] = 0xFF;
	buf[3] = 0xFF;
	buf[4] = 0xFF;
	buf[5] = 0xFF;
	buf[6] = 0xFF;
	buf[7] = 0xFF;
	buf[8] = 0xFF;
	len = 9;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}
	for (uint8_t i = 0; i < 8; i++) {
		for (uint8_t j = 0; j < 8; j++) {
			uint8_t lsb = crc_reg & 0x01;
			crc_reg >>= 1;
			uint8_t input = lsb ^ ((buf[i] >> j) & 0x01);
			crc_reg |= input << 7;
			if (((crc_reg >> 3) & 0x01) ^ input)
			{
				crc_reg |= (1 << 3);
			}
			else
			{
				crc_reg &= ~(1 << 3);
			}
			if (((crc_reg >> 2) & 0x01) ^ input)
			{
				crc_reg |= (1 << 2);
			}
			else
			{
				crc_reg &= ~(1 << 2);
			}
		}
	}
	if(crc_reg != buf[8])
	{
		return STATUS_ERROR;
	}

	// Reset Sequence
	if(onewire_reset(device) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Write skip ROM 0xCC
	buf[0] = 0xCC;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Write copy scratchpad 0x48
	buf[0] = 0x48;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return STATUS_ERROR;
	}

	// Read wait for copy to finish
	uint64_t timeout = MILLIS();
	len = 1;
	do {
		if(MILLIS() - timeout > 100)
		{
			return STATUS_TIMEOUT;
		}
		buf[0] = 0xFF;
		if(onewire_readwrite(device, buf, len) != STATUS_OK)
		{
			return STATUS_ERROR;
		}
	} while(buf[0] != 0xFF );

	return STATUS_OK;
}

TempProbe ds18b20_read(OneWireDevice* device)
{
	TempProbe result = {
		.temperature = NAN,
	};
	uint8_t buf[ONEWIRE_MAX_LEN];
	uint8_t len = 0;

	// Reset Sequence
	if(onewire_reset(device) != STATUS_OK)
	{
		return result;
	}

	// Write skip ROM 0xCC
	buf[0] = 0xCC;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return result;
	}

	// Write convert temp 0x44
	buf[0] = 0x44;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return result;
	}

	// Read wait for conversion to finish
	uint64_t timeout = MILLIS();
	len = 1;
	do {
		if(MILLIS() - timeout > 100)
		{
			return result;
		}
		buf[0] = 0xFF;
		if(onewire_readwrite(device, buf, len) != STATUS_OK)
		{
			return result;
		}
	} while(buf[0] != 0xFF );

	// Reset Sequence
	if(onewire_reset(device) != STATUS_OK)
	{
		return result;
	}

	// Write skip ROM 0xCC
	buf[0] = 0xCC;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return result;
	}

	// Write read scratchpad 0xBE
	buf[0] = 0xBE;
	len = 1;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return result;
	}

	// Read scratchpad
	uint8_t crc_reg = 0;
	buf[0] = 0xFF;
	buf[1] = 0xFF;
	buf[2] = 0xFF;
	buf[3] = 0xFF;
	buf[4] = 0xFF;
	buf[5] = 0xFF;
	buf[6] = 0xFF;
	buf[7] = 0xFF;
	buf[8] = 0xFF;
	len = 9;
	if(onewire_readwrite(device, buf, len) != STATUS_OK)
	{
		return result;
	}
	for (uint8_t i = 0; i < 8; i++) {
		for (uint8_t j = 0; j < 8; j++) {
			uint8_t lsb = crc_reg & 0x01;
			crc_reg >>= 1;
			uint8_t input = lsb ^ ((buf[i] >> j) & 0x01);
			crc_reg |= input << 7;
			if (((crc_reg >> 3) & 0x01) ^ input)
			{
				crc_reg |= (1 << 3);
			}
			else
			{
				crc_reg &= ~(1 << 3);
			}
			if (((crc_reg >> 2) & 0x01) ^ input) {
				crc_reg |= (1 << 2);
			}
			else
			{
				crc_reg &= ~(1 << 2);
			}
		}
	}
	if(crc_reg != buf[8])
	{
		return result;
	}

	uint16_t temp_raw = ((uint16_t) buf[1] << 8) | buf[0];
	result.temperature = ((temp_raw & 0x7F8) / 16.0);
	result.temperature *= temp_raw & 0xF800 ? -1 : 1;

	return result;
}
