#include "lut.h"

signed short sin( int angle_512 ) {
	int modangle = angle_512 & 0x1FF; // positive modulo
	return SIN[modangle];
}

