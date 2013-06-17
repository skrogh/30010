#include <eZ8.h>
#include <sio.h>
#include <string.h>
#include <stdlib.h>
#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"

int main() {
	striker_t * striker = create_striker( 10, 10 );
	color( 5, 4 );
	printf( "%s", PILCROW );

	
	striker -> render( striker );

	//pause before ending
	getch();
	while ( getch() != 'q' ) {}

	return 0;
}
