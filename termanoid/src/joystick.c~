
#include <eZ8.h>
#include <gpio.h>
#include <sio.h>

void setup_joystick() {
	//joystick located on PB0
	//set up PB0 for alternate function
	PBADDR = 0x02; // select alternate function
	PBCTL = 0x00; //reset pins
	PBCTL |= 0x00; //set PB0 for alternate input
	PBADDR = 0x00; //stop configuring

	// enable ADC for PB0, continous mode with internal VREF
	ADCCTL = 0x90;
}

unsigned char read_joystick_x() {
	return ADCD_H;
}

