	#include "USART.h"
	/*********************************************/
	/*NAME:			USART_Configurataion	**/
	/*INPUT:		NULL									**/
	/*RETURN:		NULL									**/
	/*9600,N81												**/
	/*********************************************/
	void USART_Configurataion(void)
	{
		//USART2_Init
		USART_InitTypeDef UART;

		UART.USART_BaudRate=9600;

		UART.USART_WordLength=USART_WordLength_8b;

		UART.USART_StopBits=USART_StopBits_1;
  		
		UART.USART_Parity=USART_Parity_No;
  		
		UART.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;

		UART.USART_HardwareFlowControl=USART_HardwareFlowControl_None;

  	USART_Init(USART2,&UART);
			
		USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);

		USART_Cmd(USART2,ENABLE);
			
	}
	void USART_Sendstring(USART_TypeDef* USARTx,char* data)
	{
		int i=0;
		while(*(data+i)!='\0')
		{
			USART_SendData(USARTx,*(data+i));
			while (USART_GetFlagStatus(USARTx,USART_FLAG_TC) == RESET);
			i++;
				
		}	
	}
	
