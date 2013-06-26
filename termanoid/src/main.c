
#include <sio.h>
#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"
#include "timekeeping.h"
#include "ball.h"
#include "brick.h"

#include "backgrounds.h"
#include "levels.h"
#define NUM_BRICKS 15
#define LEVEL_CHANGE_DELAY 100 


char flag;
enum {SPLASH_SCREEN, MENU, PLAYING, WON_LEVEL };
char game_state;

void update_handler(void) {
	flag = true;
}

void main() {
	unsigned char i;
	unsigned char j;
	unsigned char level_counter = 1;
	unsigned char brick_counter;
	unsigned char delay_counter;
	striker_t * striker = create_striker( STRIKER_SPAWN_X, SCREEN_HEIGHT );
	ball_t * ball = create_ball();
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

	load_level( level_counter );
	start_current_level();	
	game_state = PLAYING;
	while ( 1 ) {
		if ( flag ) {
			if ( game_state == PLAYING ) {
				get_input();
				ball -> update( ball );
				ball -> check_collision( ball, striker, STRIKER );
				for ( i = 0; i < current_level.num_bricks; i++ ) {
					ball -> check_collision( ball, bricks[ i ], BRICK );
				}
				ball -> render( ball );
				striker -> update( striker );
				striker -> render( striker );
				flag = false;	

				//winning condition check
				brick_counter = 0;
				for ( i = 0; i < current_level.num_bricks; i++ ) {
					if ( bricks[ i ] -> lives > 0 )
						brick_counter++;
				}
				if ( brick_counter == 0 ) { 
					game_state = WON_LEVEL;
					end_current_level();
					cleanup_current_level();
					ball -> x = BALL_SPAWN_X << 8;
					ball -> y = BALL_SPAWN_Y << 8;
					ball -> direction = BALL_SPAWN_DIRECTION;
					striker -> x = STRIKER_SPAWN_X;
					level_counter++;
				}
			}
			else if ( game_state == WON_LEVEL ) {
				//wait for user before starting next level
				get_input();
				if ( inputvalues[ ACTION_BUTTON ] ) {
					delay_counter = 0;
					load_level( level_counter );
					start_current_level();
					game_state = PLAYING;
				}
			}

		}
	}
}
