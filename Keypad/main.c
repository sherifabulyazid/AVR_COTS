/*
 * main.c
 *
 *  Created on: Dec 16, 2023
 *      Author: Sherif
 */


#include "BIT_MATH.h"
#include "Keypad_Interface.h"
#include "DIO_Interface.h"
#include "Keypad_config.h"
#include "DIO_Register.h"
#include "LCD_Interface.h"
#include "STD.h"

uint8 val = 0xff;
int main (void)
{
		DIO_SetPortDirection(DIO_PORTA, PORT_OUTPUT); //for LCD data pins
		DIO_SetPortDirection(DIO_PORTB, PORT_OUTPUT); //for RS,RW,EN
		LCD_init();
		_delay_ms(25);
		//LCD_Write_data('M');
		DIO_SetPortDirection(KEYPAD_PORT, KEYPAD_Direction);
		DIO_SetPortValue(KEYPAD_PORT,KEYPAD_Value);

		while(1)
		{
			do
			{
				val = get_button_pressed();
			}while(val == 0xff);
			LCD_Write_data(val);

		}
	return 0;
}
