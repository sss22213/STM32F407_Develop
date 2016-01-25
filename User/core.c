#include "core.h"

//Systick papameter
int timer2=0;
//TASK TABLE
int (*TASK_Ptr[TASK_MAX])(void);

//TASK Sched
int (*TASK_Sched[TASK_MAX])(void);

//TASK Time
int TASK_Time[TASK_MAX];

//Init OS
int OS_Start(void)
{
    if(TASK_Init()!=0)return -1;
    return 0;
}

int OS_Stop(void)
{
    if(TASK_Init()!=0)return -1;
    return 0;
}

int TASK_Init(void)
{
    int i=0;
    for(i=0;i<TASK_MAX-1;i++)
    {
       TASK_Ptr[i]=TASK_NULL;
       TASK_Sched[i]=TASK_NULL;
       TASK_Time[i]=-1;
    }
    return 0;
}
int TASK_Create(int (*TASK)(),int Prior,int timer)
{
    TASK_Ptr[Prior]=TASK;
    TASK_Time[Prior]=timer;
    return 0;
}

int TASK_Delete(int (*TASK)())
{
    int i=0;
    for(i=0;i<TASK_MAX-1;i++)
    {
       if(TASK_Ptr[i]==TASK)
       {
            TASK_Ptr[i]=TASK_NULL;
            TASK_Time[i]=-1;
            break;
       }
    }
    return 0;
}

//TASK Dispatch
int TASK_Switch()
{
   int i=0;
   int j=0;

   for(i=0;i<TASK_MAX-1;i++)
   {
     if(TASK_Time[i]!=-1)
     {
       if(timer2%TASK_Time[i]==0)
       {
          TASK_Sched[j]=*TASK_Ptr[i];
          j++;
       }
     }
   }
   return 0;
}
int TASK_Excute()
{
    int i=0;
    //TASK Excute
    while(TASK_Sched[i]!=TASK_NULL)
    {
      //Excute
      (*TASK_Sched[i])();

      //Empty
      TASK_Sched[i]=TASK_NULL;
      i++;
    }
    TASK_Switch();
    return 0;

}
/*
int *TASK_Where()
{
  static int Get_info[2];
  Get_info[0]=TASK_Now;
  return Get_info;
}*/
//TASK Sned Output ???
/*
int TASK_Output(void *parameter,int Prior)
{
  TASK_Out[Prior]=parameter;
  //printf("%d\n",(int*)var);
  return 0;
}*/
int TASK_NULL()
{
    return 0;
}
