//******************************************************************************
// rcc.h
// Author: Yuqi Fu
// Description:
// Driver source file for Reset and Clock Control module for stm32f446re
// - The current driver takes HSE bypass as clock source (will need to switch
// to HSE Crystal when put on a pcb)
// - The current version of driver does not support the use of internal RC oscillator
// and any low-speed clocks
// - More functionalities may be added in future depending on the application
//*******************************************************************************
#include "rcc.h"

//-------------------------------------------------------------------------------
//Definitions & Macros
//-------------------------------------------------------------------------------
#define RCC_CR_HSION				0
#define RCC_CR_HSIRDY				1
#define RCC_CR_HSEON				16
#define RCC_CR_HSERDY				17
#define RCC_CR_HSEBYP				18
#define RCC_CR_PLLON				24
#define RCC_CR_PLLRDY				25

#define RCC_CR_HSE_BYPASSED			((uint32)(0ul<<RCC_CR_HSION)|(1ul<<RCC_CR_HSEON)|\
									(1ul<<RCC_CR_HSEBYP))
#define RCC_CR_HSE_CRYSTAL			((uint32)(0ul<<RCC_CR_HSION)|(1ul<<RCC_CR_HSEON)|\
									(0ul<<RCC_CR_HSEBYP))





//-------------------------------------------------------------------------------
//global variables
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
//local variables
//-------------------------------------------------------------------------------

//
// rcc_reg_set *rcc_regs provides the pointer to the base address of the rcc block
// registers will be accessed using this structure pointer in this way:
// i.e. rcc_regs->rcc_cr = what_ever_uint32_val
//

local rcc_reg_set *rcc_regs = (rcc_reg_set *) RCC_BASE_ADDR;

//-------------------------------------------------------------------------------
//function prototypes
//-------------------------------------------------------------------------------

void rcc_pll_clk_config(enum rcc_extern_clk_src clk_src);

//-------------------------------------------------------------------------------
//local functions
//-------------------------------------------------------------------------------




//-------------------------------------------------------------------------------
//global functions
//-------------------------------------------------------------------------------

global void rcc_pll_clk_config(bool hse_bypassed)
{
	//configure the cr register based on whether hse is bypassed (crystal not used)
	rcc_regs->rcc_cr = hse_bypassed ? RCC_CR_HSE_BYPASSED : RCC_CR_HSE_CRYSTAL;

	//wait till HSE is ready and stable
	while(rcc_regs->rcc_cr & (1ul<<RCC_CR_HSERDY));


}

