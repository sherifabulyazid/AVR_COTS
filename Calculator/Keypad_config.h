/*
 * Keypad_config.h
 *
 *  Created on: Dec 16, 2023
 *      Author: hp
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define ROW_NUM 4
#define COL_NUM 4
#define KEYPAD_PORT DIO_PORTC
#define KEYPAD_Direction 0xf0 //Lower nibble of port is input , Higher nibble is output
#define KEYPAD_Value 0xff     // set pull up resistance for input pins , set output pins as high

#endif /* KEYPAD_CONFIG_H_ */
