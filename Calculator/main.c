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
		uint32 Num1=0;
		uint32 Num2=0;
		uint32 Result=0;
		uint8 op=0;
		while(1)
		{
			do
			{
				val = get_button_pressed();
			}while(val == 0xff);
			if(val=='C')
			{
				LCD_cmd(01);
				Num1=0;
				Num2=0;
				op=0;
			}
			else
			{
				LCD_Write_data(val);
				if(val!='+'&&val!='-'&&val!='/'&&val!='*'&&val!='=')
					{
						Num1=(val-48)+Num1*10;
					}
				if(val=='+'||val=='-'||val=='/'||val=='*')
				{
					Num2=Num1;
					Num1=0;
					op=val;
				}
				if(val=='=')
				{
					if(op=='+')
					Result=Num1+Num2;
					else if (op=='-')
					Result=Num2-Num1;
					else if (op=='*')
					Result=Num2*Num1;
					else if (op=='/')
					Result=Num2/Num1;
					else
					Result='E'-48;//Error

					if(Result<10)
					{
						LCD_Write_data(Result+48);

					}
					else if(Result<100)
					{
						LCD_Write_data(Result/10+48);
						LCD_Write_data(Result%10+48);
					}
					else if(Result<1000) //864
					{
						LCD_Write_data(Result/100+48);
						LCD_Write_data((Result%100)/10+48);
						LCD_Write_data(Result%10+48);
					}
					else
					{
						LCD_Write_data('E');//Error
					}


				}
			}

		}

	return 0;
}
