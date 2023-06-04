/*
 * AFSK.h
 *
 *  Created on: Jul 13, 2020
 *      Author: matthewtran
 */

#ifndef INC_AFSK_H_
#define INC_AFSK_H_

#include "main.h"
#include "board.h"
#include <stdbool.h>
#include <malloc.h>

#include "BitFIFO.h"
#include "IntFIFO.h"
#include "APRS.h"

#define TX_PTT_Pin PIN_PA10

extern DAC_HandleTypeDef hdac;
extern LPTIM_HandleTypeDef hlptim2;

extern bool AFSK_sending;

void AFSK_init();
bool AFSK_send(BitFIFO *bfifo);

// private helpers
void AFSK_send_fillbuff(uint8_t *buff, uint32_t samples);
void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef *hdac_p);
void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac_p);

#endif /* INC_AFSK_H_ */
