#include "Mult_CLLC_HAL.h"






void Mult_CLLC_HAL_setupDevice(void)
{
    Device_init();// Initialize device clock and peripherals

    Device_initGPIO();// Disable pin locks and enable internal pull-ups.

    Interrupt_initModule(); // Initialize PIE and clear PIE registers. Disables CPU interrupts.

    Interrupt_initVectorTable();// Initialize the PIE vector table with pointers to the shell Interrupt
                                // Service Routines (ISR).

    CPUTIMER_init();
    //
    // initialize CPU timers
    // Initialize timer period to rate at which they will be used
    // to slice of task
    // TASK A FREQUENCY
    //
    CPUTimer_setPeriod(MULT_CLLC_TASKA_CPUTIMER_BASE,
                       DEVICE_SYSCLK_FREQ / MULT_CLLC_TASKA_FREQ_HZ);
    //
    // TASK B FREQUENCY
    //
    CPUTimer_setPeriod(MULT_CLLC_TASKB_CPUTIMER_BASE,
                       DEVICE_SYSCLK_FREQ / MULT_CLLC_TASKB_FREQ_HZ);
    //
    // TASK C FREQUENCY
    //
    CPUTimer_setPeriod(MULT_CLLC_TASKC_CPUTIMER_BASE,
                       DEVICE_SYSCLK_FREQ / MULT_CLLC_TASKC_FREQ_HZ);
}
void Mult_CLLC_HAL_setupLED(void)
{

}
void Mult_CLLC_HAL_disablePWMClkCounting(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 关闭EPWM时钟
}

void Mult_CLLC_HAL_enablePWMClkCounting(void)
{
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 开启EPWM时钟
}
