
#ifndef _STRIKER_H
#define _STRIKER_H

#define STRIKER_GRAPHIC "΋΋΋΋΋"

typedef struct tag_striker striker_t; //make striker_t known to the compiler

struct tag_striker {
	char x;
	char y;
	char x_velocity;
	char x_direction;
	void * cleanup;
	void ( *render )( striker_t * striker );
	void ( *update )( striker_t * striker );
};

striker_t * create_striker( char x, char y );
#endif

