/*
 * main.c
 *
 *  Created on: May 10, 2015
 *      Author: mraouf
 */

#include "micro_config.h"
#include "uart.h"
#include "common_macros.h"


int main() /////////////////////////////////// MASTER ///////////////////////////////////////////
{

	CLEAR_BIT(DDRA,PA0);  // motor start button
	CLEAR_BIT(PORTA,PA0); // motor start button initialization

	CLEAR_BIT(DDRA,PA1); // motor stop button
	CLEAR_BIT(PORTA,PA1); // motor stop button initialization

	CLEAR_BIT(DDRA,PA2); // request motor status button
	CLEAR_BIT(PORTA,PA2); // request motor status button initialization

	SET_BIT(DDRC,PC0); // status led
	CLEAR_BIT(PORTC,PC0); // status led initialization

	UART_init(); // UART module initialization

	uint8 motorStatus;

	while(1)
	{

		if(BIT_IS_SET(PINA,PA0))
		{
			_delay_ms(250);
			UART_sendByte('A'); // turn motor on
		}

		if(BIT_IS_SET(PINA,PA1))
		{
			_delay_ms(250);
			UART_sendByte('B'); // turn motor off
		}

		if(BIT_IS_SET(PINA,PA2))
		{
			_delay_ms(250);
			UART_sendByte('G'); // request motor status
			motorStatus = UART_recieveByte(); // update led
			switch(motorStatus)
			{
			case 0:
				CLEAR_BIT(PORTC,PC0);
				break;
			case 1:
				SET_BIT(PORTC,PC0);
				break;
			}
		}


	}

	return 0;
}


