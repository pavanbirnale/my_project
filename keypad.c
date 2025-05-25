#include "keypad.h"
#include "lcd.h"


void keypad() {
    while (1) {
        // Set all columns high initially
        C0 = C1 = C2 = 1;

        // Set all rows as input (optional: connect external pull-up)
        R0 = R1 = R2 = R3 = 1;

        // Scan column 0
        C0 = 0; C1 = C2 = 1;
        if (R0 == 0) lcd_data('1');
        else if (R1 == 0) lcd_data('4');
        else if (R2 == 0) lcd_data('7');
        else if (R3 == 0) lcd_data('*');
        C0 = 1;

        // Scan column 1
        C1 = 0; C0 = C2 = 1;
        if (R0 == 0) lcd_data('2');
        else if (R1 == 0) lcd_data('5');
        else if (R2 == 0) lcd_data('8');
        else if (R3 == 0) lcd_data('0');
        C1 = 1;

        // Scan column 2
        C2 = 0; C0 = C1 = 1;
        if (R0 == 0) lcd_data('3');
        else if (R1 == 0) lcd_data('6');
        else if (R2 == 0) lcd_data('9');
        else if (R3 == 0) lcd_data('#');
        C2 = 1;

        delay(30); // Debounce delay
    }
}
