#include "gpio.h"

void gpio_setPinMode(uint8_t pin, bool mode)
{
    if (mode == OUTPUT)
    {
        switch (pin)
        {
            case 2: // PD2
            {
                DDRD |= (1 << PD2);
            } break;

            case 3: // PD3
            {
                DDRD |= (1 << PD3);
            } break;

            case 4: // PD4
            {
                DDRD |= (1 << PD4);
            } break;

            case 5: // PD5
            {
                DDRD |= (1 << PD5);
            } break;

            case 6: // PD6
            {
                DDRD |= (1 << PD6);
            } break;

            case 7: // PD7
            {
                DDRD |= (1 << PD7);
            } break;

            case 8: // PB0
            {
                DDRB |= (1 << PB0);
            } break;

            case 9: // PB1
            {
                DDRB |= (1 << PB1);
            } break;

            case 10: // PB2
            {
                DDRB |= (1 << PB2);   
            } break;

            case 11: // PB3
            {
                DDRB |= (1 << PB3);
            } break;

            case 12: // PB4
            {
                DDRB |= (1 << PB4);
            } break;

            case 13: // PB5
            {
                DDRB |= (1 << PB5);
            } break;
        }
    }
    else
    {
        switch (pin)
        {
            case 2: // PD2
            {
                DDRD &= ~(1 << PD2);
            } break;

            case 3: // PD3
            {
                DDRD &= ~(1 << PD3);
            } break;

            case 4: // PD4
            {
                DDRD &= ~(1 << PD4);
            } break;

            case 5: // PD5
            {
                DDRD &= ~(1 << PD5);
            } break;

            case 6: // PD6
            {
                DDRD &= ~(1 << PD6);
            } break;

            case 7: // PD7
            {
                DDRD &= ~(1 << PD7);
            } break;

            case 8: // PB0
            {
                DDRB &= ~(1 << PB0);
            } break;

            case 9: // PB1
            {
                DDRB &= ~(1 << PB1);
            } break;

            case 10: // PB2
            {
                DDRB &= ~(1 << PB2);
            } break;

            case 11: // PB3
            {
                DDRB &= ~(1 << PB3);
            } break;

            case 12: // PB4
            {
                DDRB &= ~(1 << PB4);
            } break;

            case 13: // PB5
            {
                DDRB &= ~(1 << PB5);
            } break;
        }
    }
}

void gpio_set(uint8_t pin, bool value)
{
    if (value == HIGH)
    {
        switch (pin)
        {
            case 2: // PD2
            {
                PORTD |= (1 << PD2);
            } break;

            case 3: // PD3
            {
                PORTD |= (1 << PD3);
            } break;

            case 4: // PD4
            {
                PORTD |= (1 << PD4);
            } break;

            case 5: // PD5
            {
                PORTD |= (1 << PD5);
            } break;

            case 6: // PD6
            {
                PORTD |= (1 << PD6);
            } break;

            case 7: // PD7
            {
                PORTD |= (1 << PD7);
            } break;

            case 8: // PB0
            {
                PORTB |= (1 << PB0);
            } break;

            case 9: // PB1
            {
                PORTB |= (1 << PB1);
            } break;

            case 10: // PB2
            {
                PORTB |= (1 << PB2);   
            } break;

            case 11: // PB3
            {
                PORTB |= (1 << PB3);
            } break;

            case 12: // PB4
            {
                PORTB |= (1 << PB4);
            } break;

            case 13: // PB5
            {
                PORTB |= (1 << PB5);
            } break;
        }
    }
    else
    {
        switch (pin)
        {
            case 2: // PD2
            {
                PORTD &= ~(1 << PD2);
            } break;

            case 3: // PD3
            {
                PORTD &= ~(1 << PD3);
            } break;

            case 4: // PD4
            {
                PORTD &= ~(1 << PD4);
            } break;

            case 5: // PD5
            {
                PORTD &= ~(1 << PD5);
            } break;

            case 6: // PD6
            {
                PORTD &= ~(1 << PD6);
            } break;

            case 7: // PD7
            {
                PORTD &= ~(1 << PD7);
            } break;

            case 8: // PB0
            {
                PORTB &= ~(1 << PB0);
            } break;

            case 9: // PB1
            {
                PORTB &= ~(1 << PB1);
            } break;

            case 10: // PB2
            {
                PORTB &= ~(1 << PB2);
            } break;

            case 11: // PB3
            {
                PORTB &= ~(1 << PB3);
            } break;

            case 12: // PB4
            {
                PORTB &= ~(1 << PB4);
            } break;

            case 13: // PB5
            {
                PORTB &= ~(1 << PB5);
            } break;
        }
    }
}

bool gpio_get(uint8_t pin)
{
    switch (pin)
    {
        case 2: // PD2
        {
            return (PIND & (1 << PD2));
        } break;

        case 3: // PD3
        {
            return (PIND & (1 << PD3));
        } break;

        case 4: // PD4
        {
            return (PIND & (1 << PD4));
        } break;

        case 5: // PD5
        {
            return (PIND & (1 << PD5));
        } break;

        case 6: // PD6
        {
            return (PIND & (1 << PD6));
        } break;

        case 7: // PD7
        {
            return (PIND & (1 << PD7));
        } break;

        case 8: // PB0
        {
            return (PINB & (1 << PB0));
        } break;

        case 9: // PB1
        {
            return (PINB & (1 << PB1));
        } break;

        case 10: // PB2
        {
            return (PINB & (1 << PB2));
        } break;

        case 11: // PB3
        {
            return (PINB & (1 << PB3));
        } break;

        case 12: // PB4
        {
            return (PINB & (1 << PB4));
        } break;

        case 13: // PB5
        {
            return (PIND & (1 << PB5));
        } break;
    }

    return 0;
}

void gpio_init_PWMT0()
{
    // Set inverting Phase Correct PWM
    TCCR0A |= (1 << COM0A1) | (1 << WGM00);

    // Set pre-scaler to 64 to get a frequency of 490Hz
    TCCR0B |= (1 << CS01) | (1 << CS00);

    // Set that same pin to OUTPUT
    DDRD |= (1 << PD6);
}

void gpio_init_CTCT1()
{
    // Set Timer to CTC mode
    TCCR1B |= (1 << WGM12);

    // Set pre-scalar for a interrupt frequency of 2Hz
    TCCR1B |= (1 << CS12);

    // Set compare value 
    OCR1A = CTC_2HZ;
}

void gpio_init_PWMT2()
{
    // Set non-inverting Fast PWM on pin 11
    // TCCR2A |= (1 << COM2A1) | (1 << WGM20) | (1 << WGM21);

    // // Set pre-scaler to 64 to get a frequency of 976Hz
    // TCCR2B |= (1 << CS21) | (1 << CS20);

    // // Set that same pin to OUTPUT
    // //DDRB |= (1 << PB3);
}

void gpio_set_DCT0(uint8_t dc)
{
    OCR0A = dc;
}

void gpio_set_DCT1(int dc)
{
    OCR1A = dc;
}

void gpio_set_DCT2(uint8_t dc)
{
    OCR2A = dc;
}

void gpio_set_ISRT0()
{
    // Interrupt on the center of the HIGH period (TOP)
    TIMSK0 |= (1 << TOIE0);
}

void gpio_set_ISRT1()
{
    TIMSK1 |= (1 << OCIE1A);
}

void gpio_set_ISRT2()
{
    // Interrupt on falling edge of PWM2A
    TIMSK2 |= (1 << OCIE2A);
}

void gpio_set_ISRINT0()
{
    // Interrupt on rising edge of INT0
    EICRA |= (1 << ISC01) | (1 << ISC00);   

    // Enable interrupt
    EIMSK |= (1 << INT0);
}