#include "rbuf.h"

void rbuf_init(rbuf *_this)
{
    // Clear the given structure
    memset(_this, 0, sizeof(*_this));
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
        _this->count++;
    }
}

int rbuf_get(rbuf *_this)
{
    unsigned char c;

    // Return a character if there is any
    if (_this->count > 0)
    {
        c = _this->buf[_this->tail];
        _this->tail = (_this->tail - 1) % RBUF_SIZE;
        _this->count--;
    }
    else 
        c = -1;

    return c;
}

bool rbuf_full(rbuf *_this)
{
    return (_this->count >= RBUF_SIZE);
}

bool rbuf_empty(rbuf *_this)
{
    return (_this->count == 0);
}