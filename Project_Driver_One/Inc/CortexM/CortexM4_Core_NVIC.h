/*
 * CotexM4_Core_NVIC.h
 *
 *  Created on: Feb 2, 2024
 *      Author: Aya Ali
 */

#ifndef CORTEXM4_CORE_NVIC_H_
#define CORTEXM4_CORE_NVIC_H_

/*------------ Include Section --------------*/
#include "Common/Std_Types.h"

/*------------ Macro Declaration Section --------------*/
#define NVIC_BASE     (0xE000E100UL)
#define NVIC       ((NVIC_Type*)NVIC_BASE)
#define NVIC_PRIO_BITS      4UL


/*------------ DataType Declaration Section --------------*/
typedef struct
{
	volatile uint_32 ISER[8U];
	uint_32 RESERVED0[24U];
	volatile uint_32 ICER[8U];
	uint_32 RESERVED1[24U];
	volatile uint_32 ISPR[8U];
	uint_32 RESERVED2[24U];
	volatile uint_32 ICPR[8U];
	uint_32 RESERVED3[24U];
	volatile uint_32 IABR[8U];
	uint_32 RESERVED4[56U];
	volatile uint_8 IP[240U];
	uint_32 RESERVED5[644U];
	volatile uint_32 STIR;
}NVIC_Type;

typedef enum{
		NonMaskable_Interrupt_IRQn   = -14,
		MemoryManagement_IRQn = -12,
		BusFault_IRQn = -11,
		UsageFault_IRQn = -10,
		SVCall_IRQn = -5,
		Debuger_Monetor_IRQn = -4,
		PendSV_IRQn= -2,
		Systick_IRQn = -1,
		WWDG_IRQn = 0,
		PVD_IRQn = 1,
		TAMP_STAM_IRQn = 2,
		RTC_WKUP_IRQn = 3,
		FLASH_IRQn = 4,
		RCC_IRQn = 5,
		EXTI0_IRQn = 6,
		EXTI1_IRQn = 7,
		EXTI2_IRQn = 8,
		EXTI3_IRQn = 9,
		EXTI4_IRQn = 10,
		DMA1_Stream0_IRQn = 11,
		DMA1_Stream1_IRQn = 12,
		DMA1_Stream2_IRQn = 13,
		DMA1_Stream3_IRQn = 14,
		DMA1_Stream4_IRQn = 15,
		DMA1_Stream5_IRQn = 16,
		DMA1_Stream6_IRQn = 17,
		ADC_IRQn = 18,
		CAN1_TX_IRQn = 19,
		CAN1_RX0_IRQn = 20,
		CAN1_RX1_IRQn = 21,
		CAN1_SCE_IRQn = 22,
		EXTI9_5_IRQn = 23,
		TIM1_BRK_TIM9_IRQn = 24,
		TIM1_UP_TIM10_IRQn = 25,
		TIM1_TRG_COM_TIM11_IRQn = 26,
		TIM1_CC_IRQn = 27,
		TIM2_IRQn = 28,
		TIM3_IRQn = 29,
		TIM4_IRQn = 30,
		I2C1_EV_IRQn = 31,
		I2C1_ER_IRQn = 32,
		I2C2_EV_IRQn = 33,
		I2C2_ER_IRQn = 34,
		SPI1_IRQn = 35,
		SPI2_IRQn = 36,
		USART1_IRQn = 37,
		USART2_IRQn= 38,
		USART3_IRQn = 39,
		EXTI15_10_IRQn = 40,
		RTC_Alarm_IRQn = 41,
		OTG_FS_WKUP_IRQn = 42,
		TIM8_BRK_TIM12_IRQn = 43,
		TIM8_UP_TIM13_IRQn = 44,
		TIM8_TRG_COM_TIM14_IRQn = 45,
		TIM8_CC_IRQn = 46,
		DMA1_Stream7_IRQn = 47,
		FSMC_IRQn = 48,
		SDIO_IRQn = 49,
		TIM5_IRQn = 50,
		SPI3_IRQn = 51,
		UART4_IRQn =52,
		UART5_IRQn = 53,
		TIM6_DAC_IRQn = 54,
		TIM7_IRQn = 55,
		DMA2_Stream0_IRQn = 56,
		DMA2_Stream1_IRQn = 57,
		DMA2_Stream2_IRQn = 58,
		DMA2_Stream3_IRQn = 59,
		DMA2_Stream4_IRQn = 60,
		ETH_IRQn = 61,
		ETH_WKUP_IRQn = 62,
		CAN2_TX_IRQn = 63,
		CAN2_RX0_IRQn = 64,
		CAN2_RX1_IRQn = 65,
		CAN2_SCE_IRQn = 66,
		OTG_FS_IRQn = 67,
		DMA2_Stream5_IRQn = 68,
		DMA2_Stream6_IRQn = 69,
		DMA2_Stream7_IRQn = 70,
		USART6_IRQn = 71,
		I2C3_EV_IRQn = 72,
		I2C3_ER_IRQn = 73,
		OTG_HS_EP1_OUT_IRQn = 74,
		OTG_HS_EP1_IN_IRQn = 75,
		OTG_HS_WKUP_IRQn = 76,
		OTG_HS_IRQn = 77,
		DCMI_IRQn = 78,
		HASH_RNG_IRQn = 79,
		FPU_IRQn = 80,
}IRQn_Type;
/*------------ Macro Function Declaration Section --------------*/
/*------------ Software Interfaces Section --------------*/


void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint_32 NVIC_GetActive(IRQn_Type IRQn);

/*
 * brief:    set the interrupt priority.
 * details:  set the priority of a device specific interrupt or processor exceptions.
 *           the interrupt number can be positive to specify a device specific interrupt.
 *           or negative to specify a processor exception.
 *Param[in]: IRQn interrupt number.
 *Param[in]: priority priority to set.
 *note:      the priority can not be set for every processor exception.
 * */
void NVIC_SetPriority(IRQn_Type IRQn, uint_32 priority);
/*
 * brief:   Get interrupt Priority.
 * details: Reads the priority of a device specification interrupt or a processor exceptions.
 *          the interrupt number can be positive to specify a device specific interrupt.
 *          or negative to specify a processor exception.
 * Param[in]: IRQn Interrupt number.
 * return:    interrupt priority.
 *             value is aligned automatically to the implemented priority bit.
 * */
uint_32 NVIC_GetPriority(IRQn_Type IRQn);

#endif /* CORTEXM4_CORE_NVIC_H_ */
