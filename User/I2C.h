#ifndef _I2C_H_
#define	_I2C_H_

#include "Delay.h"
#include "stm32f4xx.h"
#include "debug_swv.h"
#include "math.h"

/*********************************************/
/*NAME:			Bo_I2C_Init											**/
/*INPUT:		void														**/
/*RETURN:		void														**/
/*********************************************/
void Bo_I2C_Init();

/*********************************************/
/*NAME:			Bo_I2C_Write										**/
/*INPUT:		u8 dev_addr,u8 in_addr,u8 *data,int length	**/
/*RETURN:		void														**/
/*********************************************/
void Bo_I2C_Write(u8 dev_addr,u8 in_addr,u8 *data,int length);


/****************************************************************************************/
/*NAME:			Bo_I2C_Read																																 **/
/*INPUT:		u8 dev_addr,u8 in_addr,u8 *buffer,int length															 **/
/*RETURN:		void																																			 **/
/****************************************************************************************/
void Bo_I2C_Read(u8 dev_addr,u8 in_addr,u8 *buffer,int length);

#endif