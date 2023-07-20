/*
 * UltraSonic.h
 *
 *  Created on: Jul 16, 2023
 *      Author: Ahmed Dwidar
 */

#include"STD_TYPES.h"


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*
 * -Initialize the ICU driver as required.
 * -Setup the ICU call back function.
 * -Setup the direction for the trigger pin as output pin through the GPIO driver.
*/
void Ultrasonic_init(void);
/*
 * -Send the Trigger pulse to the ultrasonic.
*/
void Ultrasonic_Trigger(void);
/*
 * -Send the trigger pulse by using Ultrasonic_Trigger function.
 * -Start the measurements by the ICU from this moment.
 * -Return: The measured distance in Centimeter.
*/
uint16 Ultrasonic_readDistance(void);
/*
 * -This is the call back function called by the ICU driver.
 * This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
*/
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */