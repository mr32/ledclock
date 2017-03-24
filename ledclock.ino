#include "SN74HC595N.h"

ShiftRegister* test = new ShiftRegister(2, 3, 4, 5);

void setup()
{
	 /* add setup code here */
	test->S2P(toSevenSegment(11));
}

void loop()
{

	for (byte i = 0; i < 10; i++)
	{
		test->S2P(toSevenSegment(i));
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
