#ifndef MULT_CLLC_HAL_H
#define MULT_CLLC_HAL_H


#include "device.h"
#include "driverlib.h"
#include "board.h"
#include "Mult_CLLC_settings.h"
#include "State_machine.h"



void Mult_CLLC_HAL_setupDevice(void);
void Mult_CLLC_HAL_setupLED(void);

void Mult_CLLC_HAL_disablePWMClkCounting(void);
void Mult_CLLC_HAL_enablePWMClkCounting(void);



#endif // MULT_CLLC_HAL_H
