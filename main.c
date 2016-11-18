//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#include "lcd.h"
#include "string.h"

void main(void)
{
	
	char test[30] = "Hello Ozzie";		//Adjust array length as needed

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    //****************************
    //Example of initial turn on
    //****************************
    Initialize_Outputs();		//Only needs to be called once but does not effect anything if called more than once
    //Initialize_4Bit();			//ONLY CALL ONCE AFTER POWER CYCLE.  Calling more than once will cause failure.
    Initialize_LCD_Screen();

    Write_Word(test);

	while(1) {

	}
}
