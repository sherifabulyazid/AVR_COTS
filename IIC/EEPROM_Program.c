/*
 * EEPROM_Program.c
 *
 *  Created on: Jan 23, 2024
 *      Author: hp
 */
#include <util/delay.h>
#include "STD.h"
#include "BIT_MATH.h"
#include "IIC_Interface.h"
#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"
/*
void EEPROM_voidSendDataByte(uint8 Copy_uint8LocationAddress, uint8 Copy_uint8DataByte)
{
	uint8 Local_uint8AddressPacket;
	Local_uint8AddressPacket= EEPROM_FIXED_ADDRESS|A2_CONNECTION<<2|A1_CONNECTION<<1|A0_CONNECTION;

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(Local_uint8AddressPacket);
	TWI_MasterWriteDataByte(Copy_uint8LocationAddress);
	TWI_MasterWriteDataByte(Copy_uint8DataByte);
	TWI_SendStopCondition();
	_delay_ms(10);
}


uint8 EEPROM_uint8ReadDataByte(uint8 Copy_uint8LocationAddress)
{
	uint8 Local_uint8AddressPacket;
	uint8 Local_uint8Data;
	Local_uint8AddressPacket= EEPROM_FIXED_ADDRESS|A2_CONNECTION<<2|A1_CONNECTION<<1|A0_CONNECTION;

	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(Local_uint8AddressPacket);
	TWI_MasterWriteDataByte(Copy_uint8LocationAddress);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(Local_uint8AddressPacket);
	TWI_MasterReadDataByte(&Local_uint8Data);
	TWI_SendStopCondition();

	return Local_uint8Data;
}
*/

void EEPROM_voidSendDataByte(uint16 Copy_uint16LocationAddress, uint8 Copy_uint8DataByte)
{
	uint8 Local_uint8AddressPacket;
/*
 *
	Local_uint8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8)(Copy_uint16LocationAddress >>8);
*/
	/*2k EEPROM*/
	Local_uint8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;


	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet*/
	TWI_SendSlaveAddressWithWrite(Local_uint8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((uint8)Copy_uint16LocationAddress);

	/*Send the data byte to the memory location*/
	TWI_MasterWriteDataByte(Copy_uint8DataByte);

	/*Send stop condition*/
	TWI_SendStopCondition();

	/*Delay until the write cycle is finished*/
	_delay_ms(10);
}

uint8 EEPROM_uint8ReadDataByte(uint16 Copy_uint16LocationAddress)
{
	uint8 Local_uint8AddressPacket, Local_uint8Data;
/*
	Local_uint8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION <<2) | (uint8)(Copy_uint16LocationAddress >>8);
*/
	/*2k EEPROM*/
	  	Local_uint8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;


	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet with write request*/
	TWI_SendSlaveAddressWithWrite(Local_uint8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((uint8)Copy_uint16LocationAddress);

	/*Send repeated start to change write request into read request*/
	TWI_SendRepeatedStart();

	/*Send the address packet with read request*/
	TWI_SendSlaveAddressWithRead(Local_uint8AddressPacket);

	/*Get the data from memory*/
	TWI_MasterReadDataByte(&Local_uint8Data);

	/*send the stop condition*/
	TWI_SendStopCondition();

	return Local_uint8Data;
}
