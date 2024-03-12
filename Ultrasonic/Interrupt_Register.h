/*
 * Interrupt_Register.h
 *
 *  Created on: Dec 20, 2023
 *      Author: Sherif
 */

#ifndef INTERRUPT_REGISTER_H_
#define INTERRUPT_REGISTER_H_

#define SREG (*(volatile uint8*)0x5f)   //status register
#define GIE 7  //GIE is the 7th bit in SREG
#define MCUCR (*(volatile uint8*)0x55)  //MCU control register
#define ISC00 0 //External Interrupt 0 sense control --> bit 0 , 1
#define ISC01 1
#define ISC10 2 //External Interrupt 1 sense control  --> bit 2 , 3
#define ISC11 3

#define MCUCSR (*(volatile uint8*)0x54) //MCU control and status register
#define ISC2 6 // External Interrupt 2 sense control  --> bit 6
#define GICR (*(volatile uint8*)0x5b)   //Global interrupt control register



#endif /* INTERRUPT_REGISTER_H_ */
