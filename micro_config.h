/* ---------------------------------------------------------------------------------------------------
[FILE NAME]:      < micro_config.h >

[AUTHOR(S)]:      < Mohamed AbdelRaouf >

[DATE CREATED]:   < Thu 07/05/2015 >

[DESCRIPTION]:    < the file contains all controller Registers definitions and controller dependent includes
		            it also can be used to set the targeted cpu clock by changing the F_CPU value     >
------------------------------------------------------------------------------------------------------- */

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

/*--------------------------------------------- INCLUDES -----------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>


#ifndef F_CPU
#define F_CPU 1000000UL
#endif /* F_CPU */


#endif /* MICRO_CONFIG_H_ */
