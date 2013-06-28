#ifndef __SYNTH__
#define __SYNTH__

#include <stdint.h>

#include "../util/FIFO.h"


/*
 * This functions waits until the next output should be calculated,
 * while moving data to the midiBuffer FIFO
 */
void busyWaiting( FIFOBuffer* midiBuffer );
/*
 * This functions writes the current output to the output buffer
 */
void writeBuffer( int32_t signal );
/*
 * This function is used to initiate the hardware, creates file on windows,
 * sets up PLL, timers and GPIO on Stellaris
 */
void initiateHardware();
/*
 * Returns 1 if the program should continue execution and 0 if it should terminate,
 * on windows this should be replaced by an actual function.
 */
#define loopCondition() 1


#endif
