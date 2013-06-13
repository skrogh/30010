#include <gpio.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "LED.h"

#define true 1
#define false 0


void main() {
	char * displayString = "Hej mor se mig jeg er paa LEDerne! ";
	char stringpos = 0;
	int counter = 0, shiftcounter = 0;
	char strLength = getStringLength( displayString );
	//set up the uart
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	LEDsetString( displayString, 0, strLength );
	LEDinit(); // set up the leds
	while( 1 ) {
		LEDupdate(); // update leds (checks for timer flag)
		//manage scrolling speeds, define const macros later
		if ( counter > 5000 ) {
			shiftBuffer();
			counter = 0;
			shiftcounter++;
		}
		if ( shiftcounter > 5 ) {
			stringpos++;
			LEDsetString( displayString, stringpos, strLength );
			shiftcounter = 0;
		}

		if ( stringpos > strLength - 1 )
			stringpos = 0;

		counter++;
	}

}
