/*
 * main.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Sherif Abuelyazid
 */

#include "STD.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"#include "Timer_interface.h"
void LedOn(void);

int main(void)
{
	setPinDirection(DIO_PORTB,PIN3,OUTPUT);
	setPinDirection(DIO_PORTD,PIN5,OUTPUT);
	setPinDirection(DIO_PORTD,PIN7,OUTPUT);

	//Timer0_Normal_CallBack(LedOn,5000);
	//Timer0_Normal();
	//Timer0_CTC_CallBack(LedOn,1000);
	//Timer0_CTC();
	//Timer0_PWM_Fast();
	//Timer0_PWM_Phase_Correct();
	Timer1_Servo(145);
/*	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
	Delay_mS(1000);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
	Delay_mS(1000);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
	Delay_mS(2000);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
	Delay_mS(2000);
*/
	while(1)
	{
	}
	return 0;
}
void LedOn(void)
{
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
	_delay_ms(250);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
	_delay_ms(100);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
	_delay_ms(250);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
	_delay_ms(100);
}
