################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Apps/led/led.c 

OBJS += \
./Apps/led/led.o 

C_DEPS += \
./Apps/led/led.d 


# Each subdirectory must supply rules for building sources it contributes
Apps/led/%.o Apps/led/%.su Apps/led/%.cyclo: ../Apps/led/%.c Apps/led/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Embedded/Embedded_SW/Stm32_cube/01_Blink/Apps/led" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Apps-2f-led

clean-Apps-2f-led:
	-$(RM) ./Apps/led/led.cyclo ./Apps/led/led.d ./Apps/led/led.o ./Apps/led/led.su

.PHONY: clean-Apps-2f-led

