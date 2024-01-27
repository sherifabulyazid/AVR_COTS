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
	setPinDirection(DIO_PORTD,PIN4,OUTPUT);
	setPinDirection(DIO_PORTD,PIN5,OUTPUT);
	setPinDirection(DIO_PORTD,PIN7,OUTPUT);

	//Timer0_Normal_CallBack(LedOn,5000);
	//Timer0_Normal();
	//Timer0_CTC_CallBack(LedOn,1000);
	//Timer0_CTC();
	//Timer0_PWM_Fast();
	//Timer0_PWM_Phase_Correct();
	//Timer1_Servo(145);

	//Timer1_Normal();
	//Timer1_Normal_CallBack(LedOn,5000);
	//Timer1_CTC();
	//Timer1_CTC_CallBack(LedOn,5000);
	//Timer1_PWM_Fast_8_bit();
	//Timer1_PWM_Fast_9_bit();
	//Timer1_PWM_Fast_10_bit();
	//Timer1_PWM_Phase_Correct_8_bit();
	//Timer1_PWM_Phase_Correct_9_bit();
	//Timer1_PWM_Phase_Correct_10_bit();
	//Timer1_PWM_Fast_ICR1(50);
	Timer1_PWM_Phase_Correct_ICR1(50);
	return 0;
}
void LedOn(void)
{
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
	_delay_ms(500);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
	_delay_ms(500);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
	_delay_ms(500);
	setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
	_delay_ms(500);
}
