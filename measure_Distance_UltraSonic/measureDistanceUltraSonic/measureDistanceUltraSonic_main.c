/*
 * measureDistanceUltraSonic_main.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Ahmed Dwidar
 */
#include"LCD.h"
#include"UltraSonic.h"
#include<avr/interrupt.h>
#include"COMMON_MACROS.h"



int main(void)
{
	uint16 measuredDistance = 0;

	SET_BIT(SREG,7);

	Ultrasonic_init();
	LCD_init();

	LCD_moveCursor(1,0);
	LCD_displayString("Distance= ");

	LCD_moveCursor(1,14);
	LCD_displayString("cm");
	while(1)
	{

		measuredDistance = Ultrasonic_readDistance();

		LCD_moveCursor(1,10);

		if(measuredDistance >=100)
		{
		LCD_intgerToString(measuredDistance);
		}
		else
		{
			LCD_intgerToString(measuredDistance);
			LCD_displayCharacter(' ');
		}

	}
}

