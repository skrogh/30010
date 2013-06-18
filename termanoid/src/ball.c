#include <stdlib.h> 
#include "constants.h" 
#include "ball.h" 
#include "graphics.h" 
#include "striker.h" 

#define BALL_GRAPHIC 184

typedef struct tag_internals internals_t;

struct tag_internals {
	char old_x;
	char old_y;
};

void render_ball( ball_t * ball ) {
	char old_x = ( (internals_t*) ball -> internals ) -> old_x;
	char old_y = ( (internals_t*) ball -> internals ) -> old_y;
	gotoxy( old_x, old_y );
	draw_char( ' ' );
	gotoxy( ball -> x, ball -> y );
	draw_char( BALL_GRAPHIC );
}

void update_ball( ball_t * ball ) {
	( (internals_t*) ball -> internals ) -> old_x = ball -> x;
	( (internals_t*) ball -> internals ) -> old_y = ball -> y;
	ball -> x += ball -> x_velocity;
	ball -> y += ball -> y_velocity;
	//boundary checks
	if ( ball -> x < 1 ) {
		ball -> x = 1;	
		ball -> x_velocity *= -1;
	}
	else if ( ball -> x > ( SCREEN_WIDTH - 1 ) ) {
		ball -> x = SCREEN_WIDTH - 1;
		ball -> x_velocity *= -1;
	}

	if ( ball -> y < 1 ) {
		ball -> y = 1;
		ball -> y_velocity *= -1;
	}
	else if ( ball -> y > ( SCREEN_HEIGHT - 1 ) ) {
		ball -> y = SCREEN_HEIGHT - 1;
		ball -> y_velocity *= -1;
	}
}

void collided_ball( ball_t * ball, void * other, char other_ID, char other_x,
		char other_y, char other_width, char other_height ) {
	if ( other_ID == STRIKER ) {
		ball -> y_velocity *= -1;
		ball -> x = ( (internals_t*)ball -> internals ) -> old_x + ball -> x_velocity;
		ball -> y = ( (internals_t*)ball -> internals ) -> old_y + ball -> y_velocity;
	}

}

void check_collision_ball( ball_t * ball, void * other, char other_ID ) {
	char other_x, other_y, other_width, other_height;
	if ( other_ID == STRIKER ) {
		other_x = ( (striker_t*)other ) -> x;
		other_y = ( (striker_t*)other ) -> y;
		other_width = STRIKER_WIDTH;
		other_height = 10;
	}

	//bounding box collision
	if ( ( ball -> x >= other_x ) && ( ball -> x <= (other_x + other_width) )
			&& ( ball -> y >= other_y ) && ( ball -> y <= (other_y + other_height) ) )
		collided_ball( ball, other, other_ID, other_x, other_y, other_width, other_height );
	else
		return;
}

ball_t * create_ball() {
	ball_t * ball = malloc( sizeof ( ball_t ) );
	ball -> internals = (internals_t*)malloc( sizeof( internals_t ) );
	ball -> x = 15;
	ball -> y = 15;
	ball -> x_velocity = 2;
	ball -> y_velocity = 1;
	( (internals_t*) ball -> internals ) -> old_x = 14;
	( (internals_t*) ball -> internals ) -> old_y = 14;
	ball -> render = &render_ball;
	ball -> update = &update_ball;
	ball -> check_collision = &check_collision_ball;
	return ball;
}

void destroy_ball( ball_t * ball ) {
	free( ball );

}

