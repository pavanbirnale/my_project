#include "rtc.h"


unsigned char dec_to_bcd(unsigned char val) {
    return ((val / 10) << 4) | (val % 10);
}
unsigned char bcd_to_dec(unsigned char val)
{
	 return ((val >> 4) * 10) + (val & 0x0F);
}

void rtc_set_time(unsigned char hour, unsigned char min, unsigned char sec)
{
	i2c_start();
	i2c_write(0xD0);    // DS1307 write address
	i2c_write(0x00);     // Start at  resister 0x00 (seconds)
	i2c_write(dec_to_bcd(sec));
  i2c_write(dec_to_bcd(min));
  i2c_write(dec_to_bcd(hour));
  i2c_stop();
}

void rtc_get_time(unsigned char *hour, unsigned char *min, unsigned char *sec)
{
	i2c_start();
	i2c_write(0xD0);    // DS1307 write address
	i2c_write(0x00);     // Start at  resister 0x00 (seconds)
	
	i2c_start();
	i2c_write(0xD1);
	*sec= bcd_to_dec(i2c_read(1));
	*min=	bcd_to_dec(i2c_read(1));
	*hour=	bcd_to_dec(i2c_read(0));
	i2c_stop();
}