
#ifndef _INPUT_H
#define _INPUT_H
enum { LEFT, RIGHT, JOYSTICK_X };
extern unsigned char inputvalues[2];
void init_input();
void get_input();
void setup_input();
#endif
