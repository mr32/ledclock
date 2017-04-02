#include "displaycontroller.h"

DisplayController* disp;
String buffer;
boolean EOL_;
unsigned long time; 
unsigned long offset = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(12, INPUT);
	pinMode(13, OUTPUT);
	// Setup display controller with the pinnumbers toward the shift registers
	disp = new DisplayController({ 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 });
	buffer.reserve(64);

	disp->setContent(0, 10);
	disp->setContent(1, 10);
	disp->setContent(2, 10);
	disp->setContent(3, 10);
	disp->setContent(4, 10);
	disp->setContent(5, 10);
	disp->setBrightness(5);

	// Setup ISR
	noInterrupts();					// Disable interrupts
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;

	OCR1A = 25;					// Compare match register for 2500Hz
	TCCR1B |= (1 << WGM12);			// Set to CTC mode
	TCCR1B |= (1 << CS12);			// Set pre-scalar to 256
	TIMSK1 |= (1 << OCIE1A);		// Enable Timer Compare Interrupt

	interrupts();					// Enable interrupts
}

void loop()
{
	digitalWrite(13, digitalRead(12));
	update();
}

// Triggered on interrupt
ISR(TIMER1_COMPA_vect)
{
	disp->next();
}

void update()
{
	if (EOL_ == true)
	{
		if (buffer.substring(0, 6) == "$GPGLL")
		{
			// Find fifth occurance of the , delimiter in the message
			byte start = 0;
			for (byte i = 0; i < 5; i++)
			{
				start = buffer.indexOf(',', start) + 1;

				if (start == -1)
				{
					buffer = "";
					EOL_ = false;
					return;
				}
			}

			// Extract the time from the starting position
			time = buffer.substring(start, start + 6).toInt();

			Serial.println(time);
			setTime(time);
		}

		buffer = "";
		EOL_ = false;
	}
}

void serialEvent()
{
	while (Serial.available())
	{
		char input = (char)Serial.read();

		buffer += input;

		if (input == '\n')
			EOL_ = true;
	}
}

void setTime(unsigned long time)
{
	time = time + offset;
	byte i = 0;

	do {
		int digit = time % 10;
		disp->setContent(i, digit);
		i++;
		time /= 10;
	} while (time > 0);
}