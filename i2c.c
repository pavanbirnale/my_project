#include "i2c.h"

void i2c_delay(unsigned int i)
{
	unsigned int j;
	for(j=0;j<i;j++);
}

void i2c_start()
{
	SCL=1;
	SDA=1;
	i2c_delay(5);
	SDA=0;
	i2c_delay(5);
	SCL=0;
}
void i2c_stop()
{
	SCL=0;
	SDA=0;
	i2c_delay(5);
	SCL=1;
	i2c_delay(5);
	SDA=1;
}


// write bite of data master to slave 

unsigned char i2c_write(unsigned char Idata)
{
	unsigned char i, ack;
	for(i=0;i<8;i++)
	{
		SDA= (Idata & 0x80)?1:0;
		i2c_delay(5);
		SCL=1;
		i2c_delay(5);
		SCL=0;
		Idata= Idata<<1;   // shift to next bit
	}
	// release SDA for ACK
	SDA=1;
	SCL=1;
	i2c_delay(5);
	ack=SDA;    // read ACK
	SCL=0;
	return !ack;
}

unsigned char i2c_read(bit ack)
{
	unsigned char i, dat=0;
	
	SDA=1;           // relese SDA for input
	
	for(i=0;i<8;i++)
	{
		SCL=1;
		i2c_delay(5);
		dat<<=1;
		
		if(SDA)
		{
			dat|=1;  // read bit from SDA
		}
		SCL=0;
		i2c_delay(5);
	}
	
	// Send ACK/NACK to slave
	
	SDA=(ack==1)? 0:1;
	i2c_delay(5);
	SCL=1;
	i2c_delay(5);
	SCL=0;
	SDA=1;        // relese SDA again
	i2c_delay(5);
	return dat;
}


void eeprom_write_multiple(unsigned char start_add, unsigned char *dat, unsigned char length)
{
	unsigned char i;
	i2c_start();
	i2c_write(0xA0);
	
	i2c_write(start_add);
	
	for(i=0;i<length;i++)
	{
		i2c_write(dat[i]);
	}
	i2c_stop();
	
	i2c_delay(500);
}

void eeprom_read_multiple(unsigned char start_add, unsigned char *buffer, unsigned char length)
{
	unsigned char i;
	i2c_start();
	i2c_write(0xA0);
	i2c_write(start_add);
	i2c_start();
	i2c_write(0xA1);
	for(i=0;i<length;i++)
	{
		buffer[i]= i2c_read(i<(length-1)?1:0);
	}
	
	i2c_stop();
	
}


