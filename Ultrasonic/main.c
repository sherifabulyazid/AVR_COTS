/*
 * main.c
 *
 *  Created on: Dec 20, 2023
 *      Author: Sherif
 */

#include "Interrupt_Interface.h"
#include "DIO_Interface.h"
#include "STD.h"
#include "Timer_interface.h"
#include "Timer_registers.h"
#include "LCD_Interface.h"
uint32 overflowCounter=0;
uint16 distance=0;
/*normal mode timer 1*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	overflowCounter++;
}
/*Interrupt*/
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	static uint8 flag=0;
	if (flag==0)
	{
		overflowCounter=0;
		TCNT0=0;
		Timer0_Normal();
		flag=1;
	}
	else if(flag==1)
	{
		uint8 timerTicks=TCNT0;
		float32 totalTime= (timerTicks+overflowCounter*256)*0.064;//in ms
		distance=totalTime*17;
		flag=0;
	}
}

int main (void)
{
	DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
	DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);

	LCD_init();
	INT_Set_GIE ();
	EXINT_Sense_Level(0);
	EXINT_PIE(0);
	setPinDirection(DIO_PORTD,PIN1,OUTPUT);
	while(1)
	{
		setPinVAlue(DIO_PORTD,PIN1,OUTPUT_HIGH);
		_delay_us(10);
		setPinVAlue(DIO_PORTD,PIN1,OUTPUT_LOW);
		LCD_ClearDisplay();
		LCD_SendString("Distance=");
		//LCD_GoToXY(1,0);
		LCD_uint8_WriteNumber(distance);
		_delay_ms(1000);
		//LCD_GoToXY(0,0);

	}




	return 0;
}


