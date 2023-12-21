/*
 * Interrupt_program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: hp
 */
#include "Interrupt_Register.h"
#include "Interrupt_Interface.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "BIT_MATH.h"
#include "STD.h"


void INT_Set_GIE (void)
{
	SETBIT(SREG,GIE);
}
void INT_Clear_GIE (void)
{
	CLEARBIT(SREG,GIE);
}
void INT_Sense_Level(uint8 copy_INTx)
{
	switch(copy_INTx)
	{
	case INT0:
		CLEARBIT(MCUCR,0); // LOW level on INT0 triggers interrupt
		CLEARBIT(MCUCR,1);
		break;
	case INT1:
		CLEARBIT(MCUCR,2); // LOW level on INT1 triggers interrupt
		CLEARBIT(MCUCR,3);
		break;
	case INT2:
		CLEARBIT(MCUCSR,6); // Falling edge on INT2 triggers interrupt
		break;
	default:
		break;
	}
}

void INT_PIE(uint8 copy_INTx)
{	//Peripheral Interrupt Enable
	switch(copy_INTx)
	{
	case INT0:
		SETBIT(GICR,6); // Enable INT0
		break;
	case INT1:
		SETBIT(GICR,7); // Enable INT1
		break;
	case INT2:
		SETBIT(GICR,5); // Enable INT2
		break;
	default:
		break;
	}
}
