/*
 * main.c
 *
 *  Created on: Jan 27, 2024
 *      Author: Sherif Abuelyazid
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "Timer_interface.h"
#include "RTOS_Interface.h"

void Fn1_toggle(void);
void Fn2_toggle(void);
void Fn3_toggle(void);


int main (void)
{
	DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
	RTOS_CreateTask(0,1000,1000,Fn1_toggle);
	RTOS_CreateTask(1,2000,2000,Fn2_toggle);
	RTOS_CreateTask(2,4000,4000,Fn3_toggle);

	RTOS_Start();
while(1)
{

}
	return 0;
}

void Fn1_toggle(void)
{
	DIO_Toggle_PIN(DIO_PORTA,PIN0);
}
void Fn2_toggle(void)
{
	DIO_Toggle_PIN(DIO_PORTA,PIN1);
}
void Fn3_toggle(void)
{
	DIO_Toggle_PIN(DIO_PORTA,PIN2);

}

