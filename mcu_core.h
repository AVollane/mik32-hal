#ifndef FPGA_MCU_CORE_H_INCLUDED
#define FPGA_MCU_CORE_H_INCLUDED

#include "csr.h"
#include "scr1_csr_encoding.h"

#include "include/mcu32_memory_map.h"
#include "periphery/pad_config.h"
#include "periphery/epic.h"
#include "periphery/gpio.h"
#include "periphery/gpio_irq.h"

#include <stdbool.h>


#ifndef FREQ
#define FREQ 10000000
#endif


__attribute__ ((weak)) void TIMER32_0_TRAP_HANDLER();
__attribute__ ((weak)) void UART_0_TRAP_HANDLER();
__attribute__ ((weak)) void UART_1_TRAP_HANDLER();
__attribute__ ((weak)) void SPI_0_TRAP_HANDLER();
__attribute__ ((weak)) void SPI_1_TRAP_HANDLER();
__attribute__ ((weak)) void GPIO_IRQ_TRAP_HANDLER();
__attribute__ ((weak)) void I2C_0_TRAP_HANDLER();
__attribute__ ((weak)) void I2C_1_TRAP_HANDLER();
__attribute__ ((weak)) void WDT_TRAP_HANDLER();
__attribute__ ((weak)) void TIMER16_0_TRAP_HANDLER();
__attribute__ ((weak)) void TIMER16_1_TRAP_HANDLER();
__attribute__ ((weak)) void TIMER16_2_TRAP_HANDLER();
__attribute__ ((weak)) void TIMER32_1_TRAP_HANDLER();
__attribute__ ((weak)) void TIMER32_2_TRAP_HANDLER();
__attribute__ ((weak)) void EEPROM_TRAP_HANDLER();
__attribute__ ((weak)) void SPIFI_TRAP_HANDLER();
__attribute__ ((weak)) void RTC_TRAP_HANDLER();
__attribute__ ((weak)) void WDT_DOM3_TRAP_HANDLER();
__attribute__ ((weak)) void WDT_SPIFI_TRAP_HANDLER();
__attribute__ ((weak)) void WDT_EEPROM_TRAP_HANDLER();
__attribute__ ((weak)) void DMA_GLB_ERR_TRAP_HANDLER();
__attribute__ ((weak)) void DMA_CHANNELS_TRAP_HANDLER();
__attribute__ ((weak)) void FREQ_MON_TRAP_HANDLER();
__attribute__ ((weak)) void PVD_AVCC_TRAP_UNDER_HANDLER();
__attribute__ ((weak)) void PVD_AVCC_TRAP_OVER_HANDLER();
__attribute__ ((weak)) void PVD_VCC_TRAP_UNDER_HANDLER();
__attribute__ ((weak)) void PVD_VCC_TRAP_OVER_HANDLER();
__attribute__ ((weak)) void BATTERY_NON_GOOD_TRAP_HANDLER();
__attribute__ ((weak)) void BOR_TRAP_HANDLER();
__attribute__ ((weak)) void TSENS_TRAP_HANDLER();
__attribute__ ((weak)) void ADC_TRAP_HANDLER();
__attribute__ ((weak)) void PROG_TRAP_HANDLER();


typedef enum {
	PIN_FUNCTION_0 = 0,
	PIN_FUNCTION_1 = 1,
	PIN_FUNCTION_2 = 2,
	PIN_FUNCTION_MAIN = 0,
	PIN_FUNCTION_GPIO = 1,
	PIN_FUNCTION_ALT = 2
} PadConfigFunction;

bool setPinFunction(GPIO_TypeDef *gpio, uint32_t gpioId, PadConfigFunction func);

bool setPortFunction(GPIO_TypeDef *gpio, PadConfigFunction func);


void enableInterrupts();

void disableInterrupts();


#endif /* FPGA_MCU_CORE_H_INCLUDED */
