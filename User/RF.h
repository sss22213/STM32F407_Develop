#ifndef _RF_H_
#define _RF_H_

#include "stm32f4xx.h"
#include "debug_swv.h"
#include "Delay.h"
#include "USART.h"
#include "arm_math.h"

#define Serial_port USART2

extern int temp3;
int RF_Init(void);
int RF_SendData(uint16_t *data);
u8 *RF_Receive(u8 *data,int length);

#endif