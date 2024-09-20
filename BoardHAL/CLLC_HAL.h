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


static inline void CLLC_HAL_setupInterrupt(uint16_t powerFlow)
{
    XINT_init();
	INTERRUPT_init();

    #if CLLC_CONTROL_MODE == CLLC_TIME_SHIF_CTRL
        if(CLLC_POWER_FLOW == CLLC_POWER_FLOW_PRIM_SEC)
            {Interrupt_enable(INT_PRIM_ZCD1_XINT);} // 只有时移控制需要开启中断
        else if(CLLC_POWER_FLOW == CLLC_POWER_FLOW_SEC_PRIM)
            {Interrupt_enable(INT_SEC_ZCD1_XINT); } // 只有时移控制需要开启中断
    #endif
    //Interrupt_enable(INT_PRIM_ZCD1_XINT);

    Interrupt_enable(INT_myCPUTIMER0);//环路中断
    
    EALLOW;
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global real-time interrupt DBGM
    EDIS;
}

// 获取初级PWM的周期值
static inline uint16_t CLLC_HAL_getPrimTBPRD(void)
{
    return (HWREGH(CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBPRD));
}

// 获取次级PWM的周期值
static inline uint16_t CLLC_HAL_getSecTBPRD(void)
{
    return (HWREGH(CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBPRD));
}

// 获取初级PWM的死区时间
static inline uint16_t CLLC_HAL_getPrimMAINdeadBand(void)
{
  return (HWREGH(CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_DBRED));
}

// 获取次级PWM的死区时间
static inline uint16_t CLLC_HAL_getSecMAINdeadBand(void)
{
  return (HWREGH(CLLC_SEC_LEGA_PWM_BASE + EPWM_O_DBRED));
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

// 强制触发PWM的OneShotTrip事件
static inline void CLLC_HAL_forcePWMOneShotTrip(uint32_t EPWM_BASE)
{
    EPWM_forceTripZoneEvent(EPWM_BASE, EPWM_TZ_FORCE_EVENT_OST);
}



#endif // CLLC_HAL_H
