#include <gpio.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "charset.h"
#include "LED.h"


#define true 1
#define false 0

char video_buffer[5][6];
char update;
char next_column; //the next column to be updated
unsigned char next_display; // the next display to have it's columns updated


void setupTimer0() { //should be a general function with timer/prescale/reload arguments

	T0CTL = 0x00; //disable the timer before setting it
	T0CTL = 0x11; //set prescale 4, continous mode, reload value will be 2304 for 0.5ms period
	T0H = 0x00; // set starting high bits to 0
	T0L = 0x01; // set starting value to 1

	T0RH = 0x09; // set reload high to upper 8 bits of 2304
	T0RL = 0x00; // set reload low to lower 8 bits of 2304	

	//enable timer as interrupt
	IRQ0ENH |= 0x20; // nominal priority
	IRQ0ENL &= 0xDF;

	//enable
	T0CTL |= 0x80;

	EI(); // enable interrupts
}

#pragma interrupt
void timer0int() {
	update = true;	
}



void LEDinit() {

	//set up PG and PE for writing
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

	//set up the LED refresh timer
	setupTimer0();
	SET_VECTOR( TIMER0, timer0int );
	
}

void LEDsetString( char * string, char startposition, char strlength ) {
	char i,j;
	for ( i = 0; i < 5; i++ ) {
		for ( j = 0; j < 5; j++ ) {
			video_buffer[ i ][ j ] = character_data[ string[ ( i + startposition ) % strlength ] - 0x20 ][ j ];  
		}
		video_buffer[ i ][ j ] = 0; //space at the end of a character.
			
	}
	
}

void updateColumn( char column, char display, char output ) {
	//make sure the diode clock is low
	switch ( display ) {
		case 1:
			PEOUT &= 0x7F; // PE(7) is D1 clock
			break;
		case 2:
			PGOUT &= 0x7F; // PG(7) is D2 clock
			break;
		case 3:
			PEOUT &= 0xDF; // PE(5) is D3 clock
			break;
		case 4:
			PEOUT &= 0xBF; // PE(6) is D4 clock
			break;
		default:
			break;
	}

	//reset the column
	PEOUT |= 0x1F; //set to high 
	
	//set the column
	switch ( column ) {
		case 0:
			PEOUT &= 0xFE; // PE(0) is column 0
			break;
		case 1:
			PEOUT &= 0xFD; // PE(1) is colum 1
			break;
		case 2:
			PEOUT &= 0xFB; // PE(2) is column2
			break;
		case 3:
			PEOUT &= 0xF7; // PE(3) is column 3 
			break;
		case 4:
			PEOUT &= 0xEF; // PE(4) is column 4
			break;
		default:
			break;
	}

	//reset the row
	PGOUT &= ~0x7F; // clear PG 6-0
	//update the row
	PGOUT |= output & 0x7F; //leave PG(7) alone since it's a clock signal

	//clock the latch up and down
	switch ( display ) {
		case 1:
			PEOUT |= 1 << 7; // PE(7) is D1 clock
			break;
		case 2:
			PGOUT |= 1 << 7; // PG(7) is D2 clock
			break;
		case 3:
			PEOUT |= 1 << 5; // PE(5) is D3 clock
			break;
		case 4:
			PEOUT |= 1 << 6; // PE(6) is D4 clock
			break;
		default:
			break;
	}
	switch ( display ) {
		case 1:
			PEOUT &= 0x7F; // PE(7) is D1 clock
			break;
		case 2:
			PGOUT &= 0x7F; // PG(7) is D2 clock
			break;
		case 3:
			PEOUT &= 0xDF; // PE(5) is D3 clock
			break;
		case 4:
			PEOUT &= 0xBF; // PE(6) is D4 clock
			break;
		default:
			break;
	}

}

void LEDupdate() {
	if ( !update ) 
		return;
	
	
	if ( next_display > 4 ){
		next_display = 1;
		next_column--;
		}
	if ( next_column < 0 ) {
		next_column = 4;
	}

	updateColumn( next_column, next_display, video_buffer[ next_display - 1 ][ 4 - next_column ] ); // 4 - column mirros the display
	
	update = false;
	
	
	
	next_display++; // update 1 row per display at a time for even lighting


}

void shiftBuffer() {
	char i, j;

	for ( i = 0; i < 5; i++ ) {
		for ( j = 0; j < 5; j++ ) {
			video_buffer[ i ][ j ] = video_buffer[ i ][ j + 1 ];
 	    }
		video_buffer[ i ][ 5 ] = video_buffer[ i + 1 ][ 0 ]; // take from the next letter
    }
}

char getStringLength( char * string ) {
	char length = 0;
	while ( *string != '\0' ) {
		length++;
		string++;
	}
	return length;
}

