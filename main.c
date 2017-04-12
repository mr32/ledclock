#include "main.h"

void main(void)
{
    // Initialize UART interface
    UART_Init();

    // Enable Global Interrupts
    sei();

    char buffer[128];
    int i = 0;

    while (1)
    {
        while (!rbuf_empty(&buf))
        {
            buffer[i] = rbuf_get(&buf);
            
            if (buffer[i] == '\n')
            {
                for(uint8_t j = 0; j < i; j++)
                {
                    UART_Send(buffer[j]);
                }
                i = -1; 
            }

            i++;
        }
    }
}