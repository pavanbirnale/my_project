#include <reg51.h>
#include "lcd.h"

void main() {
    lcd_init();
    lcd_str("Hello, Pavan");
    while (1);
}
