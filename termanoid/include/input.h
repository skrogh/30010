
#ifndef _INPUT_H
#define _INPUT_H
enum { LEFT, RIGHT, JOYSTICK_X };
extern char inputvalues[2];
void init_input();
void get_input();
#endif
