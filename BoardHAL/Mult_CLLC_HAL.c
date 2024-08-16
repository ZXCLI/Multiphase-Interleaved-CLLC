#include "Mult_CLLC_HAL.h"







void Mult_CLLC_HAL_setupDevice(void)
{
    
}
void Mult_CLLC_HAL_setupLED(void)
{
    
}
void Mult_CLLC_HAL_disablePWMClkCounting(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 关闭EPWM时钟
}

void Mult_CLLC_HAL_enablePWMClkCounting(void)
{
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC); // 开启EPWM时钟
}
