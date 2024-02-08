################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CortexM/CortexM4_Core_NVIC.c \
../Src/CortexM/CortexM4_Core_SBC.c \
../Src/CortexM/CortexM4_Core_SYSTICK.c 

OBJS += \
./Src/CortexM/CortexM4_Core_NVIC.o \
./Src/CortexM/CortexM4_Core_SBC.o \
./Src/CortexM/CortexM4_Core_SYSTICK.o 

C_DEPS += \
./Src/CortexM/CortexM4_Core_NVIC.d \
./Src/CortexM/CortexM4_Core_SBC.d \
./Src/CortexM/CortexM4_Core_SYSTICK.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CortexM/%.o Src/CortexM/%.su Src/CortexM/%.cyclo: ../Src/CortexM/%.c Src/CortexM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-CortexM

clean-Src-2f-CortexM:
	-$(RM) ./Src/CortexM/CortexM4_Core_NVIC.cyclo ./Src/CortexM/CortexM4_Core_NVIC.d ./Src/CortexM/CortexM4_Core_NVIC.o ./Src/CortexM/CortexM4_Core_NVIC.su ./Src/CortexM/CortexM4_Core_SBC.cyclo ./Src/CortexM/CortexM4_Core_SBC.d ./Src/CortexM/CortexM4_Core_SBC.o ./Src/CortexM/CortexM4_Core_SBC.su ./Src/CortexM/CortexM4_Core_SYSTICK.cyclo ./Src/CortexM/CortexM4_Core_SYSTICK.d ./Src/CortexM/CortexM4_Core_SYSTICK.o ./Src/CortexM/CortexM4_Core_SYSTICK.su

.PHONY: clean-Src-2f-CortexM

