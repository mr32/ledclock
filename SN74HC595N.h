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
	byte p_SER;
	byte p_RCLK;
	byte p_SRCLK;
	byte p_SRCLR;
	byte p_OE;

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

