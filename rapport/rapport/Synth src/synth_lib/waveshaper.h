#ifndef __WAVESHAPER__
#define __WAVESHAPER__

#include <stdint.h>
#include "generalModules.h"

typedef struct tag_WaveTable WaveTable;
typedef struct tag_WaveShaper WaveShaper;

struct tag_WaveTable {
	uint32_t size; // number of different tables (with less and less harmonics)
	const uint32_t* thresholds; // table of thresholds for choosing correct table
	const uint32_t* length; // table of lengths of the different tables, in format 2^length
	const int32_t* table; // all the tables.
};

void createWaveTable( WaveTable* waveTable, uint32_t size, const uint32_t* thresholds, const uint32_t* length, const int32_t* table );

struct tag_WaveShaper {
	WaveTable* waveTable; // the wavetable to lookup in
	int32_t prev; // previous inputvalue, used for determining speed
	int32_t (*update)( WaveShaper* waveShaper, int32_t input );
};

void createWaveShaper( WaveShaper* waveShaper, WaveTable* waveTable );


#endif
