#include "debug_swv.h"
void debug_swv(char *ptr)
{
	while(*ptr!='/0')
	{
	
		ITM_SendChar(*ptr);
		*ptr++;
	}


}