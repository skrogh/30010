#include "oneshotter.h"

int32_t updateOneShotter( OneShotter* oneShotter, int32_t trigger, uint32_t speed, const uint8_t* data, int32_t length ) {
	uint32_t tmp = oneShotter -> counter;

	if ( trigger ) {
		oneShotter -> head = 0;
		oneShotter -> playing = 1;
	}

	if ( !oneShotter -> playing )
		return 0;

	oneShotter -> counter += speed;
	if ( tmp > oneShotter -> counter ) {
		oneShotter -> head++;
	}
	if ( oneShotter -> head >= length ) {
		oneShotter -> head = length;
		oneShotter -> playing = 0;
		return 0;
	}

	return ( data[ oneShotter -> head ] << 24 ) + 0x80000000; // return as 32b signed
}

void createOneShotter( OneShotter* oneShotter ) {
	oneShotter -> playing = 0;
	oneShotter -> counter = 0;
	oneShotter -> head = 0;
	oneShotter -> update = &updateOneShotter;
}
