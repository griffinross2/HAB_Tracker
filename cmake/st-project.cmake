# THIS FILE IS AUTOMATICALLY GENERATED. DO NOT EDIT.
# BASED ON c:\Users\griff\STM32CubeIDE\workspace_1.11.2\HAB_Tracker_new

function(add_st_target_properties TARGET_NAME)

target_compile_definitions(
    ${TARGET_NAME} PRIVATE
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:ASM>>:DEBUG>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:DEBUG>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:CORE_CM4>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:USE_HAL_DRIVER>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:STM32WLE5xx>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:CORE_CM4>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:USE_HAL_DRIVER>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:STM32WLE5xx>"
)

target_include_directories(
    ${TARGET_NAME} PRIVATE
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Core\\Inc>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\STM32WLxx_HAL_Driver\\Inc>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\STM32WLxx_HAL_Driver\\Inc\\Legacy>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Device\\ST\\STM32WLxx\\Include>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Include>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/LoRaWAN\\App>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/LoRaWAN\\Target>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\trace\\adv_trace>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\misc>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\sequencer>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\timer>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\lpm\\tiny_lpm>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\LmHandler\\Packages>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Crypto>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Mac>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\LmHandler>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Utilities>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\SubGHz_Phy>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\SubGHz_Phy\\stm32_radio_driver>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Core\\Inc>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\STM32WLxx_HAL_Driver\\Inc>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\STM32WLxx_HAL_Driver\\Inc\\Legacy>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Device\\ST\\STM32WLxx\\Include>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Include>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/LoRaWAN\\App>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/LoRaWAN\\Target>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\trace\\adv_trace>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\misc>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\sequencer>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\timer>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Utilities\\lpm\\tiny_lpm>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\LmHandler\\Packages>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Crypto>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Mac>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\LmHandler>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\LoRaWAN\\Utilities>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\SubGHz_Phy>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Middlewares\\Third_Party\\SubGHz_Phy\\stm32_radio_driver>"
)

target_compile_options(
    ${TARGET_NAME} PRIVATE
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:ASM>>:-g3>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g3>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g3>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:ASM>>:-g0>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:-g0>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:-g0>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:-Os>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:-Os>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:>"
    "$<$<CONFIG:Debug>:-mcpu=cortex-m4>"
    "$<$<NOT:$<CONFIG:Debug>>:-mcpu=cortex-m4>"
)

target_link_libraries(
    ${TARGET_NAME} PRIVATE
)

target_link_directories(
    ${TARGET_NAME} PRIVATE
)

target_link_options(
    ${TARGET_NAME} PRIVATE
    "$<$<CONFIG:Debug>:-mcpu=cortex-m4>"
    "$<$<NOT:$<CONFIG:Debug>>:-mcpu=cortex-m4>"
    -T
    "$<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/STM32WLE5CCUX_FLASH.ld>"
    "$<$<NOT:$<CONFIG:Debug>>:${PROJECT_SOURCE_DIR}/STM32WLE5CCUX_FLASH.ld>"
)

target_sources(
    ${TARGET_NAME} PRIVATE
    "Custom\\lib\\aprs\\AFSK.c"
    "Custom\\lib\\aprs\\APRS.c"
    "Custom\\lib\\aprs\\BitFIFO.c"
    "Custom\\lib\\aprs\\IntFIFO.c"
    "Custom\\lib\\gps\\max_m10s.c"
    "Custom\\lib\\radio\\hx1\\hx1.c"
    "Custom\\lib\\radio\\lora\\lora.c"
    "Custom\\lib\\sensors\\iis2mdc\\iis2mdc.c"
    "Custom\\lib\\sensors\\lsm6dsox\\lsm6dsox.c"
    "Custom\\lib\\sensors\\ms5637\\ms5637_model.c"
    "Custom\\lib\\sensors\\ms5637\\ms5637.c"
    "Core\\Src\\gpio.c"
    "Core\\Src\\hab_program.c"
    "Core\\Src\\hab_timer.c"
    "Core\\Src\\i2c.c"
    "Core\\Src\\main.c"
    "Core\\Src\\spi.c"
    "Core\\Src\\stm32_adv_trace_if.c"
    "Core\\Src\\stm32_lpm_if.c"
    "Core\\Src\\stm32wlxx_hal_msp.c"
    "Core\\Src\\stm32wlxx_it.c"
    "Core\\Src\\sys_app.c"
    "Core\\Src\\syscalls.c"
    "Core\\Src\\sysmem.c"
    "Core\\Src\\system_stm32wlxx.c"
    "Core\\Src\\timer_if.c"
    "Core\\Startup\\startup_stm32wle5ccux.s"
    "LoRaWAN\\App\\app_lorawan.c"
    "LoRaWAN\\App\\lora_app.c"
    "LoRaWAN\\App\\lora_info.c"
    "LoRaWAN\\Target\\radio_board_if.c"
    "Utilities\\lpm\\tiny_lpm\\stm32_lpm.c"
    "Utilities\\misc\\stm32_mem.c"
    "Utilities\\misc\\stm32_systime.c"
    "Utilities\\misc\\stm32_tiny_sscanf.c"
    "Utilities\\misc\\stm32_tiny_vsnprintf.c"
    "Utilities\\sequencer\\stm32_seq.c"
    "Utilities\\timer\\stm32_timer.c"
    "Utilities\\trace\\adv_trace\\stm32_adv_trace.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Crypto\\cmac.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Crypto\\lorawan_aes.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Crypto\\soft-se.c"
    "Middlewares\\Third_Party\\LoRaWAN\\LmHandler\\LmHandler.c"
    "Middlewares\\Third_Party\\LoRaWAN\\LmHandler\\NvmDataMgmt.c"
    "Middlewares\\Third_Party\\LoRaWAN\\LmHandler\\Packages\\LmhpCompliance.c"
    "Middlewares\\Third_Party\\LoRaWAN\\LmHandler\\Packages\\LmhpPackagesRegistration.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMac.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMacAdr.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMacClassB.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMacCommands.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMacConfirmQueue.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMacCrypto.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMacParser.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\LoRaMacSerializer.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\Region.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionAS923.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionAU915.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionBaseUS.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionCN470.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionCN470A20.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionCN470A26.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionCN470B20.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionCN470B26.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionCN779.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionCommon.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionEU433.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionEU868.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionIN865.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionKR920.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionRU864.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Mac\\Region\\RegionUS915.c"
    "Middlewares\\Third_Party\\LoRaWAN\\Utilities\\utilities.c"
    "Middlewares\\Third_Party\\SubGHz_Phy\\stm32_radio_driver\\radio_driver.c"
    "Middlewares\\Third_Party\\SubGHz_Phy\\stm32_radio_driver\\radio_fw.c"
    "Middlewares\\Third_Party\\SubGHz_Phy\\stm32_radio_driver\\radio.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_cortex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_dac_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_dac.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_dma_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_dma.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_exti.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_flash_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_flash.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_gpio.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_i2c_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_i2c.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_lptim.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_pwr_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_pwr.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_rcc_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_rcc.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_spi_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_spi.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_subghz.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_tim_ex.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal_tim.c"
    "Drivers\\STM32WLxx_HAL_Driver\\Src\\stm32wlxx_hal.c"
)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${TARGET_NAME}>
)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex
    $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.hex
)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary
    $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.bin
)

endfunction()