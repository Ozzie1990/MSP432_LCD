# MSP432_LCD_EXAMPLE
This example code is to get started using an LCD screen with the Texas Instrument MSP432 Launch Pad. 

The LCD screen is one I bought on Adafruit. Links below.  I love Adafruit for there cheap and easy to use design 
boards but I don't enjoy that many development libraries are focused on Arduino.  While Arduino's are great they're very
limiting in what you can do and don't give you full control of a MCU.  

That's why I'm sharing this code.  Fair warning, I'm no expert in C coding.  I'm sure they're are ways to optimize this 
code and when I come back to this project I likely will optimize certain things.  Some quick notes:

-The gpio_support.c file is mostly ripped from the ti code gpio.c.  There are some minor differences and I've added my own 
wording that I find easier to read. <br />
-The code isn't complete, there are other functions I can add that do various other things and initializations.  I will get 
to them at some point but if you can read the code and understand what is going on you can easily add them yourself.  Just
look at the datasheet. <br />
-Follow the wiring guide for the LCD screen from Adafruit.  See link. <br />
-You'll need a pot resistor (see same link that is in the wiring guide). <br />
-I will add a schematic at some point to show how the wiring can be done and might make a PCB file in EAGLE to interface
with the LCD screen and launch pad board. <br />
-This code uses a 4 bit output mode rather than 8 bit.  Slightly more complicated timing requirements and takes more time to 
write to the screen but it's an LCD screen.  You shouldn't need to write to it that fast anyway. <br />  

Links <br />
TI: http://www.ti.com/tool/msp-exp432p401r <br />
LCD: https://www.adafruit.com/products/181 <br />
LCD Wiring: https://learn.adafruit.com/character-lcds <br />
