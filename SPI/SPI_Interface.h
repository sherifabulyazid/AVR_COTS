/*
 * SPI_Interface.h
 *
 *  Created on: Jan 6, 2024
 *      Author: hp
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_SlaveInit(void);
void SPI_MasterInit(void);
uint8 SPI_Transmit_Receive(uint8 copy_Data);

void SPI_EN_Interrupt(void);
#endif /* SPI_INTERFACE_H_ */
