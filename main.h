#define __DEBUG

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>

#include "gpio.h"
#include "uart.h"
#include "time.h"
#include "display.h"

#define COLON_PIN   3
#define BUTTON_PIN  13
#define PPS_PIN     2
static bool s;
static bool jumpstart;

// Let's keep some time
void clockhandler();