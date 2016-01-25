#include "Delay.h"

int timer=0;

void Delay_100us(int nTime)
 {
   timer = nTime;

  while(timer != 0);
 }
 
void Delay_Ms(int Ms)
 {
	 int i=0;
	 for(i=0;i<Ms;i++)
	 {
			Delay_100us(10);
	 
	 }
 
 }