#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"
#include "timekeeping.h"
#include "ball.h"
#include "brick.h"
#include "backgrounds.h"
#define NUM_BRICKS 15

char flag;
enum {SPLASH_SCREEN, MENU, PLAYING };
char game_state;

void update_handler(void) {
	flag = true;
}

void check_collisions() {
}

void draw_borders() {
	int i;
	gotoxy( 1, 1 );
	for ( i = 1; i < SCREEN_WIDTH; i++ ) {
		draw_char_bg( '=', 0x70 );
	}
	for ( i = 1; i <= SCREEN_HEIGHT; i++ ) {
		gotoxy( SCREEN_WIDTH, i );
		draw_char_bg( '|', 0x70 );
	}
	for ( i = 1; i <= SCREEN_HEIGHT; i++ ) {
		gotoxy( 1, i );
		draw_char_bg( '|', 0x70 );
	} 
}

void main() {
	unsigned char i;
	unsigned char j;
	striker_t * striker = create_striker( 40, SCREEN_HEIGHT );
	ball_t * ball = create_ball();
	brick_t * bricks[8];

	setup_input();
	setup_timer( 0, (unsigned long)33333, 2, &update_handler );


	reset_term();
	clrscr();
	game_state = SPLASH_SCREEN;
	set_background( start_splash );
	draw_whole_bg();

	while ( 1 ) {
		if ( flag ) {
			get_input();
			if ( inputvalues[ ACTION_BUTTON ] == true )
				break;
		}
	}

	set_monochrome( true );
	draw_whole_bg();
	
	for ( i = 0; i < 8; i++ ) {
		bricks[ i ] = create_brick( (int)( i * BRICK_WIDTH ) % (int)60 + (int)10, 4 + i / 15, 16 );
	}

	draw_borders();
	for ( i = 0; i < 8; i++ ) {
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
			for ( i = 0; i < 8; i++ ) {
				ball -> check_collision( ball, bricks[ i ], BRICK );
			}
			ball -> render( ball );
			striker -> update( striker );
			striker -> render( striker );
			flag = false;
		}
	}
}
