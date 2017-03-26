#include "displaycontroller.h"

DisplayController* disp;

void setup()
{
	// Setup display controller with the pinnumbers toward the shift registers
	disp = new DisplayController({ 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 });

	disp->setContent(0, 0);
	disp->setContent(1, 1);
	disp->setContent(2, 2);
	disp->setContent(3, 3);
	disp->setContent(4, 4);
	disp->setContent(5, 5);
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
	//for (byte i = 2; i < 6; i++)
	//{
	//	disp->setBrightness(i);
	//	delay(250);
	//}
  /* add main program code here */

}

// Triggered on interrupt
ISR(TIMER1_COMPA_vect)
{
	disp->next();
}