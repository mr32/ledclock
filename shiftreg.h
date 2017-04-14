#ifndef shiftreg_H
#define shiftreg_H

#include "gpio.h"

typedef unsigned char uint8_t;

typedef struct shiftreg
{
    // Output registers
    uint8_t SER;
    uint8_t RCLK;
    uint8_t SRCLK;
    uint8_t SRCLR;
    //uint8_t OE;

    // Data buffer
    uint8_t data;
} shiftreg;

// Initiate shiftregister
void shiftreg_init(shiftreg *_this, uint8_t SER_, uint8_t RCLK_, uint8_t SRCLK_, uint8_t SRCLR_);

// Serialize data to the shift register buffer
void shiftreg_s2p(shiftreg *_this, uint8_t _data);

// Swap buffer of the register to the output
void shiftreg_set(shiftreg *_this);

// Shift data on the buffer one place
void shiftreg_shift(shiftreg *_this);

// Disable the output
void shiftreg_disable(shiftreg *_this);

// Enable the output
void shiftreg_enable(shiftreg *_this);

// Reset the register and clear all data
void shiftreg_flush(shiftreg *_this);

#endif