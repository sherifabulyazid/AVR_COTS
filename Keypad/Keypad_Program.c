/*
 * Keypad_Program.c
 *
 *  Created on: Dec 16, 2023
 *      Author: hp
 */

#include "BIT_MATH.h"
#include "Keypad_Interface.h"
#include "DIO_Interface.h"
#include "Keypad_config.h"
#include "DIO_Register.h"
#include "LCD_Interface.h"
#include "STD.h"

uint8 get_button_pressed(void)
{
	uint8 row=0,column=0;
	uint8 buttonStatus=0xff;
	uint8 buttonPressed = 0xff;
	uint8 buttonArray[ROW_NUM][COL_NUM]={{'7','8','9','/'},
										 {'4','5','6','*'},
										 {'1','2','3','-'},
										 {'%','0','=','+'}};

	for(column=4;column<8;column++)
	{
		setPinVAlue(KEYPAD_PORT,column,OUTPUT_LOW);
		for(row=0;row<4;row++)
		{
			DIO_GetPinValue(KEYPAD_PORT,row,&buttonStatus);
			if(buttonStatus==LOW)
			{
				while(buttonStatus==LOW)
				{
					DIO_GetPinValue(KEYPAD_PORT,row,&buttonStatus);
				}
				setPinVAlue(KEYPAD_PORT,column,OUTPUT_HIGH);
				buttonPressed= buttonArray[row][column];
				return buttonPressed;
			}
		}
		setPinVAlue(KEYPAD_PORT,column,OUTPUT_HIGH);
	}

	return buttonPressed;
}

