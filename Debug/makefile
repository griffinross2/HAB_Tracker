################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/misc/subdir.mk
-include Drivers/STM32WLxx_HAL_Driver/Src/subdir.mk
-include Drivers/Radio/subdir.mk
-include Custom/lib/sensors/ms5637/subdir.mk
-include Custom/lib/sensors/lsm6dsox/subdir.mk
-include Custom/lib/sensors/iis2mdc/subdir.mk
-include Custom/lib/sensors/ds18b20/subdir.mk
-include Custom/lib/gps/subdir.mk
-include Custom/lib/aprs/subdir.mk
-include Custom/fatfs/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := HAB_Tracker_new
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
HAB_Tracker_new.elf \

MAP_FILES += \
HAB_Tracker_new.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
HAB_Tracker_new.list \


# All Target
all: main-build

# Main-build Target
main-build: HAB_Tracker_new.elf secondary-outputs

# Tool invocations
HAB_Tracker_new.elf HAB_Tracker_new.map: $(OBJS) $(USER_OBJS) C:\Users\griff\STM32CubeIDE\workspace_1.11.2\HAB_Tracker_new\STM32WLE5CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "HAB_Tracker_new.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\griff\STM32CubeIDE\workspace_1.11.2\HAB_Tracker_new\STM32WLE5CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="HAB_Tracker_new.map" -Wl,--gc-sections -Wl,--verbose -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

HAB_Tracker_new.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "HAB_Tracker_new.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) HAB_Tracker_new.elf HAB_Tracker_new.list HAB_Tracker_new.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
