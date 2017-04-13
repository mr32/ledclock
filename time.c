#include "time.h"

void time_init()
{
    time = malloc(sizeof(struct Time));
    time_str = malloc(6 * sizeof(char));

    memset(time, 0, sizeof(struct Time));
    memset(time_str, 0, 6 * sizeof(char));
}

bool time_extractFromGps(char* nmeaMsg)
{
    // This is what we want: $GPGLL,5130.58772,N,00530.11096,E,130132.00,A,A*6A
    if (strncmp(nmeaMsg, "$GPGLL", 6 * sizeof(char)) == 0)
    {
        char* p = nmeaMsg;

        for (uint8_t i = 0; i < 5; i++)
        {
            p = strstr(p, ",");

            if (!p)
                break;

            p++;
        }

        time->hh = _N(p[0]);        
        time->h  = _N(p[1]);
        time->mm = _N(p[2]);
        time->m  = _N(p[3]);
        time->ss = _N(p[4]);
        time->s  = _N(p[5]);

        return 1;
    }

    return 0;
}

struct Time* time_get()
{
    return time;
}

char* time_toStr()
{
    time_str[0] = _C(time->hh);
    time_str[1] = _C(time->h);
    time_str[2] = _C(time->mm);
    time_str[3] = _C(time->m);
    time_str[4] = _C(time->ss);
    time_str[5] = _C(time->s);

    return time_str;
}
