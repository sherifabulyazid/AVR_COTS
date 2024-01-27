/*
 * main.c
 *
 *  Created on: Jan 6, 2024
 *      Author: hp
 */
#include "STD.h"
#include "BIT_MATH.h"
#include "UART_Interface.h"
#include <util/delay.h>
int main(void)
{
	UART_Init();
	while(1)
	{
		UART_Transmit_data('C');
		_delay_ms(1000);
		UART_Transmit_data('D');
		_delay_ms(1000);

	}



	return 0;
}
