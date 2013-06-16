#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "graphics.h"
#include "constants.h"
#include "input.h"
#include "striker.h"

int main() {
	//ncurses init
	init_graphics();
	init_input();

	color( 5, 4 );
	printw( "%s", PILCROW );

	striker_t * striker = create_striker( 10, 10 );
	striker -> render( striker );

	refresh();
	//pause before ending
	getch();
	while ( getch() != 'q' ) {}
	endwin(); //end ncurses

	return 0;
}
