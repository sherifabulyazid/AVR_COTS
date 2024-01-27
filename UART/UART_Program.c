/*
 * UART_Program.c
 *
 *  Created on: Jan 5, 2024
 *      Author: hp
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "UART_Registers.h"
#include "UART_Interface.h"
#include "UART_Config.h"
#include "UART_Private.h"

void UART_Init(void)
{
	uint8 Local_UCSRCVal = 0;
	/*Receiver enable*/
#if  RXEN_MODE == ENABLED
	SETBIT(UCSRB,UCSRB_RXEN);
#elif  RXEN_MODE == DISABLED
	CLEARBIT(UCSRB,UCSRB_RXEN);
#else
	#error  Wrong RXEN_MODE configuration options
#endif

	/*Transmitter enable*/
#if  TXEN_MODE == ENABLED
	SETBIT(UCSRB,UCSRB_TXEN);
#elif  TXEN_MODE == DISABLED
	CLEARBIT(UCSRB,UCSRB_TXEN);
#else
	#error  Wrong TXEN_MODE configuration options
#endif


	/* UART MODE */
#if   UART_MODE == ASYCHRONOUS
	CLEARBIT(Local_UCSRCVal,UCSRC_UMSEL);
#endif

	/* Parity Mode */
#if PARITY_MODE == Disabled
	CLEARBIT(Local_UCSRCVal,UCSRC_UPM0);
	CLEARBIT(Local_UCSRCVal,UCSRC_UPM1);
#elif PARITY_MODE == EVEN_PARITY
	CLEARBIT(Local_UCSRCVal,UCSRC_UPM0);
	SETBIT(Local_UCSRCVal,UCSRC_UPM1);
#elif PARITY_MODE == ODD_PARITY
	SETBIT(Local_UCSRCVal,UCSRC_UPM0);
	SETBIT(Local_UCSRCVal,UCSRC_UPM1);
#else
	#error   Wrong PARITY_MODE configuration options
#endif

	/*STOP BIT Select*/
#if STOPBIT_MODE == ONE_BIT
	CLEARBIT(Local_UCSRCVal,UCSRC_USBS);
#elif STOPBIT_MODE == TWO_BIT
	SETBIT(Local_UCSRCVal,UCSRC_USBS);
#endif

	/*character size*/
#if CHAR_SIZE_MODE ==BITS_5
	CLEARBIT(Local_UCSRCVal,UCSRC_UCSZ0);
	CLEARBIT(Local_UCSRCVal,UCSRC_UCSZ1);
	CLEARBIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE_MODE ==BITS_6
	SETBIT(Local_UCSRCVal,UCSRC_UCSZ0);
	CLEARBIT(Local_UCSRCVal,UCSRC_UCSZ1);
	CLEARBIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE_MODE ==BITS_7
	CLEARBIT(Local_UCSRCVal,UCSRC_UCSZ0);
	SETBIT(Local_UCSRCVal,UCSRC_UCSZ1);
	CLEARBIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE_MODE ==BITS_8
	SETBIT(Local_UCSRCVal,UCSRC_UCSZ0);
	SETBIT(Local_UCSRCVal,UCSRC_UCSZ1);
	CLEARBIT(UCSRB,UCSRB_UCSZ2);
#elif CHAR_SIZE_MODE ==BITS_9
	SETBIT(Local_UCSRCVal,UCSRC_UCSZ0);
	SETBIT(Local_UCSRCVal,UCSRC_UCSZ1);
	SETBIT(UCSRB,UCSRB_UCSZ2);
#else
#error Wrong CHARACTER_SIZE_MODE configuration options
#endif

	/* Register select : UCSRC */
	SETBIT(Local_UCSRCVal,UCSRC_URSEL);
	UCSRC=Local_UCSRCVal;


	/*Transmission Speed*/
#if UART_SPEED == NORMAL_U2X
	CLEARBIT(UCSRA,UCSRA_U2X);
	UBRRL=51u;
#elif UART_SPEED == DOUBLE_U2X
	SETBIT(UCSRA,UCSRA_U2X);
	UBRRL=103u;
#endif
}

void UART_Transmit_data(uint8 copy_send_data)
{
	/* wait until transmit buffer is ready */
	while(!(GETBIT(UCSRA,UCSRA_UDRE)));
	UDR = copy_send_data;
}

uint8 UART_Receive_data(void)
{
	/*wait until there's data received in the receiver buffer */
	while(!(GETBIT(UCSRA,UCSRA_RXC)));
	return UDR;
}
