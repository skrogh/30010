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
#include "brick.h"
char flag;



void derphandler(void) {
	flag = true;
}

void check_collisions() {
}

void main() {
	char i;
	striker_t * striker = create_striker( 40, 24 );
	ball_t * ball = create_ball();
	brick_t * bricks[40];
	for ( i = 0; i < 40; i++ ) {
		bricks[ i ] = create_brick(  10 +  ( i * 4 ) % 48, 4 + i / 12, 2 );
	}
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	clrscr();
	flag = true;
	setup_input();
	setup_timer( 0, (unsigned long)60000, 2, &derphandler );

	for ( i = 0; i < 40; i++ ) {
		if ( bricks[ i ] -> lives == 0 )
			continue;
		else
			bricks[ i ] -> render( bricks[ i ]  );
	}
	while ( 1 ) {
		if ( flag ) {
			get_input();
			ball -> update( ball );
			ball -> check_collision( ball, striker, STRIKER );
			for ( i = 0; i < 40; i++ ) {
				ball -> check_collision( ball, bricks[ i ], BRICK );
			}
			ball -> render( ball );
			striker -> update( striker );
			striker -> render( striker );
			gotoxy( 10, 10 );
			printf( "      " );
			gotoxy( 10, 10 );
			printf( "%d", (unsigned char)inputvalues[ JOYSTICK_X ] );
			flag = false;
		}
	}
}
