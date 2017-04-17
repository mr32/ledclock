#include "main.h"

void main(void)
{
    // Initialize UART interface
    UART_Init();

    // Initialize time
    time_init();

    // Initialize display
    display_init();

    // Initialize TIMER2
    gpio_init_CTCT1();
    gpio_set_ISRT1();

    // Init Colon pin
    gpio_setPinMode(3, OUTPUT);
    gpio_set(3, LOW);

    // Set PPS pin
    gpio_setPinMode(2, INPUT);
    gpio_set_ISRINT0();

    // Enable Global Interrupts
    sei();

    display_set(0, '-');
    display_set(1, '-');
    display_set(2, '-');
    display_set(3, '-');
    display_set(4, '-');
    display_set(5, '-');

    s = 0;

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

ISR(TIMER1_COMPA_vect)
{
    gpio_set(3, s);
    s = !s;

    if (s)
        return;
    // Executed every 0.5 seconds
    time_increment();

    display_set(0, time->hh);
    display_set(1, time->h);
    display_set(2, time->mm);
    display_set(3, time->m);
    display_set(4, time->ss);
    display_set(5, time->s);


}

ISR(INT0_vect)
{
    // Executed on PPS HIGH
    // Reset TIMER1 Counter to sync with the PPS pulse
    TCNT1H = 0x00;
    TCNT1L = 0x00;

    s = 1;
    gpio_set(3, s);

    s = 0;
    // Executed every 0.5 seconds

    display_set(0, time->hh);
    display_set(1, time->h);
    display_set(2, time->mm);
    display_set(3, time->m);
    display_set(4, time->ss);
    display_set(5, time->s);
}