/*
 * CortexM4_Core_NVIC.c
 *
 *  Created on: Feb 2, 2024
 *      Author: Aya Ali
 */
#include <CortexM/CortexM4_Core_NVIC.h>


void NVIC_EnableIRQ(IRQn_Type IRQn){

	if((uint_32)IRQn >= 0){
		NVIC->ISER[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1F));
	}
	else{
		return 0UL;
	}
}
void NVIC_DisableIRQ(IRQn_Type IRQn){

	if((uint_32)IRQn >= 0){
		NVIC->ICER[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1F)); //[] for choosing the register number and =() for choosing the number of bits.
	}
	else{

		}
}
void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	if((uint_32)IRQn >= 0){
		NVIC->ISPR[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1F)); //[] for choosing the register number and =() for choosing the number of bits.
		}
	else{

		}

}
void NVIC_ClearPendingIRQ(IRQn_Type IRQn){
	if((uint_32)IRQn >= 0){
		NVIC->ICPR[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1F)); //[] for choosing the register number and =() for choosing the number of bits.
		}
	else{

		}
}
uint_32 NVIC_GetActive(IRQn_Type IRQn){
	if((uint_32)IRQn >= 0){
	return((NVIC->IABR[((uint_32)IRQn) >> 5] &(1UL << ((uint_32)IRQn) & 0x1F))) != ((uint_32)0) ? 1UL: 0UL; //[] for choosing the register number and =() for choosing the number of bits.
	}
	else{
		return 0UL;
	}
}


/*
 * brief:    set the interrupt priority.
 * details:  set the priority of a device specific interrupt or processor exceptions.
 *           the interrupt number can be positive to specify a device specific interrupt.
 *           or negative to specify a processor exception.
 *Param[in]: IRQn interrupt number.
 *Param[in]: priority priority to set.
 *note:      the priority can not be set for every processor exception.
 * */
void NVIC_SetPriority(IRQn_Type IRQn, uint_32 priority){
	if((uint_32)IRQn >= 0){
		NVIC->IP[(uint_32)IRQn] = (uint_8)((priority << (8U - NVIC_PRIO_BITS)) & (uint_32)0xFF);
	}
	else{
		return 0UL;
	}
}

/*
 * brief:   Get interrupt Priority.
 * details: Reads the priority of a device specification interrupt or a processor exceptions.
 *          the interrupt number can be positive to specify a device specific interrupt.
 *          or negative to specify a processor exception.
 * Param[in]: IRQn Interrupt number.
 * return:    interrupt priority.
 *             value is aligned automatically to the implemented priority bit.
 * */

uint_32 NVIC_GetPriority(IRQn_Type IRQn){
	if((uint_32)IRQn >= 0){
			return ((NVIC->IP[(uint_32)IRQn]));
		}
		else{

		}
}

