#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

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
