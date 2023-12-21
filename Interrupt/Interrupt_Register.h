/*
 * Interrupt_Register.h
 *
 *  Created on: Dec 20, 2023
 *      Author: Sherif
 */

#ifndef INTERRUPT_REGISTER_H_
#define INTERRUPT_REGISTER_H_

#define SREG (*(volatile uint8*)0x5f)   //status register
#define MCUCR (*(volatile uint8*)0x55)  //MCU control register
#define MCUCSR (*(volatile uint8*)0x54) //MCU control and status register
#define GICR (*(volatile uint8*)0x5b)   //Global interrupt control register


#endif /* INTERRUPT_REGISTER_H_ */
