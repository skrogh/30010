#include <gpio.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

#define true 1
#define false 0
#define WIDTH 80
#define HEIGTH 25


enum { right, up, left, down };

typedef struct {
	char width, height;
	char* symb;
	char* color; //msb front, lsb back
} Sprite;


const unsigned char rocket[20] = {
		246,   0, 248,   0,   0,   0,   2,  30,   0,   0,
		249,  15,   0, 249, 250, 219, 178, 177, 176,  16
		};

const unsigned char rocketColor[20] = {
		0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a,
		0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a
		};

unsigned char background[1000];

void setColor( unsigned char* background, unsigned char color, unsigned char x, unsigned char y );

void main( ) {
	int i, j;	
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	reset();
	clrscr();
	reverse( 0 );
	printf( "start" );
	reverse( 1 );
	printf( "start" );
	reverse( 0 );
	printf( "start" );
	putch( '\n' );

	while(1);
}

void setColor( unsigned char* background, unsigned char color, unsigned char x, unsigned char y ) {
	
}
