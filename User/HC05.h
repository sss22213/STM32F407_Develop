/*************************************************************
Use USART2 at Receive and Transmitter
Extern variable Temp is USART2 interrupt receive variable
**************************************************************/
#ifndef _HC05_H_
#define _HC05_H_

#include "stm32f4xx.h"
#include "debug_swv.h"
#include "Delay.h"
#include "USART.h"

#define Serial USART2

/*********************************************/
/*NAME:			HC05_Tran												**/
/*INPUT:		u8															**/
/*RETURN:		NULL														**/
/*********************************************/
void HC05_Tran(u8 data);

/*********************************************/
/*NAME:			HC05_Reci												**/
/*INPUT:		void														**/
/*RETURN:		int															**/
/*If Receive 	Greater than or equal ASCII 0,**/
/*then Data will be return									**/
/*********************************************/
int HC05_Reci(void);

//USART2 interrupt receive variable
extern int temp;





#endif