// 
// 
// 

#include "SN74HC595N.h"

ShiftRegister::ShiftRegister(int SER, int RCLK, int SRCLK, int SRCLR, int OE)
{
	// Set pin values
	p_SER = SER;
	p_RCLK = RCLK;
	p_SRCLK = SRCLK;
	p_SRCLR = SRCLR;
	p_OE = OE;
}

ShiftRegister::~ShiftRegister()
{
	// Reset output
	digitalWrite(p_SER, LOW);
	digitalWrite(p_RCLK, LOW);
	digitalWrite(p_SRCLK, LOW);
	digitalWrite(p_SRCLR, LOW);
	digitalWrite(p_OE, HIGH);
}

void ShiftRegister::S2P(int input)
{

}