// 
// 
// 

#include "gpstime.h"

GPSTIME::GPSTIME(byte pPPS, void (*callback)(char*))
{
	if (pPPS == 2 || pPPS == 3)
	{
		pPPS_ = pPPS;
		attachInterrupt(pPPS_, sync, RISING);
	}
	buffer_.reserve(64);
	triggerUpdate_ = callback;

	pinMode(pPPS_, INPUT);
	pinMode(13, OUTPUT);

	Serial.begin(9600);
}

GPSTIME::~GPSTIME()
{
	detachInterrupt(pPPS_);
}

void GPSTIME::writeTime()
{
	if (EOL_ == true)
	{
		if (buffer_.substring(0, 6) == "$GPGLL")
		{
			// Find fifth occurance of the , delimiter in the message
			byte start = 0;
			for (byte i = 0; i < 5; i++)
			{
				start = buffer_.indexOf(',', start) + 1;

				if (start == -1)
				{
					buffer_ = "";
					EOL_ = false;
					return;
				}
			}

			// Extract the time from the starting position
			buffer_.substring(start, start + 6).toCharArray(t_, 7);
			//time_ = time_ + offset_;

			Serial.println(t_);
			triggerUpdate_(t_);
		}

		buffer_ = "";
		EOL_ = false;
	}
}

void GPSTIME::serialIn()
{
	while (Serial.available())
	{
		char input = (char)Serial.read();

		buffer_ += input;

		if (input == '\n')
		{
			EOL_ = true;
			writeTime();
		}
	}
}

void GPSTIME::sync()
{
	// This is called when the PPS signal goes high
	// When that is the case, increment the time following this signal
	// The information will now be ahead of the serial GPS time


}