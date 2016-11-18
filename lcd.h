/*
 * lcd.h
 *
 *  Created on: Nov 12, 2016
 *      Author: Ozzie
 */

#ifndef LCD_H_
#define LCD_H_

//****************************
//Enable port and pin
//Currently set to PORT3 and PIN5
//****************************
#define EN_PORT		2
#define EN_PIN		0x0020

//****************************
//RS port and pin
//Currently set to PORT3 and PIN7
//****************************
#define RS_PORT		2
#define RS_PIN		0x0080

//****************************
//Shift the cursor left by "num" times
//****************************
#define LCD_4_BIT				0x28		//LCD 4 bit mode
#define LCD_DISPLAY_ON			0x0F		//Display on with blinking
#define LCD_DISPLAY_ON_NB		0x0E		//Display on w/o blinking
#define LCD_ENTRY_MODE_SET		0x06		//Entry mode
#define LCD_DISPLAY_OFF			0x08		//Display off
#define LCD_DISPLAY_CLEAR		0x01		//Display clear
#define LCD_CURSOR_LEFT			0x10		//Move cursor left
#define LCD_CURSOR_RIGHT			0x14		//Move cursor right
#define LCD_DISPLAY_LEFT			0x18		//Move display left
#define LCD_DISPLAY_RIGHT		0x1C		//Move display right
#define LCD_LINE_1				0x80		//Line 1's address
#define LCD_LINE_2				0xC0		//Line 2's address


#endif /* LCD_H_ */
