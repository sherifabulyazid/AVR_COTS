/*
 * main.c
 *
 *  Created on: Dec 16, 2023
 *      Author: Sherif
 */
#include <util/delay.h>
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
		LCD_init();//initializing LCD
		DIO_SetPortDirection(KEYPAD_PORT, KEYPAD_Direction);
		DIO_SetPortValue(KEYPAD_PORT,KEYPAD_Value);
		setPinDirection(DIO_PORTD,PIN6,OUTPUT);
		setPinDirection(DIO_PORTD,PIN7,OUTPUT);

		LCD_GoToXY(FirstLine,0);
		LCD_SendString("Welcome to Smart Keypad");
		_delay_ms(1000);
		LCD_ClearDisplay();
		LCD_SendString("Enter option");
		_delay_ms(1000);
		LCD_ClearDisplay();
		LCD_SendString("1- Lights ON");
		_delay_ms(1000);
		LCD_ClearDisplay();
		LCD_SendString("2- Lights OFF");
		_delay_ms(1000);
		LCD_ClearDisplay();
		LCD_SendString("3- Fan ON");
		_delay_ms(1000);
		LCD_ClearDisplay();
		LCD_SendString("4- Fan OFF");
		_delay_ms(1000);
		LCD_ClearDisplay();
		_delay_ms(1000);

		while(1)
		{

			do
			{
				val = get_button_pressed();
			}while(val == 0xff);
			if(val=='1')
			{
				setPinVAlue(DIO_PORTD,PIN6,OUTPUT_HIGH);
			}
			else if(val=='2')
			{
				setPinVAlue(DIO_PORTD,PIN6,OUTPUT_LOW);
			}
			else if(val=='3')
			{
				setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
			}
			else if(val=='4')
			{
				setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
			}
		}

	return 0;
}
