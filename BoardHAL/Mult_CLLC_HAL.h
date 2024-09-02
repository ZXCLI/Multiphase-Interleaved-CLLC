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
void Mult_CLLC_HAL_disablePWMClkCounting(void);
void Mult_CLLC_HAL_enablePWMClkCounting(void);

static inline void MULT_CLLC_HAL_setupInterrupt(uint16_t powerFlow)
{
    XINT_init();
	INTERRUPT_init();

    #if MULT_CLLC_INCR_BUILD == MULT_CLLC_CLOSED_LOOP_BUILD
        Interrupt_disable(INT_PRIM_ZCD1_XINT); // 关闭zcd中断，以直接控制频率模式运行
    #endif
}
#endif // MULT_CLLC_HAL_H
