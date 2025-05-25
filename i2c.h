// i2c.h

#ifndef I2C_H
#define I2C_H

#include <reg51.h>

sbit SDA = P3^3;
sbit SCL = P3^4;

void i2c_start();
void i2c_stop();
void i2c_write(unsigned char dat);
unsigned char i2c_read();
void i2c_ack();
void i2c_nack();
void Idelay(unsigned int i);


#endif
