//std int, for fixed integer types
#include <stdint.h>

//danger danger!
//#define static

// own libraries
#include "../util/FIFO.h"

#include "../hardware/hardInterface.h"

#include "../synth_lib/generalModules.h"
#include "instruments.h"
#include "../synth_lib/waveshaper.h"
#include "../synth_lib/oneShotter.h"
#include "../synth_lib/MIDI.h"


#include "waveTables.h"
#include "drums.h"
#include "nigel.h"
#include "popcorn.h"

// constants for sequencers



int main(void)
{
	initiateHardware();

	uint32_t midiArray[16];
	FIFOBuffer midiBuffer;
	createFIFOBuffer( &midiBuffer, midiArray, 16 );
	MIDIInterpreter midiIn;
	createMIDIInterpreter( &midiIn, &midiBuffer );

	Sequencer leadN;
	createSequencer( &leadN, popLead1N, 64 );
	Sequencer leadT;
	createSequencer( &leadT, popLead1T, 64 );

	Sequencer bassN;
	createSequencer( &bassN, popBass1N, 64 );
	Sequencer bassT;
	createSequencer( &bassT, popBass1T, 64 );

	Sequencer percN;
	createSequencer( &percN, popDrum1N, 64 );
	Sequencer percT;
	createSequencer( &percT, popDrum1T, 64 );

	LFO lfo;
	createLFO( &lfo );

	// waveshapes
	WaveTable saw;
	createWaveTable( &saw, 1, sawWaveThresholds, sawWaveLength, sawWaveTable );
	WaveTable square;
	createWaveTable( &square, 1, squareWaveThresholds, squareWaveLength, squareWaveTable );

	// for the basic synth
	RawSynth rawSynth1;
	WaveShaper rsWaveS1;
	VCO rsVco1;
	AHDSR rsAhdsrV1;
	createRawSynth( &rawSynth1, &rsWaveS1, &rsVco1, &rsAhdsrV1, &saw );

	FilterSynth filterSynth1;
	WaveShaper fsWaveS1;
	VCO fsVco1;
	AHDSR fsAhdsrV1;
	AHDSR fsAhdsrF1;
	SVF fsFilter1;
	createFilterSynth( &filterSynth1, &fsWaveS1, &fsVco1, &fsAhdsrV1, &fsAhdsrF1, &fsFilter1, &square );

	OneShotter percussion; // percusion
	createOneShotter( &percussion );

	OneShotter nigel;
	createOneShotter( &nigel );


	while( loopCondition() ) { // Until exit (never for MCU)

		busyWaiting( &midiBuffer );

		// start of synth
		midiIn.update( &midiIn );

		lfo.update( &lfo, 75 );

		bassN.update( &bassN, lfo.tick, !midiIn.playing );
		bassT.update( &bassT, lfo.tick, !midiIn.playing );

		leadN.update( &leadN, lfo.tick, !midiIn.playing );
		leadT.update( &leadT, lfo.tick, !midiIn.playing );

		percN.update( &percN, lfo.tick, !midiIn.playing );
		percT.update( &percT, lfo.tick, !midiIn.playing );

		int32_t signal = (nigel.update( &nigel, midiIn.noteTrigger, 0x2FFFFFFF, nigelTable[midiIn.note], *nigelLength[midiIn.note] ) >> 2); // game sounds

		if ( midiIn.playing )
			signal += (percussion.update( &percussion, lfo.tick?(percT.output & 0x01):0, 0x7FFFFFFF, drumsTable[percN.output - 3], *drumsLength[percN.output - 3] ) >> 3)
			+ (rawSynth1.update( &rawSynth1, ( leadT.output & 0x02 )>>1, lfo.tick?(leadT.output & 0x01):0, leadN.output + 24 ) >> 3)
			+ (filterSynth1.update( &filterSynth1, ( bassT.output & 0x02 )>>1, lfo.tick?(bassT.output & 0x01):0, bassN.output ) >> 2);

		writeBuffer( signal );

	}

	return 1; // we will never get here on the MCU

}
