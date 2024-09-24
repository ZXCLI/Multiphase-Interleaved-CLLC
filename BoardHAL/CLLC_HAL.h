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

// 设置谐振腔CBC保护的阈值
static inline void CLLC_HAL_setupCMPSSDacValue(uint32_t CMPSS_BASE,
                                    float32_t offset_pu,
                                    uint16_t Limit)
{
    CMPSS_setDACValueHigh(CMPSS_BASE,
                        (4096 * offset_pu) + Limit);
    CMPSS_setDACValueLow(CMPSS_BASE,
                        (4096 * offset_pu) - Limit);
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

// 强制触发PWM的OneShotTrip事件
static inline void CLLC_HAL_forcePWMOneShotTrip(uint32_t EPWM_BASE)
{
    EPWM_forceTripZoneEvent(EPWM_BASE, EPWM_TZ_FORCE_EVENT_OST);
}



#endif // CLLC_HAL_H
