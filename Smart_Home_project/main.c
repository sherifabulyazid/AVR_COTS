#include "Library/STD_TYPES.h"
#include "Library/BIT_MATH.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"
#include "Keypad_config.h"
#include "Timer_interface.h"

static uint8 ComparePasswords(uint8 *pass1 , uint8 *pass2 );


int main (void)
{
	DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);//LCD data
	setPinDirection(DIO_PORTA,PIN5,OUTPUT);// LCD EN
	setPinDirection(DIO_PORTA,PIN6,OUTPUT); // LCD R/W
	setPinDirection(DIO_PORTA,PIN7,OUTPUT); //LCD RS
	DIO_SetPortDirection(DIO_PORTC, KEYPAD_Direction);
	DIO_SetPortValue(DIO_PORTC,KEYPAD_Value);
	setPinDirection(DIO_PORTD,PIN7,OUTPUT);//Lights
	setPinDirection(DIO_PORTD,PIN4,OUTPUT);//Fan
	setPinDirection(DIO_PORTD,PIN5,OUTPUT);//Servo motor
	ADC_init();
	LCD_init();
	uint8 valueADC=0;
	uint32 analogue=0;
	uint8 temprature=0;
	uint8 passReal[4]={'4','3','2','1'};
	uint8 passArr[4];
	uint8 passStatus=2;
	uint8 iterator=0;
	uint8 choosenOption =0;
	uint8 trials=0;
	uint8 angle=0;

	LCD_SendString("Welcome To SMART HOME");
	_delay_ms(1500);
	LCD_ClearDisplay();
	_delay_ms(2);
	LCD_SendString("Enter Password");
	LCD_GoToXY(SecondLine, 0);
	while(iterator<4)
	{
		do
		{
			passArr[iterator]=get_button_pressed();

		}while(passArr[iterator]==0xff);
		LCD_Write_data('*');
		iterator++;
	}
	_delay_ms(500);
	LCD_ClearDisplay();
	_delay_ms(2);

	/*control servo motor using potentiometer*/
	uint32 it=40000;
	LCD_SendString("Adjust Servo");
	_delay_ms(1000);
	LCD_ClearDisplay();
	while(it)
	{
		valueADC=ADC_StartConversion(ADC0);
		angle=ADC_To_Angle(valueADC);
		Timer1_Servo(angle);
		it--;
	}

	while(1)
	{

		passStatus = ComparePasswords(passReal,passArr);
		if(passStatus==FALSE)
		{
			trials++;
			if(trials==3)
			{
				break;
			}
			LCD_SendString("Wrong Password");
			_delay_ms(1000);
			LCD_ClearDisplay();
			_delay_ms(2);
			LCD_SendString("Enter Pass Again");
			LCD_GoToXY(SecondLine, 3);
			iterator=0;
			while(iterator<4)
			{
				do
				{
					passArr[iterator]=get_button_pressed();
				}while(passArr[iterator]==0xff);
				LCD_Write_data('*');
				iterator++;
			}
			_delay_ms(1000);
			LCD_ClearDisplay();
			_delay_ms(2);

		}
		else if(passStatus==TRUE)
		{
			LCD_SendString("Options:");
			LCD_GoToXY(SecondLine, 0);
			LCD_SendString("1-Display Temp");
			_delay_ms(1500);
			LCD_ClearDisplay();
			_delay_ms(2);
			LCD_SendString("2- Fan ON");
			LCD_GoToXY(SecondLine, 0);
			LCD_SendString("3- Fan OFF");
			_delay_ms(1500);
			LCD_ClearDisplay();
			_delay_ms(2);
			LCD_SendString("4- Lights ON");
			LCD_GoToXY(SecondLine, 0);
			LCD_SendString("5- Lights OFF");
			_delay_ms(1500);
			LCD_ClearDisplay();
			_delay_ms(2);
			do
			{
				choosenOption=get_button_pressed();

			}while(choosenOption==0xff);

			switch(choosenOption)
			{
				case '1':
					valueADC= ADC_StartConversion(ADC1);
					analogue=(uint32)valueADC*5000UL/256UL; //in mV
					temprature=analogue/10;
					LCD_SendString("Temp=");
					LCD_GoToXY(FirstLine, 6);
					LCD_uint8_WriteNumber(temprature);
					LCD_SendString(" 'C");
					_delay_ms(3000);
					LCD_ClearDisplay();
					_delay_ms(2);
					break;
				case '2':
					setPinVAlue(DIO_PORTD,PIN4,OUTPUT_HIGH);
					break;
				case '3':
					setPinVAlue(DIO_PORTD,PIN4,OUTPUT_LOW);
					break;
				case '4':
					setPinVAlue(DIO_PORTD,PIN7,OUTPUT_HIGH);
					break;
				case '5':
					setPinVAlue(DIO_PORTD,PIN7,OUTPUT_LOW);
					break;
				default:
					break;
			}
		}
	}
	return 0;
}

static uint8 ComparePasswords(uint8 *pass1 , uint8 *pass2 )
{
	if(pass1[0]==pass2[3]&&pass1[1]==pass2[2]&&pass1[2]==pass2[1]&&pass1[3]==pass2[0])
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}
