#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "lut.h"


#define FIX2_14 int
#define FIX2_14_SHIFT 14
#define FIX2_14_MULT( a, b )	( ( (long)(a) * (long)(b) ) >> FIX2_14_SHIFT )
#define FIX2_14_DIV( a, b )		( ( (long)(a) << FIX2_14_SHIFT ) / (b)
#define FIX16_16 long
#define FIX16_16_SHIFT 16
#define FIX16_16_MULT( a, b )	( ( (long long)(a) * (long long)(b) ) >> FIX16_16_SHIFT )
#define FIX16_16_DIV( a, b )		( ( (long long)(a) << FIX2_14_SHIFT ) / (b) )
#define FIX18_14_MULT( a, b )   ( ( (long long)(a) * (long long)(b) ) >> FIX2_14_SHIFT )
#define cos( angle ) sin( (int)(angle) + 128 )  //cos( x ) = sin( x + 128 ) when 2pi = 512 degrees
#define VECTOR2( v, a, b ) initVector( (v), (int)(a), (int)(b) )

typedef struct {
	long x;
	long y;
} vector; 

void printFix( long i ) {
	if ( ( i & 0x80000000) != 0 ) {
    	printf( "-" );
		i = ~i + 1;
	}
	printf("%ld.%04ld", i>>16, 10000*(unsigned long) (i & 0xffff) >> 16);
}

long expand( long i ) {
	return i << 2;
}

long sin( int angle ) { //angle in 512degrees
	int modangle = angle & 0x1ff; // loop over so 0<=modangle<512
	return SIN[modangle];
}

void rotate( vector * vectorptr, int deg ) {
	long cosdeg = cos( deg ); //convert 2.14 from sin() to 18.14
	long sindeg = sin( deg ); // convert 2.14 from sin() to 18.14
	long tempx = vectorptr -> x;
	long tempy = vectorptr -> y;
	vectorptr -> x = (long) ( (long) FIX18_14_MULT( tempx, cosdeg ) - (long) FIX18_14_MULT( tempy, sindeg ) );
	vectorptr -> y = (long) ( (long ) FIX18_14_MULT( tempx, sindeg ) + (long) FIX18_14_MULT( tempy, cosdeg ) );
}

void initVector( vector* vec, int x, int y ) {
	vec -> x = (long) x << 14;	   //convert to 18_14
	vec -> y = (long) y << 14;
}
	

void main() {
	vector * vector1;
	vector * vector2;
	vector * vector3;
	vector * vector4;
	init_uart( _UART0, _DEFFREQ, _DEFBAUD );
	clrscr();
	
	VECTOR2( vector1, 1, 2 );
	VECTOR2( vector2, 6, 4 );
	VECTOR2( vector3, -4, -4 );
	VECTOR2( vector4, -4, 2 );
	printf( "Hej mor, se mig, jeg er i terminalen <3 \n" );
/*
	printFix( expand( sin( 0 ) ) ); 
	printf( "\n" );
	printFix( expand( sin( 64 ) ) ); 
	printf( "\n" );
	printFix( expand( sin( -111 ) ) ); 
	printf( "\n" );
	printFix( expand( sin( 923 ) ) ); 
	printf( "\n" );

	printFix( expand( cos( 0 ) ) ); 
	printf( "\n" );
	printFix( expand( cos( 64 ) ) ); 
	printf( "\n" );
	printFix( expand( cos( -111 ) ) ); 
	printf( "\n" );
	printFix( expand( cos( 923 ) ) ); 
	printf( "\n" );
	printFix( expand( sin( 256 ) ) ); 
	printf( "\n" );
	printFix( expand( cos( 256 ) ) ); 
	printf( "\n" );

*/	
	rotate( vector1, 256 );
	printf( "vector1 \n" );
	printFix( vector1 -> x << 2 );
	printf( " , " );
	printFix( vector1 -> y << 2 );
	printf( "\n" );

	rotate( vector2, -14 );
	printf( "vector2 \n" );
	printFix( vector2 -> x << 2 );
	printf( " , " );
	printFix( vector2 -> y << 2 );
	printf( "\n" );

	rotate( vector3, 1280 );
	printf( "vector3 \n" );
	printFix( vector3 -> x << 2 );
	printf( " , " );
	printFix( vector3 -> y << 2 );
	printf( "\n" );
	
	rotate( vector4, -50 );
	printf( "vector4 \n" );
	printFix( vector4 -> x << 2 );
	printf( " , " );
	printFix( vector4 -> y << 2 );
	printf( "\n" );
	
	printf( "Victory!!! \n" );
	while(1);
}
