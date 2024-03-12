/*
 * main.c
 *
 *  Created on: Mar 6, 2024
 *      Author: Sherif
 */
#include "LIBRARIES/STD_Types.h"
#include "LIBRARIES/bitmath.h"
#include "UART_interface.h"
#include "DIO_Interface.h"
#include <string.h>
#include <util/delay.h>
uint8 arr_ID[5]="ZIAD";
uint8 arr_ID2[5]="1998";
uint8 arr_R[5]={0};
uint8 R_var=0;
int main (void)
{
	DIO_setPinDirection(DIO_PORTA,PIN6,OUTPUT);
	DIO_setPinDirection(DIO_PORTA,PIN0,OUTPUT);

	UART_Init();

	while(1)
	{
		UART_sendString("Enter Number:");
		R_var= UART_Receive();
		if(R_var == '1')
		{
			DIO_setPinValue(DIO_PORTA,PIN6,HIGH);
			_delay_ms(1000);
		}
		else if(R_var == '2')
		{
			DIO_setPinValue(DIO_PORTA,PIN0,HIGH);
			_delay_ms(1000);
		}
		else
		{
			DIO_setPinValue(DIO_PORTA,PIN0,LOW);
			DIO_setPinValue(DIO_PORTA,PIN6,LOW);
		}
	}
	while(1)
	{
		UART_sendString("Enter ID: ");
			UART_recieve_string(arr_R);
		if(strncmp(arr_R,arr_ID,4) == 0)
		{
			DIO_setPinValue(DIO_PORTA,PIN6,HIGH);
			_delay_ms(1000);
		}
		else if (strncmp(arr_R,arr_ID2,4) == 0)
		{
			DIO_setPinValue(DIO_PORTA,PIN0,HIGH);
			_delay_ms(1000);
		}
		else
		{
		DIO_setPinValue(DIO_PORTA,PIN0,LOW);
		DIO_setPinValue(DIO_PORTA,PIN6,LOW);
		}

	}

	return 0;
}
