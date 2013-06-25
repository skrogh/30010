#include "spi.h"

void setup_sound() {
	setup_SPI_master();
}

void play_sound( unsigned char sound ) {
	write_spi( 0x80 );
	write_spi( sound );
}
