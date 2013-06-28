#include <stdint.h>

#include "../synth_lib/generalModules.h"
#include "../synth_lib/waveshaper.h"
#include "instruments.h"




int32_t updateRawSynth( RawSynth* synth, int32_t gate, int32_t trigger, int32_t freq ) {
	int32_t oscillator = synth -> waveS -> update( synth -> waveS, synth -> vco -> update( synth -> vco, freq ) ) >> 2; // set input of wave-shaper to raw oscillator
	uint32_t vol = synth -> ahdsrV -> update( synth -> ahdsrV, gate, trigger, 0xF0000000, 0xFFF00000, 0xFFF00000, 0x3FFFFFFF, 0xFFFF0000 );
	return ( (int64_t)oscillator * (uint64_t)vol )>>32;
}

void createRawSynth( RawSynth* synth, WaveShaper* waveS, VCO* vco, AHDSR* ahdsrV, WaveTable* wave ) {
	synth -> waveS = waveS;
	synth -> wave = wave;
	createWaveShaper( waveS, wave );
	synth -> vco = vco;
	createVCO( synth -> vco );
	synth -> ahdsrV = ahdsrV; // volume control
	createAHDSR( synth -> ahdsrV );
	synth -> update = &updateRawSynth;
}

int32_t updateFilterSynth( FilterSynth* synth, int32_t gate, int32_t trigger, int32_t freq ) {
	int32_t oscillator = synth -> waveS -> update( synth -> waveS, synth -> vco -> update( synth -> vco, freq ) ) >> 2; // set input of wave-shaper to raw oscillator
	uint32_t cutoff = synth -> ahdsrF -> update( synth -> ahdsrF, gate, trigger, 0xF000000, 0xFF000000, 0xFFF70000, 0x1FFFFFFF, 0xFFFF0000 );
	uint32_t vol = synth -> ahdsrV -> update( synth -> ahdsrV, gate, trigger, 0xF0000000, 0xFFF00000, 0xFFF00000, 0xFFFFFFFF, 0xFFFF0000 );
	synth -> filter -> update( synth -> filter, oscillator>>2, cutoff>>2, 0x0FFFFFFF ); // the oscillator volume is taken down to avoid clipping inside the filter.
	return ( (int64_t)synth -> filter -> lowpass * (uint64_t)vol )>>32;
}

void createFilterSynth( FilterSynth* synth, WaveShaper* waveS, VCO* vco, AHDSR* ahdsrV, AHDSR* ahdsrF, SVF* filter, WaveTable* wave ) {
	synth -> waveS = waveS;
	synth -> wave = wave;
	createWaveShaper( waveS, wave );
	synth -> vco = vco;
	createVCO( synth -> vco );
	synth -> ahdsrV = ahdsrV; // volume control
	createAHDSR( synth -> ahdsrV );
	synth -> ahdsrF = ahdsrF; // filter control
	createAHDSR( synth -> ahdsrF );
	synth -> filter = filter;
	createSVF( synth -> filter );
	synth -> update = &updateFilterSynth;
}

