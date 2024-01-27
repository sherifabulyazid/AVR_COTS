/*
 * main.c
 *
 *  Created on: Jan 6, 2024
 *      Author: hp
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "UART_Interface.h"
#include "DIO_Interface.h"

int main(void)
{
	setPinDirection(DIO_PORTD,PIN7,OUTPUT);
	uint8 Val_Received = 0;
	UART_Init();
	while(1)
	{
		Val_Received=UART_Receive_data();
		if(Val_Received == 'C')
		{
			setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
		}
		else
		{
			setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
		}


	}

	return 0;
}
