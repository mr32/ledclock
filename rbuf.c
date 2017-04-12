#include "rbuf.h"

void rbuf_init(rbuf *_this)
{
    // Clear the given structure
    memset(_this, 0, sizeof(*_this));

    // Set 'received sentence' flag to 0
    flag_rxSC = false;

}

void rbuf_flush(rbuf *_this, bool clear)
{
    // Clear entire buffer if required
    if (clear)
    {
        memset(_this, 0, sizeof(*_this));
        return;
    }
    
    // Otherwise, just clear the tracking variables
    _this->head = 0;
    _this->tail = 0;
    _this->count = 0;   
}

void rbuf_put(rbuf *_this, const unsigned char c)
{
    // Place character in the buffer if there is space
    if (_this->count < RBUF_SIZE)
    {
        _this->buf[_this->head] = c;
        _this->head = (_this->head + 1) % RBUF_SIZE;
        _this->count += 1;

        // Line ending received, set flag for other routines
        if (c == 10 || c == 13)
        {
            flag_rxSC = true;
        }   
    }
}

int rbuf_get(rbuf *_this)
{
    unsigned char c;

    // Return a character if there is any
    if (_this->count > 0)
    {
        c = _this->buf[_this->tail];
        _this->tail = (_this->tail + 1) % RBUF_SIZE;
        _this->count -= 1;
    }
    else 
        c = -1;

    // Reset flag
    flag_rxSC = false;

    // Return either a character or -1
    return c;
}

bool rbuf_full(rbuf *_this)
{
    // Return true if buffer is full
    return (_this->count >= RBUF_SIZE);
}

bool rbuf_empty(rbuf *_this)
{
    // Return false if buffer is empty
    return (_this->count == 0);
}