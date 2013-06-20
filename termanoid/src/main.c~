#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"
#include "timekeeping.h"
#include "ball.h"
#include "brick.h"

char flag;
char game_state;

void derphandler(void) {
	flag = true;
}

void check_collisions() {
}

void draw_borders() {
	int i;
	gotoxy( 1, 1 );
	for ( i = 1; i < SCREEN_WIDTH; i++ ) {
		draw_char( '=', 0x70 );
	}
	for ( i = 1; i < SCREEN_HEIGHT; i++ ) {
		gotoxy( SCREEN_WIDTH, i );
		draw_char( '|', 0x70 );
	}
	for ( i = 1; i < SCREEN_HEIGHT; i++ ) {
		gotoxy( 1, i );
		draw_char( '|', 0x70 );
	}
}

void main() {
	char i;
	striker_t * striker = create_striker( 40, 24 );
	ball_t * ball = create_ball();
	brick_t * bricks[30];
	setup_input();
	for ( i = 0; i < 30; i++ ) {
		bricks[ i ] = create_brick(  (int)10 +  ( (int)(i * 4) ) % 40, 4 + i / 10, 2 );
	}
	reset_term();
	clrscr();
	draw_whole_bg();
	flag = true;
	setup_timer( 0, (unsigned long)33333, 2, &derphandler );

	draw_borders();
	for ( i = 0; i < 30; i++ ) {
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
			for ( i = 0; i < 30; i++ ) {
				ball -> check_collision( ball, bricks[ i ], BRICK );
			}
			ball -> render( ball );
			striker -> update( striker );
			striker -> render( striker );
			flag = false;
		}
	}
}
