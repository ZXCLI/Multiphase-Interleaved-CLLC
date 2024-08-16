//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1> 
//!
//! This example is an empty project setup for Driverlib development.
//!
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
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


//
// Main
//
void main(void)
{

    Mult_CLLC_HAL_setupDevice(); // 初始化设备


    Mult_CLLC_HAL_disablePWMClkCounting();//关闭EPWM时钟
    

    

    CPUTimer_startTimer(CPUTIMER0_BASE);
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
