// Hardware dependent functions. change these when changing hardware

#include <stdint.h>

#include <stdio.h>
#include <assert.h>

#include "hardInterface.h"
#include "make_wav.h"
#include "../util/FIFO.h"

uint32_t volatile outputBuffer = 127;
uint32_t volatile busy = 0;

#define S_RATE  (44000)
#define BUF_SIZE (S_RATE*20) /* 20 second buffer */

short int buffer[BUF_SIZE];
int bufferCounter = 0;

void initiateHardware(){};

void writeOutput() {
	write_wav("test.wav", BUF_SIZE, buffer, S_RATE);
}

int32_t loopCondition() {
	return !busy;
}

void busyWaiting( FIFOBuffer* midiBuffer ){
	if ( bufferCounter> S_RATE*1 ) // one second of silence
		midiBuffer -> push( midiBuffer, 0xFA ); // fill the buffer with requests to start the music
}

void writeBuffer( int32_t signal) {

	buffer[bufferCounter] = signal>>16;

	bufferCounter++;
	if ( bufferCounter >= BUF_SIZE ) {
		busy = 1; // stop calculation. Program doesn't exit
		writeOutput(); // write to file
	} else {
		busy = 0; // continue
	}
}

