#ifndef MCU_DIGITAL_H_INCLUDED
#define MCU_DIGITAL_H_INCLUDED

#include "include/mcu32_memory_map.h"
#include "periphery/gpio.h"

#include <stdbool.h>

#include "mcu_core.h"


typedef enum {
	GPIO_HIGH = 1, GPIO_LOW = 0
} GPIO_PinState;

GPIO_PinState GPIO_PinRead(GPIO_TypeDef *gpio, uint32_t gpioNum);


void GPIO_PinWrite(GPIO_TypeDef *gpio, uint32_t gpioNum, GPIO_PinState state);


void GPIO_PinToggle(GPIO_TypeDef *gpio, uint32_t gpioNum);


typedef enum {
	GPIO_DIR_OUTPUT = 1, GPIO_DIR_INPUT = 0
} GPIO_PinDirection;

void GPIO_SetPinDirection(GPIO_TypeDef *gpio, uint32_t gpioNum, GPIO_PinDirection dir);

void GPIO_SetPinMaskDirection(GPIO_TypeDef *gpio, uint32_t mask, GPIO_PinDirection dir);


typedef enum {
	GPIO_LINE_0 = 0,
	GPIO_LINE_1 = 1,
	GPIO_LINE_2 = 2,
	GPIO_LINE_3 = 3,
	GPIO_LINE_4 = 4,
	GPIO_LINE_5 = 5,
	GPIO_LINE_6 = 6,
	GPIO_LINE_7 = 7,
} GPIO_Line;

typedef enum {
	/*
	GPIO_MUX_GPIO_0_0_LINE_0 = 0,
	GPIO_MUX_GPIO_0_8_LINE_0 = 1,
	GPIO_MUX_GPIO_1_0_LINE_0 = 2,
	GPIO_MUX_GPIO_1_8_LINE_0 = 3,
	GPIO_MUX_GPIO_2_0_LINE_0 = 4,
	GPIO_MUX_GPIO_0_4_LINE_0 = 5,
	GPIO_MUX_GPIO_0_12_LINE_0 = 6,
	GPIO_MUX_GPIO_1_4_LINE_0 = 7,
	GPIO_MUX_GPIO_1_12_LINE_0 = 8,
	GPIO_MUX_GPIO_2_4_LINE_0 = 9,

	GPIO_MUX_GPIO_0_1_LINE_1 = 0,
	GPIO_MUX_GPIO_0_9_LINE_1 = 1,
	GPIO_MUX_GPIO_1_1_LINE_1 = 2,
	GPIO_MUX_GPIO_1_9_LINE_1 = 3,
	GPIO_MUX_GPIO_2_1_LINE_1 = 4,
	GPIO_MUX_GPIO_0_5_LINE_1 = 5,
	GPIO_MUX_GPIO_0_13_LINE_1 = 6,
	GPIO_MUX_GPIO_1_5_LINE_1 = 7,
	GPIO_MUX_GPIO_1_13_LINE_1 = 8,
	GPIO_MUX_GPIO_2_5_LINE_1 = 9,

	GPIO_MUX_GPIO_0_2_LINE_2 = 0,
	GPIO_MUX_GPIO_0_10_LINE_2 = 1,
	GPIO_MUX_GPIO_1_2_LINE_2 = 2,
	GPIO_MUX_GPIO_1_10_LINE_2 = 3,
	GPIO_MUX_GPIO_2_2_LINE_2 = 4,
	GPIO_MUX_GPIO_0_6_LINE_2 = 5,
	GPIO_MUX_GPIO_0_14_LINE_2 = 6,
	GPIO_MUX_GPIO_1_6_LINE_2 = 7,
	GPIO_MUX_GPIO_1_14_LINE_2 = 8,
	GPIO_MUX_GPIO_2_6_LINE_2 = 9,

	GPIO_MUX_GPIO_0_3_LINE_3 = 0,
	GPIO_MUX_GPIO_0_11_LINE_3 = 1,
	GPIO_MUX_GPIO_1_3_LINE_3 = 2,
	GPIO_MUX_GPIO_1_11_LINE_3 = 3,
	GPIO_MUX_GPIO_2_3_LINE_3 = 4,
	GPIO_MUX_GPIO_0_7_LINE_3 = 5,
	GPIO_MUX_GPIO_0_15_LINE_3 = 6,
	GPIO_MUX_GPIO_1_7_LINE_3 = 7,
	GPIO_MUX_GPIO_1_15_LINE_3 = 8,
	GPIO_MUX_GPIO_2_7_LINE_3 = 9,

	GPIO_MUX_GPIO_0_4_LINE_4 = 0,
	GPIO_MUX_GPIO_0_12_LINE_4 = 1,
	GPIO_MUX_GPIO_1_4_LINE_4 = 2,
	GPIO_MUX_GPIO_1_12_LINE_4 = 3,
	GPIO_MUX_GPIO_2_4_LINE_4 = 4,
	GPIO_MUX_GPIO_0_0_LINE_4 = 5,
	GPIO_MUX_GPIO_0_8_LINE_4 = 6,
	GPIO_MUX_GPIO_1_0_LINE_4 = 7,
	GPIO_MUX_GPIO_1_8_LINE_4 = 8,
	GPIO_MUX_GPIO_2_0_LINE_4 = 9,

	GPIO_MUX_GPIO_0_5_LINE_5 = 0,
	GPIO_MUX_GPIO_0_13_LINE_5 = 1,
	GPIO_MUX_GPIO_1_5_LINE_5 = 2,
	GPIO_MUX_GPIO_1_13_LINE_5 = 3,
	GPIO_MUX_GPIO_2_5_LINE_5 = 4,
	GPIO_MUX_GPIO_0_1_LINE_5 = 5,
	GPIO_MUX_GPIO_0_9_LINE_5 = 6,
	GPIO_MUX_GPIO_1_1_LINE_5 = 7,
	GPIO_MUX_GPIO_1_9_LINE_5 = 8,
	GPIO_MUX_GPIO_2_1_LINE_5 = 9,

	GPIO_MUX_GPIO_0_6_LINE_6 = 0,
	GPIO_MUX_GPIO_0_14_LINE_6 = 1,
	GPIO_MUX_GPIO_1_6_LINE_6 = 2,
	GPIO_MUX_GPIO_1_14_LINE_6 = 3,
	GPIO_MUX_GPIO_2_6_LINE_6 = 4,
	GPIO_MUX_GPIO_0_2_LINE_6 = 5,
	GPIO_MUX_GPIO_0_10_LINE_6 = 6,
	GPIO_MUX_GPIO_1_2_LINE_6 = 7,
	GPIO_MUX_GPIO_1_10_LINE_6 = 8,
	GPIO_MUX_GPIO_2_2_LINE_6 = 9,

	GPIO_MUX_GPIO_0_7_LINE_7 = 0,
	GPIO_MUX_GPIO_0_15_LINE_7 = 1,
	GPIO_MUX_GPIO_1_7_LINE_7 = 2,
	GPIO_MUX_GPIO_1_15_LINE_7 = 3,
	GPIO_MUX_GPIO_2_7_LINE_7 = 4,
	GPIO_MUX_GPIO_0_3_LINE_7 = 5,
	GPIO_MUX_GPIO_0_11_LINE_7 = 6,
	GPIO_MUX_GPIO_1_3_LINE_7 = 7,
	GPIO_MUX_GPIO_1_11_LINE_7 = 8,
	GPIO_MUX_GPIO_2_3_LINE_7 = 9,
	*/


	GPIO_MUX_LINE_0_GPIO_0_0 = 0,
	GPIO_MUX_LINE_0_GPIO_0_8 = 1,
	GPIO_MUX_LINE_0_GPIO_1_0 = 2,
	GPIO_MUX_LINE_0_GPIO_1_8 = 3,
	GPIO_MUX_LINE_0_GPIO_2_0 = 4,
	GPIO_MUX_LINE_0_GPIO_0_4 = 5,
	GPIO_MUX_LINE_0_GPIO_0_12 = 6,
	GPIO_MUX_LINE_0_GPIO_1_4 = 7,
	GPIO_MUX_LINE_0_GPIO_1_12 = 8,
	GPIO_MUX_LINE_0_GPIO_2_4 = 9,

	GPIO_MUX_LINE_1_GPIO_0_1 = 0,
	GPIO_MUX_LINE_1_GPIO_0_9 = 1,
	GPIO_MUX_LINE_1_GPIO_1_1 = 2,
	GPIO_MUX_LINE_1_GPIO_1_9 = 3,
	GPIO_MUX_LINE_1_GPIO_2_1 = 4,
	GPIO_MUX_LINE_1_GPIO_0_5 = 5,
	GPIO_MUX_LINE_1_GPIO_0_13 = 6,
	GPIO_MUX_LINE_1_GPIO_1_5 = 7,
	GPIO_MUX_LINE_1_GPIO_1_13 = 8,
	GPIO_MUX_LINE_1_GPIO_2_5 = 9,

	GPIO_MUX_LINE_2_GPIO_0_2 = 0,
	GPIO_MUX_LINE_2_GPIO_0_10 = 1,
	GPIO_MUX_LINE_2_GPIO_1_2 = 2,
	GPIO_MUX_LINE_2_GPIO_1_10 = 3,
	GPIO_MUX_LINE_2_GPIO_2_2 = 4,
	GPIO_MUX_LINE_2_GPIO_0_6 = 5,
	GPIO_MUX_LINE_2_GPIO_0_14 = 6,
	GPIO_MUX_LINE_2_GPIO_1_6 = 7,
	GPIO_MUX_LINE_2_GPIO_1_14 = 8,
	GPIO_MUX_LINE_2_GPIO_2_6 = 9,

	GPIO_MUX_LINE_3_GPIO_0_3 = 0,
	GPIO_MUX_LINE_3_GPIO_0_11 = 1,
	GPIO_MUX_LINE_3_GPIO_1_3 = 2,
	GPIO_MUX_LINE_3_GPIO_1_11 = 3,
	GPIO_MUX_LINE_3_GPIO_2_3 = 4,
	GPIO_MUX_LINE_3_GPIO_0_7 = 5,
	GPIO_MUX_LINE_3_GPIO_0_15 = 6,
	GPIO_MUX_LINE_3_GPIO_1_7 = 7,
	GPIO_MUX_LINE_3_GPIO_1_15 = 8,
	GPIO_MUX_LINE_3_GPIO_2_7 = 9,

	GPIO_MUX_LINE_4_GPIO_0_4 = 0,
	GPIO_MUX_LINE_4_GPIO_0_12 = 1,
	GPIO_MUX_LINE_4_GPIO_1_4 = 2,
	GPIO_MUX_LINE_4_GPIO_1_12 = 3,
	GPIO_MUX_LINE_4_GPIO_2_4 = 4,
	GPIO_MUX_LINE_4_GPIO_0_0 = 5,
	GPIO_MUX_LINE_4_GPIO_0_8 = 6,
	GPIO_MUX_LINE_4_GPIO_1_0 = 7,
	GPIO_MUX_LINE_4_GPIO_1_8 = 8,
	GPIO_MUX_LINE_4_GPIO_2_0 = 9,

	GPIO_MUX_LINE_5_GPIO_0_5 = 0,
	GPIO_MUX_LINE_5_GPIO_0_13 = 1,
	GPIO_MUX_LINE_5_GPIO_1_5 = 2,
	GPIO_MUX_LINE_5_GPIO_1_13 = 3,
	GPIO_MUX_LINE_5_GPIO_2_5 = 4,
	GPIO_MUX_LINE_5_GPIO_0_1 = 5,
	GPIO_MUX_LINE_5_GPIO_0_9 = 6,
	GPIO_MUX_LINE_5_GPIO_1_1 = 7,
	GPIO_MUX_LINE_5_GPIO_1_9 = 8,
	GPIO_MUX_LINE_5_GPIO_2_1 = 9,

	GPIO_MUX_LINE_6_GPIO_0_6 = 0,
	GPIO_MUX_LINE_6_GPIO_0_14 = 1,
	GPIO_MUX_LINE_6_GPIO_1_6 = 2,
	GPIO_MUX_LINE_6_GPIO_1_14 = 3,
	GPIO_MUX_LINE_6_GPIO_2_6 = 4,
	GPIO_MUX_LINE_6_GPIO_0_2 = 5,
	GPIO_MUX_LINE_6_GPIO_0_10 = 6,
	GPIO_MUX_LINE_6_GPIO_1_2 = 7,
	GPIO_MUX_LINE_6_GPIO_1_10 = 8,
	GPIO_MUX_LINE_6_GPIO_2_2 = 9,

	GPIO_MUX_LINE_7_GPIO_0_7 = 0,
	GPIO_MUX_LINE_7_GPIO_0_15 = 1,
	GPIO_MUX_LINE_7_GPIO_1_7 = 2,
	GPIO_MUX_LINE_7_GPIO_1_15 = 3,
	GPIO_MUX_LINE_7_GPIO_2_7 = 4,
	GPIO_MUX_LINE_7_GPIO_0_3 = 5,
	GPIO_MUX_LINE_7_GPIO_0_11 = 6,
	GPIO_MUX_LINE_7_GPIO_1_3 = 7,
	GPIO_MUX_LINE_7_GPIO_1_11 = 8,
	GPIO_MUX_LINE_7_GPIO_2_3 = 9,

	GPIO_MUX_LINE0 = 10
} GPIO_Line_Mux;

#define GPIO_MODE_BIT_LEVEL 1
#define GPIO_MODE_BIT_EDGE 2
#define GPIO_MODE_BIT_ANYEDGE 4

typedef enum {
	GPIO_MODE_LOW = 0b000,
	GPIO_MODE_HIGH = 0b001,
	GPIO_MODE_FALLING = 0b010,
	GPIO_MODE_RISING = 0b011,
	GPIO_MODE_CHANGE = 0b100
} GPIO_InterruptMode;

void GPIO_InitInterruptLine(GPIO_Line irq_line, GPIO_Line_Mux mux,
		GPIO_InterruptMode mode);

void GPIO_DeInitInterruptLine(GPIO_Line irq_line);

bool GPIO_LineInterruptState(GPIO_Line irq_line);

bool GPIO_LinePinState(GPIO_Line irq_line);

void GPIO_ClearInterrupt();

void GPIO_EnableInterrupts();

void GPIO_DisableInterrupts();


#endif
