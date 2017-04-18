#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <stdbool.h>

#define HIGH    1
#define LOW     0
#define OUTPUT  1
#define INPUT   0
#define CTC_2HZ 31250

typedef unsigned char uint8_t;



// Set I/O mode of GPIO pins according to the Arduino Uno pin mapping
void gpio_setPinMode(uint8_t pin, bool mode);

// Set the GPIO logic level
void gpio_set(uint8_t pin, bool value);

// Get the GPIO logic level
bool gpio_get(uint8_t pin);

// Initialize an ADC
void gpio_init_ADC();

// Measure an analog input and return the value
int gpio_get_ADC(uint8_t pin);

// Use PWM
void gpio_init_PWMT0(); // Phase Correct PWM
void gpio_init_PWMT2(); // Fast PWM

// Set CTC Timer
void gpio_init_CTCT1();


// Set duty cycle
void gpio_set_DCT0(uint8_t dc);
void gpio_set_DCT1(int dc);
void gpio_set_DCT2(uint8_t dc);

// Enable interrupt
void gpio_set_ISRT0();
void gpio_set_ISRT1();
void gpio_set_ISRT2();

// Set External interrupt
void gpio_set_ISRINT0();


#endif