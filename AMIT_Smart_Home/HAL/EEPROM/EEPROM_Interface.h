/*
 * Author   : Ahmed Mohamed Aboud
 * Linkedin :https://www.linkedin.com/in/ahmed-mohamed-aboud-33b2471b1/
 * File Name: EEPROM_Interface.h
 * Date: 12 Feb 2024
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#define EEPROM_MAX_ADDRESS	0x03FF


void EEPROM_voidSendDataByte(uint16 Copy_uint16LocationAddress, uint8 Copy_uint8DataByte);
uint8 EEPROM_uint8ReadDataByte(uint16 Copy_uint16LocationAddress);
void EEPROM_voidSend4Numbers(uint16 Copy_uint16LocationAddress, uint8* Array_Recieve_Str, uint8 cop_EEPROM_maxNum);
void EEPROM_voidRead4Numbers(uint16 Copy_uint16LocationAddress, uint8* Array_Recieve_Str, uint8 cop_EEPROM_maxNum);
void EEPROM_voidRemoveUser(uint16 Copy_uint16LocationAddress);
void EEPROM_voidSendString(uint16 Copy_uint16LocationAddress, uint8* str);
void EEPROM_INIT(void);

#endif /* EEPROM_INTERFACE_H_ */
