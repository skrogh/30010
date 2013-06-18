
#ifndef _BALL_H
#define _BALL_H

typedef struct tag_ball ball_t;

struct tag_ball {
	char x;
	char y;
	char x_velocity;
	char y_velocity;
	void * internals;
	void (*render)( ball_t * ball );
	void (*update)( ball_t * ball );
	void (*check_collision)( ball_t * ball, void * other, char other_ID );
};

ball_t * create_ball();
void destroy_ball( ball_t * ball );
#endif
