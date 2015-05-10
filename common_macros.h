/* ---------------------------------------------------------------------------------------------------
[FILE NAME]:      < common_macros.h >
[AUTHOR(S)]:      < Mohamed AbdelRaouf >
[DATE CREATED]:   < Thu 07/05/2015 >
[DESCRIPTION]:    < This file contains some common macros that are used to deal with registers >
------------------------------------------------------------------------------------------------------- */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


/* Set a certain bit in any given register */
#define SET_BIT(REG,BIT_NUM) ( REG = REG | (1<<BIT_NUM) )

/* Clear a certain bit in any given register */
#define CLEAR_BIT(REG,BIT_NUM) (REG = REG & ~(1<<BIT_NUM))

/* Toggle a certain bit in any given register */
#define TOGGLE_BIT(REG,BIT_NUM) ( REG = REG ^ (1<<BIT_NUM) )

/* Check if any bit is set in any given register and return true if yes  */
#define BIT_IS_SET(REG,BIT_NUM) ( REG & (1<<BIT_NUM) )
/* Check if any bit is Clear in any given register and return true if yes  */
#define BIT_IS_CLEAR(REG,BIT_NUM) ( !( REG & (1<<BIT_NUM) ) )






#endif /* COMMON_MACROS_H_ */
