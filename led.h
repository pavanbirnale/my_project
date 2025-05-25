#include<reg51.h>

sbit LED = P1^0;
sbit push_button= P1^1;

void led_status(void);