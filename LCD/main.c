
/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *  Author: Sherif Abuelyazid
 */

#include "STD.h"
#include "BIT_MATH.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Register.h"
#include "LCD_Interface.h"

int main(void)
{
	DIO_SetPortDirection(DIO_PORTA, PORT_OUTPUT); //for LCD data pins
	DIO_SetPortDirection(DIO_PORTB, PORT_OUTPUT); //for RS,RW,EN
	LCD_init();
	_delay_ms(100);
	while(1)
	{
		LCD_Write_data('H');
		_delay_ms(150);
		LCD_Write_data('E');
		_delay_ms(150);
		LCD_Write_data('L');
		_delay_ms(150);
		LCD_Write_data('L');
		_delay_ms(150);
		LCD_Write_data('O');
		_delay_ms(150);
		LCD_Write_data(' ');
		_delay_ms(150);
		LCD_Write_data('W');
		_delay_ms(150);
		LCD_Write_data('O');
		_delay_ms(150);
		LCD_Write_data('R');
		_delay_ms(150);
		LCD_Write_data('L');
		_delay_ms(150);
		LCD_Write_data('D');
		_delay_ms(150);
		LCD_cmd(0xc0);
		LCD_Write_data('Y');
		_delay_ms(150);
		LCD_Write_data('O');
		_delay_ms(150);
		LCD_Write_data('U');
		_delay_ms(150);
		LCD_Write_data('R');
		_delay_ms(150);
		LCD_Write_data('S');
		_delay_ms(150);
		LCD_Write_data(',');
		_delay_ms(150);
		LCD_Write_data('S');
		_delay_ms(150);
		LCD_Write_data('H');
		_delay_ms(150);
		LCD_Write_data('E');
		_delay_ms(150);
		LCD_Write_data('R');
		_delay_ms(150);
		LCD_Write_data('I');
		_delay_ms(150);
		LCD_Write_data('F');
		_delay_ms(150);
		//LCD_cmd(0x0e);//Display on
		_delay_ms(500);
		LCD_cmd(0x01);//Clear LCD display screen
		_delay_ms(300);
	}
	return 0;
}
