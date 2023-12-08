/*
 * DIO_Interface.h
 *
 *  Created on: Dec 8, 2023
 *      Author: hp
 */

/*
1-set pin directoin
2-set port direction
3- set pin value
4-set port value
5- get pin value
*/
#ifndef _DIO_REGISTER_H_
#define _DIO_REGISTER_H_

/*Mactos for ports */
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define OUTPUT_HIGH  1
#define OUTPUT_LOW   0

uint8  setPinDirection(uint8  Copy_Port ,  uint8 Copy_pin ,  uint8 Copy_Direction);

uint8 setPinVAlue(uint8  Copy_Port ,  uint8 Copy_Pin ,  uint8 Copy_Status);

uint8 DIO_uint8_SetPortDirection (uint8 Copy_uint8_Port, uint8 Copy_uint8_Direction );

uint8 DIO_uint8_SetPortValue  (uint8 Copy_uint8_Port ,   uint8 Copy_uint8_Value );

uint8 DIO_uint8_GetPinValue (uint8 Copy_uint8_Port , uint8 Copy_uint8_Pin , uint8* Copy_uint8_Value);


#endif
