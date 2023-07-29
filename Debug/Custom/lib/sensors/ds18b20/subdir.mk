################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom/lib/sensors/ds18b20/ds18b20.c 

OBJS += \
./Custom/lib/sensors/ds18b20/ds18b20.o 

C_DEPS += \
./Custom/lib/sensors/ds18b20/ds18b20.d 


# Each subdirectory must supply rules for building sources it contributes
Custom/lib/sensors/ds18b20/%.o Custom/lib/sensors/ds18b20/%.su Custom/lib/sensors/ds18b20/%.cyclo: ../Custom/lib/sensors/ds18b20/%.c Custom/lib/sensors/ds18b20/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom/lib" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/conf" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/misc" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Drivers/Radio" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Custom-2f-lib-2f-sensors-2f-ds18b20

clean-Custom-2f-lib-2f-sensors-2f-ds18b20:
	-$(RM) ./Custom/lib/sensors/ds18b20/ds18b20.cyclo ./Custom/lib/sensors/ds18b20/ds18b20.d ./Custom/lib/sensors/ds18b20/ds18b20.o ./Custom/lib/sensors/ds18b20/ds18b20.su

.PHONY: clean-Custom-2f-lib-2f-sensors-2f-ds18b20

