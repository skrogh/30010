

#ifndef _LED_H_
#define _LED_H_

extern char video_buffer[5][6];
extern char update;
extern char next_column; //the next column to be updated
extern unsigned char next_display; // the next display to have it's columns updated



void setupTimer0();
void timer0int();
void LEDinit();
void LEDsetString( char * string, char startposition, char strlength );
void updateColumn( char column, char display, char output );
void LEDupdate();
void shiftBuffer();
char getStringLength( char * string );

#endif