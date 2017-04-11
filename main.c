#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "uart.h"

void main(void)
{
    // Initialize UART interface
    UART_Init();

    // Enable Global Interrupts
    sei();
    
    while(1)
    {
        //UART_Send(UART_Receive());
    }
}