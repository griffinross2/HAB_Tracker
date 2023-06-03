#ifndef HAB_TIMER_H
#define HAB_TIMER_H

#include <stdint.h>

void init_timers();

uint64_t MICROS();

uint64_t MILLIS();

void DELAY(uint16_t mS);

void DELAY_MICROS(uint32_t uS);

#endif