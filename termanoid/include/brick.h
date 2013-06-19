
#ifndef _BRICK_H
#define _BRICK_H
#define BRICK_GRAPHICS "DURR"
#define BRICK_SPACES "    "

typedef struct tag_brick brick_t;

struct tag_brick {
	short x;
	short y;
	char lives;
	void (*collided)( brick_t * brick ); // can only happen with a ball
	void (*render)( brick_t * brick );
};

brick_t * create_brick( short x, short y, char lives );
void destroy_brick( brick_t * brick );

#endif
