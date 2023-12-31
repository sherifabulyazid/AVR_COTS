/*
 * Timer0_registers.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Sherif Abuelyazid
 */

#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

#define SREG (*(volatile uint8*)0x5f)   //status register
#define GIE 7  //GIE is the 7th bit in SREG
/******************************************TIMER0****************************************************/

/*Timer/Counter Control Register*/
#define TCCR0   *((volatile uint8*)0x53)
#define TCCR0_FOC0			7
#define TCCR0_WGM00			6
#define TCCR0_COM01			5
#define TCCR0_COM00			4
#define TCCR0_WGM01			3
#define TCCR0_CS02			2
#define TCCR0_CS01			1
#define TCCR0_CS00			0

/*timer/counter register*/
#define TCNT0	*((volatile uint8*)0x52)

/*Output Compare Register*/
#define OCR0 	*((volatile uint8*)0x5C)

/*Timer/Counter Interrupt Mask Register*/
#define TIMSK	*((volatile uint8*)0x59)
#define TIMSK_OCIE0			1
#define TIMSK_TOIE0			0

/*Timer/Counter Interrupt Flag Register*/
#define TIFR *((volatile uint8*)0x58)
#define TIFR_TOV0 	0	//OverFlow flag
#define TIFR_OCF0 	1	//Output Compare Flag

/******************************************TIMER1****************************************************/
#define TCCR1A 	 *((volatile uint8*)0x4f)
#define TCCR1B	 *((volatile uint8*)0x4E)
#define TCNT1L   *((volatile uint16*)0x4C)
#define ICR1L   *((volatile uint16*)0x46)
#define OCR1AL   *((volatile uint16*)0x4A)
#define OCR1BL   *((volatile uint16*)0x48)
#endif /* TIMER_REGISTERS_H_*/
