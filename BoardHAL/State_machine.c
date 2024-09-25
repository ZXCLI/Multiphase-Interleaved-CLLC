#include "State_machine.h"

int16_t vTimer[4];          // Virtual Timers slaved off CPU Timers (A events)
int16_t vTimerCompare[4];   // Virtual Timers slaved off CPU Timers (B events)

void (*Alpha_State_Ptr)(void);  // 基态状态机指针
void (*A_Task_Ptr)(void);       // State pointer A branch
void (*B_Task_Ptr)(void);       // State pointer B branch

void A0(void) // 快速任务。状态机A由CPU_TIMER1管理
{
    if (CLLC_GET_TASKA_TIMER_OVERFLOW_STATUS == 1)
    {
        CLLC_CLEAR_TASKA_TIMER_OVERFLOW_FLAG; // clear flag

        (*A_Task_Ptr)();
    }
    Alpha_State_Ptr = &B0; // Comment out to allow only A tasks
}

void B0(void) // 更慢的任务。状态机B由CPU_TIMER2管理
{
   
    if (CLLC_GET_TASKB_TIMER_OVERFLOW_STATUS == 1)
    {
        CLLC_CLEAR_TASKB_TIMER_OVERFLOW_FLAG; // clear flag

        (*B_Task_Ptr)();

        vTimer[0]++;

        if(vTimer[0] > 1000){
            vTimer[0] = 0;
        }
    }
    Alpha_State_Ptr = &A0;
}

void A1(void)// 0.5ms执行一次
{
    CLLL_checkPowerFlow(); // 检查功率流

    CLLC_updateBoardStatus();

    EALLOW;
    if(CLLC_tripFlag.trip_MAIN == 1){
        GPIO_writePin(STATUS1,0);
        GPIO_writePin(FAULT_OUTPUT, 1);
    }
    if(CLLC_tripFlag.trip_SECONDARY == 1){
        GPIO_writePin(STATUS2,0);
        GPIO_writePin(FAULT_OUTPUT, 1);
    }
    EDIS;
    A_Task_Ptr = &A2;
}

void A2(void)
{
    static uint16_t lastStute[3] = {0};
    CLLC_HAL_HysteresisLoop(0.1f, 0.05f,
                            CLLC_iPrimMAINSensedAvg_pu.out,
                            &CLLC_systemState.systemstate_Brust, 
                            &lastStute[0],
                            &CLLC_isBRUSTModeEnabled);// BRUST
    CLLC_HAL_HysteresisLoop(0.1f, 0.05f,
                            CLLC_iPrimMAINSensedAvg_pu.out, 
                            &CLLC_systemState.systemstate_SyncRectification,
                            &lastStute[1],
                            &CLLC_isSyncRectificationModeEnabled);// 同步整流
    CLLC_HAL_HysteresisLoop(0.1f, 0.05f,
                            CLLC_iPrimMAINSensedAvg_pu.out,
                            &CLLC_systemState.systemstate_SecondaryEnabled, 
                            &lastStute[2],
                            &CLLC_isSecondaryEnabled); // 开启第二相
    A_Task_Ptr = &A1;
}

void B1(void)
{
    // DEBUG2_TRACE_IN;
    // CLLC_HAL_DEBUG_Transnit(); // 调试信息传输，顺序Vprim, Vsec, Iprim1, Isec1
    // DEBUG2_TRACE_OUT;

    B_Task_Ptr = &B1;
}
