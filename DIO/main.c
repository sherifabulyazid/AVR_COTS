
/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *      Author: Sherif Abuelyazid
 */

#include "STD.h"
#include "BIT_MATH.h"

#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Register.h"

int main(void)
{
	/*

	 setPinDirection(DIO_PORTD,PIN3,OUTPUT);
	setPinDirection(DIO_PORTC,PIN2,OUTPUT);
	setPinDirection(DIO_PORTC,PIN7,OUTPUT);

	setPinVAlue(DIO_PORTD,PIN3,OUTPUT_HIGH);
	setPinVAlue(DIO_PORTC,PIN2,OUTPUT_HIGH);
	setPinVAlue(DIO_PORTC,PIN7,OUTPUT_HIGH);
	DIO_uint8_SetPortDirection(DIO_PORTC,OUTPUT);
*/
	setPinDirection(DIO_PORTD,PIN3,OUTPUT);
	setPinDirection(DIO_PORTC,PIN2,OUTPUT);
	setPinDirection(DIO_PORTC,PIN7,OUTPUT);
	uint8 pinStatus=2;
	setPinDirection(DIO_PORTD,PIN2,INPUT);

	 while(1)
	 {

		 DIO_uint8_GetPinValue(DIO_PORTD,PIN2,&pinStatus);
		 _delay_ms(50);

		 if(pinStatus==1)
		 {
			setPinVAlue(DIO_PORTD,PIN3,OUTPUT_HIGH);
			setPinVAlue(DIO_PORTC,PIN2,OUTPUT_HIGH);
			setPinVAlue(DIO_PORTC,PIN7,OUTPUT_HIGH);
		 }
		 else if (pinStatus==0)
		 {
				setPinVAlue(DIO_PORTD,PIN3,OUTPUT_LOW);
				setPinVAlue(DIO_PORTC,PIN2,OUTPUT_LOW);
				setPinVAlue(DIO_PORTC,PIN7,OUTPUT_LOW);

		 }
		 else
		 {

		 }


	 }
	return 0;
}

