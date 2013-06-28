
#ifndef _ANSI_H_
#define _ANSI_H_

#define ESC 0x1B
#define true 1
#define false 0

void fgcolor( int foreground );
void bgcolor( int background );
void color(int foreground, int background);
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy( int x, int y );
void underline( char on );
void blink( char on );
void reverse( char on );
void reset();
void textType();
char strLen( char* string );
void window( char x, char y, char width, char height, char* header, char type );

#endif
