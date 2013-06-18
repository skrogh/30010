
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#define ESC 0x1B
#define true 1
#define false 0

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

void gotoxy( unsigned char x, unsigned char y );
void clrscr();
void background_color( unsigned char color );
void foreground_color( unsigned char color );
void color( unsigned char foreground, unsigned char background );
void draw_chars( char * chars );
void draw_char( unsigned char symbol );
#endif
