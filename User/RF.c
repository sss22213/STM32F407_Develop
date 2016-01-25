#include "RF.h"
int RF_Init()
{	
	USART_InitTypeDef UART;
	UART.USART_BaudRate=9600;
	UART.USART_WordLength=USART_WordLength_8b;
	UART.USART_StopBits=USART_StopBits_1;
	UART.USART_Parity=USART_Parity_No;		
	UART.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
	UART.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(Serial_port,&UART);		
	USART_ITConfig(Serial_port,USART_IT_RXNE,ENABLE);
	USART_Cmd(Serial_port,ENABLE);
	return 0;
}
int RF_SendData(uint16_t *data)
{
	while(data=='\0')
	{
		USART_SendData(Serial_port,*data);
		data++;
	}
	return 0;
}
u8 *RF_Receive(u8 *data,int length)
{
	while(length!=0)
	{
		length--;
		*data=temp3;
		data++;
	}
	return data;
}