################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Radio/lr_fhss_mac.c \
../Drivers/Radio/radio.c \
../Drivers/Radio/radio_board_if.c \
../Drivers/Radio/radio_driver.c \
../Drivers/Radio/radio_fw.c \
../Drivers/Radio/subghz_phy_app.c \
../Drivers/Radio/wl_lr_fhss.c 

OBJS += \
./Drivers/Radio/lr_fhss_mac.o \
./Drivers/Radio/radio.o \
./Drivers/Radio/radio_board_if.o \
./Drivers/Radio/radio_driver.o \
./Drivers/Radio/radio_fw.o \
./Drivers/Radio/subghz_phy_app.o \
./Drivers/Radio/wl_lr_fhss.o 

C_DEPS += \
./Drivers/Radio/lr_fhss_mac.d \
./Drivers/Radio/radio.d \
./Drivers/Radio/radio_board_if.d \
./Drivers/Radio/radio_driver.d \
./Drivers/Radio/radio_fw.d \
./Drivers/Radio/subghz_phy_app.d \
./Drivers/Radio/wl_lr_fhss.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Radio/%.o Drivers/Radio/%.su Drivers/Radio/%.cyclo: ../Drivers/Radio/%.c Drivers/Radio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32WLE5xx -c -I../Core/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc -I../Drivers/STM32WLxx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../Drivers/CMSIS/Include -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Custom/lib" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/conf" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Utilities/misc" -I"C:/Users/griff/STM32CubeIDE/workspace_1.11.2/HAB_Tracker_new/Drivers/Radio" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Radio

clean-Drivers-2f-Radio:
	-$(RM) ./Drivers/Radio/lr_fhss_mac.cyclo ./Drivers/Radio/lr_fhss_mac.d ./Drivers/Radio/lr_fhss_mac.o ./Drivers/Radio/lr_fhss_mac.su ./Drivers/Radio/radio.cyclo ./Drivers/Radio/radio.d ./Drivers/Radio/radio.o ./Drivers/Radio/radio.su ./Drivers/Radio/radio_board_if.cyclo ./Drivers/Radio/radio_board_if.d ./Drivers/Radio/radio_board_if.o ./Drivers/Radio/radio_board_if.su ./Drivers/Radio/radio_driver.cyclo ./Drivers/Radio/radio_driver.d ./Drivers/Radio/radio_driver.o ./Drivers/Radio/radio_driver.su ./Drivers/Radio/radio_fw.cyclo ./Drivers/Radio/radio_fw.d ./Drivers/Radio/radio_fw.o ./Drivers/Radio/radio_fw.su ./Drivers/Radio/subghz_phy_app.cyclo ./Drivers/Radio/subghz_phy_app.d ./Drivers/Radio/subghz_phy_app.o ./Drivers/Radio/subghz_phy_app.su ./Drivers/Radio/wl_lr_fhss.cyclo ./Drivers/Radio/wl_lr_fhss.d ./Drivers/Radio/wl_lr_fhss.o ./Drivers/Radio/wl_lr_fhss.su

.PHONY: clean-Drivers-2f-Radio

