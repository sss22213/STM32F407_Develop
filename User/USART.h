#ifndef __USART_H
#define __USART_H

#include "stm32f4xx.h"


/*****************************************/
/*NAME:			USART_Configurataion	**/
/*INPUT:		NULL					**/
/*RETURN:		NULL					**/
/*****************************************/
void USART_Configurataion(void);


/*************************************************/
/*NAME:			USART_Sendstring				**/
/*INPUT:		USART_TypeDef* USARTx,char* data**/
/*RETURN:		NULL							**/
/*************************************************/
void USART_Sendstring(USART_TypeDef* USARTx,char* data);

#endif

