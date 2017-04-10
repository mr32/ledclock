#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include "uart.h"


int main(void)
{
    // Enable the Global Interrupt Enable flag to ensure interrupts are being triggered
    sei();

    // Initialize UART port
    UART_Init();
}
