
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#define PUTTY // define as putty
#undef HYPER_T // define as ny hyperterminal 

#define ESC 0x1B
#define true 1
#define false 0

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40
#define BACKGROUND_WIDTH 80
#define BACKGROUND_HEIGHT 40
//constants for drawing background, 1 indentet

void gotoxy( unsigned char x, unsigned char y );
void clrscr();
void reset_term();
void background_color( unsigned char color );
void foreground_color( unsigned char color );
void color( unsigned char foreground, unsigned char background );
void draw_chars_bg( char * chars, unsigned char _color );
void draw_char_bg( unsigned char symbol, unsigned char _color );
void draw_whole_bg();
void set_monochrome( char truefalse );
void set_background( const unsigned char * background );
void draw_borders();
#endif
