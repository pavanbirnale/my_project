#include <reg51.h>
#include "lcd.h"
#include "i2c.h"
void main() {
	  unsigned char x;
    lcd_init();
	  lcd_cmd(0x80);
		lcd_str("I2C Protocol");
	    // Sending data to a slave Device
	  i2c_start();
	  i2c_write(0xA0);
		i2c_write(0x00);  // register address or memory address
	  i2c_write('A');
		i2c_stop();
	   Idelay(500);
	  // Reading Data from slave
	  i2c_start();
	  i2c_write(0xA0); //	 	1010 0000
	  i2c_write(0x00); // register address or memory address
	  i2c_start();
	  i2c_write(0xA1);   // 1010 0001
		x=i2c_read();
	  i2c_stop();
		lcd_cmd(0xC0);
		lcd_data(x);
	 
	  while(1);
    
	  
}
