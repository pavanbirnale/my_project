#include <reg51.h>
#include "lcd.h"
#include "i2c.h"

void main() {
    unsigned char x;
		lcd_init();
    lcd_str("I2C PROTOCOL R/W");
   // sending Data to slave device
    i2c_start();
		i2c_write(0xA0);        // slave Address
		i2c_write(0x00);
		i2c_write('A');
		i2c_stop();
		i2c_delay(500);
	// Reading Data from slave device
    i2c_start();
		i2c_write(0xA0);        // slave Address
		i2c_write(0x00);
		i2c_start();
		i2c_write(0xA1); 
	  x=i2c_read();
		lcd_cmd(0xC0);
		lcd_data(x);
		i2c_stop();
	  while(1);
}
  
