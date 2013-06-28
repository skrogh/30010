
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
#include "sound.h"

#define NUM_BRICKS 15
#define LEVEL_CHANGE_DELAY 100 
#define MENU_X 20
#define MENU_Y 10
#define MENU_WIDTH 40
#define MENU_HEIGHT 20
#define MENU_COLOR 0x20


char flag;
enum {SPLASH_SCREEN, MENU, PLAYING, WON_LEVEL, LOST_GAME, WON_GAME };
char game_state;

void update_handler(void) {
	flag = true;
}

//start a new game
void start_game( striker_t ** striker, ball_t ** ball ) {
	*striker = create_striker( STRIKER_SPAWN_X, SCREEN_HEIGHT );
	*ball = create_ball();
	load_level( 1 );
	start_current_level();	
	game_state = PLAYING;
	play_sound( POPCORN_START );
}

//end a game and cleanup
void end_game( striker_t ** striker, ball_t ** ball ) {
	play_sound( POPCORN_STOP );
	destroy_striker( *striker );
	destroy_ball( *ball );
}

void display_lost_message() {
	draw_box( (unsigned char)MENU_X, (unsigned char)MENU_Y, (unsigned char)MENU_WIDTH, (unsigned char)MENU_HEIGHT, (unsigned char)MENU_COLOR );
	gotoxy( MENU_X + 4, MENU_Y + 2 );
	printf( "You lost the game" );
	gotoxy( MENU_X + 8, MENU_Y + 6 );
	printf( "Press S to try again" );
	while ( 1 ) {
		if ( flag ) {
			get_input();
			if ( inputvalues[ ACTION_BUTTON ] == true )
				break;
		}
	}

}

void display_won_message( ball_t * ball ) {
	draw_box( (unsigned char)MENU_X, (unsigned char)MENU_Y, (unsigned char)MENU_WIDTH, (unsigned char)MENU_HEIGHT, (unsigned char)MENU_COLOR );
	gotoxy( MENU_X + 4, MENU_Y + 2 );
	printf( "Congrats, you won the game" );
	gotoxy( MENU_X + 8, MENU_Y + 6 );
	printf( "Your final score is: %d", ball -> score );
	gotoxy( MENU_X + 9, MENU_Y + 8 );
	printf( "Press S to try again" );
	while ( 1 ) {
		if ( flag ) {
			get_input();
			if ( inputvalues[ ACTION_BUTTON ] == true )
				break;
		}
	}
}



void main() {
	unsigned char i = 0;
	unsigned char j;
	unsigned char level_counter = 1;
	unsigned char brick_counter;
	//allocate striker and ball entities
	striker_t * striker;
	ball_t * ball;
	
	//initialize need API functions
	setup_input();
	setup_sound();
	setup_timer( 0, (unsigned long)33333, 2, &update_handler );

	//initialize the terminal
	reset_term();
	clrscr();

	//initialize game state
	game_state = SPLASH_SCREEN;
	set_background( start_splash );
	draw_whole_bg();
	//display splash screen until user continues
	while ( 1 ) {
		if ( flag ) {
			get_input();
			if ( inputvalues[ ACTION_BUTTON ] == true ) 
				break;
		}
	}
	
	//load first level and enter main game loop
	start_game( &striker, &ball );

	while ( 1 ) {
		if ( flag ) {
			if ( game_state == PLAYING ) {
				get_input();
				ball -> update( ball );
				//check collision with the striker
				ball -> check_collision( ball, striker, STRIKER );
				//check collision with the borders
				ball -> check_collision( ball, ball, ALL_BORDERS );
				//check collision with the bricks
				for ( i = 0; i < current_level.num_bricks; i++ ) {
					ball -> check_collision( ball, bricks[ i ], BRICK );
				}
				//render game entities
				ball -> render( ball );
				striker -> update( striker );
				striker -> render( striker );

				flag = false;	

				//winning and losing conditions check
				brick_counter = 0;
				for ( i = 0; i < current_level.num_bricks; i++ ) {
					if ( bricks[ i ] -> lives > 0 )
						brick_counter++;
				}
				if ( brick_counter == 0  ) { 
					play_sound( WINNING_SOUND );
					game_state = WON_LEVEL;
					end_current_level();
					cleanup_current_level();
					ball -> x = BALL_SPAWN_X << 8;
					ball -> y = BALL_SPAWN_Y << 8;
					ball -> direction = BALL_SPAWN_DIRECTION;
					striker -> x = STRIKER_SPAWN_X << 8;
					level_counter++;
				}
			   if ( ball -> score < 0 ) {
				    display_lost_message( ball );
					end_game( &striker, &ball );
					start_game( &striker, &ball );		
			   }
			}
			else if ( game_state == WON_LEVEL ) {
				//wait for user before starting next level
				get_input();
				if ( inputvalues[ ACTION_BUTTON ] ) {
					//if the user proceeded from the final screen
					if ( level_counter >= NUM_LEVELS ) {
						level_counter = 1;
						display_won_message( ball ); //blocking call till user accepts
						end_game( &striker, &ball );
						start_game( &striker, &ball );
					} else {
						load_level( level_counter );
						start_current_level();
						game_state = PLAYING;
					}
				}
			}

		}
	}
}
