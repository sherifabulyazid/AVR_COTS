/*
 * main.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Sherif
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "SPI_Interface.h"
#include "DIO_Interface.h"
#include "SPI_Registers.h"

int main(void)
{
	setPinDirection(DIO_PORTB,PIN4,INPUT);//<<<<SS
	setPinDirection(DIO_PORTB,PIN5,INPUT);//<<<<MOSI
	setPinDirection(DIO_PORTB,PIN6,OUTPUT);//<<<<<MISO
	setPinDirection(DIO_PORTB,PIN7,INPUT);//<<<<<SCK
	setPinDirection(DIO_PORTD,PIN7,OUTPUT);//LED

 	uint8 Val_Sample=0;
	SPI_SlaveInit();

	while(1)
	{
		Val_Sample= SPI_Transmit_Receive(255);
		if(Val_Sample=='C')
		{
			setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);//LED
		}
	}
}

/*
uint8 arr[3]={5,6,7};
int main(void)
{
	setPinDirection(DIO_PORTB,PIN4,INPUT);//<<<<SS
	setPinDirection(DIO_PORTB,PIN5,INPUT);//<<<<MOSI
	setPinDirection(DIO_PORTB,PIN6,OUTPUT);//<<<<<MISO
	setPinDirection(DIO_PORTB,PIN7,INPUT);//<<<<<SCK
	setPinDirection(DIO_PORTD,PIN7,OUTPUT);//LED


	SPI_SlaveInit();
	SPI_EN_Interrupt();
	while(1)
	{

	}
	return 0;
}
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	uint8 i =SPDR;
	if(i==1)
	SPDR=arr[0];
	else if(i==2)
	SPDR=arr[1];
	else if(i==3)
	SPDR=arr[2];
}
*/
