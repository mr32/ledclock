#include "main.h"

void main(void)
{
    // Initialize UART interface
    UART_Init();

    // Initialize time
    time_init();

    // Initialize display
    display_init();

    // Enable Global Interrupts
    sei();

    display_set(0, 0);
    display_set(1, 1);
    display_set(2, 2);
    display_set(3, 3);
    display_set(4, 4);
    display_set(5, 5);

    // Initiate second buffer
    char* buffer;
    buffer = malloc(128 * sizeof(char));
    uint8_t i = 0;

    while (1)
    {
        // Do things while there is stuff in the inputbuffer
        while (!rbuf_empty(&buf))
        {
            // Get the latest data
            buffer[i] = rbuf_get(&buf);
            
            // Check if there are <CR> symbols that indicate the end 
            // of a NMEA string
            if (buffer[i] == '\n')
            {
                // Check if there is new time information
                if(time_extractFromGps(buffer))
                {
#ifdef __DEBUG                    
                    UART_SendLine(time_toStr());
#endif              
                }

                // Other data is not needed, discard and start over
                memset(buffer, 0, i * sizeof(char));
                i = -1;
            }

            // Next character
            i++;
        }
    }
}