#include <eZ8.h>s
#include <sio.h>
#include <string.h>
#include <stdlib.h>
#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"
#include "timekeeping.h"
#include "ball.h"
#include "brick.h"

char flag;



void derphandler(void) {
	flag = true;
}

void check_collisions() {
}

void main() {
	striker_t * striker = create_striker( 40, 24 );
	ball_t * ball = create_ball();
	brick_t * bricks[5];
	bricks[0] = create_brick( 5, 5, 3 );
	bricks[1] = create_brick( 9, 5, 3 );
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	clrscr();
	flag = true;
	setup_input();
	setup_timer( 0, (unsigned long)60000, 2, &derphandler );

	while ( 1 ) {
		if ( flag ) {
			get_input();
			ball -> update( ball );
			ball -> check_collision( ball, striker, STRIKER );
			ball -> render( ball );
			striker -> update( striker );
			striker -> render( striker );
			bricks[0] -> render( bricks[0] );
			bricks[1] -> render( bricks[1] );
			gotoxy( 10, 10 );
			printf( "      " );
			gotoxy( 10, 10 );
			printf( "%d", (unsigned char)inputvalues[ JOYSTICK_X ] );
			flag = false;
		}
	}
}
