#include <stdint.h>

#include "FIFO.h"



uint32_t FIFOpush( FIFOBuffer* fifoBuffer, uint32_t data ) {

	if ( fifoBuffer -> elements < fifoBuffer -> length ) { // of writing over
		fifoBuffer -> data[( fifoBuffer -> pointer + fifoBuffer -> elements ) % fifoBuffer -> length] = data;
		fifoBuffer -> elements++;
		return 1; // Success
	}
	return 0; // Failure
}

uint32_t FIFOpop( FIFOBuffer* fifoBuffer, uint32_t* data ) {
	if ( fifoBuffer -> elements > 0 ) {
		*data = fifoBuffer -> data[fifoBuffer -> pointer]; // load data out
		fifoBuffer -> pointer = ( fifoBuffer -> pointer + 1 ) % fifoBuffer -> length; // move pointer
		fifoBuffer -> elements--; // reduce number of elements.
		return 1; // Success
	}
	return 0; // Failure, nu such data
}

uint32_t FIFOpeak( FIFOBuffer* fifoBuffer, uint32_t* data, uint32_t depth ) {
	if ( fifoBuffer -> elements > depth ) {
		*data = fifoBuffer -> data[( fifoBuffer -> pointer + depth ) % fifoBuffer -> length]; // load data out
		return 1; // Success
	}
	return 0; // Failure, no such data
}

void createFIFOBuffer( FIFOBuffer* fifoBuffer, uint32_t* dataArray, uint32_t arrayLength ) {
	fifoBuffer -> data = dataArray;
	fifoBuffer -> length = arrayLength;
	fifoBuffer -> pointer = 0;
	fifoBuffer -> elements = 0;
	fifoBuffer -> push = &FIFOpush;
	fifoBuffer -> pop = &FIFOpop;
	fifoBuffer -> peak = &FIFOpeak;
}
