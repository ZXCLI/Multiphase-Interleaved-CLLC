// By ZXC on 2024/08/16

#include "CLLC_HAL.h"
#include "board.h"
#include "CLLC.h"
#include "epwm.h"
#include "inc/hw_types.h"

uint16_t test;
uint16_t test2;
uint16_t test3;


void main(void)
{

    CLLC_HAL_setupDevice(); // 初始化设备

    CLLC_initGlobalVariables(); // 初始化全局变量

    CLLC_HAL_disablePWMClkCounting();//关闭EPWM时钟

    CLLC_HAL_setPins();//设置引脚

    CLLC_HAL_setupLED();//初始化LED

    CLLC_HAL_setupCPI();//通信外设初始化

    CLLC_HAL_setupFAN();//初始化风扇

    CLLC_HAL_setupADC();//初始化ADC

    CLLC_HAL_setupPWM(
            CLLC_powerFlowStateActive.CLLC_PowerFlowState_Enum);
    // 初始化PWM
    
    CLLC_HAL_setupBoardProtection(); // 初始化保护

    CLLC_HAL_setupInterrupt(
            CLLC_powerFlowStateActive.CLLC_PowerFlowState_Enum); 
    // 初始化中断

    CLLC_HAL_enablePWMClkCounting(); // 初始化完成，开启EPWM时钟

    Alpha_State_Ptr = &A0;
    A_Task_Ptr = &A1;
    B_Task_Ptr = &B0;

    //ECAP_enableCounter(ECAP7_BASE);
    //ECAP_startCounter(ECAP6_BASE);

    while (1) {
        (*Alpha_State_Ptr)(); //调用状态机

        // // 读取时间戳
        // rising_edge_1 =
        //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_1); // 上升沿1
        // falling_edge_1 =
        //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_2); // 下降沿1
        // rising_edge_2 =
        //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_3); // 上升沿2
        // falling_edge_2 =
        //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_4); // 下降沿2

        // uint32_t pwm_period = rising_edge_2 - rising_edge_1;  // 周期
        // pwm_frequency = 1.0f / (pwm_period * time_scale);  // 频率，time_scale 是 eCAP 计数器时钟周期

        // uint32_t high_time = falling_edge_1 - rising_edge_1;  // 高电平时间
        // duty_cycle = (float)high_time / pwm_period * 100.0f;  // 占空比（百分比）

        // uint32_t dead_time = rising_edge_1 - falling_edge_1; // 死区时间
        // dead_time_us = dead_time * time_scale;   // 转换为微秒

        // EPWM_setTimeBasePeriod(EPWM3_BASE,pwm_period_3);
    }
}

//
// 下面是中断函数的定义
//


__interrupt void INT_M_EPWM3_TZ_ISR(void)
{

}

//
// End of File
//
