#include "SN74HC595N.h"

ShiftRegister::ShiftRegister(byte SER, byte RCLK, byte SRCLK, byte SRCLR, byte OE)
{
	// Set pin values
	SER_ = SER;
	RCLK_ = RCLK;
	SRCLK_ = SRCLK;
	SRCLR_ = SRCLR;
	OE_ = OE;

	// Set pin modes
	pinMode(SER_, OUTPUT);
	pinMode(RCLK_, OUTPUT);
	pinMode(SRCLK_, OUTPUT);
	pinMode(SRCLR_, OUTPUT);
	if (OE_ != -1) { pinMode(OE_, OUTPUT); }

	// Set default values
	if (OE_ != -1) { digitalWrite(OE_, LOW); }		// Enable output
	digitalWrite(SRCLR_, LOW);							// Reset register
	digitalWrite(SER_, LOW);
	digitalWrite(RCLK_, LOW);
	digitalWrite(SRCLK_, LOW);
}

ShiftRegister::~ShiftRegister()
{
	// Reset output
	digitalWrite(SER_, LOW);
	digitalWrite(RCLK_, LOW);
	digitalWrite(SRCLK_, LOW);
	digitalWrite(SRCLR_, LOW);
	digitalWrite(OE_, HIGH);							// Disable output
}

void ShiftRegister::S2P(byte input)
{
	digitalWrite(SRCLR_, HIGH);

	for (byte i = 0; i < 8; i++)
	{
		digitalWrite(SER_, bitRead(input, i));
		digitalWrite(SRCLK_, HIGH);
		digitalWrite(SRCLK_, LOW);
	}

	digitalWrite(RCLK_, HIGH);
	digitalWrite(RCLK_, LOW);
}