#ifndef HAB_TIMER_H
#define HAB_TIMER_H

#include <stdint.h>

void init_timers();

uint64_t MICROS();

uint64_t MILLIS();

void DELAY(volatile uint64_t mS);

void DELAY_MICROS(volatile uint64_t uS);

#endif
