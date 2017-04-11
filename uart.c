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

    UCSR0B |= (1 << RXCIE0);
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
    //unsigned char length = strlen(str);
    //unsigned char i = 0;

    while ( !(UCSR0A & (1 << UDRE0))){};/*&& (i < length)*/
    UDR0 = c;
        //UDR0 = str[i];
        //i++;
}

unsigned char UART_Receive()
{
    while ( !(UCSR0A & (1 << RXC0)) ) {};
    return UDR0;
}

// Triggered when RX receives a byte
ISR(USART_RX_vect, ISR_BLOCK)
{
    // while ( !(UCSR0A & (1 << RXC0)) );

    // if (rxno == INPUT_BUFFER_SIZE)
    //     rxno = 0;
    
    // rx[rxno++] = UDR0;
    
    volatile unsigned char rx = UDR0;
    UDR0 = rx;

    // If a sentence has not been read, ignore the incoming data
    // if (UART_SentenceReceived)
    //     return;

    // // Check for sentence termination, otherwise add input to buffer
    // if (rx == '\n')
    //     UART_SentenceReceived = true;
    // else
    //     UART_RX_Buffer += rx;    

    PORTB &= ~_BV(PORTB5);
}
