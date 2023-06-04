################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom/lib/radio/hx1/hx1.c 

OBJS += \
./Custom/lib/radio/hx1/hx1.o 

C_DEPS += \
./Custom/lib/radio/hx1/hx1.d 


# Each subdirectory must supply rules for building sources it contributes
Custom/lib/radio/hx1/%.o Custom/lib/radio/hx1/%.su Custom/lib/radio/hx1/%.cyclo: ../Custom/lib/radio/hx1/%.c Custom/lib/radio/hx1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../LoRaWAN/App -I../LoRaWAN/Target -I../Utilities/trace/adv_trace -I../Utilities/misc -I../Utilities/sequencer -I../Utilities/timer -I../Utilities/lpm/tiny_lpm -I../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../Middlewares/Third_Party/LoRaWAN/Crypto -I../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../Middlewares/Third_Party/LoRaWAN/Mac -I../Middlewares/Third_Party/LoRaWAN/LmHandler -I../Middlewares/Third_Party/LoRaWAN/Utilities -I../Middlewares/Third_Party/SubGHz_Phy -I../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Custom-2f-lib-2f-radio-2f-hx1

clean-Custom-2f-lib-2f-radio-2f-hx1:
	-$(RM) ./Custom/lib/radio/hx1/hx1.cyclo ./Custom/lib/radio/hx1/hx1.d ./Custom/lib/radio/hx1/hx1.o ./Custom/lib/radio/hx1/hx1.su

.PHONY: clean-Custom-2f-lib-2f-radio-2f-hx1

