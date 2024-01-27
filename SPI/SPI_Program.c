/*
 * SPI_Program.c
 *
 *  Created on: Jan 6, 2024
 *      Author: hp
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "SPI_Registers.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"



void SPI_MasterInit(void)
{
	/*Data Order*/
	CLEARBIT(SPCR,SPCR_DORD);
	/*Master/Slave Select*/
	SETBIT(SPCR,SPCR_MSTR); //<<<<<<<<<<<
	/*Clock Polarity*/
	CLEARBIT(SPCR,SPCR_CPOL);
	/*Clock Phase*/
	CLEARBIT(SPCR,SPCR_CPHA);
	/*Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0*/
	/* 0 1 1 fosc/4 */
	CLEARBIT(SPCR,SPCR_SPR0);
	CLEARBIT(SPCR,SPCR_SPR1);
	CLEARBIT(SPSR,SPSR_SPI2X);
	/*SPI Enable*/
	SETBIT(SPCR, SPCR_SPE);
}

uint8 SPI_Transmit_Receive(uint8 copy_Data)
{
	SPDR = copy_Data;
	while((GETBIT(SPSR,SPSR_SPIF))==0);
	return SPDR;
}

void SPI_SlaveInit(void)
{

	/*Data Order*/
	CLEARBIT(SPCR,SPCR_DORD);
	/*Master/Slave Select*/
	CLEARBIT(SPCR,SPCR_MSTR); //<<<<<<<<<<<
	/*Clock Polarity*/
	CLEARBIT(SPCR,SPCR_CPOL);
	/*Clock Phase*/
	CLEARBIT(SPCR,SPCR_CPHA);
	/*Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0*/
	/* 0 1 1 fosc/4 */
	CLEARBIT(SPCR,SPCR_SPR0);
	CLEARBIT(SPCR,SPCR_SPR1);
	CLEARBIT(SPSR,SPSR_SPI2X);
	/*SPI Enable*/
	SETBIT(SPCR, SPCR_SPE);
}
void SPI_EN_Interrupt(void)
{
	/*enable external interrupt*/
	SETBIT(SREG,GIE);
	/*enable spi interrupt*/
	SETBIT(SPCR,SPCR_SPIE);
}

