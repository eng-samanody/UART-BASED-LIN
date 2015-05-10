/* ------------------------------------------------------------------------------------------------------
[FILE NAME]:      < dio.h >
[AUTHOR(S)]:      < Mohamed AbdelRaouf >
[DATE CREATED]:   < Thu 07/05/2015 >
[DESCRIPTION]:    < The dio file includes all the functions that deals with the hardware of the chip such as
					setting ports direction, reading status and sending output values >

-------------------------------------------------------------------------------------------------------- */

#ifndef DIO_H_
#define DIO_H_
/*--------------------------------------------- INCLUDES -----------------------------------------------*/

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/*---------------------------------- DEFINITIONS AND CONFIGURATIONS ---------------------------------*/

/* 	changing INPUT and OUTPUT values is recomendded while dealing with different hardware that treats 0
	as output and 1 as input (like PIC families)  */
#define INPUT 0
#define OUTPUT 1

/* changing the LOGIC_HIGH and LOGIC_LOW values dictates
 *  whether we are dealing with pull up or pull down configurations */
#define LOGIC_HIGH 1
#define LOGIC_LOW 0

/****************************************************************************************************************/

/*-------------------------------------- STRUCTURES AND UNIONS --------------------------------------------------*/

/* ---------------------------------------------------------------------------------------------------------------
[Structure Name]: DioConfig
[Structure Description]:

uint8 port --> the PORT Which the pin belongs to. 'A 'B' 'C' or 'D'
uint8 pinNum --> the number of the pin in the PORT.
uint8 direction --> the direction of pin => INPUT or OUTPUT
uint8 value --> the value of the pin  =>  LOGIC_HIGH or LOGIC_LOW
--------------------------------------------------------------------------------------------------------------- */
typedef struct
{
	uint8 port;
	uint8 pinNum;
	uint8 direction;
	uint8 value;
}DioConfig;
/***************************************************************************************************************/

/*----------------------------------- FUNCTION DECLARATIONS --------------------------------*/

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_setDirection
[Description]  : This function is responsible for setting direction of the selected port
[Args]   :
[in]   		const DioConfig * a_CONFIG_MSG_Ptr :
			recives the address of  the DioConfig struct containing all information about the targeted registers
			of the hardware	the received struct will contain :
			1. the PORT Which the pin belongs to. 'A 'B' 'C' or 'D'
			2. the number of the pin in the PORT.
			3. the direction of pin --> INPUT or OUTPUT
			4. the value of the pin
[Returns] : void
--------------------------------------------------------------------------------------------------------------- */
void DIO_setDirection(const DioConfig * a_CONFIG_MSG_Ptr );

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_writePin
[Description]  : This function is responsible for setting output value of the selected port and pin
[Args]   :
[in]   	const DioConfig * a_STATE_Ptr :
		recives the address of  the DioConfig struct containing all information about the targeted registers of the hardware
		the received struct will contain
		1. the PORT Which the pin belongs to. 'A 'B' 'C' or 'D'
		2. the number of the pin in the PORT.
		3. the direction of pin --> INPUT or OUTPUT
		4. the value of the pin
[Returns] : void
-------------------------------------------------------------------------------------------------------------------- */
void DIO_writePin(const DioConfig * a_STATE_Ptr);

/* ---------------------------------------------------------------------------------------------------------------
[Function Name] : DIO_readPin
[Description]  : This function is responsible for reading the input value of the selected port and pin
[Args]   :
[in]   	const DioConfig * a_STATE_Ptr :
		recives the address of  the DioConfig struct containing all information about the targeted registers of the hardware
		the received struct will contain
		1. the PORT Which the pin belongs to. 'A 'B' 'C' or 'D'
		2. the number of the pin in the PORT.
		3. the direction of pin --> INPUT or OUTPUT
		4. the value of the pin
[out]	uint8 output : this variable will store the value of the targeted pin
[Returns] : output is the value of the targeted pin
-------------------------------------------------------------------------------------------------------------------- */
uint8 DIO_readPin(const DioConfig * a_STATE_Ptr);

#endif /* DIO_H_ */
