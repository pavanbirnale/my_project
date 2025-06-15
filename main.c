#include <reg51.h>
#include "lcd.h"
#include "spi.h"

void main()
{
    unsigned char ch;

    CS = 1;    // Deselect EEPROM
    SCK = 0;   // Clock low

    lcd_init();
    lcd_str("SPI Commu.");

    
	
    EEPROM_WriteByte(0x0123, 'B');
    spi_delay();  // 5ms delay

    // Now read the same byte
    ch = EEPROM_ReadByte(0x0123);

    // Display received data on LCD 2nd line
    lcd_cmd(0xC0);
    lcd_data(ch);

    while(1);  // STOP: Do nothing after this
}
