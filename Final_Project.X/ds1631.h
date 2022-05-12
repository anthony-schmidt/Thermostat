/* 
 * File:   ds1631.h
 * Author: aschmi25
 *
 * Created on April 28, 2022, 3:34 PM
 */

#ifndef DS1631_H
#define	DS1631_H
#include <xc.h>

#define NO_I2C_ERROR 1
#define I2c_ERROR 0

#define DS1631_ADDRESS 0b10010000
#define DS1631_CMD_ACCESS_CONFIG 0xAC
#define DS1631_DATA_CONFIG 0x0C
#define DS1631_CMD_START_CONVERT 0x51
#define DS1631_CMD_STOP_CONVERT 0x22
#define DS1631_CMD_READ_TEMP 0xAA
#define DS1631_CMD_ACCESS_TH 0xA1
#define DS1631_CMD_ACCESS_TL 0xA2
#define DS1631_CMD_SOFTWARE_POR 0x54

void ds1631_config();
void ds1631_start_convert();
float ds1631_read_temp();

#endif	/* DS1631_H */

