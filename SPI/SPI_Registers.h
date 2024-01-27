/*
 * SPI_Registers.h
 *
 *  Created on: Jan 6, 2024
 *      Author: hp
 */

#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

#define  SPDR   	*((volatile uint8*)0x2F)

#define SPSR    	*((volatile uint8*)0x2E)
#define SPSR_SPIF 	7
#define SPSR_WCOL 	6
#define SPSR_SPI2X 	0

#define  SPCR   	*((volatile uint8*)0x2D)
#define SPCR_SPIE 	7
#define SPCR_SPE	6
#define SPCR_DORD	5
#define SPCR_MSTR	4
#define SPCR_CPOL	3
#define SPCR_CPHA	2
#define SPCR_SPR1	1
#define SPCR_SPR0	0

#define SREG (*(volatile uint8*)0x5f)   //status register
#define GIE 7  //GIE is the 7th bit in SREG

#endif /* SPI_REGISTERS_H_ */
