#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "uart.h"

void main(void)
{
    DDRB |= _BV(DDB5);

    PORTB |= _BV(PORTB5);

    UART_Init();

    sei();

    while(1)
    {
        //UART_Send(UART_Receive());
    }
}