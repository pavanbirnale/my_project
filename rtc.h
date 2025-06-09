#ifndef _RTC_H
#define _RTC_H
#include<reg51.h>
#include "i2c.h"
void rtc_set_time(unsigned char hour, unsigned char min, unsigned char sec);
unsigned char dec_to_bcd(unsigned char val);
unsigned char bcd_to_dec(unsigned char val);
void rtc_get_time(unsigned char *hour, unsigned char *min, unsigned char *sec);

#endif