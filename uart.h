/****************************************************************************************************************
[FILE NAME]   : uart.h
[AUTHOR]      : Mohamed Abd El Raouf
[DATE CREATED]: 1/17/2015 6:57:54 PM
[DESCRIPTION] : UART Module header file for general use
*****************************************************************************************************************/

#ifndef UART_H_
#define UART_H_

/****************************************************INCLUDES**************************************************/
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/****************************************Definitions and configurations*****************************************/

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : UART_init
[Description]   : initialize UART by double transmission speed, enable UART as transmitter and receiver, set UART to
				  8-bit data, NO parity, one stop bit and asynch,baud rate=9600 & Fosc=1MHz.
[Args]          : non
[Returns]       : non
--------------------------------------------------------------------------------------------------------------- */
void UART_init(void);


/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : UART_sendByte
[Description]   : wait for UDRE flag to be set indicating that the buffer is empty and ready for transmitting
				  then send one byte.
[Args]          : a_DATA --> the data to send through UART
[Returns]       : non
--------------------------------------------------------------------------------------------------------------- */
void UART_sendByte(const char a_DATA);

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : UART_recieveByte
[Description]   : wait for RXC flag to be set indicating that the buffer is empty and ready for transmitting
				  then receive one byte.
[Args]          : non
[Returns]       : the data received through UART
--------------------------------------------------------------------------------------------------------------- */
char UART_recieveByte(void);

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : UART_sendString
[Description]   :  wait for UDRE flag to be set indicating that the buffer is empty and ready for transmitting
				 then send a string.
[Args]          : pointer to character --> points to the string to be send through UART
[Returns]       : non
--------------------------------------------------------------------------------------------------------------- */
void UART_sendString(const char *a_STR_Ptr);

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : UART_receiveString
[Description]   : wait for RXC flag to be set indicating that the buffer is empty and ready for transmitting
				  then receive a string.
				 ( Receive until #)
[Args]          : pointer to character --> points to the string that is received through UART
[Returns]       : non
--------------------------------------------------------------------------------------------------------------- */
void UART_receiveString(char *a_STR_Ptr);

#endif /* UART_H_ */
