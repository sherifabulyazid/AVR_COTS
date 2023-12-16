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
#define EN 3 //PortC
#define RW 2 //PortC
#define RS 1 //PortC

void LCD_init(void);
void LCD_cmd(uint8 cmd);
void LCD_Write_data(uint8 data);


#endif /* LCD_INTERFACE_H_ */
