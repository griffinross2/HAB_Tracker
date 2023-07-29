################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom/lib/sensors/iis2mdc/iis2mdc.c 

OBJS += \
./Custom/lib/sensors/iis2mdc/iis2mdc.o 

C_DEPS += \
./Custom/lib/sensors/iis2mdc/iis2mdc.d 


# Each subdirectory must supply rules for building sources it contributes
Custom/lib/sensors/iis2mdc/%.o Custom/lib/sensors/iis2mdc/%.su Custom/lib/sensors/iis2mdc/%.cyclo: ../Custom/lib/sensors/iis2mdc/%.c Custom/lib/sensors/iis2mdc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom/lib" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/conf" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/misc" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Drivers/Radio" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Custom-2f-lib-2f-sensors-2f-iis2mdc

clean-Custom-2f-lib-2f-sensors-2f-iis2mdc:
	-$(RM) ./Custom/lib/sensors/iis2mdc/iis2mdc.cyclo ./Custom/lib/sensors/iis2mdc/iis2mdc.d ./Custom/lib/sensors/iis2mdc/iis2mdc.o ./Custom/lib/sensors/iis2mdc/iis2mdc.su

.PHONY: clean-Custom-2f-lib-2f-sensors-2f-iis2mdc

