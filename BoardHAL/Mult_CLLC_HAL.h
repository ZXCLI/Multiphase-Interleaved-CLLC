#ifndef MULT_CLLC_HAL_H
#define MULT_CLLC_HAL_H

#include "device.h"
#include "driverlib.h"
#include "board.h"
#include "Mult_CLLC_settings.h"
#include "Mult_CLLC_user_settings.h"
#include "State_machine.h"


void Mult_CLLC_HAL_setupDevice(void);
void Mult_CLLC_HAL_setPins(void);
void Mult_CLLC_HAL_setupLED(void);
void Mult_CLLC_HAL_setupADC(void);
void MUlt_CLLC_HAL_setupBoardProtection(void);
void Mult_CLLC_HAL_setupPWM(uint16_t powerFlowDir);
void Mult_CLLC_HAL_setupFAN(void);
void Mult_CLLC_HAL_setupCPI(void);
void Mult_CLLC_HAL_disablePWMClkCounting(void);
void Mult_CLLC_HAL_enablePWMClkCounting(void);

void MULT_CLLC_HAL_ClaADCOffset(void);
void MULT_CLLC_HAL_SwitchPowerFlow_PWMLogic(uint16_t powerFlow);

static inline void MULT_CLLC_HAL_setupInterrupt(uint16_t powerFlow)
{
    XINT_init();
	INTERRUPT_init();

    #if MULT_CLLC_CONTROL_MODE == MULT_CLLC_TIME_SHIF_CTRL
        if(MULT_CLLC_POWER_FLOW == MULT_CLLC_POWER_FLOW_PRIM_SEC)
            {Interrupt_enable(INT_PRIM_ZCD1_XINT);} // 只有时移控制需要开启中断
        else if(MULT_CLLC_POWER_FLOW == MULT_CLLC_POWER_FLOW_SEC_PRIM)
            {Interrupt_enable(INT_SEC_ZCD1_XINT); } // 只有时移控制需要开启中断
    #endif

    EALLOW;
    //
    // Enable Global interrupt INTM
    //
    EINT;
    //
    // Enable Global real-time interrupt DBGM
    //
    ERTM;
    EDIS;
}
#endif // MULT_CLLC_HAL_H
