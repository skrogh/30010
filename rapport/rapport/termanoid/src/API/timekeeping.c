#include "timekeeping.h"
#include "constants.h"
#include "timerlib.h"


void setup_timer( char timer, unsigned long u_period, char priority, void (*callback)(void) ) {
	set_timer( timer, u_period, priority, callback );
}

