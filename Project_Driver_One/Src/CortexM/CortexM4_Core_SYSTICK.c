/*
 * CortexM4_Core_SYSTICK.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Aya Ali
 */
#include "CortexM/CortexM4_Core_SYSTICK.h"

static ptrFunction Systick_CallBack = NULL;
static volatile uint_8 Systick_Mode = 0;

uint_8 Systick_Init(uint_32 Systick_Ticks){
	uint_8 RetVal = 0;

	if (Systick_Ticks > SYSTICK_LOAD_RELOAD_MSK){
		RetVal = 1;
	}
	else{
	CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_MSK);
	SYSTICK->LOAD = Systick_Ticks;
	SYSTICK->VAL = 0;
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV_8)
	CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_CLKSOURCE_MSK);
#elif(SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV_1)
	SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_CLKSOURCE_MSK);
#else
#error "Invalid Clock Source"

#endif
	CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_TICKINT_MSK);
	}
return RetVal;
}

void Systick_DeInit(void){
	CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_MSK);
	SYSTICK->LOAD = 0;
	SYSTICK->VAL = 0;
	CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_TICKINT_MSK);
}

void Systick_WaitBlocking(uint_32 Systick_Ticks){
	SYSTICK->LOAD = Systick_Ticks;
	SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_MSK);
	while(READ_BIT(SYSTICK->CTRL, SYSTICK_CTRL_COUNTFLAG_MSK) == 0);
    CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_MSK);
	SYSTICK->LOAD = 0;
	SYSTICK->VAL = 0;
}

void Systick_SingleInterval(uint_32 Systick_Ticks, ptrFunction *CallBack){
	if(CallBack != NULL){
		SYSTICK->LOAD = Systick_Ticks;
		Systick_CallBack = CallBack;
		Systick_Mode = SYSTICK_SINGLEINTERVAL_MODE;
		SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_TICKINT_MSK);

		SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_MSK);
		}
	else{
	   	/*Nothing*/
	}
}
void Systick_PeriodicInterval(uint_32 Systick_Ticks, ptrFunction *CallBack){
	if(CallBack != NULL){
			SYSTICK->LOAD = Systick_Ticks;
			Systick_CallBack = CallBack;
			Systick_Mode = SYSTICK_PERIODICINTERVAL_MODE;
			SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_TICKINT_MSK);
			SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_MSK);
			}
		else{
		   	/*Nothing*/
		}
}

uint_32 Systick_GetRemainingTicks(void){
	uint_32 Ramain_Ticks = 0;
	Ramain_Ticks = SYSTICK->VAL;
	return Ramain_Ticks;

}

uint_32 Systick_GetElapsedTicks(void){
	uint_32 Elapsed_Ticks = 0;
	Elapsed_Ticks = SYSTICK->LOAD - SYSTICK->VAL;
	return Elapsed_Ticks;
}

void SysTick_Handler(void){
	if(Systick_Mode == SYSTICK_SINGLEINTERVAL_MODE){
		Systick_DeInit();
	}
	if(Systick_CallBack){
		Systick_CallBack();
	}

}
