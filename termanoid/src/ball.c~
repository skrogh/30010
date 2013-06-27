#include <stdlib.h> 
#include <sio.h>
#include "constants.h" 
#include "ball.h" 
#include "graphics.h" 
#include "striker.h" 
#include "math.h"
#include "brick.h"
#include "sound.h"

#define BALL_GRAPHIC 0xB8
#define BALL_COLOR 0x28
#define BRICK_KILL_SCORE 5
#define BRICK_HIT_SCORE 1
#define DEATH_SCORE_PENALTY 25
#define SPAWN_DELAY 50
#define DEATH_DELAY 5
#define BALL_START_DIRECTION 128
#define SCORE_X 5
#define SCORE_Y 41

typedef struct tag_internals internals_t;

struct tag_internals {
	short old_x;
	short old_y;
	short delay_timer;
};

void update_score( ball_t * ball ) {
	color( 0xF, 0x0 );
	gotoxy( SCORE_X, SCORE_Y );
	printf( "Score: %03d", ball -> score );
}

void render_ball( ball_t * ball ) {
	short old_x = ( (internals_t*) ball -> internals ) -> old_x;
	short old_y = ( (internals_t*) ball -> internals ) -> old_y;

	if ( ball -> state != DEAD ) {
		gotoxy( (old_x & 0xFF00) >> 8  , ( old_y & 0xFF00 ) >> 8 );
		draw_char_bg( ' ', BALL_COLOR );
		gotoxy( (ball -> x & 0xFF00) >> 8, (ball -> y & 0xFF00) >> 8 );
		draw_char_bg( BALL_GRAPHIC, BALL_COLOR );
	} 
}

void update_ball( ball_t * ball ) {

	if ( ball -> state == ALIVE ) {
		short sindeg = sin( ball -> direction );
		short cosdeg = cos( ball -> direction );
		( (internals_t*) ball -> internals ) -> old_x = ball -> x;
		( (internals_t*) ball -> internals ) -> old_y = ball -> y;
		ball -> x += FIX8_8_MULT( cos( (ball -> direction) ), (ball -> speed) );
		ball -> y -= FIX8_8_MULT( sin( (ball -> direction) ), (ball -> speed) );
	} else if ( ball -> state == SPAWNED ) {
		( (internals_t*)ball -> internals ) -> delay_timer++;
		if ( ( (internals_t*)ball -> internals ) -> delay_timer > SPAWN_DELAY ) { 
			ball -> state = ALIVE;
			( (internals_t*)ball -> internals ) -> delay_timer = 0;
		}

	} else if ( ball -> state == DEAD ) {
		( (internals_t*)ball -> internals ) -> delay_timer++;
		if ( ( (internals_t*)ball -> internals ) -> delay_timer > DEATH_DELAY ) {
			play_sound( 0x03 );
			ball -> state = SPAWNED;
			ball -> score -= DEATH_SCORE_PENALTY;
			update_score( ball );
			//give the ball spawn position
			ball -> x = BALL_SPAWN_X << 8;
			ball -> y = BALL_SPAWN_Y << 8;
			ball -> direction = BALL_START_DIRECTION;
			( (internals_t*)ball -> internals ) -> delay_timer = 0;
		}
	}

}

//uses formula 2*(Vnormal + 90deg ) - Vdirection to calculate reflection
void collided_ball( ball_t * ball, void * other, char other_ID, short other_x,
		short other_y, short other_width, short other_height, char other_lives ) {
	short normal_vector;
	short old_x = ( (internals_t*)ball -> internals ) -> old_x;
	short old_y = ( (internals_t*)ball -> internals ) -> old_y;
	if ( other_ID == STRIKER ) {
		//ball -> direction = 512 - ball -> direction;
		//striker acts as a Fresnel lens
		normal_vector = ((int)128) + ( ( -ball -> x + other_x + ( ( other_width )
					   	>> 1 ) ) >> 4 ); 
		//ball -> direction = 256 + normal_vector * 2 - ball -> direction;
		ball -> direction = (int)normal_vector;
		ball -> x = ( (internals_t*)ball -> internals ) -> old_x + FIX8_8_MULT( cos( ball 
					-> direction ), ball -> speed );
		ball -> y = ( (internals_t*)ball -> internals ) -> old_y - FIX8_8_MULT( sin( ball
					-> direction ), ball -> speed );
		play_sound( 0x02 );
		return;
	}

	else if ( other_ID == BRICK ) {
		//figure out which side the ball hits
		if ( old_y < other_y || old_y > other_y ) {
			ball -> direction = 512 - ball -> direction;
			ball -> x = old_x + FIX8_8_MULT( cos( ball -> direction ), ball -> speed );
			ball -> y = old_y - FIX8_8_MULT( sin( ball -> direction ), ball -> speed );
		} else {
			ball -> direction = 256 - ball -> direction;
			ball -> x = old_x + FIX8_8_MULT( cos( ball -> direction ), ball -> speed );
			ball -> y = old_y - FIX8_8_MULT( sin( ball -> direction ), ball -> speed );
		}
		( (brick_t*)other ) -> collided( (brick_t*)other );
		if ( other_lives == 1 )
			ball -> score += BRICK_KILL_SCORE;
		else 
			ball -> score += BRICK_HIT_SCORE;
		update_score( ball );
		play_sound( 0x01 );
		return;
	}

	//collision with the Y axis borders
	else if ( other_ID == VERTICAL_BORDER ) {
		ball -> direction = 256 - ball -> direction;
		ball -> x = ( (internals_t*)ball -> internals ) -> old_x + FIX8_8_MULT( cos( ball
					-> direction ), ball -> speed );
		ball -> y = ( (internals_t*)ball -> internals ) -> old_y - FIX8_8_MULT( sin( ball
					-> direction ), ball -> speed );
		play_sound( 0x02 );
		return;
	}
	
	//collision with the top border
	else if ( other_ID == HORIZONTAL_BORDER ) {
		ball -> direction = 512 - ball -> direction;
		ball -> x = ( (internals_t*)ball -> internals ) -> old_x + FIX8_8_MULT( cos( ball
					-> direction ), ball -> speed );
		ball -> y = ( (internals_t*)ball -> internals ) -> old_y - FIX8_8_MULT( sin( ball
					-> direction ), ball -> speed );
		play_sound( 0x02 );
		return;
	}
	//collision with bottom border decrements score and resets ball
	else if ( other_ID == BOTTOM_BORDER ) {
		ball -> state = DEAD;
		return;
	}



}

void check_collision_ball( ball_t * ball, void * other, char other_ID ) {
	short other_x, other_y, other_width, other_height;
	char other_lives;
	if ( other_ID == STRIKER ) {
		other_x = (short)( (striker_t*)other ) -> x;
		other_y = (short)( (striker_t*)other ) -> y;
		other_width = STRIKER_WIDTH << 8;
		other_height = 1 << 8;
	}

	else if ( other_ID == BRICK ) {
		other_lives = ( (brick_t*)other ) -> lives;
		if ( other_lives == 0 )
			return;

		other_x = ( (brick_t*)other ) -> x;
		other_y = ( (brick_t*)other ) -> y;
		other_width = BRICK_WIDTH << 8;
		other_height = BRICK_HEIGHT << 8;
	}
	
	//boundary checks
	else if ( other_ID == ALL_BORDERS ) {
		if ( ball -> x < ( 2 << 8 ) ) {
			collided_ball( ball, other, VERTICAL_BORDER, 2 << 8, 1 << 8, 1 << 8, 25 << 8, 0 );
			return;
		}
		else if ( ball -> x > ( SCREEN_WIDTH ) << 8 ) {
			collided_ball( ball, other, VERTICAL_BORDER, ( SCREEN_WIDTH -1 ) << 8, 1 << 8,
				   	1 << 8, 25 << 8, 0 );
			return;
		}	

		if ( ball -> y < 2 << 8 ) {
			collided_ball( ball, other, HORIZONTAL_BORDER, 1 << 8, 2 << 8, SCREEN_WIDTH << 8,
				   	1 << 8, 0 );
			return;
		}
		//Player misses the ball.
		else if ( ball -> y > ( ( SCREEN_HEIGHT + 1 ) << 8 ) ) {
			collided_ball( ball, other, BOTTOM_BORDER, 1 << 8, ( SCREEN_HEIGHT ) << 8,
				   	25 << 8, 1 << 8, 0 );
			return;
		}
	}
	//bounding box collision
	if ( (  ( ball -> x >> 8 ) >= ( other_x >> 8 ) )
			&& ( ( ball -> x >> 8 ) <= ( (other_x + other_width) >> 8 ) )
			&& (  ( ball -> y >> 8 ) >= ( other_y >> 8 ) )
		   	&& ( ( ball -> y >> 8 ) <= ( (other_y + other_height) >> 8 ) ) ) {
		collided_ball( ball, other, other_ID, other_x, other_y, other_width, other_height,
			   other_lives	);
		return;
	}

	
}

ball_t * create_ball() {
	ball_t * ball = malloc( sizeof ( ball_t ) );
	ball -> internals = (internals_t*)malloc( sizeof( internals_t ) );
	ball -> x = BALL_SPAWN_X << 8;
	ball -> y = BALL_SPAWN_Y << 8;
	ball -> state = SPAWNED;
	ball -> score = 0;
	ball -> speed = BALL_SPAWN_SPEED << 8;
	ball -> direction = BALL_SPAWN_DIRECTION;
	( (internals_t*) ball -> internals ) -> old_x = 14 << 8;
	( (internals_t*) ball -> internals ) -> old_y = 14 << 8;
	( (internals_t*) ball -> internals ) -> delay_timer = 0;
	ball -> render = &render_ball;
	ball -> update = &update_ball;
	ball -> check_collision = &check_collision_ball;
	return ball;
}

void destroy_ball( ball_t * ball ) {
	free( ball );

}

