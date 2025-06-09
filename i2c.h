#ifndef _I2C_H
#define _I2C_H
#include<reg51.h>

void i2c_start(void);
void i2c_stop(void);
unsigned char i2c_write(unsigned char Idata);
unsigned char i2c_read(bit ack);
void i2c_delay(unsigned int i);
sbit SDA = P3^4;
sbit SCL = P3^3;
void eeprom_write_multiple(unsigned char start_add, unsigned char *dat, unsigned char length);
void eeprom_read_multiple(unsigned char start_add,unsigned char *buffer , unsigned char length);
void rtc_set_time(unsigned char hour, unsigned char min, unsigned char sec);
unsigned char dec_to_bcd(unsigned char val);
unsigned char bcd_to_dec(unsigned char val);
void rtc_get_time(unsigned char *hour, unsigned char *min, unsigned char *sec);
#endif;
