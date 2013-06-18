#include <eZ8.h>
#include <sio.h>
#include <string.h>
#include <stdlib.h>
#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"
#include "timekeeping.h"
#include "ball.h"
char flag;



void derphandler(void) {
	flag = true;
}

void check_collisions() {
}

void main() {
	striker_t * striker = create_striker( 40, 24 );
	ball_t * ball = create_ball();

	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	clrscr();
	flag = true;
	setup_timer( 0, (unsigned long)66666, 2, &derphandler );

	while ( 1 ) {
		get_input();
		if ( flag ) {
			ball -> update( ball );
			ball -> check_collision( ball, striker, STRIKER );
			ball -> render( ball );
			striker -> update( striker );
			striker -> render( striker );
			flag = false;
		}
	}
}
