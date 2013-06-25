#include <ez8.h>
#include <sio.h>
#include <gpio.h>

void setup_SPI_master() {
	//port C contains spi pins
	//set up port C for alternate function
	PCADDR = 0x02;
	PCCTL = 0x00; // reset pins
	PCCTL |= 0x04; // alternate function for slave select
	PCCTL |= 0x08; // alternate function for SCK
	PCCTL |= 0x10; // alternate function for MOSI
	PCCTL |= 0x20; // alternate function for MISO
	
	PCADDR = 0x01; // start configuring pin data directions
	PCCTL = 0x00; // reset data direction register
	PCCTL |= 0x20; // configure MISO for input, all others as output
	PCADDR = 0x00;

	//configure SPI mode register, numbits 8
	SPIMODE &= 0xE0; // reset non reserved bits
	SPIMODE |= 0x03; // set slave select as output and drive slave select high

	//configure SPI control register and baud rate
	SPICTL = 0x00; //reset register
	SPIBRH = 0x00; // set baud high register
	SPIBRL = 0x02; // set baud low to max speed
	SPICTL |= 0x08; // set clock polarity 1
	SPICTL |= 0x20; // enable SCK generation
	SPICTL |= 0x03; // set master mode enable and enable spi

}

void write_spi( unsigned char data ) {
	SPIMODE &= 0xFE; //drive SS low to initiate transfer
	SPIDATA = data;
	while ( ( 0x02 & SPISTAT ) ) { } //busy wait until transfer is complete
	SPIMODE |= 0x01; // drive SS high again
}


