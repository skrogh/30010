// Hardware dependent functions. change these when changing hardware

#include <stdint.h>

#define PART_LM4F120H5QR
#define TARGET_IS_BLIZZARD_RA1

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"

#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"

#include "hardInterface.h"

#include "../util/FIFO.h"


/***HIDEN FUNCTIONS START***/

//Local "globals". As these are not in the header file, they are local to the hardInterface.c file and cannot be accessed directly
uint32_t volatile outputBuffer = 127; // is read in an interrupt, thus volatile - this also explains the need for a global
uint32_t volatile busy = 1; // is set in an interrupt, thus volatile - this also explains the need for a global

/*
 * Setup the cpu, use external 16MHZ crystal and PLL to 80MHz
 */
void setupCPU() {
	// 80MHz, use PLL, external crystal (16MHz)
	SysCtlClockSet( SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN );
}

/*
 * Setup and enable an interrupt, firering at 44kHz.
 * set Timer0IntHandler as the function for Timer 0 subtimer A in the interrupt vector table
 * in startup_ccs.c
 */
void setupLoop() {
	// Enable periphery
	SysCtlPeripheralEnable( SYSCTL_PERIPH_TIMER0 ); // timer0 (realtime loop)

	// Configure loop timer
	TimerConfigure(TIMER0_BASE, TIMER_CFG_32_BIT_PER); // setup loop timer
	TimerLoadSet(TIMER0_BASE, TIMER_A, ( SysCtlClockGet() / 44000 ) - 1); // set period (freq=44000)
	IntEnable(INT_TIMER0A); // enable interrupt on timer 0A
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT); // on timer timeout
	IntMasterEnable(); // enable interrupts globally

	TimerEnable(TIMER0_BASE, TIMER_A); // start the timer
}

/*
 * Setup GPIO, both LEDs
 * and PWM output
 */
void setupOutput() {
	SysCtlPeripheralEnable( SYSCTL_PERIPH_TIMER1 ); // timer1 (output)
	SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOF ); // outputs on port F (LEDS, BUTTONS)

	// Turn off LEDs
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);

	// PF2 as PWM
	GPIOPinConfigure(GPIO_PF2_T1CCP0);
	GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_2);

	// Configure output timer
	TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM|TIMER_CFG_B_PWM); // setup both as pwm
	TimerLoadSet(TIMER1_BASE, TIMER_A, 0x00FF); // 8-bit for ~300kHz carrier
	TimerMatchSet(TIMER1_BASE, TIMER_A, 0); // PWM
	TimerEnable(TIMER1_BASE, TIMER_A); // Start
}

/*
 * Setup SPI input from SPI(3) as slave, port D
 * D0 = CLK, D1 = SS, D2 = MOSI, D3 = MISO (not used)
 * (SSI is TI's version of SPI, it covers both MICROWIRE, FREESCALE and TI's protocol)
 */
void setupSPI(){
	//

	//enable peripehri
	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI3);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	//setup weak pullups
	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);

	// mux the ssi module to port D
	GPIOPinConfigure(GPIO_PD0_SSI3CLK);
	GPIOPinConfigure(GPIO_PD1_SSI3FSS);
	GPIOPinConfigure(GPIO_PD2_SSI3RX);
	GPIOPinConfigure(GPIO_PD3_SSI3TX);

	// set the pins to be ssi pins
	GPIOPinTypeSSI(GPIO_PORTD_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 );

	// setup the ssi
	SysCtlPeripheralReset(SYSCTL_PERIPH_SSI3);
	SSIDisable(SSI3_BASE);
	SSIConfigSetExpClk(SSI3_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_1, SSI_MODE_SLAVE, 4608000, 8);
	SSIEnable(SSI3_BASE);
}

/*
 * Write output buffer to PWM
 */
void writeOutput() {
	TimerMatchSet(TIMER1_BASE, TIMER_A, outputBuffer); // PWM
}

/*
 * Interrupt function fired @ 44kHz
 */
void Timer0IntHandler( ) {
	// Clear interrupt flag
	TimerIntClear( TIMER0_BASE, TIMER_TIMA_TIMEOUT );

	writeOutput();
	busy = 0;
}

/*
 * Function for turning LED off, used for checking timing of realtime loop
 */
void timingEnd(){
	GPIOPinWrite( GPIO_PORTF_BASE, GPIO_PIN_3, 0 );
}

/*
 * Function for turning LED on, used for checking timing of realtime loop
 */
void timingStart(){
	GPIOPinWrite( GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3 );
}

/*
 * Moves data from the SPI FIFO (depth of 8) to the software FIFO (depth of 9)
 */
void processMIDIBuffer( FIFOBuffer* dataBuffer ){
	unsigned long data;
	while( SSIDataGetNonBlocking( SSI3_BASE, &data ) != 0 ) { // for all data in the buffer
		dataBuffer -> push( dataBuffer, data );
	}
}


/***HIDEN FUNCTIONS END***/





void busyWaiting( FIFOBuffer* midiBuffer ) {
	timingStart(); // turn green LED on for timing

	while(busy) // Busy waiting
		processMIDIBuffer( midiBuffer ); // move midi from SPI buffer, to software buffer

	timingEnd(); // turn green LED off for timing - more green means more waiting ~ good

	// move the midi buffer, just to be sure it is done at least once just before the loop
	processMIDIBuffer( midiBuffer );

	// set bussy.
	busy = 1;
}

void writeBuffer( int32_t signal) {
	outputBuffer = ( signal >> 24 ) + 127;
}

void initiateHardware() {
	setupCPU();
	setupOutput();
	setupLoop();
	setupSPI();
}

