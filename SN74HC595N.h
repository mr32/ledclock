// SN74HC595N.h

#ifndef _SN74HC595N_h
#define _SN74HC595N_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

struct ShiftRegisterPins
{
	byte SER;
	byte RCLK;
	byte SRCLK;
	byte SRCLR;
	byte OE;
};

class ShiftRegister
{
private:
	ShiftRegisterPins p_;

public:
	// Constructor
	ShiftRegister(ShiftRegisterPins pins);

	// Destructor (sets pins to 0)
	~ShiftRegister();

	// Serial 2 Parallel
	//	int input: 8-bit character to be set on the eight output ports QA to QH
	void S2P(byte input);

	// Shift the data one place
	void shift();

	// Reset data on the shift register
	void reset();

	// Disable output
	void disable();

	// Enable output
	void enable();
};

#endif

