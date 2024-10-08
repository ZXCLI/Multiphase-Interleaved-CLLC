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
    EALLOW;
    PinMux_init();
    INPUTXBAR_init();
    GPIO_init();
    EDIS;
}

void CLLC_HAL_setupCPI(void)
{
    PMBUS_init();
    SCI_init();
}

void CLLC_HAL_setupLED(void)
{
    EALLOW;
    GPIO_writePin(STATUS1,1);
    GPIO_writePin(STATUS2,1);
    GPIO_writePin(FAULT_OUTPUT,0);
    GPIO_writePin(DEBUG2,0);
    EDIS;
}


void CLLC_HAL_setupADC(void)
{
    ASYSCTL_init();// 配置内部参考电压
    ADC_init();// 初始化ADC
    DEVICE_DELAY_US(1000000);// 延时1s，保证偏置电压稳定
    CLLC_HAL_ClaADCOffset();// 校准ADC偏移量
    CLLL_checkPowerFlow();
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
        for(j = 0; j < 80; j++){
            ADC_forceSOC(ADC_SOC_TABLE[i].ADC_SOC, ADC_SOC_TABLE[i].ADC_SOC_NUMBER);
            DEVICE_DELAY_US(10);
            ADC_offset[i] += (ADC_readResult(ADC_SOC_TABLE[i].ADC_RESULTREGBASE,
                                             ADC_SOC_TABLE[i].ADC_SOC_NUMBER));
        }
    }

    CLLC_iPrimMAINTankSensedOffset_pu      = (ADC_offset[0] / (80.0f * 4096.0f));
    CLLC_iSecMAINSensedOffset_pu           = (ADC_offset[1] / (80.0f * 4096.0f));
    CLLC_iPrimMAINSensedOffset_pu          = (ADC_offset[2] / (80.0f * 4096.0f));
    CLLC_iPrimSECONDARYTankSensedOffset_pu = (ADC_offset[3] / (80.0f * 4096.0f));
    CLLC_iSecMAINTankSensedOffset_pu       = (ADC_offset[4] / (80.0f * 4096.0f));
    CLLC_iPrimSECONDARYSensedOffset_pu     = (ADC_offset[5] / (80.0f * 4096.0f));
    CLLC_iSecSECONDARYTankSensedOffset_pu  = (ADC_offset[6] / (80.0f * 4096.0f));
    CLLC_iSecSECONDARYSensedOffset_pu      = (ADC_offset[7] / (80.0f * 4096.0f));
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

// 设置板卡保护
void CLLC_HAL_setupBoardProtection(void)
{
    #if CLLC_PROTECTION == CLLC_PROTECTION_DISABLED
        CLLC_HAL_disableAllTripZoneSignals();
    #elif CLLC_PROTECTION == CLLC_PROTECTION_ENABLED
        CMPSS_init(); // 初始化比较器，但是这个时候并没有启用比较器模块
        CLLC_HAL_disableCPMSSXBAR();// 关闭比较器输出到EPWMXBAR的信号
        CLLC_HAL_setupCMPSSDacValue(CMPSS1_BASE,
                                    CLLC_iPrimMAINTankSensedOffset_pu , 2000);
    #endif
        CLLC_HAL_clearAllTripZoneFlag();
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
    MAINEPWM->PWM_deadBand_ticks = CLLC_HAL_getDeadBand(CLLC_PRIM_LEGB_PWM_BASE); 
    // 死区时间
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
    MAINEPWM->PWM_deadBand_ticks = CLLC_HAL_getDeadBand(CLLC_SEC_LEGB_PWM_BASE);
    // 死区时间
}

void CLLC_HAL_HysteresisLoop(float32_t highThreshold, float32_t lowThreshold,
                             float32_t INPUT,uint16_t* nowState,uint16_t* lastState,
                             void (*function)())
{
    if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == powerFlow_PrimToSec){
        if(INPUT > highThreshold){
            (*nowState) = 1;
        }else if(INPUT < lowThreshold){
            (*nowState) = 0;
        }
    }else if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == powerFlow_SecToPrim){
        if(INPUT > highThreshold){
            (*nowState) = 1;
        }else if(INPUT < lowThreshold){
            (*nowState) = 0;
        }
    }

    if((*nowState) != (*lastState)){
        function();
    }

    (*lastState) = (*nowState);
}

void CLLC_HAL_disablePWMClkCounting(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 关闭EPWM时钟
}

void CLLC_HAL_enablePWMClkCounting(void)
{
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 开启EPWM时钟
}

void CLLC_runEMAVG(void)
{
    EMAVG_run(&CLLC_iPrimMAINSensedAvg_pu, CLLC_iPrimMAINSensed_pu);
    EMAVG_run(&CLLC_iSecMAINSensedAvg_pu, CLLC_iSecMAINSensed_pu);

    EMAVG_run(&CLLC_iPrimSECONDARYSensedAvg_pu, CLLC_iPrimSECONDARYSensed_pu);
    EMAVG_run(&CLLC_iSecSECONDARYSensedAvg_pu, CLLC_iSecSECONDARYSensed_pu);

    EMAVG_run(&CLLC_vPrimSensedAvg_pu, CLLC_vPrimSensed_pu);
    EMAVG_run(&CLLC_vSecSensedAvg_pu, CLLC_vSecSensed_pu);
}
