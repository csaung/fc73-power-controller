//******************************************************************************
// stm32f44re_mem_map.h
// Author: Yuqi Fu
// Description:
// A memory map for stm32f44re's registers to be used in the power logger project
//
//*******************************************************************************

#ifndef STM32F44RE_MEM_MAP_H_
#define STM32F44RE_MEM_MAP_H_

#include "driver_keyword_defs.h"

//
//Base addresses of peripheral registers:
//the peripheral registers of the microcontroller starts at the address 0x4000_0000,
//and ends at 0x6000_0000. Please refer to the chart at page 57-59 of the reference
//manual. The base addresses of the peripherals shown below are organized from lower
//to higher addresses
//
#define 		BASE_ADDR_OFFSET		0x400
#define			TIM2_BASE_ADDR			0x40000000
#define			TIM3_BASE_ADDR			0x40000400
#define			TIM4_BASE_ADDR			0x40000800
#define			TIM5_BASE_ADDR			0x40000C00
#define			TIM6_BASE_ADDR			0x40001000
#define			TIM7_BASE_ADDR			0x40001400
#define			TIM12_BASE_ADDR			0x40001800
#define			TIM13_BASE_ADDR			0x40001C00
#define			TIM14_BASE_ADDR			0x40002000
#define			RTC_BASE_ADDR			0x40002800
#define			WWDG_BASE_ADDR			0x40002C00
#define			IWDG_BASE_ADDR			0x40003000
#define			SPI2_BASE_ADDR			0x40003800
#define			SPI3_BASE_ADDR			0x40003C00
#define			SPDIF_BASE_ADDR			0x40004000
#define			USART2_BASE_ADDR		0x40004400
#define			USART3_BASE_ADDR		0x40004800
#define			UART4_BASE_ADDR			0x40004C00
#define			UART5_BASE_ADDR		    0x40005000
#define			I2C1_BASE_ADDR		    0x40005400
#define			I2C2_BASE_ADDR		    0x40005800
#define			I2C3_BASE_ADDR		    0x40005C00
#define			CAN1_BASE_ADDR		    0x40006400
#define			CAN2_BASE_ADDR		    0x40006800
#define			HDMI_BASE_ADDR		    0x40006C00
#define			PWR_BASE_ADDR		    0x40007000
#define			DAC_BASE_ADDR		    0x40007400

#define			TIM1_BASE_ADDR		    0x40010000
#define			TIM8_BASE_ADDR		    0x40010400
#define			USART1_BASE_ADDR		0x40011000
#define			USART6_BASE_ADDR		0x40011400
#define			ADC1_BASE_ADDR			0x40012000
#define			ADC2_BASE_ADDR			0x40012100
#define			ADC3_BASE_ADDR			0x40012200
#define			SDMMC_BASE_ADDR			0x40012C00
#define			SPI1_BASE_ADDR			0x40013000
#define			SPI4_BASE_ADDR			0x40013400
#define			SYSCFG_BASE_ADDR		0x40013800
#define 		EXTI_BASE_ADDR			0x40013C00
#define			TIM9_BASE_ADDR			0x40014000
#define			TIM10_BASE_ADDR			0x40014400
#define			TIM11_BASE_ADDR			0x40014800
#define			SAI1_BASE_ADDR			0x40015800
#define			SAI2_BASE_ADDR			0x40015C00
#define			GPIOA_BASE_ADDR			0x40020000
#define			GPIOB_BASE_ADDR			0x40020400
#define			GPIOC_BASE_ADDR			0x40020800
#define			GPIOD_BASE_ADDR			0x40020C00
#define			GPIOE_BASE_ADDR			0x40021000
#define			GPIOF_BASE_ADDR			0x40021400
#define			GPIOG_BASE_ADDR			0x40021800
#define			GPIOH_BASE_ADDR			0x40021C00
#define			CRC_BASE_ADDR			0x40023000
#define			RCC_BASE_ADDR			0x40023800
#define			FLSHI_BASE_ADDR			0x40023C00
#define			BKPSRAM_BASE_ADDR		0x40024000
#define			DMA1_BASE_ADDR			0x40026000
#define			DMA2_BASE_ADDR			0x40026400
#define			USBHS_BASE_ADDR			0x40040000
#define			USBFS_BASE_ADDR			0x50000000
#define			DCMI_BASE_ADDR			0x50050000
#define			FMC_BASE_ADDR			0xA0000000
#define			QSPI_BASE_ADDR			0xA0001000

//
//Register set structures: add to this section when new driver is finished
//The registers are grouped into structures. Each structure is mapped to a specific base address
//as defined above
//

//
//RCC Registers
//

typedef struct
{
	__vo uint32 rcc_cr;
	__vo uint32 rcc_pll_cfgr;
	__vo uint32 rcc_cfgr;
	__vo uint32 rcc_cir;
	__vo uint32 rcc_ahb1_rstr;
	__vo uint32 rcc_ahb2_rstr;
	__vo uint32 rcc_ahb3_rstr;
	__vo uint32 rcc_reserved0;
	__vo uint32 rcc_apb1_rstr;
	__vo uint32 rcc_apb2_rstr;
	__vo uint32 rcc_reserved1[2];
	__vo uint32 rcc_ahb1_enr;
	__vo uint32 rcc_ahb2_enr;
	__vo uint32 rcc_ahb3_enr;
	__vo uint32 rcc_reserved2;
	__vo uint32 rcc_apb1_enr;
	__vo uint32 rcc_apb2_enr;
	__vo uint32 rcc_reserved3[2];
	__vo uint32 rcc_ahb1lp_enr;
	__vo uint32 rcc_ahb2lp_enr;
	__vo uint32 rcc_ahb3lp_enr;
	__vo uint32 rcc_reserved4;
	__vo uint32 rcc_apb1lp_enr;
	__vo uint32 rcc_apb2lp_enr;
	__vo uint32 rcc_reserved5[2];
	__vo uint32 rcc_bdcr;
	__vo uint32 rcc_csr;
	__vo uint32 rcc_reserved6[2];
	__vo uint32 rcc_sscgr;
	__vo uint32 rcc_pll_i2s_cfgr;
	__vo uint32 rcc_pll_sai_scfgr;
	__vo uint32 rcc_dck_scfgr;
	__vo uint32 rcc_ckgat_enr;
	__vo uint32 rcc_dck_scfgr2;
} rcc_reg_set;

//
// rcc_reg_set *rcc_regs provides the pointer to the base address of the rcc block
// registers will be accessed using this structure pointer in this way:
// i.e. rcc_regs->rcc_cr = what_ever_uint32_val
//

rcc_reg_set *rcc_regs = (rcc_reg_set *) RCC_BASE_ADDR;

#endif
