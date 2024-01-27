/*
 * main.c
 *
 *  Created on: Jan 6, 2024
 *      Author: hp
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"
#include <util/delay.h>

int main(void)
{
	setPinDirection(DIO_PORTB,PIN4,OUTPUT);//<<<<SS
	setPinDirection(DIO_PORTB,PIN5,OUTPUT);//<<<<MOSI
	setPinDirection(DIO_PORTB,PIN6,INPUT);//<<<<<MISO
	setPinDirection(DIO_PORTB,PIN7,OUTPUT);//<<<<<SCK
	setPinVAlue(DIO_PORTB,PIN4,OUTPUT_HIGH);//<<<< MASTER
	setPinDirection(DIO_PORTD,PIN4,OUTPUT); // Slave Select: ActiveLOW

	SPI_MasterInit();
	setPinVAlue(DIO_PORTD,PIN4,OUTPUT_LOW);//enabled the slave controller
	_delay_us(2);
	while(1)
	{
		SPI_Transmit_Receive('C');
	}
	return 0;
}

/*
int main(void)
{
	setPinDirection(DIO_PORTB,PIN4,OUTPUT);//<<<<SS
	setPinDirection(DIO_PORTB,PIN5,OUTPUT);//<<<<MOSI
	setPinDirection(DIO_PORTB,PIN6,INPUT);//<<<<<MISO
	setPinDirection(DIO_PORTB,PIN7,OUTPUT);//<<<<<SCK
	setPinVAlue(DIO_PORTB,PIN4,OUTPUT_HIGH);//<<<< MASTER
	setPinDirection(DIO_PORTD,PIN4,OUTPUT); // Slave Select: ActiveLOW
	uint8 sensor_val[3]={0,0,0};
	uint8 recycle_pin=0;
	SPI_MasterInit();
	while(1)
	{
		setPinVAlue(DIO_PORTD,PIN4,OUTPUT_LOW);//enabled the slave controller
		_delay_us(2);
		recycle_pin= SPI_Transmit_Receive(1);
		_delay_us(20);
		sensor_val[0]=SPI_Transmit_Receive(2);
		_delay_us(20);
		sensor_val[1]=SPI_Transmit_Receive(3);
		_delay_us(20);
		sensor_val[2]=SPI_Transmit_Receive(255);
		_delay_us(20);
		setPinVAlue(DIO_PORTD,PIN4,OUTPUT_HIGH);//disabled the slave controller
		DIO_SetPortValue(DIO_PORTA,sensor_val[0]);
		_delay_ms(100);
		DIO_SetPortValue(DIO_PORTA,sensor_val[1]);
		_delay_ms(100);
		DIO_SetPortValue(DIO_PORTA,sensor_val[2]);
		_delay_ms(100);
	}

	return 0;
}
*/
