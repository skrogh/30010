#include <stdlib.h> 
#include "constants.h" 
#include "ball.h" 
#include "graphics.h" 
#include "striker.h" 
#include "math.h"

#define BALL_GRAPHIC 184

typedef struct tag_internals internals_t;

struct tag_internals {
	short old_x;
	short old_y;
};

void render_ball( ball_t * ball ) {
	short old_x = ( (internals_t*) ball -> internals ) -> old_x;
	short old_y = ( (internals_t*) ball -> internals ) -> old_y;
	gotoxy( (old_x & 0xFF00) >> 8  , ( old_y & 0xFF00 ) >> 8 );
	draw_char( ' ' );
	gotoxy( (ball -> x & 0xFF00) >> 8, (ball -> y & 0xFF00) >> 8 );
	draw_char( BALL_GRAPHIC );
}

void update_ball( ball_t * ball ) {
	short sindeg = sin( ball -> direction );
	short cosdeg = cos( ball -> direction );
	( (internals_t*) ball -> internals ) -> old_x = ball -> x;
	( (internals_t*) ball -> internals ) -> old_y = ball -> y;
	ball -> x += FIX8_8_MULT( cos( (ball -> direction) ), (ball -> speed) );
	ball -> y += FIX8_8_MULT( sin( (ball -> direction) ), (ball -> speed) );
}

void collided_ball( ball_t * ball, void * other, char other_ID, short other_x,
		short other_y, short other_width, short other_height ) {
	if ( other_ID == STRIKER ) {
		ball -> direction = 512 - ball -> direction;
		ball -> x = ( (internals_t*)ball -> internals ) -> old_x + FIX8_8_MULT( cos( ball 
					-> direction ), ball -> speed );
		ball -> y = ( (internals_t*)ball -> internals ) -> old_y + FIX8_8_MULT( sin( ball
					-> direction ), ball -> speed );
		return;
	}

	if ( other_ID == VERTICAL_BORDER ) {
		ball -> direction = 256 - ball -> direction;
		ball -> x = ( (internals_t*)ball -> internals ) -> old_x + FIX8_8_MULT( cos( ball
					-> direction ), ball -> speed );
		ball -> y = ( (internals_t*)ball -> internals ) -> old_y + FIX8_8_MULT( sin( ball
					-> direction ), ball -> speed );
		return;
	}

	if ( other_ID == HORIZONTAL_BORDER ) {
		ball -> direction = 512 - ball -> direction;
		ball -> x = ( (internals_t*)ball -> internals ) -> old_x + FIX8_8_MULT( cos( ball
					-> direction ), ball -> speed );
		ball -> y = ( (internals_t*)ball -> internals ) -> old_y + FIX8_8_MULT( sin( ball
					-> direction ), ball -> speed );
		return;
	}

}

void check_collision_ball( ball_t * ball, void * other, char other_ID ) {
	short other_x, other_y, other_width, other_height;
	if ( other_ID == STRIKER ) {
		other_x = (short)( (striker_t*)other ) -> x;
		other_y = (short)( (striker_t*)other ) -> y;
		other_width = STRIKER_WIDTH << 8;
		other_height = 10 << 8;
	}

	//bounding box collision
	if ( ( ball -> x >= other_x ) && ( ball -> x <= (other_x + other_width) )
			&& ( ball -> y >= other_y ) && ( ball -> y <= (other_y + other_height) ) ) {
		collided_ball( ball, other, other_ID, other_x, other_y, other_width, other_height );
		return;
	}

	//boundary checks
	if ( ball -> x < ( 1 << 8 ) ) {
		collided_ball( ball, other, VERTICAL_BORDER, 1 << 8, 1 << 8, 1 << 8, 24 << 8 );
		return;
	}
	else if ( ball -> x > ( SCREEN_WIDTH - 1 ) << 8 ) {
		collided_ball( ball, other, VERTICAL_BORDER, ( SCREEN_WIDTH -1 ) << 8, 1 << 8,
			   	1 << 8, 24 << 8 );
		return;
	}

	if ( ball -> y < 1 << 8 ) {
		collided_ball( ball, other, HORIZONTAL_BORDER, 1 << 8, 1 << 8, SCREEN_WIDTH << 8,
			   	1 << 8 );
		return;
	}
	else if ( ball -> y > ( ( SCREEN_HEIGHT ) << 8 ) ) {
		collided_ball( ball, other, HORIZONTAL_BORDER, 1 << 8, ( SCREEN_HEIGHT - 1 ) << 8,
			   	24 << 8, 1 << 8 );
		return;
	}
}

ball_t * create_ball() {
	ball_t * ball = malloc( sizeof ( ball_t ) );
	ball -> internals = (internals_t*)malloc( sizeof( internals_t ) );
	ball -> x = 15 << 8;
	ball -> y = 15 << 8;
	ball -> speed = 1 << 8;
	ball -> direction = 400;
	( (internals_t*) ball -> internals ) -> old_x = 14 << 8;
	( (internals_t*) ball -> internals ) -> old_y = 14 << 8;
	ball -> render = &render_ball;
	ball -> update = &update_ball;
	ball -> check_collision = &check_collision_ball;
	return ball;
}

void destroy_ball( ball_t * ball ) {
	free( ball );

}

