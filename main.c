// By ZXC on 2024/08/16

#include "Mult_CLLC_HAL.h"
#include "board.h"
#include "Mult_CLLC.h"

uint16_t test;
uint16_t test2;
uint16_t test3;

void main(void)
{

    Mult_CLLC_HAL_setupDevice(); // 初始化设备

    MULT_CLLC_initGlobalVariables(); // 初始化全局变量

    Mult_CLLC_HAL_disablePWMClkCounting();//关闭EPWM时钟

    Mult_CLLC_HAL_setPins();//设置引脚

    Mult_CLLC_HAL_setupLED();//初始化LED

    Mult_CLLC_HAL_setupCPI();//通信外设初始化

    Mult_CLLC_HAL_setupFAN();//初始化风扇

    Mult_CLLC_HAL_setupADC();//初始化ADC

    Mult_CLLC_HAL_setupPWM(
            MULT_CLLC_powerFlowStateActive.MULT_CLLC_PowerFlowState_Enum);
    // 初始化PWM
    
    MUlt_CLLC_HAL_setupBoardProtection(); // 初始化保护

    MULT_CLLC_HAL_setupInterrupt(
            MULT_CLLC_powerFlowStateActive.MULT_CLLC_PowerFlowState_Enum); 
    // 初始化中断

    Mult_CLLC_HAL_enablePWMClkCounting(); // 初始化完成，开启EPWM时钟

    Alpha_State_Ptr = &A0;
    A_Task_Ptr = &A1;
    B_Task_Ptr = &B0;

    while (1) {
        (*Alpha_State_Ptr)(); //调用状态机
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
