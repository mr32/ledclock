#ifndef TIME_H
#define TIME_H

#define _N(x) (uint8_t)(x - 48)
#define _C(x) (char)(x + 48)

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char uint8_t;

struct Time {
    uint8_t hh;
    uint8_t h;
    uint8_t mm;
    uint8_t m;
    uint8_t ss;
    uint8_t s;
};

struct Time* time;
char* time_str;

void time_init();
bool time_extractFromGps(char* nmeaMsg);
struct Time* time_get();
char* time_toStr();


#endif
