#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 25
#define FP_CONST 3

void main() {
	int x, y, i, dx, dy;
	dx = 1;
	dy = 3;
	x = 1<<FP_CONST;
	y = 1<<FP_CONST;
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	reset();
	clrscr();
	while( 1 ){
		x += dx;
		y += dy;
		if ( ( x < 1<<FP_CONST ) || ( x > (TERMINAL_WIDTH - 10)<<FP_CONST  ) ) {
			dx = -dx;
		}
		if ( ( y < 1<<FP_CONST ) || ( y > (TERMINAL_HEIGHT - 5)<<FP_CONST  ) ) {
			dy = -dy;
		}

		clrscr();
		window( (char)(x>>FP_CONST), (char)(y>>FP_CONST), 10, 5, "lol", 1 );
		for( i = 0; i < 0x5FFF; i++ ){
			asm("NOP");
		}
	}

}
