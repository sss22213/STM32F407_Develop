#ifndef _CORE_H_
#define _CORE_H_
#include "main.h"
//#include <stdio.h>
//#include <stdlib.h>
#define TASK_MAX 20

//OS Start and Task init
int OS_Start(void);

//Task init
int OS_Stop(void);

/*Parameter Output
void *TASK_Out[TASK_MAX];*/

//Now TASK
//int TASK_Now[TASK_MAX];

/*******************************************/
/*1.Name:TASK_Init                         */
/*2.input:void                             */
/*3.output:int                             */
/*4.excute succeed return 0                */
/*Clear TASK TABLE,TASK Sched and TASK Time*/
/*******************************************/
int TASK_Init(void);

/*******************************************/
/*1.Name:TASK_Create                       */
/*2.input:int(*)(),int,int                 */
/*3.output:int                             */
/*4.excute succeed return 0                */
/*Put Task on TASK TABLE                   */
/*put prior on Task prior                  */
/*put TASK Time on TASK Time               */
/*******************************************/
int TASK_Create(int (*TASK)(),int Priormint,int timer);

/*****************************************************/
/*1.Name:TASK_Delete                                 */
/*2.input:int(*)()                                   */
/*3.output:int                                       */
/*4.excute succeed return 0                          */
/*Remoce Task on TASK TABLE and put TASK_NULL on TASK*/
/*put -1 on Task Time                                */
/*****************************************************/
int TASK_Delete(int (*TASK)());

/*****************************************************/
/*1.Name:TASK_Excute                                 */
/*2.input:void                                       */
/*3.output:int                                       */
/*4.excute succeed return 0                          */
/*****************************************************/
int TASK_Excute(void);

//int *TASK_Where(void);

//Empty Task
int TASK_NULL(void);

//int TASK_Output(void *parameter,int Prior);
#endif
