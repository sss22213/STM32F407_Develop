#include "HTU21.h"


void HTU21_Init()
{
	


}
void HTU21_Set()
{
	

}
float HTU21_read_temp()
{
	u8 data[3];
	u16 buffer=0;
	//Hold Temp
	Bo_I2C_Read(HTU21_addr|0x01,0xE3,data,3); 
	//MSB,LSB
	buffer=data[1]<<8|data[2];
	return -46.85+175.72*buffer/pow(2,16);
}
float HTU21_read_humidity()
{


}