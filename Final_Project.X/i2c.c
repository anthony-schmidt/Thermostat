#include "i2c.h"


void i2c_config(){
    I2C2BRG = 0x1F;         //Baud rate generator value
    I2C2CONbits.I2CEN = 1;  //Enable I2c
}

void i2c_start(){
    I2C2CONbits.SEN = 1;    //Initialize start
    while(I2C2CONbits.SEN); //Wait until start is finished
}

BYTE i2c_put(BYTE data){
    I2C2TRN = data;              //Put data in the buffer
    while(I2C2STATbits.TRSTAT);  //Wait until transfer is finished
    return I2C2STATbits.ACKSTAT; //Return Acknowledge signal
}

void i2c_stop(){
    I2C2CONbits.PEN = 1;    //Initialize Stop
    while(I2C2CONbits.PEN); //Wait until stop finishes
}

BYTE i2c_get(BYTE ack_to_send){
    BYTE in_byte;
    
    while(I2C2CON & 0x1F);   //Wait for idle condition
    I2C2CONbits.RCEN = 1;    //Enable Receive
    while(!I2C2STATbits.RBF);//Wait for receive byte
    in_byte = I2C2RCV;       //Copy byte into buffer
    while(I2C2CON & 0x1F);   //Wait for idle condition
   
     I2C2CONbits.ACKDT = ack_to_send; //Acknowledge type to send
     I2C2CONbits.ACKEN = 1;     //Enable Acknowledge transmission
     while(I2C2CONbits.ACKEN);  //Wait for acknowledge
     
     return in_byte;
}