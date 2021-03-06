#ifndef TIME_H
#define TIME_H

#define _N(x) (uint8_t)(x - 48)
#define _C(x) (char)(x + 48)

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char uint8_t;

// Define Time struct, which separates the time variables
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
uint8_t hourOffset;

// Initiate time by reserving the required memory
void time_init();
// Find time from the given NMEA message and stores it in the time obj
bool time_extractFromGps(char* nmeaMsg);
// Returns the time in a Time format
struct Time * time_get();
// Returns the time as a String
char* time_toStr();
// Increase time with one second 
struct Time * time_increment(struct Time * time_);
// Add Hours to the time
void time_incrementHour();
static void time_writeOffset();
#endif
