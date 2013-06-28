#ifndef __wavetables__
#define __wavetables__

#include <stdint.h>


/*			Semi-saw wave
 *            __          __
 *         __|  |      __|  |
 *      __|     |   __|     |
 *  |__|        |__|
 *
 */
static const int32_t sawWaveTable[] = {
		/*8	   size*/ 0x80000000, 0x40000000, 0x3FFFFFFF, 0x7FFFFFFF
};
static const uint32_t sawWaveLength[] = { 3 };
static const uint32_t sawWaveThresholds[] = { 0x745D1746 };


/*			Square wave
 *         _____
 *        |     |
 *        |     |
 *  |_____|
 *
 */
static const int32_t squareWaveTable[] = {
		/*2	   size*/ 0x80000000, 0x7FFFFFFF
};
static const uint32_t squareWaveLength[] = { 1 };
static const uint32_t squareWaveThresholds[] = { 0x745D1746 };

#endif
