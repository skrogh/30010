#include <stdlib.h>
#include "constants.h"
#include "brick.h"
#include "graphics.h"

const unsigned char brick_graphic[] = { '\xC9', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xBB',
								   '\xC8', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xCD', '\xBC' };

void render_brick( brick_t * brick ) {
	char i, j;
	if ( brick -> lives != 0 ) {
		for ( i = 0; i < BRICK_HEIGHT; i++ ) {
			gotoxy( brick -> x >> 8, ( brick -> y >> 8 ) + i );	
			for( j = 0; j < BRICK_WIDTH; j++ ) {
				draw_char_bg( brick_graphic[j + i * BRICK_WIDTH ], 
						( brick -> lives << 4 ) | 0x08 );
			}
		}
	} else {
		for ( i = 0; i < BRICK_HEIGHT; i++ ) {
			gotoxy( brick -> x >> 8, ( brick -> y >> 8 ) + i );	
			for( j = 0; j < BRICK_WIDTH; j++ ) {
				draw_char_bg( ' ', BRICK_COLOR );
			}
		}
	}
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
