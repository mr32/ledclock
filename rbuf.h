#ifndef RBUF_H
#define RBUF_H

#include <string.h>
#include <stdbool.h>

#define RBUF_SIZE       128

// Define 8-bit integer type
typedef unsigned char uint8_t;
bool flag_rxSC;

// Define buffer
typedef struct rbuf 
{
    // Main buffer of size RBUF_SIZE
    unsigned char buf[RBUF_SIZE];
    // Head tracking variable
    uint8_t head;
    // Tail tracking variable
    uint8_t tail;
    // Number of items contained in the buffer
    uint8_t count;  
} rbuf;

// Initialize buffer, make _this ready to use
void rbuf_init(rbuf *_this);
// Empty the given buffer. A quick wipe (clear = false) or a full wipe can be used
void rbuf_flush(rbuf *_this, bool clear);
// Put a character in the buffer
void rbuf_put(rbuf *_this, const unsigned char c);
// Get the first character stored in the buffer
int rbuf_get(rbuf *_this);
// Get the buffer full state
bool rbuf_full(rbuf *_this);
// Get the buffer empty state
bool rbuf_empty(rbuf *_this);

#endif