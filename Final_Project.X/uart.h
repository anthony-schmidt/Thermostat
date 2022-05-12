/* 
 * File:   uart.h
 * Author: aschmi25
 *
 * Created on April 25, 2022, 7:00 PM
 */

#ifndef UART_H
#define	UART_H

#define BAUDRATE 19200
#define FCY 7370000/2

void uart_config();
void uart_putch(char c);

#endif	/* UART_H */

