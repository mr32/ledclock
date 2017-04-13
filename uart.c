#include "uart.h"

void UART_Init() 
{
    // Load upper part into Baud Rate Register
    UBRR0H = (unsigned char)(BAUD_PRESCALE >> 8);
    // Load lower part into Baud Rate Register
    UBRR0L = (unsigned char)BAUD_PRESCALE;

    // Set Character size (= 8)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    // Enable UART receiver and transmitter
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // Enable RX interrupts
    UCSR0B |= (1 << RXCIE0);

    // Initialize buffer
    rbuf_init(&buf);

    buffer = malloc(128 * sizeof(char));
}

void UART_End()
{
    // Disable RX and TX ports
    UCSR0B |= (0 << RXEN0) | (0 << TXEN0);

    // Disable RX interrupts
    UCSR0B |= (0 << RXCIE0);
}

void UART_Send(unsigned char c)
{
    // Wait until buffer is empty
    while ( !(UCSR0A & (1 << UDRE0))){};

    // Place charachter in buffer
    UDR0 = c;

}

unsigned char UART_Receive()
{
    // Wait until buffer is filled
    while ( !(UCSR0A & (1 << RXC0)) ) {};

    rbuf_put(&buf, UDR0);

    // Read character from buffer
    return rbuf_get(&buf);
}

// Triggered when RX receives a byte
ISR(USART_RX_vect)
{
    // Store incoming byte directly in a ring buffer
    if (!rbuf_full(&buf))
    {
        unsigned char c = UDR0;
        rbuf_put(&buf, c);     
    }

    

}