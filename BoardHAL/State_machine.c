#include "State_machine.h"

int16_t vTimer0[4];         // Virtual Timers slaved off CPU Timers (A events)
int16_t vTimer1[4];         // Virtual Timers slaved off CPU Timers (B events)

void (*Alpha_State_Ptr)(void);  // 基态状态机指针
void (*A_Task_Ptr)(void);       // State pointer A branch
void (*B_Task_Ptr)(void);       // State pointer B branch

void A0(void) // 快速任务。状态机A由CPU_TIMER1管理
{
    if (CLLC_GET_TASKA_TIMER_OVERFLOW_STATUS == 1)
    {
        CLLC_CLEAR_TASKA_TIMER_OVERFLOW_FLAG; // clear flag

        (*A_Task_Ptr)();

        vTimer0[0]++; // virtual timer 0, instance 0 (spare)
    }
    Alpha_State_Ptr = &B0; // Comment out to allow only A tasks
}

void B0(void) // 更慢的任务。状态机B由CPU_TIMER2管理
{
   
    if (CLLC_GET_TASKB_TIMER_OVERFLOW_STATUS == 1)
    {
        CLLC_CLEAR_TASKB_TIMER_OVERFLOW_FLAG; // clear flag

        (*B_Task_Ptr)();

        vTimer1[0]++; // virtual timer 1, instance 0 (spare)
    }
    Alpha_State_Ptr = &A0;
}

void A1(void)// 0.5ms执行一次
{
    CLLC_softStart(); // 软启动
    CLLL_checkPowerFlow(); // 检查功率流


    A_Task_Ptr = &A1;
}

void A2(void)
{

    A_Task_Ptr = &A1;
}

void B1(void)
{
    DEBUG2_TRACE_IN;
    CLLC_HAL_DEBUG_Transnit(); // 调试信息传输，顺序Vprim, Vsec, Iprim1, Isec1
    DEBUG2_TRACE_OUT;


    B_Task_Ptr = &B1;
}
