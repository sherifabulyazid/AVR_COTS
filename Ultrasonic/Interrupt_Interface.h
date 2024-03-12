/*
 * Interrupt_Interface.h
 *
 *  Created on: Dec 20, 2023
 *      Author: hp
 */

#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_

#include "STD.h"


void INT_Set_GIE (void);
void INT_Clear_GIE (void);
void EXINT_Sense_Level(uint8 copy_INTx);
void EXINT_PIE(uint8 copy_INTx);
void ISR_CallBack(void (*copy_INT_ptr)(void));


//void __vector_1(void)__attribute__((signal));

#define ISR(VectNum) void VectNum(void)__attribute__((signal));\
					void VectNum(void)
#define VECT_INT0 __vector_1
#define VECT_INT1 __vector_2
#define INT0 0
#define INT1 1
#define INT2 2


#define VECT_INT0 __vector_1
#define VECT_INT1 __vector_2
#define VECT_INT2 __vector_3

#endif /* INTERRUPT_INTERFACE_H_ */
