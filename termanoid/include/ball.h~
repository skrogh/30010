
#ifndef _BALL_H
#define _BALL_H

typedef struct tag_ball ball_t;

struct tag_ball {
	short x;
	short y;
	short speed;
	int direction; //512 angles
	void * internals;
	void (*render)( ball_t * ball );
	void (*update)( ball_t * ball );
	void (*check_collision)( ball_t * ball, void * other, char other_ID );
};

ball_t * create_ball();
void destroy_ball( ball_t * ball );
#endif
