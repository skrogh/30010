#include <stdlib.h>
#include "constants.h"
#include "brick.h"
#include "levels.h"
#include "backgrounds.h"
#include "graphics.h"
#define MAX_BRICKS 40

level_t current_level;
brick_t * bricks[MAX_BRICKS];

// Level arrangements [ x_pos, y_pos, lives ]
const unsigned char arrangement_one[] = { 10, 4, 2, 10 + BRICK_WIDTH, 4, 2,
   	10 + 2*BRICK_WIDTH, 4, 2, 10 + 3 * BRICK_WIDTH, 4, 2, 10 + 4 * BRICK_WIDTH, 4,
   	2, 10 + 5 * BRICK_WIDTH, 4, 2, 10 + 6 * BRICK_WIDTH, 4, 2, 10 + 7 * BRICK_WIDTH, 4, 2 };	
const unsigned char arrangement_two[] = { 10, 4, 3, 10 + BRICK_WIDTH, 4, 3,
   	10 + 2*BRICK_WIDTH, 4, 3, 10 + 3 * BRICK_WIDTH, 4, 3, 10 + 4 * BRICK_WIDTH, 4,
   	3, 10 + 5 * BRICK_WIDTH, 4, 3, 10 + 6 * BRICK_WIDTH, 4, 3, 10 + 7 * BRICK_WIDTH, 4, 3,
	10, 4 + BRICK_HEIGHT, 2, 10 + BRICK_WIDTH, 4 + BRICK_HEIGHT, 2, 10 + 2*BRICK_WIDTH, 4
		+ BRICK_HEIGHT, 2, 10 + 3 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2, 10 + 4 * BRICK_WIDTH, 4
		+ BRICK_HEIGHT, 2, 10 + 5 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2, 10 + 6 * BRICK_WIDTH,
   	4 + BRICK_HEIGHT, 2, 10 + 7 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2 };

const unsigned char arrangement_three[] = { 10, 4, 3, 10 + BRICK_WIDTH, 4, 7,
	10 + 5 * BRICK_WIDTH, 4, 3, 10 + 6 * BRICK_WIDTH, 4, 7,
	10, 4 + BRICK_HEIGHT, 2, 10 + BRICK_WIDTH, 4 + BRICK_HEIGHT, 2,
	10 + 5 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2, 10 + 6 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2,
	10, 4 + 2 * BRICK_HEIGHT, 1, 10 + BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT, 1,
	10 + 5 * BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT, 1, 10 + 6 * BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT,
	1 };	

const unsigned char arrangement_four[] = { 10, 4, 3, 10 + BRICK_WIDTH, 4, 3,
   	10 + 2*BRICK_WIDTH, 4, 3, 10 + 3 * BRICK_WIDTH, 4, 3, 10 + 4 * BRICK_WIDTH, 4,
   	3, 10 + 5 * BRICK_WIDTH, 4, 3, 10 + 6 * BRICK_WIDTH, 4, 3, 10 + 7 * BRICK_WIDTH, 4, 3,
	10, 4 + BRICK_HEIGHT, 2, 10 + BRICK_WIDTH, 4 + BRICK_HEIGHT, 2, 10 + 2*BRICK_WIDTH, 4
		+ BRICK_HEIGHT, 2, 10 + 3 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2, 10 + 4 * BRICK_WIDTH, 4
		+ BRICK_HEIGHT, 2, 10 + 5 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2, 10 + 6 * BRICK_WIDTH,
   	4 + BRICK_HEIGHT, 2, 10 + 7 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 2,
	10, 4 + 2 * BRICK_HEIGHT, 8, 10 + BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT, 8, 10 +
	   	2*BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT, 8, 10 + 3 * BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT,
		8, 10 + 4 * BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT, 8, 10 + 5 * BRICK_WIDTH, 4 + 2 * 
			BRICK_HEIGHT, 8, 10 + 6 * BRICK_WIDTH,
   	4 + 2 * BRICK_HEIGHT, 8, 10 + 7 * BRICK_WIDTH, 4 + 2 * BRICK_HEIGHT, 8};

const unsigned char arrangement_five[] = { 10, 4, 3, 10 + BRICK_WIDTH, 4, 16,
   	10 + 2*BRICK_WIDTH, 4, 16, 10 + 3 * BRICK_WIDTH, 4, 16, 10 + 4 * BRICK_WIDTH, 4,
   	16, 10 + 5 * BRICK_WIDTH, 4, 16, 10 + 6 * BRICK_WIDTH, 4, 16, 10 + 7 * BRICK_WIDTH, 4, 16,
	10, 4 + BRICK_HEIGHT, 16, 10 + BRICK_WIDTH, 4 + BRICK_HEIGHT, 16, 10 + 2*BRICK_WIDTH, 4
		+ BRICK_HEIGHT, 16, 10 + 3 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 16, 10 + 4 * BRICK_WIDTH, 4
		+ BRICK_HEIGHT, 16, 10 + 5 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 12, 10 + 6 * BRICK_WIDTH,
   	4 + BRICK_HEIGHT, 12, 10 + 7 * BRICK_WIDTH, 4 + BRICK_HEIGHT, 12,
	10, 6 + 2 * BRICK_HEIGHT, 18, 10 + BRICK_WIDTH, 6 + 2 * BRICK_HEIGHT, 18, 10 +
	   	2*BRICK_WIDTH, 6 + 2 * BRICK_HEIGHT, 18, 10 + 3 * BRICK_WIDTH, 6 + 2 * BRICK_HEIGHT,
		18, 10 + 4 * BRICK_WIDTH, 6 + 2 * BRICK_HEIGHT, 18, 10 + 5 * BRICK_WIDTH, 6 + 2 * 
			BRICK_HEIGHT, 18, 10 + 6 * BRICK_WIDTH,
   	6 + 2 * BRICK_HEIGHT, 18, 10 + 7 * BRICK_WIDTH, 6 + 2 * BRICK_HEIGHT, 18 };


const level_t level_one = { 8, arrangement_one, &background_1};
const level_t level_two = { 16, arrangement_two, &background_2 };
const level_t level_three = { 12, arrangement_three, &background_3 };
const level_t level_four = { 24, arrangement_four, &background_4 };
const level_t level_five = { 24, arrangement_five, &background_5 };

void load_level( char level ) {
	switch ( level ) {
	case 1:
		current_level = level_one;
		break;
	case 2:
		current_level = level_two;
		break;
	case 3:
		current_level = level_three;
		break;
	case 4:
		current_level = level_four;
		break;
	case 5:
		current_level = level_five;
		break;
	default:
		current_level = level_one;
		break;
	}
}


void start_current_level() {
	unsigned char i;
	set_background( *current_level.background );
	set_monochrome( true );
	draw_whole_bg();
	for	( i = 0; i < current_level.num_bricks * 3; i += 3 ) {
		bricks[ i / 3 ] = create_brick( current_level.brick_arrangement[ i ],
			   	current_level.brick_arrangement[ i + 1 ], 
				current_level.brick_arrangement[ i + 2 ] );
	}
	for ( i = 0; i < current_level.num_bricks; i++ ) {
		bricks[ i ] -> render( bricks[ i ] );
	}
	draw_borders();
}

void end_current_level() {
	set_monochrome( false );
	draw_whole_bg();
}

void cleanup_current_level() {
	unsigned char i;
	for ( i = 0; i < current_level.num_bricks; i++ ) {
		free( bricks[ i ] );
	}
}

