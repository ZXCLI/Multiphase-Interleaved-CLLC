#include "Mult_CLLC_HAL.h"
#include "Mult_CLLC.h"
#include "Mult_CLLC_settings.h"
#include "Mult_CLLC_user_settings.h"
#include "inc/hw_types.h"
#include "stdio.h"



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

    CPUTimer_startTimer(MULT_CLLC_TASKA_CPUTIMER_BASE);
    CPUTimer_startTimer(MULT_CLLC_TASKB_CPUTIMER_BASE);
    CPUTimer_startTimer(MULT_CLLC_TASKC_CPUTIMER_BASE);
}

void Mult_CLLC_HAL_setPins(void)
{
    PinMux_init();
    INPUTXBAR_init();    
    GPIO_init();
}

void Mult_CLLC_HAL_setupCPI(void)
{
    PMBUS_init();
    SCI_init();
}

void Mult_CLLC_HAL_setupLED(void)
{
    
}


void Mult_CLLC_HAL_setupADC(void)
{
    ASYSCTL_init();//配置内部参考电压
    ADC_init();//初始化ADC
    DEVICE_DELAY_US(100);
    MULT_CLLC_HAL_ClaADCOffset();//校准ADC偏移量，并写入寄存器
}

void MULT_CLLC_HAL_ClaADCOffset(void)
{

}

void Mult_CLLC_HAL_setupFAN(void)
{
    #if USE_FAN_AUTO_CONTROL == 1
        DAC_init();
    #elif USE_FAN_AUTO_CONTROL == 0
        
        OUTPUTXBAR_init();
    #endif

    ECAP_init();
}
//
void MUlt_CLLC_HAL_setupBoardProtection(void)
{
    #if MULT_CLLC_PROTECTION == MULT_CLLC_PROTECTION_DISABLED
        CMPSS_init();// 配置用于cbc保护的比较器
        // 移除初级跳闸事件
        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGA_PWM_BASE,
                                EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGA_PWM_BASE, 
                                EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_PRIM_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);
        // 移除次级跳闸事件
        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGA_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGA_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(MULT_CLLC_SEC_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);
#endif
    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGA_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGB_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGA_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGB_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
                           // 清除第一相的OST

    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGC_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_PRIM_LEGD_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGC_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1));
    EPWM_clearTripZoneFlag(MULT_CLLC_SEC_LEGD_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT1)); 
                           // 清除第二相的OST
}

void Mult_CLLC_HAL_setupPWM(uint16_t powerFlowDir)
{
    SYNC_init(); // 初始化同步模块
    EPWM_init(); // 初始化EPWM
}

void MULT_CLLC_HAL_SwitchPowerFlow_PWMLogic(uint16_t powerFlow)
{
    if(powerFlow == MULT_CLLC_POWER_FLOW_SEC_PRIM && 
        MULT_CLLC_powerFlowState.MULT_CLLC_PowerFlowState_Enum == MULT_CLLC_POWER_FLOW_PRIM_SEC){
        // 执行由 高压到低压 切换至 低压到高压 的PWM逻辑
        // 先将标志切换至过渡阶段，避免环路在此时影响PWM
        MULT_CLLC_powerFlowState.MULT_CLLC_PowerFlowState_Enum = powerFlow_intermediateState;

        // 切换pwm的逻辑

        MULT_CLLC_powerFlowState.MULT_CLLC_PowerFlowState_Enum = powerFlow_SecToPrim;
        //PWM逻辑切换完成，标志切换至 低压到高压
    }else if(powerFlow == MULT_CLLC_POWER_FLOW_PRIM_SEC && 
        MULT_CLLC_powerFlowState.MULT_CLLC_PowerFlowState_Enum == MULT_CLLC_POWER_FLOW_SEC_PRIM){
        // 执行由 低压到高压 切换至 高压到低压 的PWM逻辑
        // 先将标志切换至过渡阶段，避免环路在此时影响PWM
        MULT_CLLC_powerFlowState.MULT_CLLC_PowerFlowState_Enum = powerFlow_intermediateState;

        // 切换pwm的逻辑

        MULT_CLLC_powerFlowState.MULT_CLLC_PowerFlowState_Enum = powerFlow_PrimToSec;
        // PWM逻辑切换完成，标志切换至 高压到低压
    }
}

void Mult_CLLC_HAL_disablePWMClkCounting(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 关闭EPWM时钟
}

void Mult_CLLC_HAL_enablePWMClkCounting(void)
{
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 开启EPWM时钟
}

void MULT_CLLC_HAL_DEBUG_Transnit(void)
{
    char DEBUG_Buffer[100];

    EMAVG_run(&MULT_CLLC_iPrimMAINSensedAvg_pu, MULT_CLLC_iPrimMAINSensed_pu);
    EMAVG_run(&MULT_CLLC_iSecMAINSensedAvg_pu, MULT_CLLC_iSecMAINSensed_pu);

    EMAVG_run(&MULT_CLLC_iPrimSECONDARYSensedAvg_pu, MULT_CLLC_iPrimSECONDARYSensed_pu);
    EMAVG_run(&MULT_CLLC_iSecSECONDARYSensedAvg_pu, MULT_CLLC_iSecSECONDARYSensed_pu);

    EMAVG_run(&MULT_CLLC_vPrimSensedAvg_pu, MULT_CLLC_vPrimSensed_pu);
    EMAVG_run(&MULT_CLLC_vSecSensedAvg_pu, MULT_CLLC_vSecSensed_pu);

    float32_t Vprim = (MULT_CLLC_vPrimSensedAvg_pu.out * MULT_CLLC_VPRIM_MAX_SENSE_VOLTS);
    float32_t Vsec = (MULT_CLLC_vSecSensedAvg_pu.out * MULT_CLLC_VSEC_MAX_SENSE_VOLTS);
    float32_t Iprim1 = (MULT_CLLC_iPrimMAINSensedAvg_pu.out * MULT_CLLC_IPRIM_MAX_BRANCH_SENSE_AMPS * 100.0f);
    float32_t Isec1 = (MULT_CLLC_iSecMAINSensedAvg_pu.out * MULT_CLLC_ISEC_MAX_BRACH_SENSE_AMPS * 100.0f);
    DEBUG2_TRACE_IN;
    formatData(Vprim, Vsec, Iprim1, Isec1, DEBUG_Buffer);

    DEBUG2_TRACE_OUT;

    DEBUG2_TRACE_IN;

    UARTprintf(DEBUG_Buffer);
    DEBUG2_TRACE_OUT;
}

