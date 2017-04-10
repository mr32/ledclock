#ifndef UART_H
#define UART_H

#include <avr/io.h>


#define FCPU            16000000
#define BAUD_RATE       9600
#define BAUD_PRESCALE   ((((FCPU / 16) + (BAUD_RATE / 2)) / (BAUD_RATE)) - 1)

// Enable UART interface and setup the corresponding CLK
void UART_Init();

#endif