#include "i2c.h"
void Idelay(unsigned int i)
{
	unsigned int j;
	for(j=0;j<i;j++);
}

void i2c_start()
{
	SCL=1;
	SDA=1;
	Idelay(5);
	SDA=0;
	Idelay(5);
	SCL=0;
}

void i2c_stop()
{
	SCL=0;
	SDA=0;
	Idelay(5);
	SCL=1;
	Idelay(5);
	SDA=1;
}

void i2c_write(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SDA=(dat&0x80)?1:0;
		SCL=1;
		Idelay(5);
		SCL=0;
		dat=dat<<1;
	}
	
	SDA=1;
	SCL=1;
	while(SDA==1);   //waiting until SDA=0 this shold be set by slave
  SCL=0;
  Idelay(5);	
}

unsigned char i2c_read()
{
		bit rd_bit;
	unsigned char i, dat=0;
	for(i=0;i<8;i++)
	{
		Idelay(5);
		SCL=1;
		Idelay(5);
		rd_bit=SDA;
		dat=dat<<1;
		dat=dat|rd_bit;
		SCL=0;
	}
	SDA=1;
	SCL=1;
	Idelay(5);
	SCL=0;
	return dat;
}