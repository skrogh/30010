#ifndef _LEVELS_H
#define _LEVELS_H

#define NUM_LEVELS 5

typedef struct tag_level level_t;

struct tag_level {
	unsigned char num_bricks;
	const unsigned char * brick_arrangement;
	const unsigned char ** background; /* zds doesn't compile code with a single 
										  level of indirection correctly */
};

extern level_t current_level;
extern brick_t * bricks[];

void load_level( char level );
void start_current_level();
void cleanup_current_level();
void end_current_level();

#endif
