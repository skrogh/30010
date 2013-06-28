
#ifndef _INPUT_H
#define _INPUT_H
enum { LEFT, RIGHT, JOYSTICK_X, ACTION_BUTTON };
extern unsigned char inputvalues[4];
void get_input();
void setup_input();
#endif
