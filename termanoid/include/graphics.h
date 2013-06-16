
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#define CURRENT_COLOR current_foreground * 8 + current_background
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

void gotoxy( unsigned char x, unsigned char y );
void clrscr();
void background_color( char color );
void foreground_color( char color );
void color( char foreground, char background );
void setup_colors();
void init_graphics();
void draw_chars( char * chars );
#endif
