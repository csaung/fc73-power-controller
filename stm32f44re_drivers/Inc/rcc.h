//******************************************************************************
// rcc.h
// Author: Yuqi Fu
// Description:
// Driver header file for Reset and Clock Control module for stm32f446re
//
//*******************************************************************************

#ifndef RCC_H_
#define RCC_H_

#include "stm32f446re_mem_map.h"

//-------------------------------------------------------------------------------
//Definitions & Macros
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//global variables
//-------------------------------------------------------------------------------

//
//Enum for users to select HSE oscillator source type
//RCC_HSE_BYPASS can be derived from nucleo's stlink
//RCC_HSE_CRYSTAL is derived from an external crystal
//check the electrical characteristics for further info
//

global enum rcc_extern_clk_src
{
	RCC_HSE_BYPASS = 0,
	RCC_HSE_CRYSTAL
};

//-------------------------------------------------------------------------------
//local variables
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//function prototypes
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//local functions
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//global functions
//-------------------------------------------------------------------------------



extern void rcc_system_clk_config(bool hse_bypassed);
extern void rcc_pll_clk_debug(void);



#endif
