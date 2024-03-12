/*
 *  Interrupt_program.c
 *
 *  Created on: Dec 20, 2023
 *      Author: hp
 */
#include "Interrupt_Register.h"
#include "Interrupt_Interface.h"
#include "Interrupt_config.h"
#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "BIT_MATH.h"
#include "STD.h"

void (*Global_ptr_INT0)(void)=NULL;//global pointer to store the address of ISR function in App layer
void (*Global_ptr_INT1)(void)=NULL;//global pointer to store the address of ISR function in App layer

void ISR_CallBack_INT0( void (*copy_INT_ptr)(void) )
{
	if(copy_INT_ptr != NULL)
		Global_ptr_INT0=copy_INT_ptr;
}
/*
ISR(VECT_INT0)
{
	if(Global_ptr_INT0 !=NULL)
		Global_ptr_INT0();
}*/
void ISR_CallBack_INT1( void (*copy_INT_ptr)(void) )
{
	if(copy_INT_ptr != NULL)
		Global_ptr_INT1=copy_INT_ptr;
}
ISR(VECT_INT1)
{
	if(Global_ptr_INT1 !=NULL)
		Global_ptr_INT1();
}


void INT_Set_GIE (void)
{
	SETBIT(SREG,GIE);
}
void INT_Clear_GIE (void)
{
	CLEARBIT(SREG,GIE);
}
void EXINT_Sense_Level(uint8 copy_INTx)
{
	switch(copy_INTx)
	{
	case INT0:
#if EXTI_INT0_SENSE_CONTROL == LOW_LEVEL
		CLEARBIT(MCUCR,ISC00); // LOW level on INT0 triggers interrupt
		CLEARBIT(MCUCR,ISC01);
#elif EXTI_INT0_SENSE_CONTROL == ON_CHANGE
		SETBIT(MCUCR,ISC00); // ON_CHANGE on INT0 triggers interrupt
		CLEARBIT(MCUCR,ISC01);
#elif EXTI_INT0_SENSE_CONTROL == FALLING_EDGE
		CLEARBIT(MCUCR,ISC00); // FALLING_EDGE on INT0 triggers interrupt
		SETBIT(MCUCR,ISC01);
#elif EXTI_INT0_SENSE_CONTROL == RISING_EDGE
		SETBIT(MCUCR,ISC00); // RISING_EDGE on INT0 triggers interrupt
		SETBIT(MCUCR,ISC01);
#endif
		break;
	case INT1:
#if EXTI_INT1_SENSE_CONTROL == LOW_LEVEL
		CLEARBIT(MCUCR,ISC10); // LOW level on INT1 triggers interrupt
		CLEARBIT(MCUCR,ISC11);
#elif EXTI_INT1_SENSE_CONTROL == ON_CHANGE
		SETBIT(MCUCR,ISC10); // ON_CHANGE on INT0 triggers interrupt
		CLEARBIT(MCUCR,ISC11);
#elif EXTI_INT1_SENSE_CONTROL == FALLING_EDGE
		CLEARBIT(MCUCR,ISC10); // FALLING_EDGE on INT0 triggers interrupt
		SETBIT(MCUCR,ISC11);
#elif EXTI_INT1_SENSE_CONTROL == RISING_EDGE
		SETBIT(MCUCR,ISC10); // RISING_EDGE on INT0 triggers interrupt
		SETBIT(MCUCR,ISC11);
#endif
		break;
	case INT2:
#if EXTI_INT2_SENSE_CONTROL == FALLING_EDGE
		CLEARBIT(MCUCSR,ISC2); // Falling edge on INT2 triggers interrupt
#elif EXTI_INT2_SENSE_CONTROL == RISING_EDGE
		SETBIT(MCUCSR,ISC2); // Rising edge on INT2 triggers interrupt
#endif
		break;
	default:
		break;
	}
}

void EXINT_PIE(uint8 copy_INTx)
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
