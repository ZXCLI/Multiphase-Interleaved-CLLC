#include "State_machine.h"

int16_t vTimer0[4];         // Virtual Timers slaved off CPU Timers (A events)
int16_t vTimer1[4];         // Virtual Timers slaved off CPU Timers (B events)

void (*Alpha_State_Ptr)(void);  // 基态状态机指针
void (*A_Task_Ptr)(void);       // State pointer A branch
void (*B_Task_Ptr)(void);       // State pointer B branch

void A0(void) // 快速任务。状态机A由CPU_TIMER1管理
{
    //
    // loop rate synchronizer for A-tasks
    //
    if (MULT_CLLC_GET_TASKA_TIMER_OVERFLOW_STATUS == 1)
    {
        MULT_CLLC_CLEAR_TASKA_TIMER_OVERFLOW_FLAG; // clear flag

        //
        // jump to an A Task (A1,A2,A3,...)
        //
        (*A_Task_Ptr)();

        vTimer0[0]++; // virtual timer 0, instance 0 (spare)
    }
    Alpha_State_Ptr = &B0; // Comment out to allow only A tasks
}

void B0(void) // 更慢的任务。状态机B由CPU_TIMER2管理
{
    //
    // loop rate synchronizer for B-tasks
    //
    if (MULT_CLLC_GET_TASKB_TIMER_OVERFLOW_STATUS == 1)
    {
        MULT_CLLC_CLEAR_TASKB_TIMER_OVERFLOW_FLAG; // clear flag

        //
        // jump to a B Task (B1,B2,B3,...)
        //
        (*B_Task_Ptr)();

        vTimer1[0]++; // virtual timer 1, instance 0 (spare)
    }

    //
    // Allow A state tasks
    //
    Alpha_State_Ptr = &A0;
}

void A1(void)
{
    //DEBUG2_TRACE_IN;

    MULT_CLLC_HAL_DEBUG_Transnit(); // 调试信息传输，顺序Vprim, Vsec, Iprim1, Isec1

    //DEBUG2_TRACE_OUT;
    //
    // the next time CpuTimer0 'counter' reaches Period value go to A2
    //
    A_Task_Ptr = &A1;
}
