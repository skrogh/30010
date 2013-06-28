#ifndef __INSTR__
#define __INSTR__

#include <stdint.h>
#include "../synth_lib/generalModules.h"
#include "../synth_lib/waveshaper.h"

// typedef structs:
typedef struct tag_RawSynth RawSynth;
typedef struct tag_FilterSynth FilterSynth;

struct tag_RawSynth { //Raw saw wave synth, one voice, two AHDSR, one filter, fixed parameters
	VCO* vco;
	AHDSR* ahdsrV; // volume controll
	WaveTable* wave;
	WaveShaper* waveS;

	int32_t (*update)( RawSynth* synth, int32_t gate, int32_t trigger, int32_t freq );
};

void createRawSynth( RawSynth* synth, WaveShaper* waveS, VCO* vco, AHDSR* ahdsrV, WaveTable* wave );

struct tag_FilterSynth { //Raw saw wave synth, one voice, two AHDSR, one filter, fixed parameters
	VCO* vco;
	AHDSR* ahdsrV; // volume controll
	AHDSR* ahdsrF; // filter controll
	SVF* filter;
	WaveTable* wave;
	WaveShaper* waveS;

	int32_t (*update)( FilterSynth* synth, int32_t gate, int32_t trigger, int32_t freq );
};

void createFilterSynth( FilterSynth* synth, WaveShaper* waveS, VCO* vco, AHDSR* ahdsrV, AHDSR* ahdsrF, SVF* filter, WaveTable* wave );


#endif
