#ifndef __DRUMS__
#define __DRUMS__

// tables lent from http://bleeplabs.com/store/the-bleep-drum/

#include <stdint.h>

static const uint8_t  kickTable[] = { /*huge array goes here*/ };
int32_t kickLength=5744;

static const uint8_t  tickTable[] = { /*huge array goes here*/ };
int32_t tickLength=832;

static const uint8_t  snareTable[] = { /*huge array goes here*/ };
int32_t snareLength= 5200;

static const uint8_t  bassTable[] = { /*huge array goes here*/ };
int32_t bassLength=12150;

const uint8_t * drumsTable[] = {
	kickTable,
	snareTable,
	tickTable,
	bassTable
};

const int32_t * drumsLength[] = {
	&kickLength,
	&snareLength,
	&tickLength,
	&bassLength
};

#endif
