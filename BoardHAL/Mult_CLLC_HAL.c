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

void Mult_CLLC_HAL_setPins(void)
{
    PinMux_init();
    INPUTXBAR_init();    
}
void Mult_CLLC_HAL_setupLED(void)
{
    
}
void Mult_CLLC_HAL_setupADC(void)
{
    ASYSCTL_init();//配置内部参考电压
    ADC_init();//初始化ADC
}
//
void MUlt_CLLC_HAL_setupBoardProtection(void)
{
    CMPSS_init();//配置用于cbc保护的比较器

    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGA_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGB_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGA_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGB_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1)); // 清除第一相的OST

    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGC_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGD_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGC_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGD_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1)); // 清除第二相的OST
}

void Mult_CLLC_HAL_setupPWM(uint16_t powerFlowDir)
{
    SYNC_init(); // 初始化同步模块
    EPWM_init(); // 初始化EPWM
}

void Mult_CLLC_HAL_disablePWMClkCounting(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 关闭EPWM时钟
}

void Mult_CLLC_HAL_enablePWMClkCounting(void)
{
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 开启EPWM时钟
}
