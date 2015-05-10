/* -------------------------------------------------------------------------------------------------------------
[FILE NAME]:      < dio.c >
[AUTHOR(S)]:      < Mohamed AbdelRaouf >
[DATE CREATED]:   < Thu 07/05/2015 >
[DESCRIPTION]:    < The dio file includes all the functions that deals with the hardware of the chip
					such as setting ports direction, reading status and sending output values >
----------------------------------------------------------------------------------------------------------------- */

/*--------------------------------------------- INCLUDES ---------------------------------------------------------*/

#include "dio.h"

/*-------------------------------------------- FUNCTION DEFINITIONS ----------------------------------------------*/

void DIO_setDirection(const DioConfig * a_CONFIG_MSG_Ptr )
{
	volatile uint8 * DDR_Ptr;

	switch(a_CONFIG_MSG_Ptr -> port)
	{
		case 'A':
			DDR_Ptr = &DDRA;
			break;
		case 'B':
			DDR_Ptr = &DDRB;
			break;
		case 'C':
			DDR_Ptr = &DDRC;
			break;
		case 'D':
			DDR_Ptr = &DDRD;
			break;
	}
	if(a_CONFIG_MSG_Ptr -> direction == OUTPUT)
	{
		/* set the corresponding bit in the DDR register to configure it as output pin */
		SET_BIT(*DDR_Ptr,a_CONFIG_MSG_Ptr->pinNum);
	}
	else if(a_CONFIG_MSG_Ptr -> direction == INPUT)
	{
		/* clear the corresponding bit in the DDR register to configure it as input pin */
		CLEAR_BIT(*DDR_Ptr,a_CONFIG_MSG_Ptr->pinNum);
	}

}

void DIO_writePin(const DioConfig * a_STATE_Ptr)
{
	volatile uint8* PORT_Ptr;

	switch(a_STATE_Ptr->port)
	{
		case 'A':
			PORT_Ptr = &PORTA;
			break;
		case 'B':
			PORT_Ptr = &PORTB;
			break;
		case 'C':
			PORT_Ptr = &PORTC;
			break;
		case 'D':
			PORT_Ptr = &PORTD;
			break;
	}
	if(a_STATE_Ptr -> value == LOGIC_HIGH)
	{
		/* set the corresponding pin in the PORT register */
		SET_BIT(*PORT_Ptr, a_STATE_Ptr -> pinNum);
	}
	else if(a_STATE_Ptr -> value == LOGIC_LOW)
	{
		/* clear the corresponding pin in the PORT register */
		CLEAR_BIT(*PORT_Ptr, a_STATE_Ptr -> pinNum);
	}

}

uint8 DIO_readPin(const DioConfig * a_STATE_Ptr)
{
	volatile uint8 * PORT_Ptr;
	uint8 state;
	/* point to the required PIN Register */
	switch( a_STATE_Ptr -> port )
	{
		case 'A': PORT_Ptr = &PORTA;
				  break;
		case 'B': PORT_Ptr = &PORTB;
				  break;
		case 'C': PORT_Ptr = &PORTC;
				  break;
		case 'D': PORT_Ptr = &PORTD;
				  break;
	}

	if (BIT_IS_SET(*PORT_Ptr, a_STATE_Ptr -> pinNum))
	{
		state = LOGIC_HIGH;
	}
	else if(BIT_IS_CLEAR(*PORT_Ptr,a_STATE_Ptr -> pinNum))
	{
		state = LOGIC_LOW;
	}

	return state;
}

