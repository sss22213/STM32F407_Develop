/**
  ******************************************************************************
  * @file    ????:Project/2.User/main.h 
  * @author  ???:???
  * @version ??:V1.0.0
  * @date    ??:2015.07.23
  * @brief   ??:??main.c?????
  ******************************************************************************
  * @attention ????:
  * ??????????????????????
    *
    *
  *
  ******************************************************************************
  */
   
/* ????????? --------------------------------------------------------*/
#ifndef _MAIN_H_
#define _MAIN_H_
 
/* Includes(??) ------------------------------------------------------------------*/
#include "core.h"
#include "stm32f4xx.h"
#include "debug_swv.h"
#include "HTU21.h"
#include "Delay.h"
#include "USART.h"
#include "arm_math.h"
#include "HC05.h"
#include "RF.h"

void GPIO_Configurataion(void);
void NVIC_Configurataion(void);
void Timer_Configuration(void);
extern int temp;
extern int timer2;
/* Exported types(??) ------------------------------------------------------------*/

 
 
/* Exported constants(??) --------------------------------------------------------*/
 
/* Exported macro(??) ------------------------------------------------------------*/
 
 
/* Exported functions(??) ------------------------------------------------------- */
 
 
#endif /* __MAIN_H */
 
/************************************** (C) COPYRIGHT ??? ***** ???? ****/