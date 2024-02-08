################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Hal_Drivers/RCC/STM32F4xx_Hal_RCC.c 

OBJS += \
./Src/Hal_Drivers/RCC/STM32F4xx_Hal_RCC.o 

C_DEPS += \
./Src/Hal_Drivers/RCC/STM32F4xx_Hal_RCC.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Hal_Drivers/RCC/%.o Src/Hal_Drivers/RCC/%.su Src/Hal_Drivers/RCC/%.cyclo: ../Src/Hal_Drivers/RCC/%.c Src/Hal_Drivers/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Hal_Drivers-2f-RCC

clean-Src-2f-Hal_Drivers-2f-RCC:
	-$(RM) ./Src/Hal_Drivers/RCC/STM32F4xx_Hal_RCC.cyclo ./Src/Hal_Drivers/RCC/STM32F4xx_Hal_RCC.d ./Src/Hal_Drivers/RCC/STM32F4xx_Hal_RCC.o ./Src/Hal_Drivers/RCC/STM32F4xx_Hal_RCC.su

.PHONY: clean-Src-2f-Hal_Drivers-2f-RCC

