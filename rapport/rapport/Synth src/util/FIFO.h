#ifndef __FIFO__
#define __FIFO__

#include <stdint.h>

// typedef structs:
typedef struct tag_FIFOBuffer FIFOBuffer;

struct tag_FIFOBuffer { //FIFO buffer
	uint32_t* data; // data array
	uint32_t length; // array size
	uint32_t pointer; // address (in array) of next element
	uint32_t elements; // number of  elements in fifo
	/*
	 * push @data into the buffer, returns 1 on success, 0 on full buffer
	 */
	uint32_t (*push)( FIFOBuffer* fifoBuffer, uint32_t data );
	/*
	 * Pops a data element from the buffer into the address specified by the pointer @data.
	 * If there is no data to pop, 0 is returned and @data is not changed, else 1 is returned.
	 */
	uint32_t (*pop)( FIFOBuffer* fifoBuffer, uint32_t* data );
	/*
	 * Peaks at a data element from the buffer and puts it into the address specified by the pointer @data,
	 * without removing it from the buffer.
	 * @depth specifies how far to look into the buffer.
	 * If there is no data to pop, 0 is returned and @data is not changed, else 1 is returned.
	 */
	uint32_t (*peak)( FIFOBuffer* fifoBuffer, uint32_t* data, uint32_t depth ); // peak at the element depth into the stack (0 = top, 1 = just under top) - returns 1 if that element exists.
};

/*
 * Creates a FIFO buffer, given a pointer to an array @dataArray where the data can be stored
 * and the length of said array, @arrayLength
 */
void createFIFOBuffer( FIFOBuffer* fifoBuffer, uint32_t* dataArray, uint32_t arrayLength );

#endif
