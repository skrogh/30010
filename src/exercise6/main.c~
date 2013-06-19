#include <gpio.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

#define true 1
#define false 0
#define CLOCK_WINDOW_X 10
#define CLOCK_WINDOW_Y 5
#define CLOCK_WINDOW_WIDTH 36
#define CLOCK_WINDOW_HEIGHT 6

typedef struct {
	char hours;
	char minutes;
	char seconds;
	char hundreths;
	char running; // used to determine whether main_clock is running or split time is being displayed
} clock;

clock main_clock;
clock split1;
clock split2;
char old;

#pragma interrupts
void timer0int() {
	if ( !main_clock.running )
		return;
	main_clock.hundreths++;
	if ( main_clock.hundreths > 99 ) {
		main_clock.hundreths = 0;
		main_clock.seconds++;
	}

	if ( main_clock.seconds > 59 ) {
		main_clock.seconds = 0;
		main_clock.minutes++; 				//this should be in a single if since it's faster
	}

	if ( main_clock.minutes > 59 ) {
		main_clock.minutes = 0;
		main_clock.hours++;
	}

	if ( main_clock.hours > 23 ) {
		main_clock.hours = 0;
		main_clock.minutes = 0;
		main_clock.seconds = 0;
		main_clock.hundreths = 0;
	}
	
}

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


void setupTimer0() {
	T0CTL = 0x00; //disable the timer before setting it
	T0CTL = 0x11; //set prescale 4, continous mode, reload value will be 46081
	T0H = 0x00; // set starting high bits to 0
	T0L = 0x01; // set starting value to 1

	T0RH = 0xB4; // set reload high to upper 8 bits of 46081
	T0RL = 0x01; // set reload low to lower 8 bits of 46081	

	//enable timer as interrupt
	IRQ0ENH |= 0x20; // nominal priority
	IRQ0ENL &= 0xDF;

	EI(); // enable interrupts
}

void inputhandler() {
	if ( button_press( old, readkey() ) ) {
		old = readkey();

		if ( ( old & 0x02) ) {  //check PF6 AND PD3 = reset clock
			if ( ( old & 0x04 ) ) {
				main_clock.hours = 0;
				main_clock.minutes = 0;
				main_clock.seconds = 0;
				main_clock.hundreths = 0;
				main_clock.running = 1; // reset main clock
				return;
			}
		}

		if ( ( old & 0x01 ) ) { //check PF7 = start/stop
			main_clock.running = !main_clock.running;
			return;
		}

		if ( old & 0x02 ) { // check for PF6 = split1
			split1.hours = main_clock.hours;
			split1.minutes = main_clock.minutes;
			split1.seconds = main_clock.seconds;
			split1.hundreths = main_clock.hundreths;
			split1.running = 1;
		   	return;
		}

		if ( old & 0x04 ) { // check for PD3 = split2
			split2.hours = main_clock.hours;
			split2.minutes = main_clock.minutes;
			split2.seconds = main_clock.seconds;
			split2.hundreths = main_clock.hundreths;
			split2.running = 1;
			return;
		}
	}

	old = readkey();
}


//print mainclock with padded zeroes at given location
void printMainClock( char xpos, char ypos ) {
	gotoxy( xpos, ypos );
	printf( "Time since start:\t %d:%02d:%02d.--", main_clock.hours, main_clock.minutes, main_clock.seconds );
}


//print split times with padded zeroes at a given location
void printSplitTimes( char xpos, char ypos ) {
	gotoxy( xpos, ypos );
	if ( split1.running )
		printf( "Split time 1:\t %d:%02d:%02d.%02d", split1.hours, split1.minutes, split1.seconds, split1.hundreths );
	else
		printf( "Split time 1:\t -:--:--.--" );
	
	gotoxy( xpos, ypos + 1 );
	if ( split2.running )
		printf( "Split time 2:\t %d:%02d:%02d.%02d", split2.hours, split2.minutes, split2.seconds, split2.hundreths );
	else
		printf( "Split time 2:\t -:--:--.--" );
}


void main() {
	long i;
	char * windowname = "Stop watch";
	//init the structs
	main_clock.hours = 0;
	main_clock.minutes = 0;
	main_clock.seconds = 0;
	main_clock.hundreths = 0;
	main_clock.running = true;

	split1.hours = 0;
	split1.minutes = 0;
	split1.seconds = 0;
	split1.hundreths = 0;
	split1.running = false;

	split2.hours = 0;
	split2.minutes = 0;
	split2.seconds = 0;
	split2.hundreths = 0;
	split2.running = false;
	
	//set up the uart
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	setUpButtons();
	setupLEDs();
	clrscr();

	old = readkey();
	

	setupTimer0(); // setup the timer
	SET_VECTOR( TIMER0, timer0int ); // point to the interrupt handler
	T0CTL |= 0x80; // enable the timer
	clrscr(); // clear the screen
	window( CLOCK_WINDOW_X, CLOCK_WINDOW_Y, CLOCK_WINDOW_WIDTH, CLOCK_WINDOW_HEIGHT, windowname, 3 ); //draw the stopwatch window
	while( 1 ) {
		printMainClock( CLOCK_WINDOW_X + 2, CLOCK_WINDOW_Y + 2 ); // right inside the window
		printSplitTimes( CLOCK_WINDOW_X + 2, CLOCK_WINDOW_Y + 3); //below main clock, 
		inputhandler(); // check for input and perform relevant ops
		for( i = 0; i < 0x6FFF; i++ );  //nop for a sane refresh value
	}

}
