################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom/lib/aprs/AFSK.c \
../Custom/lib/aprs/APRS.c \
../Custom/lib/aprs/BitFIFO.c \
../Custom/lib/aprs/IntFIFO.c 

OBJS += \
./Custom/lib/aprs/AFSK.o \
./Custom/lib/aprs/APRS.o \
./Custom/lib/aprs/BitFIFO.o \
./Custom/lib/aprs/IntFIFO.o 

C_DEPS += \
./Custom/lib/aprs/AFSK.d \
./Custom/lib/aprs/APRS.d \
./Custom/lib/aprs/BitFIFO.d \
./Custom/lib/aprs/IntFIFO.d 


# Each subdirectory must supply rules for building sources it contributes
Custom/lib/aprs/%.o Custom/lib/aprs/%.su Custom/lib/aprs/%.cyclo: ../Custom/lib/aprs/%.c Custom/lib/aprs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I../LoRaWAN/App -I../LoRaWAN/Target -I../Utilities/trace/adv_trace -I../Utilities/misc -I../Utilities/sequencer -I../Utilities/timer -I../Utilities/lpm/tiny_lpm -I../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../Middlewares/Third_Party/LoRaWAN/Crypto -I../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../Middlewares/Third_Party/LoRaWAN/Mac -I../Middlewares/Third_Party/LoRaWAN/LmHandler -I../Middlewares/Third_Party/LoRaWAN/Utilities -I../Middlewares/Third_Party/SubGHz_Phy -I../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Custom-2f-lib-2f-aprs

clean-Custom-2f-lib-2f-aprs:
	-$(RM) ./Custom/lib/aprs/AFSK.cyclo ./Custom/lib/aprs/AFSK.d ./Custom/lib/aprs/AFSK.o ./Custom/lib/aprs/AFSK.su ./Custom/lib/aprs/APRS.cyclo ./Custom/lib/aprs/APRS.d ./Custom/lib/aprs/APRS.o ./Custom/lib/aprs/APRS.su ./Custom/lib/aprs/BitFIFO.cyclo ./Custom/lib/aprs/BitFIFO.d ./Custom/lib/aprs/BitFIFO.o ./Custom/lib/aprs/BitFIFO.su ./Custom/lib/aprs/IntFIFO.cyclo ./Custom/lib/aprs/IntFIFO.d ./Custom/lib/aprs/IntFIFO.o ./Custom/lib/aprs/IntFIFO.su

.PHONY: clean-Custom-2f-lib-2f-aprs

