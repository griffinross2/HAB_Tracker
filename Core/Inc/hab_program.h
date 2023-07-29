/*
 * hab_program.h
 *
 *  Created on: Jun 2, 2023
 *      Author: griff
 */

#ifndef SRC_HAB_PROGRAM_H_
#define SRC_HAB_PROGRAM_H_

#include "main.h"

extern DAC_HandleTypeDef hdac;
extern LPTIM_HandleTypeDef hlptim1;

void hab_init();
void hab_loop();
void sensor_irq();

#endif /* SRC_HAB_PROGRAM_H_ */
