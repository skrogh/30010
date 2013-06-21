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
	//reset inputs that are only valid for one update cycle
	inputvalues[ ACTION_BUTTON ] = false;

	//get keyboard input
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
		case 's':
			inputvalues[ ACTION_BUTTON ] = true;
			break;
		default:
			break;
		}

	//get joystick input
	inputvalues[ JOYSTICK_X ] = read_joystick_x();
	//compensate for extreme joystick values 
	if ( inputvalues[ JOYSTICK_X ] > 240 )
		inputvalues[ JOYSTICK_X ] = 240;
	else if ( inputvalues[ JOYSTICK_X ] < 10 )
		inputvalues[ JOYSTICK_X ] = 10;
}

void setup_input() {
	//UART is used for both input and output but is initialized here
	init_uart( _UART0, _DEFFREQ, BAUD_115200 );
	setup_joystick();
}
