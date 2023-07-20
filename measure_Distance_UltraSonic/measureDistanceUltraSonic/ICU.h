/*
 * ICU_driver.h
 *
 *  Created on: Jun 21, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

typedef enum {
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_ClockType;

typedef enum {
	falling,raising
}ICU_EdgeType;

typedef struct
{
	ICU_ClockType clock;
	ICU_EdgeType edge;
}ICU_ConfigType;

void ICU_init(const ICU_ConfigType *config_ptr); //initialization of ICU with (dynamic configration)

void ICU_setCallBack(void(*a_ptr)(void)); // we pass function name the we want to pass

void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType); // to set the edge we want the ICU to detect

uint16 ICU_getInputCaptureValue(void);  // return the captured value of the timer on ICR1

void ICU_clearTimerValue(void);  // clear the timer to zero to get another value from it

void ICU_deint(void); // disable the Timer1 to stop the ICU Driver(as ICU is part of the timer)



#endif /* ICU_H_ */
