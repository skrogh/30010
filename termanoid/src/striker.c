#include <stdlib.h>
#include "graphics.h"
#include "striker.h"
#include "input.h"
#include "constants.h"

typedef struct cleanup_info {
	char old_x;
	char old_y;
} cleanup_t;

void update_striker( striker_t * striker ) {
	striker -> x += striker -> x_velocity * striker -> x_direction;
}

void render_striker( striker_t * striker ) {
	gotoxy( striker -> x, striker -> y );
	draw_chars( STRIKER_GRAPHIC );
}

striker_t *  create_striker( char x, char y ) {
	striker_t * striker = malloc( sizeof ( striker_t ) );
	striker -> x = x;
	striker -> y = y;
	striker -> x_velocity = 1;
	striker -> x_direction = 0;
	striker -> cleanup = (cleanup_t*)malloc( sizeof( cleanup_t ) );
	( (cleanup_t*)striker -> cleanup ) -> old_x = x;
	( (cleanup_t*)striker -> cleanup ) -> old_y = y;
	striker -> render = &render_striker;
	striker -> update = &update_striker;
	return striker;
}




	

