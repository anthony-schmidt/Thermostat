/* 
 * File:   i2c.h
 * Author: aschmi25
 *
 * Created on April 28, 2022, 3:33 PM
 */

#ifndef I2C_H
#define	I2C_H

#define FCY 7370000/2
#define FSCL 100

#define I2C_ACK 0
#define I2c_NACK 1

typedef unsigned char BYTE;

#include <xc.h>

void i2c_config();
void i2c_start();
BYTE i2c_put(BYTE data);
void i2c_stop();
BYTE i2c_get(BYTE ack_to_send);

#endif	/* I2C_H */

