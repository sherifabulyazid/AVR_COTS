/*
 * UART_Interface.h
 *
 *  Created on: Jan 5, 2024
 *      Author: hp
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(void);
void UART_Transmit_data(uint8 copy_send_data);
uint8 UART_Receive_data(void);

#endif /* UART_INTERFACE_H_ */
