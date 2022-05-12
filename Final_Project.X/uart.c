#include <xc.h>
#include "uart.h"


void uart_config(){
    RPOR4bits.RP43R = 1;      //Map Uart Tx to pin Rp36
    
    int brg = (FCY/BAUDRATE/4) - 1; // Calculate and store baud rate generator value
    U1MODEbits.BRGH = 1; //High speed mode
    U1BRG = brg;  


    U1MODEbits.PDSEL = 0;   //8 bit data
    U1MODEbits.STSEL = 0;   //1 stop top bit
    
    U1MODEbits.UEN = 0b00;  //Tx and RX pins are enabled and used
    U1MODEbits.UARTEN = 1;  //Enable Uart
    U1STAbits.UTXEN = 1;    //ENable the transmitter
}


void uart_putch(char c){
    while(U1STAbits.UTXBF); //Wait for transmit buffer to be empty
    U1TXREG = c; //Write charcter to transmit register
}