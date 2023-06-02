################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/github_repos/HAB_Tracker/Common/lib/sensors/lsm6dsox/lsm6dsox.c 

OBJS += \
./Common/lib/sensors/lsm6dsox/lsm6dsox.o 

C_DEPS += \
./Common/lib/sensors/lsm6dsox/lsm6dsox.d 


# Each subdirectory must supply rules for building sources it contributes
Common/lib/sensors/lsm6dsox/lsm6dsox.o: D:/github_repos/HAB_Tracker/Common/lib/sensors/lsm6dsox/lsm6dsox.c Common/lib/sensors/lsm6dsox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Common-2f-lib-2f-sensors-2f-lsm6dsox

clean-Common-2f-lib-2f-sensors-2f-lsm6dsox:
	-$(RM) ./Common/lib/sensors/lsm6dsox/lsm6dsox.cyclo ./Common/lib/sensors/lsm6dsox/lsm6dsox.d ./Common/lib/sensors/lsm6dsox/lsm6dsox.o ./Common/lib/sensors/lsm6dsox/lsm6dsox.su

.PHONY: clean-Common-2f-lib-2f-sensors-2f-lsm6dsox

