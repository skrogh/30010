#ifndef __GENERAL_MODULES__
#define __GENERAL_MODULES__
/*
 * General modules for music generation.
 * the update functions should be called once for each module
 * for each frame/sample.
 *
 * Common pitfalls:
 * 		Forgetting to call the update for modules that store the output.
 * 		Calling the update function multiple times for modules being routed to multiple places
 *
 */


#define TONE_LUT_SIZE 128

#include <stdint.h>

// typedef structs:
typedef struct tag_VCO VCO;
typedef struct tag_LFO LFO;
typedef struct tag_Sequencer Sequencer;
typedef struct tag_LowPass LowPass;
typedef struct tag_SVF SVF;
typedef struct tag_AHDSR AHDSR;


// lookup table for tones. 0 = A-1, 12 = A0 etc....
//static const uint32_t TONE_LUT[TONE_LUT_SIZE]; NOT ACESESSABLE TO OTHER FILES.

struct tag_VCO {
	uint32_t counter; // continues counter, incremented by the note value on update
	/*
	 * Update the oscillator @vco, playing the note @freq. 0 is A-1, 1 is B-1 12: A0 13: B0 etc...
	 * Returns the output saw wave.
	 */
	int32_t (*update)( VCO* vco, int freq );
};

/*
 * Create an oscillator module with a saw wave output - no band limiting
 * Initiate the structure @vco.
 */
void createVCO( VCO* vco );

struct tag_LFO {
	uint32_t counter; // continues counter, incremented by the note value on update
	int32_t tick; // delta-function on overflow of counter
	/*
	 * Updates the low frequency oscillator @lfo. @freq sets the frequency of the lfo.
	 * 0 is ~0.1Hz the frequency doubles for every 12.
	 * Returns the output saw wave
	 */
	int32_t (*update)( LFO* lfo, int32_t freq );
};

/*
 * Create a low frewuency oscillator module with a saw wave output - no band limiting
 * Initiate the structure @vco.
 */
void createLFO( LFO* lfo );



struct tag_Sequencer {
	uint32_t counter; // Position in sequencer.
	uint32_t length;
	const int32_t* sequence; // Pointer to array.
	int32_t output; // the output of the sequencer, stored as this is often used multiple places
	int32_t tickOut; // deltafunction on overflow
	/*
	 * Updates the sequencer @sequencer advancing when @tick is high and resetting when @reset is high
	 *
	 */
	int32_t (*update)( Sequencer* sequencer, int32_t tick, int32_t reset );
};

/*
 * Create a sequencer from the array @sequencer with length @length
 * Initiate the structure @sequencer
 */
void createSequencer( Sequencer* sequencer, const int32_t* sequence, int32_t length );



struct tag_LowPass {
	int32_t prev; // stores the previous value
	/*
	 * Updates the low pass filter @lowPass where @signal is the input and @K2 is the filter coefficient.
	 *
	 */
	int32_t (*update)( LowPass* lowPass, int input, unsigned int K2 );
};

void createLowPass1( LowPass* lowPass );



struct tag_SVF {
	int32_t prev1; // stores the previous value
	int32_t prev2; // stores the previous value
	int32_t hipass;
	int32_t lowpass;
	int32_t bandpass;
	int32_t (*update)( SVF* sfv, int32_t input, uint32_t Kf, uint32_t Kq );
};


void createSVF( SVF* svf );



struct tag_AHDSR {
	uint32_t state; // Enum for this? 0: release state, 1: attack, 2: hold, 3: decay, 4: sustain.
	uint32_t counter;
	uint32_t output;
	uint32_t (*update)( AHDSR* ahdsr, int32_t gate, int32_t trigger, uint32_t attack, uint32_t hold, uint32_t decay, uint32_t sustain, uint32_t release );
};

void createAHDSR( AHDSR* ahdsr );

#endif
