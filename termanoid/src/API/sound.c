#include "spi.h"

void setup_sound() {
	setup_SPI_master();
}

void play_sound( unsigned char sound ) {
	write_spi( 0x80 );
	write_spi( sound );
}

//Toggle playback of the supported background track
void toggle_track( unsigned char toggle ) {
	if ( toggle )
		write_spi( 0xFA );
	else 
		write_spi( 0xFC );
}
