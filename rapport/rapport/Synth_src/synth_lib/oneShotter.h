#ifndef __ONE_SHOTTER__
#define __ONE_SHOTTER__

#include <stdint.h>

// typedef structs:
typedef struct tag_OneShotter OneShotter;

struct tag_OneShotter { //FIFO buffer
	int32_t playing; // indicates if the sound is playing or not.
	uint32_t counter; // counter for determining when to move the head
	uint32_t head; // play back head in the wave file.
	/*
	 * Updates the wave player. The player will replay on @trigger at @speed (0xFFFFFFFE being 44kHz),
	 * playing the wave file pointed to by @data and with length @length
	 */
	int32_t (*update)( OneShotter* oneShotter, int32_t trigger, uint32_t speed, const uint8_t* data, int32_t length ); // push data onto the buffer, true on success, false on full buffer
};


/*
 * Initializes the OneShotter module,
 */
void createOneShotter( OneShotter* oneShotter );


#endif
