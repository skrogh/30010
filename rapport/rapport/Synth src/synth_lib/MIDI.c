#include <stdint.h>

#include "MIDI.h"
#include "../util/FIFO.h"

// MIDI format described at: https://ccrma.stanford.edu/~craig/articles/linuxmidi/misc/essenmidi.html

void updateMIDIInterpreter( MIDIInterpreter* midiInt ) {
	uint32_t data;
	midiInt -> noteTrigger = 0;
	while( midiInt -> midiBuffer -> peak( midiInt -> midiBuffer, &data, 0 ) ) { // as long as there is anything to peak at
		if ( data == 0x80 ) {// note on on ch 1
			if ( midiInt -> midiBuffer -> elements >= 2 ) { // recieved the full message?
				midiInt -> midiBuffer -> pop( midiInt -> midiBuffer, &data ); // pop it off
				midiInt -> midiBuffer -> pop( midiInt -> midiBuffer, &(midiInt -> note) ); // set note as output
				// velocity is omitted, if it's sent, it will simply be thrown away
				midiInt -> noteTrigger = 1;
			} else {
				break; // break the while loop, wait for more data
			}
		} else if ( data == 0xFA ) {// start
			midiInt -> midiBuffer -> pop( midiInt -> midiBuffer, &data ); // pop it off
			midiInt -> playing = 1;
		}  else if ( data == 0xFC ) {// stop
			midiInt -> midiBuffer -> pop( midiInt -> midiBuffer, &data ); // pop it off
			midiInt -> playing = 0;
		} else { // invalid input
			midiInt -> midiBuffer -> pop( midiInt -> midiBuffer, &data ); // pop it off
		}
	}
}

void createMIDIInterpreter( MIDIInterpreter* midiInt, FIFOBuffer* midiBuffer ) {
	midiInt -> midiBuffer = midiBuffer;
	midiInt -> note = 0; // set to a "safe" place, and not the standart 127 for note off, as this could lead to reading in restricted memory
	midiInt -> noteTrigger = 0;
	midiInt -> playing = 0;
	midiInt -> update = &updateMIDIInterpreter;
}
