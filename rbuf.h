#ifndef RBUF_H
#define RBUF_H

#include <string.h>
#include <stdbool.h>

#define RBUF_SIZE       128

// Define 8-bit integer type
typedef unsigned char uint8_t;

// Define buffer
typedef struct rbuf 
{
    unsigned char buf[RBUF_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;  
} rbuf;

void rbuf_init(rbuf *_this);
void rbuf_flush(rbuf *_this, bool clear);
void rbuf_put(rbuf *_this, const unsigned char c);
int rbuf_get(rbuf *_this);
bool rbuf_full(rbuf *_this);
bool rbuf_empty(rbuf *_this);

#endif