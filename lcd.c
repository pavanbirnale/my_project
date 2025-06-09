#include<LCD.h>

// LCD initialization
void lcd_init(void)
{
    lcd_cmd(0x38);  // 8-bit, 2 line, 5x7
    lcd_cmd(0x0C);  // Display ON, cursor OFF
    lcd_cmd(0x01);  // Clear display
    delay(20);      // Extra delay after clear
    lcd_cmd(0x80);  // Set cursor to 1st line
}

// Delay function (~1ms per unit at 11.0592 MHz)
void delay(unsigned int i)
{
    unsigned int j, k;
    for(j = 0; j < i; j++)
        for(k = 0; k < 1275; k++);
}

// Send command to LCD
void lcd_cmd(unsigned char a)
{
    rs = 0;
    rw = 0;       // Write mode
    ldata = a;
    en = 1;
    delay(2);
    en = 0;
    delay(2);    
}

// Send data to LCD
void lcd_data(unsigned char b)
{
    rs = 1;
    rw = 0;       // Write mode
    ldata = b;
    en = 1;
    delay(2);
    en = 0;
    delay(2);
}

// Send string to LCD
void lcd_str(unsigned char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}


void lcd_print_time(unsigned char h, unsigned char m, unsigned char s) {
    lcd_cmd(0xC0);  // Start of second line

    lcd_data((h / 10) + '0');
    lcd_data((h % 10) + '0');
    lcd_data(':');
    lcd_data((m / 10) + '0');
    lcd_data((m % 10) + '0');
    lcd_data(':');
    lcd_data((s / 10) + '0');
    lcd_data((s % 10) + '0');
}
