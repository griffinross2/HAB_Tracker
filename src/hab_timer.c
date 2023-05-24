#include "hab_timer.h"

#include "stm32wlxx_hal.h"

TIM_HandleTypeDef tim1_handle;
TIM_HandleTypeDef tim2_handle;

void init_timers(uint32_t sensor_interval_ms) {
    __HAL_RCC_TIM1_CLK_ENABLE();

    TIM_Base_InitTypeDef tim1_conf = {
        .Prescaler = __HAL_TIM_CALC_PSC(HAL_RCC_GetPCLK1Freq(), 1000000),
        .CounterMode = TIM_COUNTERMODE_UP,
        .Period = 0xFFFFFFFF - 1,
        .ClockDivision = TIM_CLOCKDIVISION_DIV1,
        .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE,
    };
    tim1_handle.Init = tim1_conf;
    tim1_handle.Instance = TIM1;
    tim1_handle.Channel = TIM_CHANNEL_1;
    TIM_ClockConfigTypeDef tim1_source_conf = {
        .ClockSource = TIM_CLOCKSOURCE_INTERNAL,
    };
    TIM_MasterConfigTypeDef tim1_master_conf = {
        .MasterOutputTrigger = TIM_TRGO_UPDATE,
    };
    HAL_TIM_Base_Init(&tim1_handle);
    HAL_TIM_ConfigClockSource(&tim1_handle, &tim1_source_conf);
    HAL_TIMEx_MasterConfigSynchronization(&tim1_handle, &tim1_master_conf);

    __HAL_RCC_TIM2_CLK_ENABLE();

    TIM_Base_InitTypeDef tim2_conf = {
        .Prescaler = 1,
        .CounterMode = TIM_COUNTERMODE_UP,
        .Period = 0xFFFF,
        .ClockDivision = TIM_CLOCKDIVISION_DIV1,
        .AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE,
    };
    tim2_handle.Init = tim2_conf;
    tim2_handle.Instance = TIM2;
    tim2_handle.Channel = TIM_CHANNEL_1;
    TIM_SlaveConfigTypeDef tim2_slave_conf = {
        .SlaveMode = TIM_SLAVEMODE_EXTERNAL1,
        .InputTrigger = TIM_TS_ITR0,
    };
    HAL_TIM_Base_Init(&tim2_handle);
    HAL_TIM_SlaveConfigSynchro(&tim2_handle, &tim2_slave_conf);

    HAL_TIM_Base_Start(&tim2_handle);
    HAL_TIM_Base_Start(&tim1_handle);
};

uint64_t MICROS() {
    uint64_t tim1_count = __HAL_TIM_GET_COUNTER(&tim1_handle);
    uint64_t tim2_count = __HAL_TIM_GET_COUNTER(&tim2_handle);
    return (tim2_count << 16) + tim1_count;
}

uint64_t MILLIS() { return MICROS() / 1000; }

void DELAY(uint16_t mS) {
    uint64_t start = MILLIS();
    while (MILLIS() < start + mS) {
    }
}

void DELAY_MICROS(uint32_t uS) {
    uint64_t start = MICROS();
    while (MICROS() < start + uS) {
    }
}