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