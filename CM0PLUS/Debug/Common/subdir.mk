################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/github_repos/HAB_Tracker/Common/gpio.c \
D:/github_repos/HAB_Tracker/Common/hab_timer.c \
D:/github_repos/HAB_Tracker/Common/i2c.c \
D:/github_repos/HAB_Tracker/Common/spi.c 

OBJS += \
./Common/gpio.o \
./Common/hab_timer.o \
./Common/i2c.o \
./Common/spi.o 

C_DEPS += \
./Common/gpio.d \
./Common/hab_timer.d \
./Common/i2c.d \
./Common/spi.d 


# Each subdirectory must supply rules for building sources it contributes
Common/gpio.o: D:/github_repos/HAB_Tracker/Common/gpio.c Common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Common/hab_timer.o: D:/github_repos/HAB_Tracker/Common/hab_timer.c Common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Common/i2c.o: D:/github_repos/HAB_Tracker/Common/i2c.c Common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Common/spi.o: D:/github_repos/HAB_Tracker/Common/spi.c Common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DCORE_CM0PLUS -DSTM32WL55xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Drivers/CMSIS/Include -I"D:/github_repos/HAB_Tracker/Common" -I"D:/github_repos/HAB_Tracker/Common/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Common

clean-Common:
	-$(RM) ./Common/gpio.cyclo ./Common/gpio.d ./Common/gpio.o ./Common/gpio.su ./Common/hab_timer.cyclo ./Common/hab_timer.d ./Common/hab_timer.o ./Common/hab_timer.su ./Common/i2c.cyclo ./Common/i2c.d ./Common/i2c.o ./Common/i2c.su ./Common/spi.cyclo ./Common/spi.d ./Common/spi.o ./Common/spi.su

.PHONY: clean-Common

