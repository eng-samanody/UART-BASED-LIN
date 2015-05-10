/* ---------------------------------------------------------------------------------------------------
[FILE NAME]:      < std_type.h >

[AUTHOR(S)]:      < Mohamed AbdelRaouf >

[DATE CREATED]:   < Mon 12/29/2014 >

[DESCRIPTION]:    < the file contains type definitions for all the data types used during the project >
------------------------------------------------------------------------------------------------------- */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*--------------------------------------------- INCLUDES -----------------------------------------------*/



/*---------------------------------- DEFINITIONS AND CONFIGURATIONS ------------------------------------*/

/* define uint8 as unsigned char (1 byte) [0-255] --> max = (2^8)-1 */
typedef unsigned char uint8;


/* define uint16 as unsigned short (2 bytes) [0-65565] --> max = (2^16)-1 */
typedef unsigned short uint16;

/* define uint32 as unsigned long (4 bytes) [0-4294967295] --> max = (2^32)-1 */
typedef unsigned long uint32;

#endif /* STD_TYPES_H_ */
