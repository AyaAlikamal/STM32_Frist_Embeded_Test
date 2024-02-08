/*
 * CortexM4_Core_SCB.h
 *
 *  Created on: Feb 2, 2024
 *      Author: Aya Ali
 */

#ifndef CORTEXM4_CORE_SCB_H_
#define CORTEXM4_CORE_SCB_H_

/*------------ Include Section --------------*/
#include "Common/Std_Types.h"
/*------------ Macro Declaration Section --------------*/

#define SCB_BASE     (0xE000ED00UL)
#define SCB          ((SCB_Type *) 0xE000ED00UL)

#define SCB_PRIORITYGROUP_0      0x00000007U
#define SCB_PRIORITYGROUP_1      0x00000006U
#define SCB_PRIORITYGROUP_2      0x00000005U
#define SCB_PRIORITYGROUP_3      0x00000004U
#define SCB_PRIORITYGROUP_4      0x00000003U


#define SCB_AIRCR_PRIGROUP_POS      8U
#define SCB_AIRCR_PRIGROUP_MSK      (7UL << SCB_AIRCR_PRIGROUP_POS)

#define SCB_AIRCR_VECTKEYSTAT_POS   16U
#define SCB_AIRCR_VECTKEYSTAT_MSK   (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_POS)


/*------------ DataType Declaration Section --------------*/
typedef struct {
 volatile uint_32 CPUID;
 volatile uint_32 ICSR;
 volatile uint_32 VTOR;
 volatile uint_32 AIRCR;
 volatile uint_32 SCR;
 volatile uint_32 CCR;
 volatile uint_32 SHPR1;
 volatile uint_32 SHPR2;
 volatile uint_32 SHPR3;
 volatile uint_32 SHCSR;
 volatile uint_32 CFFSR;
}SCB_Type;
/*------------ Macro Function Declaration Section --------------*/
/*------------ Software Interfaces Section --------------*/

/*
 * brief:     set priority grouping
 * details:   set the priority grouping field using the required unlocked sequence.
 *            the parameter priorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
 *            only values from 0..7 are used.
 *            In case of a conflict between priority grouping and available
 *Param[in]:  PriorityGroup priority grouping field.
 * */
void SCB_SetpriorityGrouping(uint_32 PriorityGroup);
/*
 * brief:      Get Priority Group
 * details:    Reads the priority grouping field from the NVIC interrupt controller.
 * return:     priority grouping field (SCB->AIRCR[10:8] PRIGROUP field).
 * */
uint_32 SCB_GetpriorityGrouping(void);

#endif /* CORTEXM4_CORE_SCB_H_ */
