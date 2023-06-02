################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/github_repos/HAB_Tracker/Common/lib/gps/max_m10s.c 

OBJS += \
./Common/lib/gps/max_m10s.o 

C_DEPS += \
./Common/lib/gps/max_m10s.d 


# Each subdirectory must supply rules for building sources it contributes
Common/lib/gps/max_m10s.o: D:/github_repos/HAB_Tracker/Common/lib/gps/max_m10s.c Common/lib/gps/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Common-2f-lib-2f-gps

clean-Common-2f-lib-2f-gps:
	-$(RM) ./Common/lib/gps/max_m10s.cyclo ./Common/lib/gps/max_m10s.d ./Common/lib/gps/max_m10s.o ./Common/lib/gps/max_m10s.su

.PHONY: clean-Common-2f-lib-2f-gps

