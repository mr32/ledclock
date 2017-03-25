// 
// 
// 

#include "displaycontroller.h"


DisplayController::DisplayController(ShiftRegisterPins pinsSegmentRegister, ShiftRegisterPins pinsDisplayRegister)
{
	// Initialize controlling shift registers
	segment_ = new ShiftRegister(pinsSegmentRegister);
	display_ = new ShiftRegister(pinsDisplayRegister);
}

DisplayController::~DisplayController()
{
	// Safely delete shift registers
	delete segment_;
	delete display_;
}

void DisplayController::next()
{
	cycleCounter_ += 1;

	if (cycleCounter_ >= 5)
		cycleCounter_ = 0;
	else if (cycleCounter_ >= brightness_)
	{
		display_->disable();
		return;
	}
	
	// Cycle to the next display
	if (displayCounter_ == NUM_DISPLAYS - 1)
	{
		displayCounter_ = 0;
		display_->S2P(B00000001);
	}
	else
	{
		displayCounter_ += 1;
		display_->shift();
	}
	// Send data to shift register
	segment_->S2P(content_[displayCounter_]);
	display_->enable();

}

void DisplayController::setContent(byte id, byte content)
{
	// Ignore if ID is larger than the number of displays
	if (id > NUM_DISPLAYS)
		return;

	// Directly convert input to binary segments and store
	content_[id] = toSevenSegment_(content);
}

void DisplayController::setBrightness(byte brightness)
{
	brightness_ = brightness;
}

byte DisplayController::toSevenSegment_(byte input)
{
	byte r;

	// Assign segments to byte using: a-b-c-d-e-f-g-DP
	switch (input)
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
