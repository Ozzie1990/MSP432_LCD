/*
 * lcd.c
 *
 *  Created on: Nov 12, 2016
 *      Author: Ozzie
 */

#include "msp.h"
#include "gpio_support.h"
#include "lcd.h"


//****************************
//Enable LCD Outputs
//****************************
void Enable_LCD_Outputs() {
	GPIO_Set_Output(RS_PORT, RS_PIN);	//RS
	GPIO_Set_Output(EN_PORT, EN_PIN);	//E

	GPIO_Set_Output(PORT5, PIN6);	//D4
	GPIO_Set_Output(PORT2, PIN4);	//D5
	GPIO_Set_Output(PORT2, PIN6);	//D6
	GPIO_Set_Output(PORT2, PIN7);	//D7
}

//****************************
//Ports used for data transfer
//****************************
static int Port_Data[] = {
		PORT2,
		PORT2,
		PORT2,
		PORT5
};

//****************************
//Pins used for data transfer
//****************************
static uint16_t Pin_Data[] = {
		PIN7,
		PIN6,
		PIN4,
		PIN6
};

//****************************
//Write output data to D7-D4
//and toggle enable bit
//****************************
void Write_Output_Data(uint8_t data) {
	uint8_t temp = 128;
	int i;
	int j;
	for(j = 0; j < 2; j++) {
		for(i = 0; i < 4; i++) {
			if((temp & data) == 0x00) {
				GPIO_Output_Bit(Port_Data[i], Pin_Data[i], OUT_LOW);
			} else {
				GPIO_Output_Bit(Port_Data[i], Pin_Data[i], OUT_HIGH);
			}
			temp = temp >> 1;
		}
		Data_Ready_To_Write();
	}
}

//****************************
//Write for only once enable cycle to set 4bit functionality
//
//Call only once after turn on.
//****************************
void Write_4Bit_Function_Set(uint8_t data) {
	uint8_t temp = 128;
	int i;
	int j;
	for(i = 0; i < 4; i++) {
		if((temp & data) == 0x00) {
			GPIO_Output_Bit(Port_Data[i], Pin_Data[i], OUT_LOW);
		} else {
			GPIO_Output_Bit(Port_Data[i], Pin_Data[i], OUT_HIGH);
		}
		temp = temp >> 1;
	}
	Data_Ready_To_Write();
}

//****************************
//Data ready to write
//
//Enable bit set high then delayed
//then enable bit set low then delayed
//Delay is necessary since MSP432 moves to fast
//
//Could read busy bit from LCD rather than waiting
//but this is simpler and for most projects will be fine
//****************************
void Data_Ready_To_Write() {
	Set_Enable_Bit_High();
	LCD_Delay();
	Set_Enable_Bit_Low();
	LCD_Delay();
}

//****************************
//Set enable bit high
//****************************
void Set_Enable_Bit_High() {
	GPIO_Output_Bit(EN_PORT, EN_PIN, OUT_HIGH);
}

//****************************
//Set enable bit low
//****************************
void Set_Enable_Bit_Low() {
	GPIO_Output_Bit(EN_PORT, EN_PIN, OUT_LOW);
}

//****************************
//Set RS bit high
//
//Used for writing letters to screen
//****************************
void Set_RS_Bit_High() {
	GPIO_Output_Bit(RS_PORT, RS_PIN, OUT_HIGH);
}

//****************************
//Set RS bit low
//
//Used for write commands to screen
//****************************
void Set_RS_Bit_Low() {
	GPIO_Output_Bit(RS_PORT, RS_PIN, OUT_LOW);
}

//****************************
//Initialize Outputs
//
//Only needs to be called once but does not harm anything if called more than once
//but calling it will cause unneeded delays to your project
//****************************
void Initialize_Outputs() {
	Enable_LCD_Outputs();
}

//****************************
//Initialize 4 bit mode
//
//ONLY CALL ONCE AFTER TURN ON!!!  Calling more than once will cause problems
//Be sure this is only called after your screen has recycled power
//During debugging call this one and then comment out
//****************************
void Initialize_4Bit() {
	Set_RS_Bit_Low();
	Write_4Bit_Function_Set(LCD_4_BIT);
}

//****************************
//Initialize LCD Screen
//****************************
void Initialize_LCD_Screen() {
	Set_RS_Bit_Low();
	Write_Output_Data(LCD_4_BIT);

	//Probably can simplify this down but had some problems and this method worked best
	//Will do some more tests but is a minor optimization
	Write_Output_Data(LCD_DISPLAY_OFF);
	Write_Output_Data(LCD_DISPLAY_CLEAR);
	Write_Output_Data(LCD_DISPLAY_ON);

	Write_Output_Data(LCD_ENTRY_MODE_SET);
}

//****************************
//Clear LCD Screen
//****************************
void Clear_LCD_Screen() {
	Set_RS_Bit_Low();
	Write_Output_Data(LCD_DISPLAY_CLEAR);
}

//****************************
//Shift the cursor left by "num" times
//****************************
void Cursor_Shift_Left(int num) {
	Set_RS_Bit_Low();
	int i;
	for(i = 0; i < num; i++) {
		Write_Output_Data(LCD_CURSOR_LEFT);
	}
}

//****************************
//Shift the cursor right by "num" times
//****************************
void Cursor_Shift_Right(int num) {
	Set_RS_Bit_Low();
	int i;
	for(i = 0; i < num; i++) {
		Write_Output_Data(LCD_CURSOR_RIGHT);
	}
}

//****************************
//Shift the display left by "num" times
//****************************
void Display_Shift_Left(int num) {
	Set_RS_Bit_Low();
	int i;
	for(i = 0; i < num; i++) {
		Write_Output_Data(LCD_DISPLAY_LEFT);
	}
}

//****************************
//Shift the display right by "num" times
//****************************
void Display_Shift_Right(int num) {
	Set_RS_Bit_Low();
	int i;
	for(i = 0; i < num; i++) {
		Write_Output_Data(LCD_DISPLAY_RIGHT);
	}
}

//****************************
//Set cursor position
//
//Row 0 is line 1 and Row 1 is line 2
//****************************
void Set_Cursor_Position(int row, int col) {
	Set_RS_Bit_Low();
	if(row == 0) {
		Write_Output_Data((LCD_LINE_1 + (uint8_t)col));
	} else if(row = 1) {
		Write_Output_Data((LCD_LINE_2 + (uint8_t)col));
	}
}

//****************************
//Write only one letter with the input
//of a uint8_t, not a char
//****************************
void Write_Letter(uint8_t letter) {
	Set_RS_Bit_High();
	Write_Output_Data(letter);
}

//****************************
//Write an entire word
//****************************
void Write_Word(char word[]) {
	int length = strlen(word);
	int i;
	Set_RS_Bit_High();
	for(i = 0; i < length; i++) {
		Write_Output_Data((uint8_t)word[i]);
	}
}

//****************************
//Delay needed for LCD screen to process inputs
//****************************
void LCD_Delay() {
	int i;
	for(i = 0; i < 200; i++) { }
}

//****************************
//A delay I randomly use for effect
//No real purpose
//****************************
void Dramatic_Delay() {
	int i;
	for(i = 0; i < 100000; i++) { }
}
