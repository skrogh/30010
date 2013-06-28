
#ifndef _BALL_H
#define _BALL_H

#define BALL_SPAWN_X 40
#define BALL_SPAWN_Y 25
#define BALL_SPAWN_DIRECTION 128
#define BALL_SPAWN_SPEED 1
enum {SPAWNED, ALIVE, DEAD};
typedef struct tag_ball ball_t;

struct tag_ball {
	short x;
	short y;
	int score;
	char state;
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
