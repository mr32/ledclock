#ifndef DISPLAY_H
#define DISPLAY_H

#define NO_DISPLAYS 6

#include <avr/interrupt.h>
#include <util/delay.h>
#include "shiftreg.h"

#define MAX_BRIGHTNESS      200
#define MIN_BRIGHTNESS      3

typedef unsigned char uint8_t;

// Shift registers
shiftreg displayreg;
shiftreg segmentreg;

// Display buffers
static uint8_t disp[NO_DISPLAYS];
static uint8_t currentDisplay;

void display_init();
void display_set(uint8_t dispID, uint8_t content);
void display_setBrightness(uint8_t brightness);

static void next();
static uint8_t toSegment(char input);

#endif