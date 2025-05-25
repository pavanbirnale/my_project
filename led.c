#include "led.h"
#include "lcd.h"

void led_status(void)
{
    lcd_cmd(0x01);              // Clear LCD
    lcd_str("LED Status");      // Print heading
    LED = 0;                    // Turn OFF LED initially

    while(1)
    {
        lcd_cmd(0xC0);          // Move to second line

        if(push_button == 0)    // If button is pressed
        {
            LED = 1;            // Turn ON LED
            lcd_str("LED ON "); // Note: space to overwrite old text
        }
        else
        {
            LED = 0;            // Turn OFF LED
            lcd_str("LED OFF"); // Same length
        }

    }
}
