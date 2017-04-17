#include "display.h"

void display_init()
{
    shiftreg_init(&displayreg, 9, 10, 11, 12);
    shiftreg_init(&segmentreg, 4, 5, 7, 8);
    gpio_init_PWMT0();
	gpio_set_ISRT0();

    currentDisplay = 0;

    display_setBrightness(200);
}

void display_set(uint8_t dispID, uint8_t content)
{
    // Store the content to the corresponding display buffer
    if (dispID < NO_DISPLAYS)
		disp[dispID] = toSegment(content);
}

void display_setBrightness(uint8_t brightness)
{
    gpio_set_DCT0(255 - brightness);
}

static void next()
{
    // Go to the next display and show the right content
    shiftreg_s2p(&segmentreg, disp[currentDisplay]);
    shiftreg_s2p(&displayreg, (1 << currentDisplay));

    // Swap buffers to output
    shiftreg_set(&segmentreg);
    shiftreg_set(&displayreg);

    // Increase display counter for the next call
    currentDisplay = (currentDisplay + 1) % NO_DISPLAYS;
}

static uint8_t toSegment(char input)
{
    // Convert integer to segment (abcdefg) format
    uint8_t r;
    
    switch (input)
	{
	case 0:
		r = 0x3F; // B11111100
		break;
	case 1:
		r = 0x06; // B01100000
		break;
	case 2:
		r = 0x5B; // B11011010
		break;
	case 3:
		r = 0x4F; // B11110010
		break;
	case 4:
		r = 0x66; // B01100110
		break;
	case 5:
		r = 0x6D; // B10110110
		break;
	case 6:
		r = 0x7D; // B10111110
		break;
	case 7:
		r = 0x07; // B11100000
		break;
	case 8:
		r = 0x7F; // B11111110
		break;
	case 9:
		r = 0x6F; // B11110110
		break;
	case '-':
		r = 0x40; // B00000010
		break;
	default:
		r = 0x00; // B00000000
	}

	return r;
}


ISR(TIMER0_OVF_vect)
{
    // Called at every falling edge of the PWM signal
    // The LOW period can be used to set the register 
    // correctly for the next cycle
    next();
}