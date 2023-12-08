/*
 * DIO_Program.c
 *
 *  Created on: Dec 8, 2023
 *      Author: hp
 */
#include "STD.h"
#include "BIT_MATH.h"

#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Register.h"

uint8 setPinDirection(uint8  Copy_Port ,  uint8 Copy_Pin ,  uint8 Copy_Direction)
{
	uint8 local_ErrorStatus=0;
	if (Copy_Pin <= 7)
	{
		if(Copy_Direction == OUTPUT)
		{
			switch(Copy_Port)
			{
				case DIO_PORTA:
					SETBIT(DDRA,Copy_Pin);
					break;
				case DIO_PORTB:
					SETBIT(DDRB,Copy_Pin);
					break;
				case DIO_PORTC:
					SETBIT(DDRC,Copy_Pin);
						break;
				case DIO_PORTD:
					SETBIT(DDRD,Copy_Pin);
					break;
				default:
					local_ErrorStatus=1;
					break;
			}
		}
		else if (Copy_Direction == INPUT)
		{
			switch(Copy_Port)
			{
				case DIO_PORTA:
					CLEARBIT(DDRA,Copy_Pin);
					break;
				case DIO_PORTB:
					CLEARBIT(DDRB,Copy_Pin);
					break;
				case DIO_PORTC:
					CLEARBIT(DDRC,Copy_Pin);
						break;
				case DIO_PORTD:
					CLEARBIT(DDRD,Copy_Pin);
					break;
				default:
					local_ErrorStatus=1;
					break;
			}
		}

		else
		{
			local_ErrorStatus=1;
		}
	}
	return local_ErrorStatus;
}

uint8 setPinVAlue(uint8  Copy_Port ,  uint8 Copy_Pin ,  uint8 Copy_Status)
{
	uint8 local_ErrorStatus=0;
	if (Copy_Pin <= 7)
	{
		if(Copy_Status == OUTPUT_HIGH)
		{
			switch(Copy_Port)
			{
				case DIO_PORTA:
					SETBIT(PORTA,Copy_Pin);
					break;
				case DIO_PORTB:
					SETBIT(PORTB,Copy_Pin);
					break;
				case DIO_PORTC:
					SETBIT(PORTC,Copy_Pin);
						break;
				case DIO_PORTD:
					SETBIT(PORTD,Copy_Pin);
					break;
				default:
					local_ErrorStatus=1;
					break;
			}
		}
		else if (Copy_Status == OUTPUT_LOW)
		{
			switch(Copy_Port)
			{
				case DIO_PORTA:
					CLEARBIT(PORTA,Copy_Pin);
					break;
				case DIO_PORTB:
					CLEARBIT(PORTB,Copy_Pin);
					break;
				case DIO_PORTC:
					CLEARBIT(PORTC,Copy_Pin);
						break;
				case DIO_PORTD:
					CLEARBIT(PORTD,Copy_Pin);
					break;
				default:
					local_ErrorStatus=1;
					break;
			}
		}

		else
		{
			local_ErrorStatus=1;
		}
	}
	return local_ErrorStatus;
}
