#include <stdint.h>

#include "generalModules.h"

// Lookup table for tones to freq
static const uint32_t TONE_LUT[TONE_LUT_SIZE] = { 1342177, 1421987, 1506543, 1596127, 1691037, 1791592, 1898125, 2010994, 2130574, 2257264, 2391488, 2533693, 2684355, 2843975, 3013086, 3192254, 3382075, 3583183, 3796251, 4021987, 4261147, 4514528, 4782976, 5067387, 5368709, 5687949, 6026172, 6384507, 6764150, 7166367, 7592501, 8043975, 8522294, 9029056, 9565952, 10134773, 10737418, 11375898, 12052344, 12769014, 13528299, 14332734, 15185002, 16087950, 17044589, 18058113, 19131904, 20269546, 21474836, 22751796, 24104689, 25538028, 27056598, 28665467, 30370004, 32175899, 34089177, 36116225, 38263808, 40539092, 42949672, 45503592, 48209377, 51076056, 54113196, 57330934, 60740009, 64351797, 68178354, 72232450, 76527615, 81078184, 85899344, 91007185, 96418753, 102152111, 108226391, 114661867, 121480017, 128703594, 136356708, 144464900, 153055230, 162156368, 171798687, 182014369, 192837506, 204304221, 216452782, 229323734, 242960033, 257407188, 272713416, 288929799, 306110459, 324312734, 343597373, 364028735, 385675010, 408608440, 432905562, 458647466, 485920063, 514814374, 545426829, 577859596, 612220915, 648625465, 687194742, 728057468, 771350017, 817216876, 865811120, 917294928, 971840122, 1029628743, 1090853654, 1155719187, 1224441826, 1297250925, 1374389478, 1456114929, 1542700029, 1634433745, 1731622233, 1834589849, 1943680237, 0 };

int updateVCO( VCO* vco, int32_t freq ) {
	if ( ( freq < 0 )||( freq >= TONE_LUT_SIZE ) )
		freq = TONE_LUT_SIZE - 1; // No tone
	vco -> counter += TONE_LUT[freq];

	return vco -> counter;
}

void createVCO( VCO* vco ) {
	vco -> counter = 0;
	vco -> update = &updateVCO;
}



int updateLowPass( LowPass* lowPass, int32_t input, uint32_t K2 ) {

	// fixed point math
	lowPass -> prev = (int32_t) ( ( (int64_t)input * (uint64_t)K2 + (int64_t)( lowPass -> prev ) * (uint64_t)(~K2) ) >> 32 );

	return lowPass -> prev;
}

void createLowPass( LowPass* lowPass ) {
	lowPass -> prev = 0;
	lowPass -> update = &updateLowPass;
}



int updateLFO( LFO* lfo, int32_t freq ) {
	uint32_t tmp;

	if ( ( freq < 0 )||( freq > TONE_LUT_SIZE ) )
		freq = TONE_LUT_SIZE; // No tone

	tmp = lfo -> counter;
	lfo -> counter += TONE_LUT[freq] >> 7; //max period ~10s doubles for every 12's

	if ( tmp >= lfo -> counter )
		lfo -> tick = 1; // tick is 1 on overflow, else 0
	else
		lfo -> tick = 0;

	return lfo -> counter;
}

void createLFO( LFO* lfo ) {
	lfo -> counter = 0;
	lfo -> tick = 0;
	lfo -> update = &updateLFO;
}



int updateSequencer( Sequencer* sequencer, int tick, int reset ) {
	if ( tick ) // tick is a delta function
		(sequencer -> counter)++;

	if ( ( sequencer -> counter >= sequencer -> length ) || ( reset ) ) {
		sequencer -> counter = 0;
		sequencer -> tickOut = 1;
	} else {
		sequencer -> tickOut = 0;
	}

	sequencer -> output = (sequencer -> sequence)[sequencer -> counter];


	return sequencer -> output;
}

void createSequencer( Sequencer* sequencer, const int* sequence, int length ) {
	sequencer -> counter = 0;
	sequencer -> length = length;
	sequencer -> sequence = sequence;
	sequencer -> output = 0;
	sequencer -> update = &updateSequencer;
	sequencer -> tickOut = 0;
}



int updateSVF( SVF* svf, int input, unsigned int Kf, unsigned int Kq ) {
	svf -> lowpass = ( ( (long long)(svf -> prev1) * (unsigned long long)Kf ) >> 32 ) + svf -> prev2;
	svf -> bandpass = svf -> prev1;
	svf -> hipass = input - svf -> lowpass - ( ( (long long)(svf -> bandpass) * (unsigned long long)Kq ) >> 31 );
	svf -> prev1 += ( (long long)(svf -> hipass) * (unsigned long long)Kf ) >> 32;
	svf -> prev2 = svf -> lowpass;

	return svf -> bandpass;
}

void createSVF( SVF* svf ) {
	svf -> prev1 = 0;
	svf -> prev1 = 0;
	svf -> hipass = 0;
	svf -> bandpass = 0;
	svf -> lowpass = 0;
	svf -> update = &updateSVF;
}


/*    A    H  D   S    R
 *        ___
 *       /   \
 *      /     \_______
 *     /              \
 *    /                \
 *
 */
uint32_t updateAHDSR( AHDSR* ahdsr, int32_t gate, int32_t trigger, uint32_t attack, uint32_t hold, uint32_t decay, uint32_t sustain, uint32_t release ) {
	uint32_t tmp;
	switch( ahdsr -> state ) {
	case 0: // release state
		tmp = ahdsr -> counter;
		ahdsr -> counter -= ~release;
		if ( ahdsr -> counter > tmp ) // on underflow
			ahdsr -> counter = 0; // constrain

		ahdsr -> output = ( (uint64_t)sustain * (uint64_t) ahdsr -> counter ) >> 32; // set output to follow falling trail.. (counting counting down * sustain)

		if ( trigger ) { // if triggered, look away from the gate to allow "late gating"
			ahdsr -> counter = 0;
			ahdsr -> state = 1; // go to attack phase
		}

		break;

	case 1: // attack state
		tmp = ahdsr -> counter;
		ahdsr -> counter += ~attack;

		if ( ahdsr -> counter < tmp ) { // on overflow
			ahdsr -> counter = 0x0; // reset
			ahdsr -> state = 2; // go to hold phase
		} else
			ahdsr -> output = ahdsr -> counter; // set output to follow rising trail..

		if ( trigger ) { // if triggered, restart attack phase
			ahdsr -> counter = 0;
			ahdsr -> state = 1; // go to attack phase
			break;
		}

		// if ( !gate ) // continue the transient

		break;

	case 2: // hold state
		tmp = ahdsr -> counter;
		ahdsr -> counter += ~hold;

		if ( ahdsr -> counter < tmp ) { // on overflow
			ahdsr -> counter = 0x0; // reset counter
			ahdsr -> state = 3; // go to decay phase
		}

		ahdsr -> output = 0xFFFFFFFF; // set output to max

		if ( trigger ) { // if triggered, restart attack phase
			ahdsr -> counter = 0;
			ahdsr -> state = 1; // go to attack phase
			break;
		}

		// if ( !gate ) // continue the transient

		break;
	case 3: // decay state
		tmp = ahdsr -> counter;
		ahdsr -> counter += ~decay;

		if ( ahdsr -> counter < tmp ) { // on overflow
			ahdsr -> state = 4; // go to sustain phase
		} else
			ahdsr -> output = 0xFFFFFFFF - ( ( (uint64_t) ahdsr -> counter * (uint64_t)(0xFFFFFFFF - sustain) ) >> 32 ); // set output

		if ( trigger ) { // if triggered, restart attack phase
			ahdsr -> counter = 0;
			ahdsr -> state = 1; // go to attack phase
			break;
		}

		// if ( !gate ) // continue the transient

		break;
	case 4: // sustain state
		ahdsr -> output = sustain;

		if ( trigger ) { // if triggered, restart attack phase
			ahdsr -> counter = 0;
			ahdsr -> state = 1; // go to attack phase
			break;
		}

		if ( !gate ) { // if gate is let go... I don't know... frankly...
			ahdsr -> counter = 0xFFFFFFFF;
			ahdsr -> state = 0; // go to release phase
			break;
		}

		break;


	}
	return ahdsr -> output;
}

void createAHDSR( AHDSR* ahdsr ) {
	ahdsr -> state = 0; // Enum for this? 0: release state, 1: attack, 2: hold, 3: decay, 4: sustain.
	ahdsr -> counter = 0;
	ahdsr -> output = 0;
	ahdsr -> update = &updateAHDSR;
}
