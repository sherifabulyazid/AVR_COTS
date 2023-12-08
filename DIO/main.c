
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
	setPinDirection(DIO_PORTD,PIN3,OUTPUT);
	setPinDirection(DIO_PORTC,PIN2,OUTPUT);
	setPinDirection(DIO_PORTC,PIN7,OUTPUT);

	setPinVAlue(DIO_PORTD,PIN3,OUTPUT_HIGH);
	setPinVAlue(DIO_PORTC,PIN2,OUTPUT_HIGH);
	setPinVAlue(DIO_PORTC,PIN7,OUTPUT_HIGH);

	return 0;
}

