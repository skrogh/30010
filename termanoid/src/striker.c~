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
	//old values for deletion
	( (cleanup_t*)striker -> cleanup ) -> old_x = striker -> x;
	( (cleanup_t*)striker -> cleanup ) -> old_y = striker -> y;
	
	//new values
	striker -> x += striker -> x_velocity * inputvalues[ RIGHT ];
	striker -> x -= striker -> x_velocity * inputvalues[ LEFT ];

	//boundary check
	if ( striker -> x + STRIKER_WIDTH > TERM_WIDTH )
	   striker -> x = TERM_WIDTH - STRIKER_WIDTH;
	else if ( striker -> x < 0 )
		striker -> x = 0;	
}

void render_striker( striker_t * striker ) {
	char old_x = ( (cleanup_t*)striker -> cleanup ) -> old_x;
	char old_y = ( (cleanup_t*)striker -> cleanup ) -> old_y;

	if ( old_x == striker -> x && old_y == striker -> y )
		return;

	//else refresh the striker
	gotoxy( old_x, old_y );
	draw_chars( STRIKER_SPACES ); 
	gotoxy( striker -> x, striker -> y );
	draw_chars( STRIKER_GRAPHIC );
}

striker_t *  create_striker( char x, char y ) {
	striker_t * striker = malloc( sizeof ( striker_t ) );
	striker -> cleanup = (cleanup_t*)malloc( sizeof( cleanup_t ) );
	striker -> x = x;
	striker -> y = y;
	striker -> x_velocity = 1;
	striker -> x_direction = 0;
	( (cleanup_t*)striker -> cleanup ) -> old_x = x;
	( (cleanup_t*)striker -> cleanup ) -> old_y = y;
	striker -> render = &render_striker;
	striker -> update = &update_striker;
	return striker;
}

void destroy_striker( striker_t * striker ) {
	free( ( (cleanup_t*)striker -> cleanup ) );
	free( striker );
}


	

