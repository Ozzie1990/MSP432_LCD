/*
 * GPIO_Support.c
 *
 *  Created on: Nov 2, 2016
 *      Author: Ozzie
 */

#include "msp.h"
#include "gpio_support.h"

//****************************
//Holds base address for various ports
//****************************
static uint32_t Port_Base_Address[] = {
		PERIPHERAL_BASE + (uint32_t)PORT1_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT2_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT3_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT4_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT5_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT6_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT7_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT8_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT9_BASE,
		PERIPHERAL_BASE + (uint32_t)PORT10_BASE,
		PERIPHERAL_BASE + (uint32_t)PORTJ_BASE
};

//****************************
//Set Port#-Pin# as a GPIO output
//****************************
void GPIO_Set_Output(int port_number, uint16_t pin_number) {
	uint32_t port = Port_Base_Address[port_number];

	REG_16(port + (uint32_t)GPIO_SEL0_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_SEL1_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_DIR_OFFSET) |= pin_number;
}

//****************************
//Set Port#-Pin# as a GPIO input
//****************************
void GPIO_Set_Input(int port_number, uint16_t pin_number) {
	uint32_t port = Port_Base_Address[port_number];

	REG_16(port + (uint32_t)GPIO_SEL0_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_SEL1_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_DIR_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_RES_EN_OFFSET) &= ~pin_number;
}

//****************************
//Toggle GPIO pin
//****************************
void GPIO_Toggle_Output(int port_number, uint16_t pin_number) {
	uint32_t port = Port_Base_Address[port_number];

	REG_16(port + (uint32_t)GPIO_OUT_OFFSET) ^= pin_number;
}

//****************************
//Set GPIO pin as high or low
//****************************
void GPIO_Output_Bit(int port_number, uint16_t pin_number, int bit_level) {
	uint32_t port = Port_Base_Address[port_number];

	if(bit_level == OUT_HIGH) {
		REG_16(port + (uint32_t)GPIO_OUT_OFFSET) |= pin_number;
	} else if(bit_level == OUT_LOW) {
		REG_16(port + (uint32_t)GPIO_OUT_OFFSET) &= ~pin_number;
	}
}

//****************************
//Set Port#-Pin# as a GPIO input w/ a pullup resistor
//****************************
void GPIO_Set_withInput_Pullup_Resistor(int port_number, uint16_t pin_number) {
	uint32_t port = Port_Base_Address[port_number];

	REG_16(port + (uint32_t)GPIO_SEL0_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_SEL1_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_DIR_OFFSET) &= ~pin_number;
	REG_16(port + (uint32_t)GPIO_RES_EN_OFFSET) |= pin_number;
	REG_16(port + (uint32_t)GPIO_OUT_OFFSET) |= pin_number;
}

//****************************
//Enable Port#-Pin# interrupt
//****************************
void GPIO_Enable_Interrupt(int port_number, uint16_t pin_number) {
	uint32_t port = Port_Base_Address[port_number];

	REG_16(port + (uint32_t)GPIO_INT_EN_OFFSET) ^= pin_number;
}

//****************************
//Clear Port#-Pin# interrupt flag
//****************************
void GPIO_Clear_Interrupt_Flag(int port_number, uint16_t pin_number) {
	uint32_t port = Port_Base_Address[port_number];

	REG_16(port + (uint32_t)GPIO_INT_FG_OFFSET) &= ~pin_number;
}
