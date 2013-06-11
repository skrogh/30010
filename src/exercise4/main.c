#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

void main() {
	char a, b, c, d, e;
	int f;
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	reset();
	clrscr();
	a = 64;
	b = 64;
	c = (a * b) >> 8;
	d = ((int)(a) * (int)(b)) >> 8;
	e = (int)(a * b) >> 8;
	f = (a * b) >> 8;
	printf("%d | %d | %d | %d", c, d, e, f );
	while(1);
}
