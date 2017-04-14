#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <stdbool.h>

#define HIGH    1
#define LOW     0
#define OUTPUT  1
#define INPUT   0


typedef unsigned char uint8_t;



// Set I/O mode of GPIO pins according to the Arduino Uno pin mapping
void gpio_setPinMode(uint8_t pin, bool mode);

// Set the GPIO logic level
void gpio_set(uint8_t pin, bool value);

// Get the GPIO logic level
bool gpio_get(uint8_t pin);

// Use Fast-PWM
void gpio_init_PWMT0();
void gpio_init_PWMT1();
void gpio_init_PWMT2();

// Set duty cycle
void gpio_set_DCT0(uint8_t dc);
void gpio_set_DCT1(int dc);
void gpio_set_DCT2(uint8_t dc);

#endif