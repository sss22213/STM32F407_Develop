#ifndef	_HTU21_H_ 
#define	_HTU21_H_

#include "stm32f4xx.h"
#include "debug_swv.h"
#include "I2C.h"


#define HTU21_addr 0x80
#define Temp_hold 0xE3
#define Hum_hold 0xE5
#define Temp_no_hold 0xF3
#define Hum_no_hold 0xF5

/*********************************************/
/*NAME:			HTU21_read_temp									**/
/*INPUT:		void														**/
/*RETURN:		float														**/	
/*Return Temperature 												**/
/*********************************************/
float HTU21_read_temp();

#endif