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
    gpio_setPinMode(COLON_PIN, OUTPUT);
    gpio_set(COLON_PIN, LOW);

    // Set PPS pin
    gpio_setPinMode(PPS_PIN, INPUT);
    gpio_set_ISRINT0();

    // Enable and init ADC for button input
    gpio_init_ADC();

    // Enable Global Interrupts
    sei();

    // Pre-set display content
    display_set(0, '-');
    display_set(1, '-');
    display_set(2, '-');
    display_set(3, '-');
    display_set(4, '-');
    display_set(5, '-');

    s = 0;
    jumpstart = 0;
    prevBtnState = 0;

    // Initiate second buffer
    char* buffer;
    buffer = malloc(128 * sizeof(char));
    uint8_t i = 0;

    while (1)
    {
        // Adjust the brightness 
        //adjustBrightness();
        display_setBrightness(200);

        // Set-Hour button debouncing
        if (gpio_get_ADC(BUTTON_PIN) > 512 && prevBtnState == LOW)
        {
            prevBtnState = HIGH;
            // Increase time with one hour
            time_incrementHour();
        }
        else if (gpio_get_ADC(BUTTON_PIN) < 512 && prevBtnState == HIGH)
        {
            // Reset button
            prevBtnState = LOW;
        }

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
                    jumpstart = 1;
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

void clockhandler()
{
    // Show the time only if there was data once before
    if (jumpstart)
    {
        gpio_setPinMode(COLON_PIN, s);

        // Increment time, also when data was available (but not anymore)
        if (s)
        {

            // Send data to displays
            display_set(0, t.hh);
            display_set(1, t.h);
            display_set(2, t.mm);
            display_set(3, t.m);
            display_set(4, t.ss);
            display_set(5, t.s);
        }
        else
        {
            // Store previous time value as a reference
            t_prev = t;

            // Buffer time (it can change while executing this)
            // Due the way time is synced, do +2
            // +1 for data transfer
            // +1 for buffering at a 'safe instance'
            // Only do that when there has been at least one moment with PPS
            if (pps_sync)
            {
                t = *time_increment(time_get());
                t = *time_increment(&t);
            }
            else
            {
                t = *time_get();
            }

            // If the time stalls (delayed GPS message), increase time by one second
            if (t.s == t_prev.s)
            {
                t = *time_increment(&t);
            }


        }
    }
    else
    {
        // No useful data to show
        for (uint8_t i = 0; i < 7; i++)
            display_set(i, '-');
    }

    s = !s;
}

void adjustBrightness()
{
    char buffer[4];
    uint8_t input = ((gpio_get_ADC(PHOTO_PIN) >> 2));
    // Measuring gives 100 for very bright light, and 0 for no light
    // Relation is not linear
    if (input > 210)
        input = 210;
    if (input < 30)
        input = 30;

    //UART_SendLine(itoa(input, buffer, 10));


    display_setBrightness((uint8_t)input);
}

ISR(TIMER1_COMPA_vect)
{
    // Do clocky things! :)
    clockhandler();
}

ISR(INT0_vect)
{
    // Avoid early triggering. Allow only when no sync has yet been established
    // or when the colons are turned off (meaning that the display update cycle will
    // be executed on the next call of 'clockhandler()')
    if (!pps_sync || !s)
    {
        // Executed on PPS HIGH
        // Force trigger the timer CTC function by setting the 
        // time buffer to a near-overflow value
        TCNT1H = (unsigned char)(CTC_2HZ >> 8);
        TCNT1L = (unsigned char)(CTC_2HZ - 1);
    }    

    // Set s to 1 to indicate the start of a second
    s = 1;
    pps_sync = 1;
}