#include "displaycontroller.h"

DisplayController* disp;

void setup()
{
	// Setup display controller with the pinnumbers toward the shift registers
	disp = new DisplayController({ 2, 3, 4, 5 }, { 6, 7, 8, 9 });

	// Setup ISR
	noInterrupts();					// Disable interrupts
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;

	OCR1A = 31250;					// Compare match register for 250Hz
	TCCR1B |= (1 << CS12);			// Set pre-scalar to 256
	TIMSK1 |= (1 << OCIE1A);		// Enable Timer Compare Interrupt

	interrupts();					// Enable interrupts
}

void loop()
{

  /* add main program code here */

}

// Triggered on interrupt
ISR(TIMER1_COMPA_vect)
{

}