#include "SN74HC595N.h"

ShiftRegister::ShiftRegister(byte SER, byte RCLK, byte SRCLK, byte SRCLR, byte OE)
{
	// Set pin values
	p_SER = SER;
	p_RCLK = RCLK;
	p_SRCLK = SRCLK;
	p_SRCLR = SRCLR;
	p_OE = OE;

	// Set pin modes
	pinMode(p_SER, OUTPUT);
	pinMode(p_RCLK, OUTPUT);
	pinMode(p_SRCLK, OUTPUT);
	pinMode(p_SRCLR, OUTPUT);
	if (p_OE != -1) { pinMode(p_OE, OUTPUT); }

	// Set default values
	if (p_OE != -1) { digitalWrite(p_OE, LOW); }		// Enable output
	digitalWrite(p_SRCLR, LOW);							// Reset register
	digitalWrite(p_SER, LOW);
	digitalWrite(p_RCLK, LOW);
	digitalWrite(p_SRCLK, LOW);
}

ShiftRegister::~ShiftRegister()
{
	// Reset output
	digitalWrite(p_SER, LOW);
	digitalWrite(p_RCLK, LOW);
	digitalWrite(p_SRCLK, LOW);
	digitalWrite(p_SRCLR, LOW);
	digitalWrite(p_OE, HIGH);							// Disable output
}

void ShiftRegister::S2P(byte input)
{
	digitalWrite(p_SRCLR, HIGH);

	for (byte i = 0; i < 8; i++)
	{
		digitalWrite(p_SER, bitRead(input, i));
		digitalWrite(p_SRCLK, HIGH);
		digitalWrite(p_SRCLK, LOW);
	}

	digitalWrite(p_RCLK, HIGH);
	digitalWrite(p_RCLK, LOW);
}