// SN74HC595N.h

#ifndef _SN74HC595N_h
#define _SN74HC595N_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ShiftRegister
{
private:
	byte SER_;
	byte RCLK_;
	byte SRCLK_;
	byte SRCLR_;
	byte OE_;

public:
	// Constructor
	ShiftRegister(byte SER, byte RCLK, byte SRCLK, byte SRCLR, byte OE = -1);

	// Destructor (sets pins to 0)
	~ShiftRegister();

	// Serial 2 Parallel
	//	int input: 8-bit character to be set on the eight output ports QA to QH
	void S2P(byte input);
};

#endif

