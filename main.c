#include "main.h"

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