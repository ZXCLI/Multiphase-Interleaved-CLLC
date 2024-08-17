#include "adc.h"
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "gpio.h"
#include "inc/hw_memmap.h"

#include "Mult_CLLC_HAL.h"

bool fault_input1_flag = false;
bool fault_input2_flag = false;


void main(void)
{

    Mult_CLLC_HAL_setupDevice(); // 初始化设备


    Mult_CLLC_HAL_disablePWMClkCounting();//关闭EPWM时钟
    

    //CPUTimer_startTimer(CPUTIMER0_BASE);
    //CPUTimer_startTimer(CPUTIMER1_BASE);


    Mult_CLLC_HAL_enablePWMClkCounting();//初始化完成，开启EPWM时钟
    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    while (1) {

       
    }
}

__interrupt void ISR1(void)
{
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);//timer0要加上清除中断标志位这句话
}

__interrupt void ISR2(void)
{

}

__interrupt void ISR3(void)
{
    
}

__interrupt void FAULT_INPUT1_ISR(void)
{
    //SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);//关闭EPWM时钟
    //GPIO_writePin(FAULT_OUTPUT,1);//触发保护
    GPIO_writePin(STATUS1,0);//指示灯切换
    GPIO_writePin(DEBUG1,1);
    fault_input1_flag = 1;//保存FAULT1
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

__interrupt void FAULT_INPUT2_ISR(void)
{
    //SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);//关闭EPWM时钟
    //GPIO_writePin(FAULT_OUTPUT,1);//触发保护
    GPIO_writePin(STATUS2,0);//指示灯切换
    GPIO_writePin(DEBUG2,1);
    fault_input2_flag = 1;//保存FAULT2
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

__interrupt void PZCD1_ISR(void)
{

    // if(strat_flag){
    //   HWREGH(EPWM3_BASE + EPWM_O_TBCTR) = 0;
    //   HWREGH(EPWM4_BASE + EPWM_O_TBCTR) = 0;
    // //   EPWM_setTimeBaseCounter(EPWM3_BASE, 0);
    // //   EPWM_setTimeBaseCounter(EPWM4_BASE, 0);
    // }
    GPIO_togglePin(DEBUG1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}
//
// End of File
//
