#include <stdlib.h>
#include "constants.h"
#include "brick.h"
#include "graphics.h"

void render_brick( brick_t * brick ) {
	gotoxy( brick -> x >> 8, brick -> y >> 8 );
	if ( brick -> lives != 0 ) 
		draw_chars( BRICK_GRAPHICS, BRICK_COLOR );
	else
		draw_chars( BRICK_SPACES, BRICK_COLOR );
}


void collided_brick( brick_t * brick ) {
	brick -> lives--;
	render_brick( brick );
}

brick_t * create_brick( short x, short y, char lives ) {
	brick_t * brick = malloc( sizeof( brick_t ) );
	brick -> x = x << 8;
	brick -> y = y << 8;
	brick -> lives = lives;
	brick -> collided = &collided_brick;
	brick -> render = &render_brick;
	return brick;
}

void destroy_brick( brick_t * brick ) {
	free( brick );
}
