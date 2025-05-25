#include<reg51.h>
#define ldata P2
// Function declarations
void delay(unsigned int i);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_init(void);
void lcd_str(unsigned char *str);

// Pin connections
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;