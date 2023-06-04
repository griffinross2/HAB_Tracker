/*
 * AFSK.c
 *
 *  Created on: Jul 14, 2020
 *      Author: matthewtran
 */

#include "AFSK.h"
#include "hab_timer.h"
#include "peripherals/gpio/gpio.h"

const uint8_t AFSK_SINE_LOOKUP[256] = {
	128, 131, 134, 137, 140, 143, 146, 149, 152, 156, 159, 162, 165, 168, 171, 174,
	176, 179, 182, 185, 188, 191, 193, 196, 199, 201, 204, 206, 209, 211, 213, 216,
	218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 237, 239, 240, 242, 243, 245,
	246, 247, 248, 249, 250, 251, 252, 252, 253, 254, 254, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 254, 254, 253, 252, 252, 251, 250, 249, 248, 247,
	246, 245, 243, 242, 240, 239, 237, 236, 234, 232, 230, 228, 226, 224, 222, 220,
	218, 216, 213, 211, 209, 206, 204, 201, 199, 196, 193, 191, 188, 185, 182, 179,
	176, 174, 171, 168, 165, 162, 159, 156, 152, 149, 146, 143, 140, 137, 134, 131,
	128, 124, 121, 118, 115, 112, 109, 106, 103,  99,  96,  93,  90,  87,  84,  81,
	79,  76,  73,  70,  67,  64,  62,  59,  56,  54,  51,  49,  46,  44,  42,  39,
	37,  35,  33,  31,  29,  27,  25,  23,  21,  19,  18,  16,  15,  13,  12,  10,
	9,   8,   7,   6,   5,   4,   3,   3,   2,   1,   1,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   1,   1,   2,   3,   3,   4,   5,   6,   7,   8,
	9,  10,  12,  13,  15,  16,  18,  19,  21,  23,  25,  27,  29,  31,  33,  35,
	37,  39,  42,  44,  46,  49,  51,  54,  56,  59,  62,  64,  67,  70,  73,  76,
	79,  81,  84,  87,  90,  93,  96,  99, 103, 106, 109, 112, 115, 118, 121, 124
};

#define DAC_REST 127 // based on AFSK_SINE_LOOKUP

// REQUIREMENTS
// Timers used for DAC and ADC are set to overflow at FS
// DMA request for DMA set in circular mode

// constants
#define SEND_FREQ_SHIFT    5 // samples_per_bit = 1 << FREQ_SHIFT
#define BAUD            1200 // bps
#define FREQ_MARK       1200 // Hz, 1
#define FREQ_SPACE      2200 // Hz, 0

// derived constants
#define SEND_FS   (BAUD << SEND_FREQ_SHIFT) // Hz, BAUD << FREQ_SHIFT
#define DPH_MARK                  134217728 // FREQ_MARK  / FS * (1 << 32) (using 2*pi rad = 2^32)
#define DPH_SPACE                 246065835 // FREQ_SPACE / FS * (1 << 32) (using 2*pi rad = 2^32)

// variables
static uint8_t send_buff[2048]; // DAC, needs to be multiple of 1 << (FREQ_MUL+1)
static uint32_t phase;
static BitFIFO *send_fifo;

// global variables
bool AFSK_sending;

// functions
void AFSK_init() {
	// Start sending
	gpio_write(TX_PTT_Pin, 1);
	HAL_LPTIM_Counter_Start(&hlptim2, 1250);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_8B_R, DAC_REST);
	AFSK_sending = false;
}

bool AFSK_send(BitFIFO *bfifo) {
	if (AFSK_sending) {
		return false;
	}

	send_fifo = bfifo;
	phase = 0;
	AFSK_sending = 1;
	AFSK_send_fillbuff(send_buff, sizeof(send_buff));
	gpio_write(TX_PTT_Pin, 0);
	DELAY(5);
	HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*) send_buff, sizeof(send_buff), DAC_ALIGN_8B_R);

	return true;
}

// private helpers
void AFSK_send_fillbuff(uint8_t *buff, uint32_t samples) {
	uint32_t sig_index = 0;
	for (uint32_t i = 0; i < (samples >> SEND_FREQ_SHIFT); i++) {
		if (BitFIFO_is_empty(send_fifo)) {
			break;
		}

		uint32_t dph = BitFIFO_pop(send_fifo) ? DPH_MARK : DPH_SPACE;
		for (sig_index = i << SEND_FREQ_SHIFT; sig_index < ((i + 1) << SEND_FREQ_SHIFT); sig_index++) {
			phase += dph;
			buff[sig_index] = AFSK_SINE_LOOKUP[phase >> 24]; // 8-bit sine lookup
		}
	}

	for (; sig_index < samples; sig_index++) {
		buff[sig_index] = DAC_REST; // at rest level if no more bits to send
	}
}

// sending interrupts
void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef *hdac_p) {
	if (!AFSK_sending) {
		HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		HAL_DAC_Start(&hdac, DAC_CHANNEL_1); // stopping DMA stops DAC too
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_8B_R, DAC_REST);
		gpio_write(TX_PTT_Pin, 1);
	}

	AFSK_send_fillbuff(send_buff, sizeof(send_buff) >> 1);
	if (BitFIFO_is_empty(send_fifo)) {
		AFSK_sending = false;
	}
}

void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac_p) {
	if (!AFSK_sending) {
		HAL_DAC_Stop_DMA(&hdac, DAC_CHANNEL_1);
		HAL_DAC_Start(&hdac, DAC_CHANNEL_1); // stopping DMA stops DAC too
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_8B_R, DAC_REST);
		gpio_write(TX_PTT_Pin, 1);
	}

	AFSK_send_fillbuff(send_buff + (sizeof(send_buff) >> 1), sizeof(send_buff) >> 1);
	if (BitFIFO_is_empty(send_fifo)) {
		AFSK_sending = false;
	}
}
