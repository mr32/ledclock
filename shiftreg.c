#include "shiftreg.h"

void shiftreg_init(shiftreg *_this, uint8_t SER_, uint8_t RCLK_, uint8_t SRCLK_, uint8_t SRCLR_)
{
    // Prepare outputs
    _this->SER = SER_;
    _this->RCLK = RCLK_;
    _this->SRCLK = SRCLK_;
    _this->SRCLR = SRCLR_;
    //_this->OE = OE_;

    gpio_setPinMode(_this->SER, OUTPUT);
    gpio_setPinMode(_this->RCLK, OUTPUT);
    gpio_setPinMode(_this->SRCLK, OUTPUT);
    gpio_setPinMode(_this->SRCLR, OUTPUT);
    //gpio_setPinMode(_this->OE, OUTPUT);
}

void shiftreg_s2p(shiftreg *_this, uint8_t _data)
{
    // Some nasty output code to write the data
    gpio_set(_this->SRCLR, HIGH);

    for (uint8_t i = 0; i < 8; i++)
    {

        gpio_set(_this->SER, _data & (1 << 7 - i));
        gpio_set(_this->SRCLK, HIGH);
        gpio_set(_this->SRCLK, LOW);
    }
}

void shiftreg_set(shiftreg *_this)
{
    // Swap buffer to the output
    gpio_set(_this->RCLK, HIGH);
    gpio_set(_this->RCLK, LOW);
}

void shiftreg_shift(shiftreg *_this)
{
    // TODO
}

void shiftreg_flush(shiftreg *_this)
{
    // Reset data on register
    gpio_set(_this->SRCLR, LOW);
    gpio_set(_this->SRCLR, HIGH);
    shiftreg_set(_this);
}

void shiftreg_disable(shiftreg *_this)
{
    // Disable output
    //gpio_set(_this->OE, HIGH);
}

void shiftreg_enable(shiftreg *_this)
{
    // Enable output
    //gpio_set(_this->OE, LOW);
}