#ifndef __NIGEL__
#define __NIGEL__

// Sir Nigel Archibald Thornberry from Nickelodeon's The Wild Thornberrys

#include <stdint.h>

static const uint8_t smashingTable[] = { /*huge array goes here*/ };
static const int32_t smashingLength = 16459;

static const uint8_t blahTable[] = { /*huge array goes here*/ };
static const int32_t blahLength = 17387;

static const uint8_t tapTable[] = { /*huge array goes here*/ };
static const int32_t tapLength = 1120;



const uint8_t * nigelTable[] = {
		tapTable,
		blahTable,
		smashingTable
};

const int32_t * nigelLength[] = {
		&tapLength,
		&blahLength,
		&smashingLength
};

#endif
