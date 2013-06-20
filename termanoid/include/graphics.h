
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#define PUTTY // define as putty
#undef HYPER_T // define as ny hyperterminal 

#define ESC 0x1B
#define true 1
#define false 0

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

//constants for drawing background, 1 indentet
extern unsigned char bgx;
extern unsigned char bgy;
extern unsigned char bgcolor; // 0xab, a = foreground b = background
extern const unsigned char* currentBg;

extern const unsigned char lady[];


void gotoxy( unsigned char x, unsigned char y );
void clrscr();
void reset_term();
void background_color( unsigned char color );
void foreground_color( unsigned char color );
void color( unsigned char foreground, unsigned char background );
void draw_chars( char * chars, unsigned char _color );
void draw_char( unsigned char symbol, unsigned char _color );
void draw_whole_bg();
#endif
