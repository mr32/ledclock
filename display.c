#include "display.h"

void display_init()
{
    shiftreg_init(&displayreg, 8, 9, 10, 11);
    shiftreg_init(&segmentreg, 4, 5, 6, 7);

    currentDisplay = 0;
}

void display_set(uint8_t dispID, uint8_t content)
{
    // Store the content to the corresponding display buffer
    if (dispID < NO_DISPLAYS)
        disp[dispID] = toSegment(content);
}

static void next()
{
    // Go to the next display and show the right content
    shiftreg_s2p(&displayreg, (1 << currentDisplay));
    shiftreg_s2p(&segmentreg, disp[currentDisplay]);

    // Swap buffers to output
    shiftreg_set(&displayreg);
    shiftreg_set(&segmentreg);

    // Increase display counter for the next call
    currentDisplay = (currentDisplay + 1) % NO_DISPLAYS;
}

static uint8_t toSegment(char input)
{
    // Convert integer to segment (abcdefg) format
    uint8_t r;
    
    switch (input)
	{
	case -1:
		r = 0x00; // B00000000
		break;
	case 0:
		r = 0xFC; // B11111100
		break;
	case 1:
		r = 0x60; // B01100000
		break;
	case 2:
		r = 0xDA; // B11011010
		break;
	case 3:
		r = 0xF2; // B11110010
		break;
	case 4:
		r = 0x66; // B01100110
		break;
	case 5:
		r = 0xB6; // B10110110
		break;
	case 6:
		r = 0xBE; // B10111110
		break;
	case 7:
		r = 0xE0; // B11100000
		break;
	case 8:
		r = 0xFE; // B11111110
		break;
	case 9:
		r = 0xF6; // B11110110
		break;
	default:
		r = 0x02; // B00000010
	}

	return r;
}


ISR(TIMER0_COMPA_vect)
{
    // Called at every falling edge of the PWM signal
    // The LOW period can be used to set the register 
    // correctly for the next cycle
    next();
}