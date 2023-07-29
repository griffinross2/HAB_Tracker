#include "peripherals/one-wire/one-wire.h"
#include "hab_timer.h"
#include "stdio.h"
#include "peripherals/gpio/gpio.h"

#include "board.h"

static uint8_t onewire_state = 0; // 0 - uninitialized, 1 - normal, 2 - reset
uint8_t onewire_operation_done = 0;
uint8_t onewire_buf[ONEWIRE_MAX_LEN];

HAL_StatusTypeDef HAL_SnglWireFullDuplex_EnableRTX(UART_HandleTypeDef *huart)
{
  __HAL_LOCK(huart);
  huart->gState = HAL_UART_STATE_BUSY;

  /* Enable the USART's transmit and receive interface by setting the TE bit in the USART CR1 register */
  SET_BIT(huart->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

  huart->gState = HAL_UART_STATE_READY;

  __HAL_UNLOCK(huart);

  return HAL_OK;
}


HAL_StatusTypeDef HAL_SnglWireFullDuplex_DisableRTX(UART_HandleTypeDef *huart)
{
  __HAL_LOCK(huart);
  huart->gState = HAL_UART_STATE_BUSY;

  /* Disable both Receive and transmit by Clearing TE and RE bits */
  CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TE | USART_CR1_RE));

  huart->gState = HAL_UART_STATE_READY;

  __HAL_UNLOCK(huart);

  return HAL_OK;
}

static Status onewireSetup(OneWireDevice *dev) {
    HAL_UART_DeInit(&huart1);

    USART_TypeDef *base = USART1;
    GPIO_InitTypeDef pin_conf = {
        .Mode = GPIO_MODE_AF_OD,
        .Pull = GPIO_NOPULL,
        .Speed = GPIO_SPEED_FREQ_MEDIUM,
    };

	pin_conf.Alternate = GPIO_AF7_USART1;
	pin_conf.Pin = GPIO_PIN_TO_NUM[PIN_PA9];
	HAL_GPIO_Init(GPIOA, &pin_conf);  // Pin PA7

    UART_InitTypeDef init_conf = {
    		.BaudRate = (onewire_state > 1 ? dev->normal_speed : dev->reset_speed),
			.WordLength = UART_WORDLENGTH_8B,
			.StopBits = UART_STOPBITS_1,
			.Parity = UART_PARITY_NONE,
			.Mode = UART_MODE_TX_RX,
			.HwFlowCtl = UART_HWCONTROL_NONE,
			.OverSampling = UART_OVERSAMPLING_16,
			.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE,
			.ClockPrescaler = UART_PRESCALER_DIV1,
    };

    UART_AdvFeatureInitTypeDef adv_init_conf = {
    		.AdvFeatureInit = UART_ADVFEATURE_NO_INIT,
    };

    UART_HandleTypeDef *handle = &huart1;
    handle->Init = init_conf;
    handle->AdvancedInit = adv_init_conf;
    handle->Instance = base;
    if (HAL_HalfDuplex_Init(handle) != HAL_OK) {
        return STATUS_ERROR;
    }

    if(onewire_state > 1)
    {
    	onewire_state = 1;
    }
    else
    {
    	onewire_state = 2;
    }
    return STATUS_OK;
}

Status onewire_reset(OneWireDevice *device) {
	onewire_operation_done = 0;
	uint64_t timeout = MILLIS();

	if(onewire_state < 2) {
		if (onewireSetup(device) != STATUS_OK) {
			return STATUS_PARAMETER_ERROR;
		}
	}

	uint8_t tx_buf = 0xF0;

	if (HAL_SnglWireFullDuplex_EnableRTX(&huart1) != HAL_OK) {
		return STATUS_ERROR;
	}
    if (HAL_UART_Transmit_DMA(&huart1, &tx_buf, 1) != HAL_OK) {
        return STATUS_ERROR;
    }
    if (HAL_UART_Receive_DMA(&huart1, &tx_buf, 1) != HAL_OK) {
		return STATUS_ERROR;
	}
    while(!onewire_operation_done)
	{
		if(MILLIS() - timeout > 200)
		{
			return STATUS_TIMEOUT;
		}
	}
    onewire_operation_done = 0;

    if(tx_buf == 0xF0)
    {
    	return STATUS_ERROR;
    }

    DELAY_MICROS(150);

    return STATUS_OK;
}

Status onewire_readwrite(OneWireDevice *device, uint8_t *buf, size_t len) {
	if(ONEWIRE_MAX_LEN < len * 8)
	{
		return STATUS_PARAMETER_ERROR;
	}

	uint64_t timeout = MILLIS();

	if(onewire_state != 1) {
		if (onewireSetup(device) != STATUS_OK) {
			return STATUS_PARAMETER_ERROR;
		}
	}

	for(size_t i = 0; i < len; i++)
	{
		for(size_t j = 0; j < 8; j++)
		{
			onewire_buf[i*8 + j] = buf[i] >> j & 0x01 ? 0xFF : 0x00;
		}
	}

	if (HAL_SnglWireFullDuplex_EnableRTX(&huart1) != HAL_OK) {
		return STATUS_ERROR;
	}
	if (HAL_UART_Transmit_DMA(&huart1, onewire_buf, len * 8) != HAL_OK) {
		return STATUS_ERROR;
	}
	if (HAL_UART_Receive_DMA(&huart1, onewire_buf, len * 8) != HAL_OK) {
		return STATUS_ERROR;
	}

	while(!onewire_operation_done)
	{
		if(MILLIS() - timeout > 200)
		{
			return STATUS_TIMEOUT;
		}
	}

	onewire_operation_done = 0;
	for(size_t i = 0; i < len; i++)
	{
		buf[i] = 0;
		for(size_t j = 0; j < 8; j++)
		{
			buf[i] |= (onewire_buf[i*8 + j] == 0xFF ? 0x01 : 0x00) << j;
		}
	}
	DELAY_MICROS(150);

	return STATUS_OK;
}

void onewire_tx_callback()
{

}

void onewire_rx_callback()
{
	onewire_operation_done = 1;
}
