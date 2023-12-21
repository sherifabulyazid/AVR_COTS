
/*
 * main.c
 *
 *  Created on: Dec 8, 2023
 *  Author: Sherif Abuelyazid
 */

#include "STD.h"
#include "BIT_MATH.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Register.h"

int main(void)
{
	/*
    Code to turn on 3 LEDs if pushbutton is pressed
	setPinDirection(DIO_PORTD,PIN3,OUTPUT);
	setPinDirection(DIO_PORTC,PIN2,OUTPUT);
	setPinDirection(DIO_PORTC,PIN7,OUTPUT);
	uint8 pinStatus=2;
	setPinDirection(DIO_PORTD,PIN2,INPUT);

	 while(1)
	 {

		 DIO_GetPinValue(DIO_PORTD,PIN2,&pinStatus);
		 _delay_ms(50);

		 if(pinStatus==1)
		 {
			setPinVAlue(DIO_PORTD,PIN3,OUTPUT_HIGH);
			setPinVAlue(DIO_PORTC,PIN2,OUTPUT_HIGH);
			setPinVAlue(DIO_PORTC,PIN7,OUTPUT_HIGH);
		 }
		 else if (pinStatus==0)
		 {
				setPinVAlue(DIO_PORTD,PIN3,OUTPUT_LOW);
				setPinVAlue(DIO_PORTC,PIN2,OUTPUT_LOW);
				setPinVAlue(DIO_PORTC,PIN7,OUTPUT_LOW);

		 }
		 else
		 {

		 }


	 }

*/

	setPinDirection(DIO_PORTB, PIN0, INPUT); // button 0
	setPinDirection(DIO_PORTD, PIN6, INPUT); // button 1
	setPinDirection(DIO_PORTD, PIN2, INPUT); // button 2

	setPinDirection(DIO_PORTC,PIN2,OUTPUT); // LED 0
	setPinDirection(DIO_PORTC,PIN7,OUTPUT); // LED 1
	setPinDirection(DIO_PORTD,PIN3,OUTPUT); // LED 2
	setPinDirection(DIO_PORTA,PIN3,OUTPUT); // BUZZER

	uint8 Button1_Value=0;
	uint8 Button2_Value=0;
	uint8 Button3_Value=0;
	uint8 i=0;

	while(1)
	{
		DIO_GetPinValue(DIO_PORTB, PIN0, &Button1_Value);
		_delay_ms(50);
		DIO_GetPinValue(DIO_PORTD, PIN6, &Button2_Value);
		_delay_ms(50);
		DIO_GetPinValue(DIO_PORTD, PIN2, &Button3_Value);
		_delay_ms(50);
		if (1 == Button1_Value)
		{
			setPinVAlue(DIO_PORTC,PIN2,OUTPUT_HIGH);
			setPinVAlue(DIO_PORTA,PIN3,OUTPUT_HIGH);
			_delay_ms(1000);
			setPinVAlue(DIO_PORTC,PIN2,OUTPUT_LOW);
			setPinVAlue(DIO_PORTA,PIN3,OUTPUT_LOW);
			_delay_ms(1000);
			setPinVAlue(DIO_PORTC,PIN7,OUTPUT_HIGH);
			setPinVAlue(DIO_PORTA,PIN3,OUTPUT_HIGH);
			_delay_ms(1000);
			setPinVAlue(DIO_PORTC,PIN7,OUTPUT_LOW);
			setPinVAlue(DIO_PORTA,PIN3,OUTPUT_LOW);
			_delay_ms(1000);
			setPinVAlue(DIO_PORTD,PIN3,OUTPUT_HIGH);
			setPinVAlue(DIO_PORTA,PIN3,OUTPUT_HIGH);
			_delay_ms(1000);
			setPinVAlue(DIO_PORTD,PIN3,OUTPUT_LOW);
			setPinVAlue(DIO_PORTA,PIN3,OUTPUT_LOW);
		}
		else if (1 == Button2_Value) //print binary from 0 to 7
		{
			for(i=0;i<8;i++)
			{
				setPinVAlue(DIO_PORTC,PIN2,GETBIT(i,0));
				setPinVAlue(DIO_PORTC,PIN7,GETBIT(i,1));
				setPinVAlue(DIO_PORTD,PIN3,GETBIT(i,2));

				_delay_ms(1000);
			}
			setPinVAlue(DIO_PORTC,PIN2,OUTPUT_LOW);
			setPinVAlue(DIO_PORTC,PIN7,OUTPUT_LOW);
			setPinVAlue(DIO_PORTD,PIN3,OUTPUT_LOW);

		}
		else if(1==Button3_Value)
		{
			for(i=1;i<=12;i++)
			{ if(i==1||i==9)
				{
					setPinVAlue(DIO_PORTC,PIN2,OUTPUT_HIGH);
					_delay_ms(1000);

				}
			else if(i==2||i==8)
			{
				setPinVAlue(DIO_PORTC,PIN7,OUTPUT_HIGH);
				_delay_ms(1000);


			}
			else if(i==3||i==7)
			{
				setPinVAlue(DIO_PORTD,PIN3,OUTPUT_HIGH);
				_delay_ms(1000);


			}
			else if(i==4||i==12)
			{
				setPinVAlue(DIO_PORTC,PIN2,OUTPUT_LOW);
				_delay_ms(1000);


			}
			else if(i==5||i==11)
			{
				setPinVAlue(DIO_PORTC,PIN7,OUTPUT_LOW);
				_delay_ms(1000);


			}
			else if(i==6||i==10)
			{
				setPinVAlue(DIO_PORTD,PIN3,OUTPUT_LOW);
				_delay_ms(1000);
			}
			else{}
			}

		}
		else{}


	}



	return 0;
}


