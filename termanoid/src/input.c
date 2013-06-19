#include <sio.h>
#include "input.h"
#include "joystick.h"
#define true 1
#define false 0

char inputvalues[2];

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
	
}

void setup_input() {
	setup_joystick();
}