################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/github_repos/HAB_Tracker/Common/lib/sensors/ms5637/ms5637.c \
D:/github_repos/HAB_Tracker/Common/lib/sensors/ms5637/ms5637_model.c 

OBJS += \
./Common/lib/sensors/ms5637/ms5637.o \
./Common/lib/sensors/ms5637/ms5637_model.o 

C_DEPS += \
./Common/lib/sensors/ms5637/ms5637.d \
./Common/lib/sensors/ms5637/ms5637_model.d 


# Each subdirectory must supply rules for building sources it contributes
Common/lib/sensors/ms5637/ms5637.o: D:/github_repos/HAB_Tracker/Common/lib/sensors/ms5637/ms5637.c Common/lib/sensors/ms5637/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Common/lib/sensors/ms5637/ms5637_model.o: D:/github_repos/HAB_Tracker/Common/lib/sensors/ms5637/ms5637_model.c Common/lib/sensors/ms5637/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Common-2f-lib-2f-sensors-2f-ms5637

clean-Common-2f-lib-2f-sensors-2f-ms5637:
	-$(RM) ./Common/lib/sensors/ms5637/ms5637.cyclo ./Common/lib/sensors/ms5637/ms5637.d ./Common/lib/sensors/ms5637/ms5637.o ./Common/lib/sensors/ms5637/ms5637.su ./Common/lib/sensors/ms5637/ms5637_model.cyclo ./Common/lib/sensors/ms5637/ms5637_model.d ./Common/lib/sensors/ms5637/ms5637_model.o ./Common/lib/sensors/ms5637/ms5637_model.su

.PHONY: clean-Common-2f-lib-2f-sensors-2f-ms5637

