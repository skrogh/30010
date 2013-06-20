#include <sio.h>
#include <eZ8.h>
#include "input.h"
#include "joystick.h"
#define true 1
#define false 0

unsigned char inputvalues[2];

void init_input() {

}

void get_input() {
	if ( kbhit() )
		switch( getch() ) {
		case 'a':
			inputvalues[ LEFT ] = ( inputvalues[ LEFT ] == true ) ? false : true;
			inputvalues[ RIGHT ] = false;
			break;
		case 'd':
			inputvalues[ RIGHT ] = inputvalues[ RIGHT ] == true ? false : true;
			inputvalues[ LEFT ] = false;
			break;
		default:
			break;
		}
	inputvalues[ JOYSTICK_X ] = read_joystick_x();
	//compensate for extreme joystick values 
	if ( inputvalues[ JOYSTICK_X ] > 240 )
		inputvalues[ JOYSTICK_X ] = 240;
	else if ( inputvalues[ JOYSTICK_X ] < 10 )
		inputvalues[ JOYSTICK_X ] = 10;
}

void setup_input() {
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	setup_joystick();
}
