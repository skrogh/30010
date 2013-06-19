#include <stdlib.h>
#include "constants.h"
#include "brick.h"
#include "graphics.h"

void render( brick_t * brick ) {
	gotoxy( brick -> x >> 8, brick -> y >> 8 );
	if ( brick -> lives != 0 ) 
		draw_chars( BRICK_GRAPHICS );
	else
		draw_chars( BRICK_SPACES );
}


void collided( brick_t * brick ) {
	brick -> lives--;
}

brick_t * create_brick( short x, short y, char lives ) {
	brick_t * brick = malloc( sizeof( brick ) );
	brick -> x = x << 8;
	brick -> y = y << 8;
	brick -> lives = lives;
	brick -> collided = &collided;
	return brick;
}

void destroy_brick( brick_t * brick ) {
	free( brick );
}
