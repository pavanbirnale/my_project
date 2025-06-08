#ifndef _I2C_H
#define _I2C_H
#include<reg51.h>

void i2c_start(void);
void i2c_stop(void);
void i2c_write(unsigned char Idata);
unsigned char i2c_read(void);
void i2c_delay(unsigned int i);
sbit SDA = P3^4;
sbit SCL = P3^3;

#endif
