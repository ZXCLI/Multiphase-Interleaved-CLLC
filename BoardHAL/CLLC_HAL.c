#include "CLLC_HAL.h"


void CLLC_HAL_setupDevice(void)
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
    CPUTimer_setPeriod(CLLC_TASKA_CPUTIMER_BASE,
                       DEVICE_SYSCLK_FREQ / CLLC_TASKA_FREQ_HZ);
    //
    // TASK B FREQUENCY
    //
    CPUTimer_setPeriod(CLLC_TASKB_CPUTIMER_BASE,
                       DEVICE_SYSCLK_FREQ / CLLC_TASKB_FREQ_HZ);
    //
    // TASK C FREQUENCY
    //
    CPUTimer_setPeriod(CLLC_TASKC_CPUTIMER_BASE,
                       DEVICE_SYSCLK_FREQ / CLLC_TASKC_FREQ_HZ);

    CPUTimer_startTimer(CLLC_TASKA_CPUTIMER_BASE);
    CPUTimer_startTimer(CLLC_TASKB_CPUTIMER_BASE);
    CPUTimer_startTimer(CLLC_TASKC_CPUTIMER_BASE);
}

void CLLC_HAL_setPins(void)
{
    PinMux_init();
    INPUTXBAR_init();
    GPIO_init();
}

void CLLC_HAL_setupCPI(void)
{
    PMBUS_init();
    SCI_init();
}

void CLLC_HAL_setupLED(void)
{
    
}


void CLLC_HAL_setupADC(void)
{
    ASYSCTL_init();// 配置内部参考电压
    ADC_init();// 初始化ADC
    DEVICE_DELAY_US(1000000);// 延时1s，保证偏置电压稳定
    CLLC_HAL_ClaADCOffset();// 校准ADC偏移量
    MULT_CLLL_checkPowerFlow();
}

void CLLC_HAL_ClaADCOffset(void)
{
    typedef struct 
    {
        uint32_t ADC_SOC;
        ADC_SOCNumber ADC_SOC_NUMBER;
        uint32_t ADC_RESULTREGBASE;
    }ADC_SOC_STRUCT;

    ADC_SOC_STRUCT ADC_SOC_TABLE[8] = {
        {CLLC_IPRIM_TANK_MAIN_ADC_MODULE,
         CLLC_IPRIM_TANK_MAIN_ADC_SOC_NO,
         CLLC_IPRIM_TANK_MAIN_ADCRESULTREGBASE},//A2
        {CLLC_ISEC_MAIN_ADC_MODULE,
         CLLC_ISEC_MAIN_ADC_SOC_NO,
         CLLC_ISEC_MAIN_ADCRESULTREGBASE},//A3
        {CLLC_IPRIM_MAIN_ADC_MODULE,
         CLLC_IPRIM_MAIN_ADC_SOC_NO,
         CLLC_IPRIM_MAIN_ADCRESULTREGBASE},//A4
        {CLLC_IPRIM_TANK_SECONDARY_ADC_MODULE,
         CLLC_IPRIM_TANK_SECONDARY_ADC_SOC_NO,
         CLLC_IPRIM_TANK_SECONDARY_ADCRESULTREGBASE},//B1
        {CLLC_ISEC_TANK_MAIN_ADC_MODULE,
         CLLC_ISEC_TANK_MAIN_ADC_SOC_NO,
         CLLC_ISEC_TANK_MAIN_ADCRESULTREGBASE},//B2
        {CLLC_IPRIM_SECONDARY_ADC_MODULE,
         CLLC_IPRIM_SECONDARY_ADC_SOC_NO,
         CLLC_IPRIM_SECONDARY_ADCRESULTREGBASE},//B3
        {CLLC_ISEC_TANK_SECONDARY_ADC_MODULE,
         CLLC_ISEC_TANK_SECONDARY_ADC_SOC_NO,
         CLLC_ISEC_TANK_SECONDARY_ADCRESULTREGBASE},//C1
        {CLLC_ISEC_SECONDARY_ADC_MODULE,
         CLLC_ISEC_SECONDARY_ADC_SOC_NO,
         CLLC_ISEC_SECONDARY_ADCRESULTREGBASE},//C2
    };

    float32_t ADC_offset[8] = {0};

    uint32_t i,j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 800; j++){
            ADC_forceSOC(ADC_SOC_TABLE[i].ADC_SOC, ADC_SOC_TABLE[i].ADC_SOC_NUMBER);
            DEVICE_DELAY_US(10);
            ADC_offset[i] += (ADC_readResult(ADC_SOC_TABLE[i].ADC_RESULTREGBASE,
                                             ADC_SOC_TABLE[i].ADC_SOC_NUMBER));
        }
    }

    CLLC_iPrimMAINTankSensedOffset_pu      = (ADC_offset[0] / (800.0f * 4096.0f));
    CLLC_iSecMAINSensedOffset_pu           = (ADC_offset[1] / (800.0f * 4096.0f));
    CLLC_iPrimMAINSensedOffset_pu          = (ADC_offset[2] / (800.0f * 4096.0f));
    CLLC_iPrimSECONDARYTankSensedOffset_pu = (ADC_offset[3] / (800.0f * 4096.0f));
    CLLC_iSecMAINTankSensedOffset_pu       = (ADC_offset[4] / (800.0f * 4096.0f));
    CLLC_iPrimSECONDARYSensedOffset_pu     = (ADC_offset[5] / (800.0f * 4096.0f));
    CLLC_iSecSECONDARYTankSensedOffset_pu  = (ADC_offset[6] / (800.0f * 4096.0f));
    CLLC_iSecSECONDARYSensedOffset_pu      = (ADC_offset[7] / (800.0f * 4096.0f));
}

void CLLC_HAL_setupFAN(void)
{
    #if USE_FAN_AUTO_CONTROL == 1
        DAC_init();
    #elif USE_FAN_AUTO_CONTROL == 0
        
    #endif
    OUTPUTXBAR_init();
    ECAP_init();
}
//
void CLLC_HAL_setupBoardProtection(void)
{
    #if CLLC_PROTECTION == CLLC_PROTECTION_DISABLED
        // 移除初级跳闸事件
        EPWM_setTripZoneAction(CLLC_PRIM_LEGA_PWM_BASE,
                                EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_PRIM_LEGA_PWM_BASE, 
                                EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(CLLC_PRIM_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_PRIM_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(CLLC_PRIM_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_PRIM_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(CLLC_PRIM_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_PRIM_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);
        // 移除次级跳闸事件
        EPWM_setTripZoneAction(CLLC_SEC_LEGA_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_SEC_LEGA_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(CLLC_SEC_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_SEC_LEGB_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(CLLC_SEC_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_SEC_LEGC_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

        EPWM_setTripZoneAction(CLLC_SEC_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_DISABLE);
        EPWM_setTripZoneAction(CLLC_SEC_LEGD_PWM_BASE,
                               EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_DISABLE);

    #elif CLLC_PROTECTION == CLLC_PROTECTION_ENABLED
        CMPSS_init(); // 初始化比较器
        CLLC_HAL_setupCMPSSDacValue(CMPSS1_BASE,
                                         CLLC_iPrimMAINTankSensedOffset_pu , 1800);
        XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS1_CTRIPH);
        XBAR_clearInputFlag(XBAR_INPUT_FLG_CMPSS1_CTRIPL);
        CMPSS_clearFilterLatchHigh(CMPSS1_BASE);
        CMPSS_clearFilterLatchLow(CMPSS1_BASE);
    #endif

    EPWM_clearTripZoneFlag(CLLC_PRIM_LEGA_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2));
    EPWM_clearTripZoneFlag(CLLC_PRIM_LEGB_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2));
    EPWM_clearTripZoneFlag(CLLC_SEC_LEGA_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2));
    EPWM_clearTripZoneFlag(CLLC_SEC_LEGB_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2));
                           // 清除第一相的OST

    EPWM_clearTripZoneFlag(CLLC_PRIM_LEGC_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2));
    EPWM_clearTripZoneFlag(CLLC_PRIM_LEGD_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2));
    EPWM_clearTripZoneFlag(CLLC_SEC_LEGC_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2));
    EPWM_clearTripZoneFlag(CLLC_SEC_LEGD_PWM_BASE,
                           (EPWM_TZ_INTERRUPT_OST | EPWM_TZ_INTERRUPT_DCAEVT2)); 
                           // 清除第二相的OST
}

void CLLC_HAL_setupPWM(uint16_t powerFlowDir)
{
    SYNC_init(); // 初始化同步模块
    EPWM_init(); // 初始化EPWM
    EPWMXBAR_init(); // 初始化XBAR
}

void CLLC_HAL_SwitchPowerFlow_PWMLogic(uint16_t powerFlow)
{
    if((powerFlow == CLLC_POWER_FLOW_SEC_PRIM) && 
       (CLLC_powerFlowState.CLLC_PowerFlowState_Enum == powerFlow_PrimToSec))
    {
        // 执行由 高压到低压 切换至 低压到高压 的PWM逻辑
        // 先将标志切换至过渡阶段，避免环路在此时影响PWM
        CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_intermediateState;

        // 切换pwm的逻辑

        CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_SecToPrim;
        //PWM逻辑切换完成，标志切换至 低压到高压
    }else if((powerFlow == CLLC_POWER_FLOW_PRIM_SEC) && 
             (CLLC_powerFlowState.CLLC_PowerFlowState_Enum == powerFlow_SecToPrim))
    {
        // 执行由 低压到高压 切换至 高压到低压 的PWM逻辑
        // 先将标志切换至过渡阶段，避免环路在此时影响PWM
        CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_intermediateState;

        // 切换pwm的逻辑

        CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_PrimToSec;
        // PWM逻辑切换完成，标志切换至 高压到低压
    }
}

// 使用ECAP在运行时移算法时获取初级主相EPWM的周期值和死区时间
static inline void 
CLLC_HAL_getPrimMAINEPWMpreiodANDdeadTime(MAINEPWM_StructType *MAINEPWM)
{
    uint32_t rising_edge_1, rising_edge_2;//, falling_edge_1, falling_edge_2;

    rising_edge_1 =
        ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_1); // 上升沿1
    // falling_edge_1 =
    //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_2); // 下降沿1
    rising_edge_2 =
        ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_3); // 上升沿2
    // falling_edge_2 =
    //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_4); // 下降沿2

    MAINEPWM->PWM_preiod_ticks = rising_edge_2 - rising_edge_1; // 周期
    MAINEPWM->PWM_deadBand_ticks = CLLC_HAL_getPrimMAINdeadBand(); // 死区时间
}

// 使用ECAP在运行时移算法时获取次级主相EPWM的周期值和死区时间
static inline void 
CLLC_HAL_getSecMAINEPWMpreiodANDdeadTime(MAINEPWM_StructType *MAINEPWM) 
{
  uint32_t rising_edge_1, rising_edge_2; //, falling_edge_1, falling_edge_2;

  rising_edge_1 = ECAP_getEventTimeStamp(ECAP7_BASE, ECAP_EVENT_1); // 上升沿1
  // falling_edge_1 =
  //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_2); // 下降沿1
  rising_edge_2 = ECAP_getEventTimeStamp(ECAP7_BASE, ECAP_EVENT_3); // 上升沿2
  // falling_edge_2 =
  //     ECAP_getEventTimeStamp(ECAP6_BASE, ECAP_EVENT_4); // 下降沿2

  MAINEPWM->PWM_preiod_ticks = rising_edge_2 - rising_edge_1; // 周期
  MAINEPWM->PWM_deadBand_ticks = CLLC_HAL_getPrimMAINdeadBand(); // 死区时间
}

void CLLC_HAL_disablePWMClkCounting(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 关闭EPWM时钟
}

void CLLC_HAL_enablePWMClkCounting(void)
{
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 开启EPWM时钟
}


