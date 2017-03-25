#include "SN74HC595N.h"

ShiftRegister* segmentSelector = new ShiftRegister(2, 3, 4, 5);
ShiftRegister* displaySelector = new ShiftRegister(6, 7, 8, 9);

void setup()
{
	segmentSelector->S2P(toSevenSegment(11));


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

	for (byte i = 0; i < 10; i++)
	{
		segmentSelector->S2P(toSevenSegment(i));
		delay(500);
	}
	//test->S2P(toSevenSegment(0));
	//delay(5);
	//test->S2P(0);
	//delay(5);
  /* add main program code here */

}

byte toSevenSegment(byte number)
{
	byte r;

	// Assign segments to byte using: a-b-c-d-e-f-g-DP
	switch (number)
	{
	case 0:
		r = B11111100;
		break;
	case 1:
		r = B01100000;
		break;
	case 2:
		r = B11011010;
		break;
	case 3:
		r = B11110010;
		break;
	case 4:
		r = B01100110;
		break;
	case 5:
		r = B10110110;
		break;
	case 6:
		r = B10111110;
		break;
	case 7:
		r = B11100000;
		break;
	case 8:
		r = B11111110;
		break;
	case 9:
		r = B11110110;
		break;
	default:
		r = B00000010;
	}

	return r;
}

// Triggered on interrupt
ISR(TIMER1_COMPA_vect)
{

}