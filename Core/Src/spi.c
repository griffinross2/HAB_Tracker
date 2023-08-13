#include "peripherals/spi/spi.h"

#include "board.h"
#include "peripherals/gpio/gpio.h"
#include "stdio.h"
#include "hab_timer.h"

static uint8_t spi_state[] = {0};
static SPI_HandleTypeDef* spi_handles[] = {&hspi1};

static uint8_t cs_pin[4] = {PIN_PA4, 0, 0, 0};

Status spi_setup(SpiDevice* dev) {
    if (dev->periph < 0 || dev->periph > 3) {
        return STATUS_PARAMETER_ERROR;
    }
    if (spi_state[dev->periph] != 0) {
        return STATUS_OK;
    }
    SPI_TypeDef* base = NULL;
    GPIO_InitTypeDef pin_conf = {
        .Mode = GPIO_MODE_AF_PP,
        .Pull = GPIO_NOPULL,
        .Speed = GPIO_SPEED_FREQ_LOW,
    };
    switch (dev->periph) {
        case P_SPI1:
            base = SPI1;
            pin_conf.Alternate = GPIO_AF5_SPI1;
            pin_conf.Pin = GPIO_PIN_TO_NUM[PIN_PA5] | GPIO_PIN_TO_NUM[PIN_PA6] |
                           GPIO_PIN_TO_NUM[PIN_PA7];  // SCK: pin PA5, MISO: pin
                                                      // PA6, MOSI: pin PA7
            gpio_write(cs_pin[0], GPIO_HIGH);         // NSS: pin PA4
            HAL_GPIO_DeInit(GPIOA, pin_conf.Pin);
            HAL_GPIO_Init(GPIOA, &pin_conf);
            HAL_GPIO_LockPin(GPIOA, pin_conf.Pin);
            break;
        case P_SPI2:
            return STATUS_PARAMETER_ERROR;
            break;
        case P_SPI3:
            return STATUS_PARAMETER_ERROR;
            break;
        case P_SPI4:
            return STATUS_PARAMETER_ERROR;
            break;
    }
    uint32_t prescale = 0;
    switch (dev->clk) {
        case SPI_SPEED_100kHz:
            prescale = SPI_BAUDRATEPRESCALER_256;
            break;
        case SPI_SPEED_500kHz:
            prescale = SPI_BAUDRATEPRESCALER_128;
            break;
        case SPI_SPEED_1MHz:
            prescale = SPI_BAUDRATEPRESCALER_64;
            break;
        case SPI_SPEED_2MHz:
			prescale = SPI_BAUDRATEPRESCALER_32;
			break;
        case SPI_SPEED_10MHz:
            prescale = SPI_BAUDRATEPRESCALER_8;
            break;
        case SPI_SPEED_20MHz:
            prescale = SPI_BAUDRATEPRESCALER_4;
            break;
        default:
            return STATUS_PARAMETER_ERROR;
    }
    SPI_InitTypeDef init_conf = {
        .BaudRatePrescaler = prescale,
        .CLKPhase = dev->cpha ? SPI_PHASE_2EDGE : SPI_PHASE_1EDGE,
        .CLKPolarity = dev->cpol ? SPI_POLARITY_HIGH : SPI_POLARITY_LOW,
        .NSS = SPI_NSS_SOFT,
        .Mode = SPI_MODE_MASTER,
        .Direction = SPI_DIRECTION_2LINES,
        .FirstBit = SPI_FIRSTBIT_MSB,
        .DataSize = SPI_DATASIZE_8BIT,
        .TIMode = SPI_TIMODE_DISABLE,
        .CRCCalculation = SPI_CRCCALCULATION_DISABLE,
        .CRCLength = SPI_CRC_LENGTH_DATASIZE,
        .NSSPMode = SPI_NSS_PULSE_DISABLE,
    };
    SPI_HandleTypeDef* handle = spi_handles[dev->periph];
    (*handle).Init = init_conf;
    (*handle).Instance = base;
    if (HAL_SPI_Init(handle) != HAL_OK) {
        return STATUS_ERROR;
    }

    spi_state[dev->periph] = 1;
    return STATUS_OK;
}

Status spi_set_cs(SpiDevice* dev, GpioValue val) {
    return gpio_write(cs_pin[dev->periph], val);
}

Status spi_exchange_nosetup(SpiDevice* dev, uint8_t* tx_buf, uint8_t* rx_buf,
                            uint16_t len) {
    if (HAL_SPI_TransmitReceive(spi_handles[dev->periph], tx_buf, rx_buf, len,
                                100) != HAL_OK) {
        return STATUS_HARDWARE_ERROR;
    }
    return STATUS_OK;
}

Status spi_exchange(SpiDevice* dev, uint8_t* tx_buf, uint8_t* rx_buf,
                    uint16_t len) {
    if (spi_setup(dev) != STATUS_OK) {
        return STATUS_PARAMETER_ERROR;
    }
    gpio_write(cs_pin[dev->periph], GPIO_LOW);
    if (spi_exchange_nosetup(dev, tx_buf, rx_buf, len) != STATUS_OK) {
        gpio_write(cs_pin[dev->periph], GPIO_HIGH);
        return STATUS_HARDWARE_ERROR;
    }
    gpio_write(cs_pin[dev->periph], GPIO_HIGH);
    return STATUS_OK;
}

SPI_HandleTypeDef* get_handle(SpiDevice* dev) {
    return spi_handles[dev->periph];
}
