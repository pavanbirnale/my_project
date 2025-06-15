#include "spi.h"

void 	spi_delay()
{
	unsigned int i;
	for(i=0;i<5000;i++);
}

unsigned char spi_Transfer(unsigned char master_out)
{
	unsigned char master_in =0;
	char i;
	for(i=0;i<8;i++)
	{
		 // 1. Send MSB first
		MOSI=(master_out & 0x80) ? 1:0;
		SCK=1;
		
		// 2. Read MISO at rising edge
		master_in <<=1;
		if(MISO)
			master_in |=1;
		SCK=0;
		master_out <<= 1;
	}
	return master_in;
}

void EEPROM_Select()
{
	CS=0;   // Enable EEPROM or we selected slave
}

void EEPROM_Deselect() {
    CS = 1;  // Disable EEPROM or deselect the slave
}


void EEPROM_WriteEnable()
{
	EEPROM_Select();
	spi_Transfer(0x06);   // WREN opcode
	EEPROM_Deselect();
}



void EEPROM_WriteByte(unsigned int address, unsigned char dat)
{
    unsigned char high_addr = (address >> 8) & 0xFF;
    unsigned char low_addr  = address & 0xFF;

    EEPROM_WriteEnable();         // Step 1: Enable Write (WREN)

    EEPROM_Select();              // Step 2: Select EEPROM (CS = 0)
    spi_Transfer(0x02);           // WRITE command
    spi_Transfer(high_addr);      // High address byte
    spi_Transfer(low_addr);       // Low address byte
    spi_Transfer(dat);           // Actual data to write
    EEPROM_Deselect();            // Step 3: Deselect EEPROM (CS = 1)
}


unsigned char EEPROM_ReadByte(unsigned int address)
{
	unsigned char high_address= (address >>8) & 0xFF;
	unsigned char low_address= (address & 0xFF);
	unsigned char	dat;
	
	EEPROM_Select();
	
	spi_Transfer(0x03);
	spi_Transfer(high_address);
	spi_Transfer(low_address);
	dat=spi_Transfer(0x00);
	
	EEPROM_Deselect();
	return dat;
}


