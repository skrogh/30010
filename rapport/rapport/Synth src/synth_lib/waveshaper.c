#include <stdint.h>
#include "waveshaper.h"
#include "generalModules.h"

void createWaveTable( WaveTable* waveTable, uint32_t size, const uint32_t* thresholds, const uint32_t* length, const int32_t* table ) {
	waveTable -> size = size;
	waveTable -> thresholds = thresholds;
	waveTable -> length = length;
	waveTable -> table = table;
}

int32_t updateWaveShaper( WaveShaper* waveShaper, int32_t signal ) {
	int32_t tableStart = 0; // Start of the selected wavetable
	int32_t table = 0; // index of used wavetable
	uint32_t signalShifted = 0x80000000 + signal;
	// points used in interpolation
	//int32_t y0, y1, y2, y3; // out commented, as interpolation turned out to be to processor heavy


	int32_t diff = waveShaper -> prev - signal;
	// find absolute difference
	if ( diff < 0 )
		diff = -diff;
	// save new pre. value.
	waveShaper -> prev = signal;

	// select correct table and find starting position of this.
	while( waveShaper -> waveTable -> thresholds[table] < diff ) {
		// as long as the maximum playback freq is greater than the current one, remove harmonics
		tableStart += 1 << (waveShaper -> waveTable -> length[table]); // add to the length, finding the correct starting point
		table++;
		if ( table >= waveShaper -> waveTable -> size ) // if we exeed the last one, return a zero - no output.
			return 0;
	}

	// Convert to fixed point, and truncate everything right of the point.
	signalShifted >>= 32 - waveShaper -> waveTable -> length[table]; // get a shiftet version of signal, so 0~0 and 0xFFFFFFFF~2^length-1
	/*// interpolation algorithm to go here,
	{ // extra scope for optimal compilation
		uint32_t v = ( 1 << waveShaper -> waveTable -> length[table] ) - 1; // mask used for modulus
		uint32_t w = ( signalShifted - 1 ) & v;
		// get 4 points, around lookup point
		y0 = waveShaper -> waveTable -> table[tableStart + w];
		w = ( w + 1 ) & v;
		y1 = waveShaper -> waveTable -> table[tableStart + w];
		w = ( w + 1 ) & v;
		y2 = waveShaper -> waveTable -> table[tableStart + w];
		w = ( w + 1 ) & v;
		y3 = waveShaper -> waveTable -> table[tableStart + w];


		// calculate two quadratic interpolation points
		{ // extra scope for optimal compilation

		}
		// interpolate between the two quadratic interpolation points
		{ // extra scope for optimal compilation

		}
	}
	*/
	return waveShaper -> waveTable -> table[tableStart + signalShifted];
}

void createWaveShaper( WaveShaper* waveShaper, WaveTable* waveTable ) {
	waveShaper -> waveTable = waveTable;
	waveShaper -> prev = 0;
	waveShaper -> update = &updateWaveShaper;

	/*WaveTable* waveTable; // the wavetable to lookup in
	int32_t prev; // previous inputvalue, used for determining speed
	int32_t (*update)( WaveShaper* waveShaper, int32_t input );*/
}
