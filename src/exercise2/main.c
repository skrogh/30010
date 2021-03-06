#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#define ESC 0x1B
#define true 1
#define false 0

void fgcolor(int foreground) {
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

void bgcolor(int background) {
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

void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
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

void gotoxy( int x, int y ) {
	printf( "%c[%d;%dH", ESC, y, x );
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

void reset() {
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

void main() {
	long x, y, i, dx, dy;
	dx = 2;
	dy = 1;
	x = 1;
	y = 1;
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	reset();
	clrscr();
	while( 1 ){
		x += dx;
		y += dy;
		if ( ( x < 1 ) || ( x > 300 ) ) {
			dx = -dx;
		}
		if ( ( y < 1 ) || ( y > 200 ) ) {
			dy = -dy;
		}
		
		clrscr();
		window( (char)(x>>3), (char)(y>>3), 10, 5, "lol", 1 );
		for( i = 0; i < 0x1FFF; i++ ){
			asm("NOP");
		}
	}

}
