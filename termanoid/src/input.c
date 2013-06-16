#include <ncurses.h>
#include "input.h"

void init_input() {
	keypad( stdscr, TRUE ); //function keys and numpad
	nodelay( stdscr, TRUE ); //make getch non-blocking
}
