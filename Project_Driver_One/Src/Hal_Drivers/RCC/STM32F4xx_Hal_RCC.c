/*
 * STM32F4xx_Hal_RCC.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Aya Ali
 */
#include "Hal_Drivers/RCC/STM32F4xx_Hal_RCC.h"



HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct){
	HAL_StatusTypeDef RetStatus = HAL_OK;
	if(RCC_OscInitStruct == NULL){
		RetStatus = HAL_ERROR;
	}
	else{
		if(RCC_OscInitStruct->OscillatorType == RCC_OSCILLATORTYPE_HSE){
			if(RCC_OscInitStruct->HSEState == RCC_HSE_ON){
				CLEAR_BIT(RCC->CFGR, RCC_CFGR_SW0_MSK);

				SET_BIT(RCC->CFGR, RCC_CFGR_SW1_MSK);

				SET_BIT(RCC->CR , RCC_CR_HSEON_MSK);

			}
			else{
				CLEAR_BIT(RCC->CR, RCC_CR_HSEON_MSK);
			}

		}
		else if(RCC_OscInitStruct->OscillatorType == RCC_OSCILLATORTYPE_HSI){


		}
		else if(RCC_OscInitStruct->OscillatorType == RCC_OSCILLATORTYPE_LSE){


				}
		else if(RCC_OscInitStruct->OscillatorType == RCC_OSCILLATORTYPE_LSI){


				}
		else{
			/*Nothing*/
		}
	}

return RetStatus;
}


HAL_StatusTypeDef Hal_RCC_ClockConfig(RCC_ClkInit_Typedef *RCC_ClkInitStruct){
	HAL_StatusTypeDef RetStatus = HAL_OK;

		if(RCC_ClkInitStruct == NULL){
			RetStatus = HAL_ERROR;
		}
		else{
			MODIFY_REG(RCC->CFGR , RCC_CFGR_HPRE_MSK, RCC_ClkInitStruct->AHBCLKDriver);
			MODIFY_REG(RCC->CFGR , RCC_CFGR_PPRE1_MSK, RCC_ClkInitStruct->APB1CLKDriver);
			MODIFY_REG(RCC->CFGR , RCC_CFGR_PPRE2_MSK, RCC_ClkInitStruct->APB2CLKDriver);
		}



}
