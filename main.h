// #define __DEBUG

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdlib.h>
#include <util/delay.h>

#include "gpio.h"
#include "uart.h"
#include "time.h"
#include "display.h"

#define COLON_PIN           5
#define BUTTON_PIN          5
#define PPS_PIN             2
#define PHOTO_PIN           0
#define MIN_PHOTO_READOUT   3
#define MAX_PHOTO_READOUT   102

static bool s;
static bool jumpstart;
static bool pps_sync;
static struct Time t;
static struct Time t_prev;
static bool prevBtnState;

// Let's keep some time
void clockhandler();

// Keep the display bright enough 
void adjustBrightness();