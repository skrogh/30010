
#ifndef _STRIKER_H
#define _STRIKER_H
						 
#define STRIKER_GRAPHIC "\xC9\xDF\xDF\xDF\xDF\xDF\xDF\xBB"
#define STRIKER_COLOR 0xD8
#define STRIKER_WIDTH 8
#define STRIKER_SPACES "        "
typedef struct tag_striker striker_t; //make striker_t known to the compiler

struct tag_striker {
	short x;
	short y;
	short x_velocity;
	short x_direction;
	void * cleanup;
	void ( *render )( striker_t * striker );
	void ( *update )( striker_t * striker );
};

striker_t * create_striker( short x, short y );
void destroy_striker( striker_t * striker );
#endif

