#include <eZ8.h>
#include <sio.h>
#include <gpio.h>
#include "timerlib.h"

#define SYSCLOCK 18432
#define PRESCALE 128

void (*timer0int_fp)(void);

#pragma interrupt
void timer0int() {
	timer0int_fp();
}

void set_timer( char timer, unsigned long u_period, char priority, void (*callback) ) {
	unsigned int reload_value = (unsigned int)( (unsigned long)( (unsigned long) u_period * (unsigned long) SYSCLOCK ) / ( (unsigned long)( (unsigned long)1000*(unsigned long)PRESCALE ) ) );

	timer0int_fp = callback;
	T0CTL = 0x00;
	T0CTL = 0x39;
	T0H = 0x00;
	T0L = 0x01;
	T0RH = (unsigned char)( (reload_value & 0xFF00) >> 8);
	T0RL = (unsigned char)(reload_value & 0x00FF);
	IRQ0ENH |= 0x20;
	IRQ0ENL &= 0xDF;
	EI();
	SET_VECTOR( TIMER0, timer0int );


	T0CTL |= 0x80;
	//SET_VECTOR( TIMER0, callback );

}
