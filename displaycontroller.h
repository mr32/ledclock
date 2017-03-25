// display.h

#ifndef _DISPLAY_h
#define _DISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SN74HC595N.h"

class DisplayController
{
private:
	// Private variables
	byte content_[6] = { B00000000 };
	byte enabledDisplay_;
	byte dutycycle_;

	ShiftRegisterPins segmentPins_;
	ShiftRegisterPins displayPins_;
	ShiftRegister* segment_;
	ShiftRegister* display_;

	// Private functions
	byte toSevenSegment_(byte input);

public:
	DisplayController(ShiftRegisterPins pinsSegmentRegister, ShiftRegisterPins pinsDisplayRegister);
	~DisplayController();

	// Cycle to the next display to print its data
	void next();

	// Set the display's content
	void setContent(byte id);

	// Set the display's brightness
	void setDutyCycle(byte dc);

	// Get the display's content
	byte getContent(byte id);

	// Get the display's brightness
	byte getDutyCycle();
};

#endif

