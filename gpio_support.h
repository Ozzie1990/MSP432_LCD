/*
 * gpio_support.h
 *
 *  Created on: Nov 18, 2016
 *      Author: Ozzie
 */

#ifndef GPIO_SUPPORT_H_
#define GPIO_SUPPORT_H_

//****************************
//Functions used to write to memory
//****************************
#define REG_8(x)         	(*((volatile uint8_t *)(x)))
#define REG_16(x)        	(*((volatile uint16_t *)(x)))
#define REG_32(x)        	(*((volatile uint32_t *)(x)))

//****************************
//Pin numbers used for Port1 thru PortJ
//****************************
#define PIN0                                                      (0x0001)
#define PIN1                                                      (0x0002)
#define PIN2                                                      (0x0004)
#define PIN3                                                      (0x0008)
#define PIN4                                                      (0x0010)
#define PIN5                                                      (0x0020)
#define PIN6                                                      (0x0040)
#define PIN7                                                      (0x0080)
#define PIN8                                                      (0x0100)
#define PIN9                                                      (0x0200)
#define PIN10                                                     (0x0400)
#define PIN11                                                     (0x0800)
#define PIN12                                                     (0x1000)
#define PIN13                                                     (0x2000)
#define PIN14                                                     (0x4000)
#define PIN15                                                     (0x8000)

//****************************
//Port array address integers, values held in gpio_support.c
//****************************
#define PORT1				0
#define PORT2				1
#define PORT3				2
#define PORT4				3
#define PORT5				4
#define PORT6				5
#define PORT7				6
#define PORT8				7
#define PORT9				8
#define PORT10				9
#define PORTJ				10

//****************************
//Base address for base and the offset for various ports
//****************************
#define PERIPHERAL_BASE		0x40004C00
#define PORT1_BASE			0x0000
#define PORT2_BASE			0x0001
#define PORT3_BASE			0x0020
#define PORT4_BASE			0x0021
#define PORT5_BASE			0x0040
#define PORT6_BASE			0x0041
#define PORT7_BASE			0x0060
#define PORT8_BASE			0x0061
#define PORT9_BASE			0x0080
#define PORT10_BASE			0x0081
#define PORTJ_BASE			0x0120

//****************************
//Offset value for GPIO
//****************************
#define GPIO_IN_OFFSET			0x0000	//GPIO Input Set
#define GPIO_OUT_OFFSET			0x0002	//GPIO Output set
#define GPIO_DIR_OFFSET			0x0004	//GPIO Direction set (1 = output, 0 = input)
#define GPIO_SEL0_OFFSET			0x000A	//GPIO Select bit, used to select type of output/input
#define GPIO_SEL1_OFFSET			0x000C	//GPIO Select bit, used to select type of output/input
#define GPIO_RES_EN_OFFSET		0x0006	//GPIO Resistor enable
#define GPIO_COM_SEL_OFFSET		0x0016	//GPIO Complement Selection (No idea what this does)
#define GPIO_INTED_SEL_OFFSET	0x0018	//GPIO Interrupt Edge Select
#define GPIO_INT_EN_OFFSET		0x001A	//GPIO Interrupt Enable
#define GPIO_INT_FG_OFFSET		0x001C	//GPIO Interrupt Flag
#define GPIO_ODD_INT_VCTR		0x000E	//GPIO Odd numbered port interrupt vector (PORT1, PORT3, etc)
#define GPIO_EVN_INT_VCTR		0x001E	//GPIO Even numbered port interrupt vector (PORT2, PORT4, etc)

//****************************
//Values for high or low GPIO output
//****************************
#define OUT_HIGH 	1
#define OUT_LOW		0



#endif /* GPIO_SUPPORT_H_ */
