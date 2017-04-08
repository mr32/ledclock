#include "gpstime.h"
#include "displaycontroller.h"

GPSTIME* time;
DisplayController* disp;

void setup()
{
	// Setup display controller with the pinnumbers toward the shift registers
	disp = new DisplayController({ 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 });
	time = new GPSTIME(12, setTime);

	disp->setContent(0, 10);
	disp->setContent(1, 10);
	disp->setContent(2, 10);
	disp->setContent(3, 10);
	disp->setContent(4, 10);
	disp->setContent(5, 10);
	disp->setBrightness(5);

	// Setup ISR
	noInterrupts();					// Disable interrupts
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;

	OCR1A = 25;					// Compare match register for 2500Hz
	TCCR1B |= (1 << WGM12);			// Set to CTC mode
	TCCR1B |= (1 << CS12);			// Set pre-scalar to 256
	TIMSK1 |= (1 << OCIE1A);		// Enable Timer Compare Interrupt

	interrupts();					// Enable interrupts
}

void loop()
{

}

// Triggered on interrupt
ISR(TIMER1_COMPA_vect)
{
	disp->next();
}

void serialEvent()
{
	time->serialIn();
}

void setTime(unsigned long time)
{
	byte i = 0;

	do {
		int digit = time % 10;
		disp->setContent(i, digit);
		i++;
		time /= 10;
	} while (time > 0);

}