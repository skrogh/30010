#include <gpio.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

#define true 1
#define false 0

char[5][6] video_buffer;

void main() {

	//set up the uart
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );

	while( 1 ) {}

}
