#include "lcd.h"
#include "i2c.h"

void main() {
   unsigned char x,i;
	char sent[]="HelloWorl";
	char buffer[9];
    lcd_init();
    lcd_str("I2C Protocol R/W ");
		
		
	  eeprom_write_multiple(0x00, (unsigned char*)sent, 8);
		
		eeprom_read_multiple(0x00, (unsigned char*)buffer, 8);
		
		lcd_cmd(0xC0);
		for(i=0;i<8;i++)
	{
		lcd_data(buffer[i]);
	}
	
    while(1);              // Stop here
}