#ifndef UART_H
#define UART_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FCPU                16000000
#define BAUD_RATE           9600
//#define BAUD_PRESCALE       ((((FCPU / 16) + (BAUD_RATE / 2)) / (BAUD_RATE)) - 1)
#define BAUD_PRESCALE       103

#define INPUT_BUFFER_SIZE   100 

volatile char rx[INPUT_BUFFER_SIZE];
volatile int rxno = 0;

// Enable UART interface and setup the corresponding CLK
void UART_Init();

// Disable UART interface and clean up memory
void UART_End();

// Transmit data over UART interface
void UART_Send(unsigned char c);

// Receive data over UART interface
unsigned char UART_Receive();
#endif