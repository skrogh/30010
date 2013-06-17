#include <ncurses.h>
#include "graphics.h"


int current_foreground;
int current_background;


void gotoxy( unsigned char x, unsigned char y ) {
	move( (int)y, (int)x );
}

void clrscr() {
	erase();
}

void draw_chars( char * chars ) {
	printw( "%s", chars );
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
