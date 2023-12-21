/*
 * main.c
 *
 *  Created on: Dec 20, 2023
 *      Author: Sherif
 */

#include "Interrupt_Interface.h"
#include "DIO_Interface.h"
#include "STD.h"
#include"DIO_Register.h"

void blinking(void)
{
	setPinVAlue(DIO_PORTC, PIN7,OUTPUT_HIGH);
			_delay_ms(200);
			setPinVAlue(DIO_PORTC, PIN7,OUTPUT_LOW);
			_delay_ms(100);
			setPinVAlue(DIO_PORTC, PIN7,OUTPUT_HIGH);
			_delay_ms(200);
			setPinVAlue(DIO_PORTC, PIN7,OUTPUT_LOW);
			_delay_ms(100);
}
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
		blinking();
}

int main (void)
{
	INT_Set_GIE ();
	INT_Sense_Level(INT0);
	INT_PIE(INT0);
	setPinDirection(DIO_PORTC, PIN2,OUTPUT); //LED0
	setPinDirection(DIO_PORTC, PIN7,OUTPUT); //LED1
	setPinDirection(DIO_PORTC, PIN6,OUTPUT); //LED2 for protus
	setPinDirection(DIO_PORTD,PIN2,INPUT); // push button 2
	setPinDirection(DIO_PORTD,PIN6,INPUT); // push button 1

	setPinVAlue(DIO_PORTD,PIN2,OUTPUT_HIGH); //pull up resistance "interrupt"
	setPinVAlue(DIO_PORTD,PIN6,OUTPUT_HIGH); //pull up resistance "test"

	uint8 buttonStatus =0;
	while(1)
	{
		setPinVAlue(DIO_PORTC, PIN2,OUTPUT_HIGH);
		_delay_ms(200);
		setPinVAlue(DIO_PORTC, PIN2,OUTPUT_LOW);
		_delay_ms(200);
		DIO_GetPinValue(DIO_PORTD,PIN6,&buttonStatus);
		_delay_ms(25);
		DIO_GetPinValue(DIO_PORTD,PIN6,&buttonStatus);
		if(buttonStatus==0)
		{
			setPinVAlue(DIO_PORTC, PIN6,OUTPUT_HIGH);
			_delay_ms(400);
			setPinVAlue(DIO_PORTC, PIN6,OUTPUT_LOW);
			_delay_ms(400);
		}

	}
	return 0;
}


