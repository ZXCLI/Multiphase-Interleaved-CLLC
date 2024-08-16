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
#include "SFO_V8.h"
//#include <cstdint>

#define DAC_PWM_Generator_MAX 1613
#define DAC_PWM_Generator_MIN 868

bool fault_input1_flag = false;
bool fault_input2_flag = false;
bool strat_flag = false;

uint16_t DAC_PWM_Generator = 0;
uint16_t ADCC_result[1000] = {};
uint16_t count = 0;

uint16_t tbprd = 500;

//
// Main
//
void main(void)
{
    
    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);//关闭EPWM时钟
    //
    // PinMux and Peripheral Initialization
    //

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);//开启EPWM时钟

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    CPUTimer_startTimer(CPUTIMER0_BASE);
    //CPUTimer_startTimer(CPUTIMER1_BASE);

    DEVICE_DELAY_US(10000);//延时10ms
    strat_flag = true;

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    while (1) {
       GPIO_togglePin(FAN1);
       EPWM_setTimeBasePeriod(EPWM3_BASE, tbprd);
       //tbprd -= 1;
       DEVICE_DELAY_US(100);
       ADCC_result[count++] = ADC_readResult(ADCCRESULT_BASE, ADC_SOC_NUMBER0);
       if( count >= 1000) {count = 0;}
       if( tbprd < 10){
          tbprd = 500;
       }
    }
}

__interrupt void ISR1(void)
{
    //ADCC_result = ADC_readResult(ADCCRESULT_BASE,ADC_SOC_NUMBER0);
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);//timer0要加上清除中断标志位这句话
}

__interrupt void ISR2(void)
{
    //GPIO_togglePin(DEBUG2);
    DAC_setShadowValue(myDAC0_BASE, DAC_PWM_Generator);
    DAC_PWM_Generator += 2;
    if (DAC_PWM_Generator > DAC_PWM_Generator_MAX) {
      DAC_PWM_Generator = DAC_PWM_Generator_MIN;
    }
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
