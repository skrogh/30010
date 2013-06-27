#ifndef _SOUND_H
#define _SOUND_H

enum { WINNING_SOUND, BRICK_COLLISION_SOUND, BORDER_COLLISION_SOUND=2, STRIKER_COLLISION_SOUND=2, DEATH_SOUND=3 }; 
void setup_sound();
void play_sound( unsigned char sound );

#endif
