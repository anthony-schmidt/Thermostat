#include "ds1631.h"
#include "i2c.h"

void ds1631_config(){
    i2c_start(); // Start transfer
    i2c_put(DS1631_ADDRESS & 0xFE); //Send address of LSb of config register
    i2c_put(DS1631_CMD_ACCESS_CONFIG); //Send access configuration
    i2c_put(DS1631_DATA_CONFIG); //Send configuration
    i2c_stop(); //Stop transfer
}

void ds1631_start_convert(){
    i2c_start(); //Start transfer
    i2c_put(DS1631_ADDRESS & 0xFE);     //Send Lsb of address
    i2c_put(DS1631_CMD_START_CONVERT);   //Send code to start converting
    i2c_stop(); //Stop Transfer
}


float ds1631_read_temp(){
    int hi_temp, low_temp;
    float temp;
    i2c_start(); //Start transfer
    i2c_put(DS1631_ADDRESS & 0xFE);     //Send Lsb of address
    i2c_put(DS1631_CMD_READ_TEMP);      //Send Read temp command
    i2c_start(); //Start transfer
    i2c_put(DS1631_ADDRESS | 0x01);     //Send Lsb 1 of address
    hi_temp = i2c_get(I2C_ACK);         //Get MSB of temp
    low_temp = i2c_get(I2c_NACK);       //Get LSB of temp
    i2c_stop(); //Stop transfer
    
    temp = (float) hi_temp + (low_temp/256.); //Convert signals to float
    return (temp * (9. / 5.)) + 32;           //Convert to celcius
  }
