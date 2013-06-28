#include <eZ8.h>
#include <sio.h>
#include "graphics.h"
#include "backgrounds.h"

#define true 1
#define false 0

//constants for drawing background, 1 indexed
unsigned char bgx = 1;
unsigned char bgy = 1;
unsigned char bgcolor = 0x70;

char monochrome_background = false;

#define BG 0x00



const unsigned char* currentBg; 

void foreground_color(unsigned char foreground) {
	/*  Value      foreground     Value     foreground
		------------------------------------------------
		0        Black            8       Dark Gray
		1        Red              9       Light Red
		2        Green           10       Light Green
		3        Brown           11       Yellow
		4        Blue            12       Light Blue
		5        Purple          13       Light Purple
		6        Cyan            14       Light Cyan
		7        Light Gray      15       White
		*/
	int type = 22;             // normal text
	if (foreground > 7) {
		type = 1;                // bold text
		foreground -= 8;
	}
	printf("%c[%d;%dm", ESC, type, foreground+30);
}

void background_color(unsigned char background) {
	/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
	   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
	   The designers of HyperTerminal, however, preferred black text on white background, which is why
	   the colors are initially like that, but when the background color is first changed there is no
	   way comming back.
Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

Value      Color      
------------------
0        Black
1        Red
2        Green
3        Brown
4        Blue
5        Purple
6        Cyan
7        Gray
*/
	printf("%c[%dm", ESC, background+40);
}

void color(unsigned char foreground, unsigned char background) {
	// combination of fgcolor() and bgcolor() - uses less bandwidth
	int type1 = 22;             // not bold text
	int type2 = 25;             // not blink text
	bgcolor = ( foreground << 4 ) | background;
	if (foreground > 7) {
		type1 = 1;                // bold text
		foreground -= 8;
	}
	if (background > 7) {
#ifdef PUTTY
		type2 = 5;                // bold bg
#endif
		background -= 8;
	}
	printf("%c[%d;%d;%d;%dm", ESC, type1, type2, foreground+30, background+40);
}

void resetbgcolor() {
	// gray on black text, no underline, no blink, no reverse
	printf( "%c[m", ESC );  
}

void clrscr() {
	printf( "%c[2J", ESC );
}

void clreol() {
	printf( "%c[K", ESC );
}

void gotoxy( unsigned char x, unsigned char y ) {
	printf( "%c[%d;%dH", ESC, y, x );
	bgx = x;
	bgy = y;
}

void underline( char on ) {
	if ( on )
		printf( "%c[%dm", ESC, 4 ); // underline esc code 4
	else
		printf( "%c[%dm", ESC, 24 ); // underline esc code 24
}

void blink( char on ) {
	if ( on )
		printf( "%c[%dm", ESC, 5 ); // blink on escape code 5
	else
		printf( "%c[%dm", ESC, 25 ); // blink on escape code 25
}

void reverse( char on ) {
	if ( on ) 
		printf( "%c[%dm", ESC, 7 ); // escape code 7 for reverse video
	else
		printf( "%c[%dm", ESC, 27 ); // escape code 7 for reverse video
}

void reset_term() {
	printf( "%c[%dm", ESC, 0 ); // underline esc code 0
}

void textType( char type ) { 
	printf( "%c[%dm", ESC, type ); // any escapecode
}

char strLen( char* string ) {
	char i = 0;
	while( string[i] != 0 )
		i++;
	return i;
}

void window( char x, char y, char width, char height, char* header, char type ) { // type: abc, a: erase, b: fat, c: wide
	char i, len, trunc;
	char tLeft,	tRight,	lH,	lV, trCorn,	tlCorn,	brCorn,	blCorn;
	if ( type & 0x02 ) {
		tLeft = 180;
		tRight = 195;
		lH = 196;
		lV = 179;
		trCorn = 191;
		tlCorn = 218; 
		brCorn = 217;
		blCorn = 192;
	} else {
		tLeft = 185;
		tRight = 204;
		lH = 205;
		lV = 186;
		trCorn = 187;
		tlCorn = 201; 
		brCorn = 188;
		blCorn = 200;
	}
	gotoxy( x, y ); //Go to top left corner
	//conceal
	textType( 8 );
	// Draw header
	printf( "%c%c", tlCorn, tLeft ); //corner and start of header
	reverse( true ); //reverse text, beginnig of header
	len = strLen( header );
	if ( len > width - 4 ) {
		trunc = true;
		len = width - 5;
	} else {
		trunc = false;
	}
	for( i = 0; i < len; i++ )
		printf( "%c", header[i] ); // print header
	if ( trunc ) {
		printf( "\xF9" ); // print dots if truncated
	} else {
		len = width - len - 4; // get number of spaces
		if ( type & 0x01 ) { // if thick header
			for( i = 0; i < len; i++ )
				printf( " " ); // print space
			reverse( false ); //reverse text
			printf( "%c%c", tRight, trCorn ); // end header
		} else {
			reverse( false ); //reverse text
			printf( "%c", tRight ); // end header
			for( i = 0; i < len; i++ )
				printf( "%c", lH ); // print line
			printf( "%c", trCorn );
		}
	}
	// Draw Rest
	for ( i = 2; i < height; i++ ) {
		gotoxy( x, y + i - 1 ); // move curser
		printf( "%c", lV ); //vertical line
		if ( type & 0x04 ) // clear?
			for ( len = 2; len < width; len ++)
				printf( " " ); //clear window
		else
			printf( "%c[%dC", ESC, width - 2 ); // move curser
		printf( "%c", lV ); //vertical line	
	}
	gotoxy( x, y + height - 1 );
	printf( "%c", blCorn ); //corner
	for ( len = 2; len < width; len ++)
		printf( "%c", lH ); //line
	printf( "%c", brCorn ); //corner
	// reveal
	textType( 28 );
}

void draw_box( unsigned char x, unsigned char y, unsigned char width, unsigned char height,
	   unsigned char _color ) {
	unsigned char tLeft,	tRight,	lH,	lV, trCorn,	tlCorn,	brCorn,	blCorn;
	unsigned char i, j;
	tLeft = 185;
	tRight = 204;
	lH = 205;
	lV = 186;
	trCorn = 187;
	tlCorn = 201; 
	brCorn = 188;
	blCorn = 200;
	
	color( (char)( _color >> 4 ), (char)( _color & 0x0F ) ); 
	//draw top and bottom edge
	gotoxy( x, y );
	draw_char_bg( tlCorn, _color );
	for ( i = 1; i < width; i++ ) {
	   draw_char_bg( lH, _color );
	}
	draw_char_bg( trCorn, _color );
	gotoxy( x, y + height );
	draw_char_bg( blCorn, _color );
	for( i = 1; i < width; i++ ) {
		draw_char_bg( lH, _color );
	}
	draw_char_bg( brCorn, _color );

	//draw vertical sides
	for ( i = 1; i < height; i++ ) {
		gotoxy( x, y + i );
		draw_char_bg( lV, _color );
	}
	for ( i = 1; i < height; i++ ) {
		gotoxy( x + width, y + i );
		draw_char_bg( lV, _color );
	}
	
	//fill background with white
	color( (unsigned char)( _color >> 4 ), 0xF );
	for ( i = 1; i < height; i++ ) {
		gotoxy( x + 1, y + i );
		for ( j = 1; j < width; j++ )
			putch( ' ' );	
	}

}

void draw_chars_bg( char * chars, unsigned char _color ) {
	while( *(chars) != '\0' )
		draw_char_bg( *(chars++), _color );

}

void draw_char_bg( unsigned char symbol, unsigned char _color ) {
	
	if ( symbol == ' ' ) {
		unsigned short x = bgx - 1;
		unsigned short y = bgy - 1;

		
		_color = currentBg[(short)BACKGROUND_WIDTH * (short)BACKGROUND_HEIGHT+ x
		   	+ (short)BACKGROUND_WIDTH * y];
		if ( monochrome_background )
			_color &= 0x88; // only b/w colors
		else
			symbol = currentBg[x + (short)BACKGROUND_WIDTH* y];
	} else {
		unsigned short x = bgx - 1;
		unsigned short y = bgy - 1;
		if ( ( _color & 0x0F ) == 0x08 ) { //ligt black for transparant
			_color &= 0xF0; // clear bg color
			_color |= currentBg[(short)BACKGROUND_WIDTH * (short)BACKGROUND_HEIGHT 
				+ x + (short)BACKGROUND_WIDTH * y] & 0x0F; // set bg color
			if ( monochrome_background )
				_color &= 0xF8; // only b/w bg colors
		}
	}
	if ( symbol == ESC )
		return; // you can't draw that...

	if ( _color != bgcolor )
		color( _color >> 4, _color & 0x0F );
	putch( symbol );
	bgx++;
#ifdef HYPER_T // do automatic line warp for hyperterminal
	if ( bgx > SCREEN_WIDTH ) {
		bgx = 1;
		bgy++;
		if ( bgy > BACKGROUND_HEIGHT )
			bgy = BACKGROUND_HEIGHT;
#endif
	}



void draw_whole_bg() {
	unsigned char i, j;
	for( j = 1; j <= BACKGROUND_HEIGHT; j++ ) {
		gotoxy( 1, j );
		for( i = 1; i <= BACKGROUND_WIDTH; i++ ) {
			draw_char_bg( ' ', 0x00 );
		}
	}
}

void set_monochrome( char truefalse ) {
	monochrome_background = ( truefalse == true ) ? true : false;
}

void set_background( const unsigned char * background ) {
	currentBg = background;
}

void draw_borders() {
	int i;
	gotoxy( 1, 1 );
	for ( i = 1; i < SCREEN_WIDTH; i++ ) {
		draw_char_bg( '=', 0x70 );
	}
	for ( i = 1; i <= SCREEN_HEIGHT; i++ ) {
		gotoxy( SCREEN_WIDTH , i );
		draw_char_bg( '|', 0x70 );
	}
	for ( i = 1; i <= SCREEN_HEIGHT; i++ ) {
		gotoxy( 1, i );
		draw_char_bg( '|', 0x70 );
	} 
}
