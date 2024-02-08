/*
 * CortexM4_Core_SYSTICK.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Aya Ali
 */

#ifndef CORTEXM_CORTEXM4_CORE_SYSTICK_H_
#define CORTEXM_CORTEXM4_CORE_SYSTICK_H_


/*------------ Include Section --------------*/
#include "Common/Std_Types.h"
#include "CortexM4_Core_Systick_Cfg.h"
#include "Common/Common_Macros.h"

/*------------ Macro Declaration Section --------------*/
#define SYSTICK_BASE   (0xE000E010UL)
#define SYSTICK        ((Systick_Type *) SYSTICK_BASE)

#define SYSTICK_CTRL_ENABLE_POS       0U
#define SYSTICK_CTRL_ENABLE_MSK       (0x1UL << SYSTICK_CTRL_ENABLE_POS)

#define SYSTICK_CTRL_TICKINT_POS      1U
#define SYSTICK_CTRL_TICKINT_MSK      (0x1UL << SYSTICK_CTRL_TICKINT_POS)

#define SYSTICK_CTRL_CLKSOURCE_POS    2U
#define SYSTICK_CTRL_CLKSOURCE_MSK    (0x1UL << SYSTICK_CTRL_CLKSOURCE_POS)

#define SYSTICK_CTRL_COUNTFLAG_POS    16U
#define SYSTICK_CTRL_COUNTFLAG_MSK    (0x1UL << SYSTICK_CTRL_COUNTFLAG_POS)

#define SYSTICK_LOAD_RELOAD_POS       0U
#define SYSTICK_LOAD_RELOAD_MSK       (0XFFFFFFUL << SYSTICK_LOAD_RELOAD_POS)


#define SYSTICK_SINGLEINTERVAL_MODE     0
#define SYSTICK_PERIODICINTERVAL_MODE   1
/*------------ Macro Function Declaration Section --------------*/

/*------------ DataType Declaration Section --------------*/
typedef void(* ptrFunction)(void);

typedef struct{
	volatile uint_32 CTRL;
	volatile uint_32 LOAD;
	volatile uint_32 VAL;
	volatile uint_32 CALIB;
}Systick_Type;

/*------------ Software Interfaces Section --------------*/
uint_8 Systick_Init(uint_32 Systick_Ticks);
void Systick_DeInit(void);
void Systick_WaitBlocking(uint_32 Systick_Ticks);
void Systick_SingleInterval(uint_32 Systick_Ticks, ptrFunction *CallBack);
void Systick_PeriodicInterval(uint_32 Systick_Ticks, ptrFunction *CallBack);
uint_32 Systick_GetRemainingTicks(void);
uint_32 Systick_GetElapsedTicks(void);
#endif /* CORTEXM_CORTEXM4_CORE_SYSTICK_H_ */
