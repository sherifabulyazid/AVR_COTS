/*
 * LCD_Interface.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Sherif
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_DATA PORTA
#define LCD_CONTROL DIO_PORTB
#define EN 0
#define RW 1
#define RS 2

#define FirstLine 0
#define SecondLine 1

void LCD_init(void);
void LCD_cmd(uint8 cmd);
void LCD_Write_data(uint8 data);
void LCD_GoToXY(uint8 copy_xPosition, uint8 copy_yPosition);
void LCD_SendString(const char *copy_string);
void LCD_ClearDisplay(void);
void LCD_uint8_WriteNumber(uint8 copy_number);

#endif /* LCD_INTERFACE_H_ */
