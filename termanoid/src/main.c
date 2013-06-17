#include <eZ8.h>
#include <sio.h>
#include <string.h>
#include <stdlib.h>
#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"

void main() {
	striker_t * striker = create_striker( 10, 10 );
	
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );

	striker -> render( striker );

	while ( 1 ) {}

}
