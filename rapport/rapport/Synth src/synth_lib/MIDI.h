#ifndef __MIDI__
#define __MIDI__

#include <stdint.h>
#include "../util/FIFO.h"

// typedef structs:
typedef struct tag_MIDIIterpreter MIDIInterpreter;

struct tag_MIDIIterpreter {
	FIFOBuffer* midiBuffer;
	int32_t note;
	int32_t noteTrigger;
	int32_t playing;
	void (*update) ( MIDIInterpreter* midiInt );
};

void createMIDIInterpreter( MIDIInterpreter* midiInt, FIFOBuffer* midiBuffer );


#endif
