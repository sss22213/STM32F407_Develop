#include "HC05.h"
void HC05_Tran(u8 data)
{
	USART_SendData(Serial,data);
}
int HC05_Reci(void)
{
	//HC05 TEMP
	int H_temp=0;
	
	//If Receive 	Greater than or equal ASCII 0
	if(temp>=0x30)
	{
		H_temp=temp;
		
		//reset USART2 interrupt receive variable
		temp=0;
		
		return H_temp;
	}
	
}

