#include <stdlib.h>
#include "graphics.h"
#include "striker.h"
#include "input.h"
#include "constants.h"
#include "math.h"
enum {SPAWNED, ALIVE, DEAD};

typedef struct cleanup_info {
	short old_x;
	short old_y;
	char state;
} cleanup_t;

void update_striker( striker_t * striker ) {
	unsigned char joystick_value; 
	//old values for deletion
	( (cleanup_t*)striker -> cleanup ) -> old_x = striker -> x;
	( (cleanup_t*)striker -> cleanup ) -> old_y = striker -> y;
	
	//stabilize joystick input
	joystick_value = (unsigned char)inputvalues[ JOYSTICK_X ];
	/*if ( joystick_value > 90 && joystick_value < 150 ) {
	}
	else {
		//new values
		striker -> x += FIX8_8_MULT( striker -> x_velocity, (char)(joystick_value - 125 ) );
	}*/
	striker -> x += striker -> x_velocity * inputvalues[ RIGHT ];
	striker -> x -= striker -> x_velocity * inputvalues[ LEFT ];

	//boundary check
	if (  striker -> x + ( STRIKER_WIDTH << 8 ) > ( SCREEN_WIDTH << 8 ) )
		striker -> x =( SCREEN_WIDTH - STRIKER_WIDTH ) << 8;
	else if ( striker -> x < ( 2 << 8 ) )
		striker -> x = 2 << 8;	
}

void render_striker( striker_t * striker ) {
	short old_x = ( (cleanup_t*)striker -> cleanup ) -> old_x;
	short old_y = ( (cleanup_t*)striker -> cleanup ) -> old_y;
	char state = ( (cleanup_t*)striker -> cleanup ) -> state;
	char i;
	if ( (old_x >> 8) == (striker -> x >> 8) && (old_y >> 8) == (striker -> y >> 8 )
		   	&& state != SPAWNED )
		return;

	if ( state == SPAWNED )
		( (cleanup_t*)striker -> cleanup ) -> state = ALIVE;

	//else refresh the striker
	gotoxy( ( striker -> x ) >> 8, ( striker -> y ) >> 8 );
	draw_chars( STRIKER_GRAPHIC, STRIKER_COLOR );

	//only erase needed characters
	if ( old_x > striker -> x ) {
		short dx = ( old_x >> 8 ) - ( striker -> x >> 8 );
		for ( i = 0; i < dx; i++ )
			draw_char( ' ', 0x00 );
	} else {
		short dx = ( striker -> x >> 8 )  - ( old_x >> 8 );
		gotoxy( (old_x >> 8), old_y >> 8 ); 
		for ( i = 0; i < dx; i++ )
			draw_char( ' ', 0x00 );
	}

}

striker_t *  create_striker( short x, short y ) {
	striker_t * striker = malloc( sizeof ( striker_t ) );
	striker -> cleanup = (cleanup_t*)malloc( sizeof( cleanup_t ) );
	striker -> x = x << 8;
	striker -> y = y << 8;
	striker -> x_velocity = 5 << 7;
	striker -> x_direction = 0 << 8;
	( (cleanup_t*)striker -> cleanup ) -> old_x = 0;
	( (cleanup_t*)striker -> cleanup ) -> old_y = 0;
	( (cleanup_t*)striker -> cleanup ) -> state = SPAWNED;
	striker -> render = &render_striker;
	striker -> update = &update_striker;
	return striker;
}

void destroy_striker( striker_t * striker ) {
	free( ( (cleanup_t*)striker -> cleanup ) );
	free( striker );
}


	

