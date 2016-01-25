#include "main.h"


int task1()
{
	ITM_SendChar('a');
	return 0;
}
int task2()
{
	ITM_SendChar('b');
	return 0;
}
int main()
{
	u8 k[1];
	SystemInit();
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	GPIO_Configurataion();
	NVIC_Configurataion();
	USART_Configurataion();
	Timer_Configuration();
	SysTick_Config(SystemCoreClock/10000); //¨C1s¤¤Â_1000¦¸
	Bo_I2C_Init();
	
	/*OS_Init*/
	OS_Start();
	/*OS_TASK*/
	TASK_Create(task1,0,20);
	TASK_Create(task2,1,50);
	
	while(1)
	{	
		TASK_Excute();
		Delay_Ms(100);
	}
	
}
void GPIO_Configurataion(void)
{
		GPIO_InitTypeDef g;

		g.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3;
		
		g.GPIO_Mode = GPIO_Mode_AF;
		
		g.GPIO_OType = GPIO_OType_PP;
		
		g.GPIO_PuPd = GPIO_PuPd_UP; 
		
		g.GPIO_Speed = GPIO_Speed_100MHz; 
		
		GPIO_Init(GPIOA,&g);
		
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);  
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2); 
		
		
		g.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;
		
		g.GPIO_Mode = GPIO_Mode_AF;
		
		g.GPIO_OType = GPIO_OType_OD;
		
    g.GPIO_PuPd =  GPIO_PuPd_UP; 
		
		g.GPIO_Speed = GPIO_Speed_50MHz; 
		
		GPIO_Init(GPIOB,&g);
		
		GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1); // SCL
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_I2C1); // SDA

	}
void Timer_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIMs;
	TIMs.TIM_Prescaler=1500;         
  TIMs.TIM_CounterMode=TIM_CounterMode_Up;       
  TIMs.TIM_Period=9999;            
  TIMs.TIM_ClockDivision=TIM_CKD_DIV1;  
	TIMs.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIMs);
	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2,ENABLE);
	
}
void NVIC_Configurataion(void)
{
		
		NVIC_InitTypeDef NVIC_Struct;

		NVIC_Struct.NVIC_IRQChannel=USART2_IRQn;

		NVIC_Struct.NVIC_IRQChannelPreemptionPriority=3;

		NVIC_Struct.NVIC_IRQChannelSubPriority=0;

		NVIC_Struct.NVIC_IRQChannelCmd=ENABLE;

		NVIC_Init(&NVIC_Struct);

		NVIC_Struct.NVIC_IRQChannel=TIM2_IRQn;

		NVIC_Struct.NVIC_IRQChannelPreemptionPriority=0;

		NVIC_Struct.NVIC_IRQChannelSubPriority=0;

		NVIC_Struct.NVIC_IRQChannelCmd=ENABLE;

		NVIC_Init(&NVIC_Struct);
	
}
	
#ifdef  USE_FULL_ASSERT
 
/**
  * @brief  ??: assert_param ?????
  * @param  ??: file: ???????
  * @param  ??: line: ?????
  * @retval ??: None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
 
  /* Infinite loop */
  while (1)
  {
  }
}
#endif