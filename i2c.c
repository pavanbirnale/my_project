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

void i2c_write(unsigned char Idata)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SDA= (Idata & 0x80)?1:0;
		SCL=1;
		i2c_delay(5);
		SCL=0;
		Idata= Idata<<1;
	}
	SDA=1;
	SCL=1;
	i2c_delay(5);
	while(SDA==1);   // waiting unting SDA =0
	i2c_delay(5);
	SCL=0;
}

unsigned char i2c_read()
{
	bit rd_bit;
	unsigned char i, Dat=0;
	
	for(i=0;i<8;i++)
	{
		i2c_delay(5);
		SCL=1;
		i2c_delay(5);
		rd_bit=SDA;
		Dat=Dat<<1;
		Dat=Dat|rd_bit;
		SCL=0;
	}
	SDA=1;
	 SCL=1;
	i2c_delay(5);
	SCL=0;
	return Dat;
}





