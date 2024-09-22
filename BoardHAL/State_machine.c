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
    if (CLLC_GET_TASKA_TIMER_OVERFLOW_STATUS == 1)
    {
        CLLC_CLEAR_TASKA_TIMER_OVERFLOW_FLAG; // clear flag

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
    if (CLLC_GET_TASKB_TIMER_OVERFLOW_STATUS == 1)
    {
        CLLC_CLEAR_TASKB_TIMER_OVERFLOW_FLAG; // clear flag

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

void A1(void)// 0.5ms执行一次
{
    if((CLLC_systemState.systemstate_off == 1) || 
       (CLLC_systemState.systemstte_softstart == 1)){//执行软启动
       if(CLLC_systemState.systemstate_off == 1){
            CLLC_systemState.systemstate_off = 0;
            CLLC_systemState.systemstte_softstart = 1;
       }

        static uint16_t softstart_counter = 0;
        softstart_counter += 2;
        uint16_t softTBPRD = (uint16_t)((CLLC_PWMSYSCLOCK_FREQ_HZ/ \
                              CLLC_NOMINAL_PWM_SWITCHING_FREQUENCY_HZ) / \
                             (3.8702f-0.1365f*softstart_counter \
                              +0.00257f* softstart_counter*softstart_counter \
                              -0.00001803f*softstart_counter* \
                              softstart_counter*softstart_counter)); 
        // 三阶多项式拟合，指数衰减从4到1，对应频率从4倍谐振频率下降到1倍谐振频率
        if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == 
           powerFlow_PrimToSec)
        {
            EPWM_setTimeBasePeriod(CLLC_PRIM_LEGB_PWM_BASE, softTBPRD);
            EPWM_setCounterCompareValue(CLLC_PRIM_LEGB_PWM_BASE,
                                        EPWM_COUNTER_COMPARE_A, (softTBPRD >> 1));
        }else if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == 
           powerFlow_SecToPrim)
        {
            EPWM_setTimeBasePeriod(CLLC_SEC_LEGB_PWM_BASE, softTBPRD);
            EPWM_setCounterCompareValue(CLLC_SEC_LEGB_PWM_BASE,
                                        EPWM_COUNTER_COMPARE_A, (softTBPRD >> 1));
        }

        if(softstart_counter > 60){
            CLLC_systemState.systemstte_softstart = 0;
            CLLC_systemState.systemstate_normal = 1;
        #if CLLC_PROTECTION == CLLC_PROTECTION_ENABLED // 软启动完成再开启CBC保护
            CMPSS_enableModule(M_CMPSS1_BASE);
            CMPSS_enableModule(M_CMPSS2_BASE);
            CMPSS_enableModule(M_CMPSS3_BASE);
            CMPSS_enableModule(M_CMPSS4_BASE);
        #endif
        }
    }

    if(CLLC_systemState.systemstate_normal == 1){

    }
    //
    // the next time CpuTimer0 'counter' reaches Period value go to A2
    //
    A_Task_Ptr = &A2;
}

void A2(void)
{
    //DEBUG2_TRACE_IN;
    // CLLC_HAL_DEBUG_Transnit(); // 调试信息传输，顺序Vprim, Vsec, Iprim1, Isec1
    //DEBUG2_TRACE_OUT;
    //
    // the next time CpuTimer0 'counter' reaches Period value go to A3
    //
    A_Task_Ptr = &A1;
}