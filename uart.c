#include "uart.h"

void UART_Init() 
{
    // Load upper part into Baud Rate Register
    UBRR0H = (BAUD_PRESCALE >> 8);
    // Load lower part into Baud Rate Register
    UBRR0L = BAUD_PRESCALE;

    // Set Character size (= 8)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    // Enable UART receiver and transmitter
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // Enable reciever interrupts
    UCSR0B = (1 << RXCIE0);  
}

// Triggered when RX receives a byte
ISR(USART0_RXC_vect)
{
    char rx;
    // Read received byte from register UDR
    rx = UDR0;
}