#include <ncurses.h>
#include <string.h>

#define true 1
#define false 0
#define CURRENT_COLOR current_foreground * 8 + current_background
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define PILCROW "¶"
int current_foreground;
int current_background;


void gotoxy( unsigned char x, unsigned char y ) {
	move( (int)y, (int)x );
}

void clrscr() {
	erase();
}

void background_color( char color ) {
	current_background = color;
	attron( COLOR_PAIR( CURRENT_COLOR ) );
}

void foreground_color( char color ) {
	current_foreground = color;
	attron( COLOR_PAIR( CURRENT_COLOR ) );
}

void color( char foreground, char background ) {
	current_background = background;
	current_foreground = foreground;
	attron( COLOR_PAIR( CURRENT_COLOR ) );
}

void setup_colors() {
	short f, b;
	for ( f = 0; f < 8; ++f ) {
		for( b = 0; b < 8; ++b)
			init_pair( f * 8 + b, f, b );
	}
	current_foreground = 7;
	current_background = 0;
}

void init_graphics() {
	initscr(); //init ncurses
	raw(); // raw ncurses input
	noecho(); //don't echo user inptu
	start_color(); //enable ncurses colors
	setup_colors();
}

void init_input() {
	keypad( stdscr, TRUE ); //function keys and numpad
	nodelay( stdscr, TRUE ); //make getch non-blocking
}

int main() {
	//ncurses init
	init_graphics();
	init_input();

	color( 5, 4 );
	printw( "%s", PILCROW );
	refresh();
	//pause before ending
	getch();
	while ( getch() != 'q' ) {}
	endwin(); //end ncurses

	return 0;
}
