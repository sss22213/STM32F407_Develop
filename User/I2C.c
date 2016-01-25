#include "I2C.h"
void Bo_I2C_Init()
{

	I2C_InitTypeDef	I2C_Set;
	I2C_Set.I2C_ClockSpeed=100000;
	I2C_Set.I2C_Mode=I2C_Mode_I2C;
	I2C_Set.I2C_DutyCycle=I2C_DutyCycle_2;
	I2C_Set.I2C_OwnAddress1=0x00;
	I2C_Set.I2C_Ack=I2C_Ack_Enable;
	I2C_Set.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;
	I2C_Init(I2C1,&I2C_Set);
}
void Bo_I2C_Write(u8 dev_addr,u8 in_addr,u8 *data,int length)
{
	int i=0;
	while(I2C_EVENT_SLAVE_BYTE_RECEIVED);
		
	I2C_GenerateSTART(I2C1,ENABLE);
	while(I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT)==0);
	
	//SendDeviceAddress
	I2C_Send7bitAddress(I2C1,dev_addr,I2C_Direction_Transmitter);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	
	I2C_SendData(I2C1,in_addr);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	
	for(i=0;i<length-1;i++)
	{
		I2C_SendData(I2C1,data[i]);
		while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	}
	I2C_GenerateSTOP(I2C1,ENABLE);
	I2C_ClearFlag(I2C1, I2C_FLAG_AF); //Clear ACK Flag
	I2C_GenerateSTOP(I2C1,ENABLE);
}/*
void Bo_I2C_Read(u8 dev_addr,u8 in_addr,u8 *buffer,int length)
{
	I2C_GenerateSTART(I2C1,ENABLE);
	I2C_SendData(I2C1,dev_addr);
	I2C_SendData(I2C1,in_addr);
	I2C_GenerateSTART(I2C1,ENABLE);
	I2C_SendData(I2C1,dev_addr|0x01);
	buffer[0]=I2C_ReceiveData(I2C1);
	I2C_GenerateSTOP(I2C1,ENABLE);
}*/

void Bo_I2C_Read(u8 dev_addr,u8 in_addr,u8 *buffer,int length)
{
	int i=0;
	
	while(I2C_GetFlagStatus(I2C1,I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2C1,ENABLE);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));
	
	//SendDeviceAddress
	I2C_Send7bitAddress(I2C1,dev_addr,I2C_Direction_Transmitter);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	I2C_Cmd(I2C1,ENABLE);
	
	I2C_SendData(I2C1,in_addr);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	//Restart
	I2C_GenerateSTART(I2C1,ENABLE);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_MODE_SELECT));
	
	//SendDeviceAddress
	I2C_Send7bitAddress(I2C1,dev_addr|0x01,I2C_Direction_Receiver);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	
	if(length>1)
	{
		//receive 
		for(i=1;i<length;i++)
		{
			I2C_AcknowledgeConfig(I2C1,ENABLE);
			while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));
			buffer[i]=I2C_ReceiveData(I2C1);
		}
	}
	
	I2C_AcknowledgeConfig(I2C1,DISABLE); //Send NACK to slave
	I2C_GenerateSTOP(I2C1,ENABLE);
	
	//final receive
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));
	buffer[0]=I2C_ReceiveData(I2C1);
	
	I2C_AcknowledgeConfig(I2C1,ENABLE);//Reset ACK
	I2C_ClearFlag(I2C1,I2C_FLAG_AF); //Clear ACK Flag
	I2C_GenerateSTOP(I2C1,ENABLE); 
	
	
}