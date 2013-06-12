#include <gpio.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

#define true 1
#define false 0

void setUpButtons() {

	PFADDR = 0x02;
	PFCTL = 0x00;
	
	PDADDR = 0x02;
	PDCTL = 0x00;

	PDADDR = 0x01;
	PDCTL |= 1<<3; //set PD3 as input
	PDADDR = 0;

	PFADDR = 0x01;
	PFCTL |= 1<<6; //set PF6 as input
	PFADDR = 0;

	PFADDR = 0x01;
	PFCTL |= 1<<7; //set PF7 as input
	PFADDR = 0;
}
	
char readkey() {
	unsigned char pd3, pf6, pf7;
	
	pd3 = ~PDIN & 1<<3;//for PD3
	pf6 = ~PFIN & 1<<6; // for PF6
	pf7 = ~PFIN & 1<<7; // for PF7

	return ( pd3 >> 1 ) | ( pf6 >> 5 ) | ( pf7 >> 7 ); //shift pf7 to least sig bit, pf6 to 2nd least and pd3 to 3rd.
}

char button_press( char old, char next ) {
	if ( ( ( old ^ next ) & next ) != 0 ) // only true if a new button is pressed
		return true;
	else
		return false;
}

void setupLEDs() { // set up for writing to column 4
	PGADDR = 0x02; // no alternate function 
	PGCTL = 0x00;

	PGADDR = 0x01; // direction
	PGCTL = 0x00; // set PG to output
	PGADDR = 0; // prevent addressing mistakes

	PEADDR = 0x02; //no alternate function
	PECTL = 0x00;

	PEADDR = 0x01; // direction
	PECTL = 0x00; //set column 4 as output and D1 clock as output
	PEADDR = 0;

	// zero display
	PEOUT = 0x1F; // 00011111
	PGOUT = 0x00; // 00000000
	//clock
	PEOUT |= 0xE0;  // set 11100000
	PGOUT |= 0x80;  // set 10000000
	PEOUT &= ~0xE0; // clear 11100000
	PGOUT &= ~0x80; // clear 10000000
	//enable column 4 for writing
	PEOUT &= ~0x10; // clear 00010000
}

void flashCounter( unsigned char counter ) {
	PGOUT &= ~0x7F; // clear 6-0
	PGOUT |= counter & 0x7F; // set 6-0 to count

	PEOUT |= 0x80;
	PEOUT &= 0x7F;
}

void main() {
	unsigned char counter;
	long i;
	char old;

	counter = 0;
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	setUpButtons();
	setupLEDs();
	clrscr();

	old = readkey();
	

	while ( 1 ) {
		clrscr();
		if ( button_press( old, readkey() ) ) 
			counter++;
		printf( "Button presses: %d\n", counter );

		old = readkey();
	
		flashCounter( counter );

		for ( i = 0; i<0x4FFF; i++ );
		
			
		
		
	}
}
