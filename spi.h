#include<reg51.h>

sbit SCK= P3^3;
sbit MOSI= P3^4;
sbit MISO= P3^5;
sbit CS= P3^6;

void spi_delay();
unsigned char spi_Transfer(unsigned char master_out);
void EEPROM_Select();
void EEPROM_Deselect();
void EEPROM_WriteEnable();
void EEPROM_WriteByte(unsigned int address, unsigned char dat);
unsigned char EEPROM_ReadByte(unsigned int address);

unsigned char spi_read();