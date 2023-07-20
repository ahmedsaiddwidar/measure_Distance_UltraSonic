/*
 * ICU_driver.c
 *
 *  Created on: Jun 21, 2023
 *      Author: Ahmed Dwidar
 */
#include<avr\io.h>
#include"gpio.h"
#include"common_macros.h"
#include <avr/interrupt.h>
#include "ICU.h"

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
	(*g_callBackPtr)();
	}
}


void ICU_init(const ICU_ConfigType *config_ptr)
{
	GPIO_setupPinDirection(PORTD_ID,PIN6_ID,PIN_INPUT);

	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);

	TCCR1B = (TCCR1B & 0xF8) | (config_ptr ->clock);
	TCCR1B = (TCCR1B & 0xBF) | ((config_ptr ->edge) <<6);


	TCNT1 = 0;
	ICR1 = 0;

	SET_BIT(TIMSK,TICIE1);
}
void ICU_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}
void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType)
{
	TCCR1B = (TCCR1B & 0xBF) | (a_edgeType<<6);
}
uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}
void ICU_clearTimerValue(void)
{
	TCNT1 = 0;
}
void ICU_deint(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	CLEAR_BIT(TIMSK,TICIE1);

	g_callBackPtr = NULL_PTR;
}
