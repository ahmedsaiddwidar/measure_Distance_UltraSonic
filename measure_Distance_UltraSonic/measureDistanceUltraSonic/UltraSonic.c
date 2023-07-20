/*
 * UltraSonic.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Ahmed Dwidar
 */
#include"UltraSonic.h"
#include<util/delay.h>
#include"GPIO.h"
#include"ICU.h"

volatile uint16 timePeriod = 0;
volatile uint8 edgeCount = 0;

	ICU_ConfigType ICU_Configurations = {F_CPU_CLOCK,raising};

void Ultrasonic_init(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);

	ICU_init(&ICU_Configurations);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

}
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void)
{
	uint16 distance;

	Ultrasonic_Trigger();

	while(edgeCount != 2)

		distance = 2 + ((float)timePeriod / 58);

	edgeCount = 0;



	return distance;

}
void Ultrasonic_edgeProcessing(void)
{
	edgeCount++;

	if(edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(falling);

	}
	else if(edgeCount == 2)
	{
		timePeriod = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(raising);


	}
}
