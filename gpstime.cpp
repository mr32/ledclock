// 
// 
// 

#include "gpstime.h"

GPSTIME::GPSTIME(byte pPPS, void (*callback)(unsigned long))
{
	pPPS_ = pPPS;
	buffer_.reserve(64);
	triggerUpdate_ = callback;

	pinMode(pPPS_, INPUT);
	pinMode(13, OUTPUT);

	Serial.begin(9600);
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
			time_ = buffer_.substring(start, start + 6).toInt();
			//time_ = time_ + offset_;

			Serial.println(time_);
			triggerUpdate_(time_);
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