/*
 * EEPROM_Interface.h
 *
 *  Created on: Jan 23, 2024
 *      Author: Sherif
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(uint16 Copy_uint16LocationAddress, uint8 Copy_uint8DataByte);

uint8 EEPROM_uint8ReadDataByte(uint16 Copy_uint16LocationAddress);

/*

void EEPROM_voidSendDataByte(uint8 Copy_uint8LocationAddress, uint8 Copy_uint8DataByte);

uint8 EEPROM_uint8ReadDataByte(uint8 Copy_uint8LocationAddress);

*/
#endif /* EEPROM_INTERFACE_H_ */
