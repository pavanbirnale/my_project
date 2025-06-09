#include <reg51.h>
#include "i2c.h"
#include "lcd.h"
#include<stdio.h>

void main() {
  unsigned char h, m, s, prev_s = 0xFF;

    lcd_init();
    lcd_str("Time:");
		//rtc_set_time(11,35,00);
    while(1) {
        rtc_get_time(&h, &m, &s);
      if (s != prev_s) {
			lcd_print_time(h, m, s);
			prev_s = s;
					           }
			delay(1);
    }
}
