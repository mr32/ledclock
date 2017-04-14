#ifndef DISPLAY_H
#define DISPLAY_H

#define NO_DISPLAYS 6

#include <avr/interrupt.h>
#include "shiftreg.h"

typedef unsigned char uint8_t;

// Shift registers
shiftreg displayreg;
shiftreg segmentreg;

// Display buffers
static uint8_t disp[NO_DISPLAYS];
static uint8_t currentDisplay;

void display_init();
void display_set(uint8_t dispID, uint8_t content);

static void next();
static uint8_t toSegment(char input);

#endif