
#ifndef _MATH_H
#define _MATH_H

#define FIX14_SHIFT 14
#define FIX8_8_SHIFT 8
#define FIX8_8_MULT( a, b ) ( ( (short)(a) * (short)(b) ) >> FIX8_8_SHIFT
#define FIX8_8_DIV( a, b ) ( ( ((long)(a) << FIX8_8_SHIFT ) / (b) )
#define cos( angle ) sin( (int)(angle) + 128 ) //cos = sin( x + 128 ) when 2pi = 512 

signed short sin( int angle_512 );


#endif
