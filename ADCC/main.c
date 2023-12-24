#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"

#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "LCD_Interface.h"
#include <util/delay.h>


int main (void)
{
	DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
	DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
	setPinDirection(DIO_PORTA,PIN5,OUTPUT);
	setPinDirection(DIO_PORTA,PIN6,OUTPUT);
	setPinDirection(DIO_PORTA,PIN7,OUTPUT);
	ADC_init();
	LCD_init();
	uint8 valueADC=0;
	uint32 analogue=0;
	uint8 temprature=0;
	while(1)
	{
		valueADC= ADC_StartConversion(ADC1);
		_delay_ms(10);
		DIO_SetPortValue(DIO_PORTD,valueADC);
		analogue=(uint32)valueADC*5000UL/256UL; //in mV
		temprature=analogue/10;
		LCD_SendString("Temp=");
		_delay_ms(100);
		LCD_GoToXY(FirstLine, 6);
		LCD_uint8_WriteNumber(temprature);
		_delay_ms(1000);
		LCD_ClearDisplay();
		_delay_ms(250);
	}

	return 0;
}


