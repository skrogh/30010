#include <eZ8.h>
#include <sio.h>
#include <string.h>
#include <stdlib.h>
#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"
#include "timekeeping.h"

char flag;

void derphandler(void) {
	flag = true;
}

void main() {
	striker_t * striker = create_striker( 40, 25 );
	
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	clrscr();
	flag = true;
	setup_timer( 0, (unsigned long)66666, 2, &derphandler );
	
	while ( 1 ) {
		get_input();
		if ( flag ) {
			striker -> update( striker );
			striker -> render( striker );
			flag = false;
		}
	}
}
