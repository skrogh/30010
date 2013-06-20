
#ifndef _BRICK_H
#define _BRICK_H
#define BRICK_GRAPHICS "\xAE\xCD\xCD\xAF"
#define BRICK_SPACES "    "
#define BRICK_COLOR 0xC0
#define BRICK_WIDTH 4
#define BRICK_HEIGHT 1
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
