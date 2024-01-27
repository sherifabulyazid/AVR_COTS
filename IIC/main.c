/*
 * main.c
 *
 *  Created on: Jan 24, 2024
 *      Author: hp
 */
#include <util/delay.h>
#include "STD.h"
#include "EEPROM_Interface.h"
#include "IIC_Interface.h"
#include "DIO_Interface.h"

int main (void)
{
	uint8 Local_uint8ReceivedData;
	DIO_SetPortDirection(DIO_PORTD,OUTPUT);
	//setPinDirection(DIO_PORTC,PIN0,OUTPUT);
	TWI_InitMaster(0);
	EEPROM_voidSendDataByte(10, 0x00);
	Local_uint8ReceivedData = EEPROM_uint8ReadDataByte(10);
	DIO_SetPortValue(DIO_PORTD , Local_uint8ReceivedData);
	_delay_ms(1000);
	while(1)
	{

	}
	return 0;
}
