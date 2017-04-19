#include "time.h"

void time_init()
{
    // Reserve memory to keep the time
    time = malloc(sizeof(struct Time));
    time_str = malloc(6 * sizeof(char));

    // Set memory content to nothing
    memset(time, 0, sizeof(struct Time));
    memset(time_str, 0, 6 * sizeof(char));
}

bool time_extractFromGps(char* nmeaMsg)
{
    // This is what we want: $GPGLL,xxxx.xxxxx,N,xxxx.xxxxx,E,130132.00,A,A*6A

    // Find the $GPGLL identifier
    if (strncmp(nmeaMsg, "$GPGLL", 6 * sizeof(char)) == 0)
    {
        char* p = nmeaMsg;

        // Set pointer to the first character after of the fifth NMEA GLL field
        for (uint8_t i = 0; i < 5; i++)
        {
            // Find next field delimiter
            p = strstr(p, ",");

            // If pointer goes to NULL, terminate
            if (!p)
                break;
            
            // Next memory location
            p++;
        }

        for (uint8_t i = 0; i < 6; i++)
        {
            if (_N(p[i]) > 9)
            {
                return 0;
            }
        }

        // Convert data to integer and store in time object
        time->hh = _N(p[0]);        
        time->h  = _N(p[1]);
        time->mm = _N(p[2]);
        time->m  = _N(p[3]);
        time->ss = _N(p[4]);
        time->s  = _N(p[5]);

    

        return 1;
    }

    // Return 0 if no time has been found
    return 0;
}

struct Time* time_get()
{
    return time;
}

char* time_toStr()
{
    // Convert time to a character array
    time_str[0] = _C(time->hh);
    time_str[1] = _C(time->h);
    time_str[2] = _C(time->mm);
    time_str[3] = _C(time->m);
    time_str[4] = _C(time->ss);
    time_str[5] = _C(time->s);

    return time_str;
}

struct Time * time_increment(struct Time * time_)
{
    struct Time * t = time_;
    t->s += 1;

    if (t->s > 9)
    {
    t->s = 0;
    t->ss += 1;

        if (t->ss > 5)
        {
            t->ss = 0;
            t->m += 1;

            if (t->m > 9)
            {
                t->m = 0;
                t->mm += 1;

                if (t->mm > 5)
                {
                    t->mm = 0;
                    t->h += 1;

                    if (t->h > 9)
                    {
                        t->h = 0;
                        t->hh += 1;

                        if (t->hh > 2)
                        {
                            t->hh = 0;
                        }
                    }
                }
            }
        }
    }

    return t;
}