/*
 * UART_Config.h
 *
 *  Created on: Jan 5, 2024
 *      Author: hp
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define  DISABLED 1
#define  ENABLED  2
/*Receiver mode  */
#define RXEN_MODE ENABLED
/*Transmitter mode  */
#define TXEN_MODE DISABLED

/* UART MODE */
#define   ASYCHRONOUS 	1
#define	  SYCHRONOUS  	2
#define   UART_MODE     ASYCHRONOUS

/*Parity Mode */
#define Disabled       1
#define EVEN_PARITY    2
#define ODD_PARITY     3
#define PARITY_MODE    Disabled

/*Stop Bit Select*/
#define ONE_BIT 		1
#define TWO_BIT 		2
#define STOPBIT_MODE	ONE_BIT

/*character size*/
#define BITS_5  	1
#define BITS_6  	2
#define BITS_7  	3
#define BITS_8  	4
#define BITS_9  	5

#define CHAR_SIZE_MODE 	BITS_8

/*UART Speed*/
#define NORMAL_U2X 		1
#define DOUBLE_U2X 		2
#define UART_SPEED 	 NORMAL_U2X


#endif /* UART_CONFIG_H_ */
