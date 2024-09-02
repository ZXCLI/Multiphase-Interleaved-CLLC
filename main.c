#include "adc.h"
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "gpio.h"
#include "inc/hw_memmap.h"

#include "Mult_CLLC.h"

volatile bool fault_input1_flag = false;
volatile bool fault_input2_flag = false;
uint16_t test = 0;
uint16_t mm = 0;

void main(void)
{

    Mult_CLLC_HAL_setupDevice(); // 初始化设备

    Mult_CLLC_HAL_disablePWMClkCounting();//关闭EPWM时钟

    Mult_CLLC_HAL_setPins();//设置引脚

    Mult_CLLC_HAL_setupLED();//初始化LED

    // Board_init();//初始化板子

    MUlt_CLLC_HAL_setupBoardProtection();//初始化保护

    Mult_CLLC_HAL_setupADC();//初始化ADC

    MULT_CLLC_HAL_setupInterrupt(
            MULT_CLLC_powerFlowStateActive.MULT_CLLC_PowerFlowState_Enum); 
    // 初始化中断

    Mult_CLLC_HAL_enablePWMClkCounting(); // 初始化完成，开启EPWM时钟
    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    while (1) {
        if(test == 1){
            EPWM_clearTripZoneFlag(EPWM3_BASE, EPWM_TZ_FLAG_OST);
        }
        mm =  EPWM_getTripZoneFlagStatus(EPWM3_BASE);
        //(*Alpha_State_Ptr)(); //调用状态机
    }
}

//
// 下面是中断函数的定义
//


__interrupt void ISR1(void)
{
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);//timer0要加上清除中断标志位这句话
}

// __interrupt void ISR2(void)
// {

// }

// __interrupt void ISR3(void)
// {
    
// }

// __interrupt void FAULT_INPUT1_ISR1(void)
// {
//     //SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);//关闭EPWM时钟
//     //GPIO_writePin(FAULT_OUTPUT,1);//触发保护
//     GPIO_writePin(STATUS1,0);//指示灯切换
//     GPIO_writePin(DEBUG1,1);
//     fault_input1_flag = 1;//保存FAULT1
//     Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
// }

// __interrupt void FAULT_INPUT2_ISR1(void)
// {
//     //SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);//关闭EPWM时钟
//     //GPIO_writePin(FAULT_OUTPUT,1);//触发保护
//     GPIO_writePin(STATUS2,0);//指示灯切换
//     GPIO_writePin(DEBUG2,1);
//     fault_input2_flag = 1;//保存FAULT2
//     Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
// }
__interrupt void INT_M_EPWM3_TZ_ISR(void)
{

}
__interrupt void PZCD1_ISR(void)
{

    // if(strat_flag){
    //   HWREGH(EPWM3_BASE + EPWM_O_TBCTR) = 0;
    //   HWREGH(EPWM4_BASE + EPWM_O_TBCTR) = 0;
    // //   EPWM_setTimeBaseCounter(EPWM3_BASE, 0);
    // //   EPWM_setTimeBaseCounter(EPWM4_BASE, 0);
    // }
    //GPIO_togglePin(DEBUG1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}
//
// End of File
//
