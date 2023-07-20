# measure_Distance_UltraSonic
1. Use ATmega32 Microcontroller with frequency 8Mhz.
2. Measure the distance using the Ultrasonic sensor HC-SR04. Check the “HC-SR04
Ultrasonic MT Student Tutorial” pdf file to understand how to interface with this
sensor.
3. The LCD should display the distance value.
4. The project should be design and implemented based on the layered architecture
model as follow:ICU,GPIO as microcontroller abstraction layer, LCD,UltraSonic sensor as hardware abstraction layer
UltraSonic sensor specifications:
1. ATmega16 microcontroller needs to transmit at least 10 us trigger pulse to the
HC-SR04 Trig Pin.
2. After getting a trigger pulse, HC-SR04 automatically sends eight 40 kHz sound
waves and the microcontroller waits for rising edge output at the Echo pin.
3. When the rising edge capture occurs at the Echo pin which is connected to an
input of ATmega16, start Timer of ATmega16 and again wait for a falling edge on
the Echo pin.
4. As soon as the falling edge is captured at the Echo pin, the microcontroller reads
the count of the Timer. This time count is used to calculate the distance to an
object.
