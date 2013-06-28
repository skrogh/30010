#ifndef _SOUND_H
#define _SOUND_H

#define WINNING_SOUND 0
#define BRICK_COLLISION_SOUND 1
#define BORDER_COLLISION_SOUND 2
#define STRIKER_COLLISION_SOUND 2
#define DEATH_SOUND 3

void setup_sound();
void play_sound( unsigned char sound );

#endif
