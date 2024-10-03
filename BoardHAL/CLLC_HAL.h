#ifndef CLLC_HAL_H
#define CLLC_HAL_H

#include "device.h"
#include "driverlib.h"
#include "board.h"
#include "CLLC_settings.h"
#include "CLLC_user_settings.h"
#include "CLLC.h"
#include "State_machine.h"
#include "stdio.h"

void CLLC_HAL_setupDevice(void);
void CLLC_HAL_setPins(void);
void CLLC_HAL_setupLED(void);
void CLLC_HAL_setupADC(void);
void CLLC_HAL_setupBoardProtection(void);
void CLLC_HAL_setupPWM(uint16_t powerFlowDir);
void CLLC_HAL_setupFAN(void);
void CLLC_HAL_setupCPI(void);
void CLLC_HAL_disablePWMClkCounting(void);
void CLLC_HAL_enablePWMClkCounting(void);

void CLLC_HAL_ClaADCOffset(void);
void CLLC_HAL_SwitchPowerFlow_PWMLogic(uint16_t powerFlow);
void CLLC_runEMAVG(void);
void CLLC_HAL_HysteresisLoop(float32_t highThreshold, float32_t lowThreshold,
                             float32_t INPUT,uint16_t* nowState,uint16_t* lastState,
                             void (*function)());


static inline void CLLC_HAL_setupInterrupt(uint16_t powerFlow)
{
    XINT_init();
	INTERRUPT_init();
    Interrupt_enable(INT_myCPUTIMER0);//环路中断
    
    EALLOW;
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global real-time interrupt DBGM
    EDIS;
}

static inline void CLLC_enablePRIM_TD_INT(void)
{
    Interrupt_enable(INT_PRIM_ZCD1_XINT);
}

// 获取PWM当前的计数器值
static inline uint16_t CLLC_HAL_getTBCTR(uint16_t EPWM_BASE)
{
    return (HWREGH(EPWM_BASE + EPWM_O_TBCTR));
}

// 获取PWM的周期值
static inline uint16_t CLLC_HAL_getTBPRD(uint16_t EPWM_BASE)
{
    return (HWREGH(EPWM_BASE + EPWM_O_TBPRD));
}

// 获取PWM的死区时间
static inline uint16_t CLLC_HAL_getDeadBand(uint16_t EPWM_BASE)
{
    return (HWREGH(EPWM_BASE + EPWM_O_DBFED));
    //只获取下降沿的死区时间，因为设置的死区时间都是相同的
}

// 设置PWM的死区时间，上升沿和下降沿死区的值相同
static inline void CLLC_HAL_setDeadBand(uint16_t EPWM_BASE, 
                                        uint16_t deadBand)
{
    HWREGH(EPWM_BASE + EPWM_O_DBFED) = deadBand;
    HWREGH(EPWM_BASE + EPWM_O_DBRED) = deadBand;
}

static inline void CLLC_HAL_setTBPRDandCMPA(uint16_t EPWM_BASE,uint16_t TBPRD)
{
    HWREGH(EPWM_BASE + EPWM_O_TBPRD) = TBPRD;
    EPWM_setCounterCompareValue(EPWM_BASE, EPWM_COUNTER_COMPARE_A, (TBPRD >> 1));
}

static inline void CLLC_HAL_disableCPMSSXBAR(void)
{
    XBAR_disableEPWMMux(CMPSS2OUT, XBAR_MUX02);
    XBAR_disableEPWMMux(CMPSS3OUT, XBAR_MUX04);
    XBAR_disableEPWMMux(CMPSS7OUT, XBAR_MUX12);
    XBAR_disableEPWMMux(CMPSS1OUT, XBAR_MUX00);
}

static inline void CLLC_HAL_enableCPMSSXBAR(void)
{
    XBAR_enableEPWMMux(CMPSS2OUT, XBAR_MUX02);
    XBAR_enableEPWMMux(CMPSS3OUT, XBAR_MUX04);
    XBAR_enableEPWMMux(CMPSS7OUT, XBAR_MUX12);
    XBAR_enableEPWMMux(CMPSS1OUT, XBAR_MUX00);
}

static inline void CLLC_HAL_disableCLBXBAR(void)
{
    XBAR_disableEPWMMux(CLB1L, XBAR_MUX03);
    XBAR_disableEPWMMux(CLB1H, XBAR_MUX01);
    XBAR_disableEPWMMux(CLB2L, XBAR_MUX07);
    XBAR_disableEPWMMux(CLB2H, XBAR_MUX05);
}

static inline void CLLC_HAL_enableCLBXBAR(void)
{
    XBAR_enableEPWMMux(CLB1L, XBAR_MUX03);
    XBAR_enableEPWMMux(CLB1H, XBAR_MUX01);
    XBAR_enableEPWMMux(CLB2L, XBAR_MUX07);
    XBAR_enableEPWMMux(CLB2H, XBAR_MUX05);
}

static inline void CLLC_HAL_disblePRIMmainEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGA_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGB_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
}

static inline void CLLC_HAL_enablePRIMmainEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGA_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGB_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
}

static inline void CLLC_HAL_disableSECmainEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGA_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGB_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
}

static inline void CLLC_HAL_enableSECmainEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGA_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGB_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
}

static inline void CLLC_HAL_disablePRIMsecondaryEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_PRIM_LEGC_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_PRIM_LEGD_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
}

static inline void CLLC_HAL_enablePRIMsecondaryEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_PRIM_LEGC_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_PRIM_LEGD_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
}

static inline void CLLC_HAL_disableSECsecondaryEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGC_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGD_PWM_BASE, CLLC_EPWM_DISABLE_DEADBAND_TICKS);
}

static inline void CLLC_HAL_enableSECsecondaryEPWM(void)
{
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGC_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
    CLLC_HAL_setDeadBand(CLLC_SEC_LEGD_PWM_BASE, CLLC_EPWM_NOMAL_DEADBAND_TICKS);
}

// 设置谐振腔CBC保护的阈值
static inline void CLLC_HAL_setupCMPSSDacValue(uint32_t CMPSS_BASE,
                                    float32_t offset_pu,
                                    uint16_t Limit)
{
    EALLOW;
    CMPSS_setDACValueHigh(CMPSS_BASE,
                        (4096 * offset_pu) + Limit);
    CMPSS_setDACValueLow(CMPSS_BASE,
                        (4096 * offset_pu) - Limit);
    EDIS;
}

static void CLLC_HAL_ManuallyTriggeredAllADC(void)
{
    typedef struct 
    {
        uint32_t ADC_SOC;
        ADC_SOCNumber ADC_SOC_NUMBER;
        uint32_t ADC_RESULTREGBASE;
    }ADC_SOC_STRUCT;

    ADC_SOC_STRUCT ADC_SOC_TABLE[10] = {
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

        {CLLC_VPRIM_ADC_MODULE,
        CLLC_VPRIM_ADC_SOC_NO,
        CLLC_VPRIM_ADCRESULTREGBASE},//B0
        
        {CLLC_VSEC_ADC_MODULE,
        CLLC_VSEC_ADC_SOC_NO,
        CLLC_VSEC_ADCRESULTREGBASE},//C0
    };

    for(uint16_t i = 0; i < 10; i++){
        ADC_forceSOC(ADC_SOC_TABLE[i].ADC_SOC, ADC_SOC_TABLE[i].ADC_SOC_NUMBER);
        DEVICE_DELAY_US(10);
    }
}

static inline void CLLC_HAL_clearAllTripZoneFlag(void)
{
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

static inline void CLLC_HAL_enableAllTripZoneSignals(void)
{
    EPWM_enableTripZoneSignals(CLLC_PRIM_LEGA_PWM_BASE,
                               EPWM_TZ_SIGNAL_OSHT1);
    EPWM_enableTripZoneSignals(CLLC_PRIM_LEGB_PWM_BASE,
                               EPWM_TZ_SIGNAL_OSHT1);
    EPWM_enableTripZoneSignals(CLLC_SEC_LEGA_PWM_BASE,
                               EPWM_TZ_SIGNAL_OSHT1);
    EPWM_enableTripZoneSignals(CLLC_SEC_LEGB_PWM_BASE,
                               EPWM_TZ_SIGNAL_OSHT1);
}

static inline void CLLC_HAL_disableAllTripZoneSignals(void)
{
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

}
// 强制触发PWM的OneShotTrip事件
static inline void CLLC_HAL_forcePWMOneShotTrip(uint32_t EPWM_BASE)
{
    EPWM_forceTripZoneEvent(EPWM_BASE, EPWM_TZ_FORCE_EVENT_OST);
}

#endif // CLLC_HAL_H
