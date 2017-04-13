#include "main.h"

void main(void)
{
    // Initialize UART interface
    UART_Init();

    // Initialize time
    time_init();

    // Enable Global Interrupts
    sei();

    char* buffer;
    buffer = malloc(128 * sizeof(char));

    int i = 0;

    while (1)
    {
        while (!rbuf_empty(&buf))
        {
            buffer[i] = rbuf_get(&buf);
            // UART_Send(rbuf_get(&buf));
            
            if (buffer[i] == '\n')
            {
//                 for(uint8_t j = 0; j < i; j++)
//                 {
                    if(time_extractFromGps(buffer))
                    {
                        char* t = time_toStr();
                        for (uint8_t k = 0; k < 6; k++)
                        {
                            UART_Send(t[k]);
                        }
                        UART_Send('\n');
                    }

                    // for (uint8_t k = 0; k < i + 1; k++)
                    // {
                    //     UART_Send(buffer[k]);
                    // }

                    memset(buffer, 0, i * sizeof(char));
                    i = -1;


//                 }
//                 i = -1; 
            }

            i++;
        }
    }
}