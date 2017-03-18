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
	int p_SER;
	int p_RCLK;
	int p_SRCLK;
	int p_SRCLR;
	int p_OE;

public:
	/**
	*	\brief ShiftRegister Constructor
	*
	*	Setup the use of a shiftregister
	*
	*	\param SER Set SER pin number
	*	\param RCLK Set RCLK pin number
	*	\param SRCLK Set SRCLK pin number
	*	\param SRCLR Set SRCLR pin number
	*	\param OE Set optional OE pin number
	**/
	ShiftRegister(int SER, int RCLK, int SRCLK, int SRCLR, int OE = -1);

	// Destructor (sets pins to 0)
	~ShiftRegister();

	// Serial 2 Parallel
	//	int input: 8-bit character to be set on the eight output ports QA to QG
	void S2P(int input);
}

#endif

