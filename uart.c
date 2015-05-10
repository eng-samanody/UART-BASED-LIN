/****************************************************************************************************************
[FILE NAME]    : UART.c
[AUTHOR]       : Mohamed Abd El Raouf
[DATE CREATED] : 1/17/2015 6:47:56 PM
[DESCRIPTION]  : UART Module source file for general use
*****************************************************************************************************************/

/*****************************************************INCLUDES***************************************************/
#include "uart.h"

/***********************************************FUNCTION DEFINITIONS*********************************************/
 
void UART_init(void)
{
	/*double transmission speed */
	SET_BIT(UCSRA,U2X);
	
	/* enable UART as transmitter and receiver */
	SET_BIT(UCSRB,RXEN);
	//SET_BIT(UCSRB,TXEN);
	
	/* 8-bit data, NO parity, one stop bit and asynch */
	SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	
	/* baud rate=9600 & Fosc=1MHz -->  UBBR=( Fosc / (8 * baud rate) ) - 1 = 12 */  
	UBRRH = 0;
	UBRRL = 12;
}

/*******************************************************************************************************************/
void UART_sendByte(const char a_DATA)
{
	/*UDRE flag is set when the buffer is empty and ready for transmitting a new byte so wait until this flag is set to one*/
	while(!(UCSRA & (1<<UDRE))){}
	SET_BIT(UCSRB,TXEN);  /// test
	UDR = a_DATA;
	CLEAR_BIT(UCSRB,TXEN); /// test
}

/*******************************************************************************************************************/
char UART_recieveByte(void)
{
	/*RXC flag is set when the UART receive data so until this flag is set to one*/
	while(!(UCSRA & (1<<RXC))){}
    return UDR;		
}

/*******************************************************************************************************************/
void UART_sendString(const char *a_STR_Ptr)
{
	unsigned char i = 0;
	while(a_STR_Ptr[i] != '\0')
	{
		UART_sendByte(a_STR_Ptr[i]);
		i++;
	}
}

/*******************************************************************************************************************/
void UART_receiveString(char *a_str_Ptr)
{
	unsigned char i = 0;
	a_str_Ptr[i] = UART_recieveByte();
	while(a_str_Ptr[i] != '#')
	{
		i++;
		a_str_Ptr[i] = UART_recieveByte();
	}
	a_str_Ptr[i] = '#';
}
