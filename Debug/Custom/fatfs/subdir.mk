################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom/fatfs/ff.c \
../Custom/fatfs/ffsystem.c \
../Custom/fatfs/ffunicode.c \
../Custom/fatfs/sd.c \
../Custom/fatfs/sd_spi.c 

OBJS += \
./Custom/fatfs/ff.o \
./Custom/fatfs/ffsystem.o \
./Custom/fatfs/ffunicode.o \
./Custom/fatfs/sd.o \
./Custom/fatfs/sd_spi.o 

C_DEPS += \
./Custom/fatfs/ff.d \
./Custom/fatfs/ffsystem.d \
./Custom/fatfs/ffunicode.d \
./Custom/fatfs/sd.d \
./Custom/fatfs/sd_spi.d 


# Each subdirectory must supply rules for building sources it contributes
Custom/fatfs/%.o Custom/fatfs/%.su Custom/fatfs/%.cyclo: ../Custom/fatfs/%.c Custom/fatfs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom/lib" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/conf" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/misc" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Drivers/Radio" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Custom-2f-fatfs

clean-Custom-2f-fatfs:
	-$(RM) ./Custom/fatfs/ff.cyclo ./Custom/fatfs/ff.d ./Custom/fatfs/ff.o ./Custom/fatfs/ff.su ./Custom/fatfs/ffsystem.cyclo ./Custom/fatfs/ffsystem.d ./Custom/fatfs/ffsystem.o ./Custom/fatfs/ffsystem.su ./Custom/fatfs/ffunicode.cyclo ./Custom/fatfs/ffunicode.d ./Custom/fatfs/ffunicode.o ./Custom/fatfs/ffunicode.su ./Custom/fatfs/sd.cyclo ./Custom/fatfs/sd.d ./Custom/fatfs/sd.o ./Custom/fatfs/sd.su ./Custom/fatfs/sd_spi.cyclo ./Custom/fatfs/sd_spi.d ./Custom/fatfs/sd_spi.o ./Custom/fatfs/sd_spi.su

.PHONY: clean-Custom-2f-fatfs

