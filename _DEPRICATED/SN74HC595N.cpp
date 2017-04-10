#include "SN74HC595N.h"

ShiftRegister::ShiftRegister(ShiftRegisterPins pins)
{
	// Set pin values
	p_ = pins;

	// Set pin modes
	pinMode(p_.SER, OUTPUT);
	pinMode(p_.RCLK, OUTPUT);
	pinMode(p_.SRCLK, OUTPUT);
	pinMode(p_.SRCLR, OUTPUT);
	if (p_.OE != -1) { pinMode(p_.OE, OUTPUT); }

	// Set default values
	if (p_.OE != -1) { digitalWrite(p_.OE, LOW); }			// Enable output
	digitalWrite(p_.SRCLR, LOW);							// Reset register
	digitalWrite(p_.SER, LOW);
	digitalWrite(p_.RCLK, LOW);
	digitalWrite(p_.SRCLK, LOW);
}

ShiftRegister::~ShiftRegister()
{
	// Reset output
	digitalWrite(p_.SER, LOW);
	digitalWrite(p_.RCLK, LOW);
	digitalWrite(p_.SRCLK, LOW);
	digitalWrite(p_.SRCLR, LOW);
	digitalWrite(p_.OE, HIGH);							// Disable output
}

byte ShiftRegister::S2P(byte input)
{
	digitalWrite(p_.SRCLR, HIGH);

	for (byte i = 0; i < 8; i++)
	{
		digitalWrite(p_.SER, bitRead(input, i));
		digitalWrite(p_.SRCLK, HIGH);
		digitalWrite(p_.SRCLK, LOW);
	}
	digitalWrite(p_.RCLK, HIGH);
	digitalWrite(p_.RCLK, LOW);
	
	return 1;
}

void ShiftRegister::shift()
{
	// Make sure first input is zero
	digitalWrite(p_.SER, LOW);
	// Make sure the output is not reset
	digitalWrite(p_.SRCLR, HIGH);
	// Shift existing content with one place
	digitalWrite(p_.SRCLK, HIGH);
	// Enable the output, if it wasn't already
	delayMicroseconds(50);
	//digitalWrite(p_.OE, LOW);
	// Lower the clock
	digitalWrite(p_.SRCLK, LOW);
	delayMicroseconds(50);
	// Store to storage
	digitalWrite(p_.RCLK, HIGH);

	delayMicroseconds(50);
	// Lower store clock
	digitalWrite(p_.RCLK, LOW);

}

void ShiftRegister::reset()
{
	// Reset data on shift register
	digitalWrite(p_.SRCLR, LOW);
	digitalWrite(p_.SRCLR, HIGH);
}

void ShiftRegister::disable()
{
	digitalWrite(p_.OE, HIGH);
}

void ShiftRegister::enable()
{
	digitalWrite(p_.OE, LOW);
}