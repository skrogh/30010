#include <sio.h>
#include "input.h"

#define true 1
#define false 0

char inputvalues[2];

void init_input() {

}

unsigned char get_input() {
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
}
