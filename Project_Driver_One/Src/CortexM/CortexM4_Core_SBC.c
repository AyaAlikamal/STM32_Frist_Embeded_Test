/*
 * CortexM4_Core_SBC.c
 *
 *  Created on: Feb 2, 2024
 *      Author: Aya Ali
 */
#include "CortexM/CortexM4_Core_SCB.h"
/*
 * brief:     set priority grouping
 * details:   set the priority grouping field using the required unlocked sequence.
 *            the parameter priorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
 *            only values from 0..7 are used.
 *            In case of a conflict between priority grouping and available
 *Param[in]:  PriorityGroup priority grouping field.
 * */
void SCB_SetpriorityGrouping(uint_32 PriorityGroup){
uint_32 Register_Value = 0;
uint_32 PriorityGroupTemp = ((uint_32) PriorityGroup & (uint_32)0x07);

Register_Value = SCB->AIRCR;
Register_Value &= ~ (SCB_AIRCR_PRIGROUP_MSK | SCB_AIRCR_VECTKEYSTAT_MSK);

Register_Value = (Register_Value | ((uint_32)0x05FA <<SCB_AIRCR_VECTKEYSTAT_POS) | (PriorityGroupTemp << SCB_AIRCR_PRIGROUP_POS));
SCB->AIRCR = Register_Value;
}
/*
 * brief:      Get Priority Group
 * details:    Reads the priority grouping field from the NVIC interrupt controller.
 * return:     priority grouping field (SCB->AIRCR[10:8] PRIGROUP field).
 * */

uint_32 SCB_GetpriorityGrouping(void){

return (((uint_32)SCB->AIRCR & (uint_32)SCB_AIRCR_PRIGROUP_MSK));

}


