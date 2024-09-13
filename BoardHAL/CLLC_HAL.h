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

void CLLC_HAL_DEBUG_Transnit(void);

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

// 将整数转换为字符串并返回长度
static inline int intToStr(int num, char *str)
{
    int i = 0;
    int isNegative = 0;
    // 处理负数
    if (num < 0){
        isNegative = 1;
        num = -num;
    }
    // 将数字转换为字符串，逆序存储
    do{
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative){str[i++] = '-';}
    // 反转字符串
    int start = 0;
    int end = i - 1;
    while (start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    // 返回生成的字符串长度
    str[i] = '\0';
    return i;
}

// 将浮点数格式化为字符串
static inline void formatData(float Vprim, float Vsec, float Iprim1, float Isec1, char *DEBUG_Buffer)
{
    int32_t Vprim_int = (int)(Vprim);
    int32_t Vsec_int = (int)(Vsec);
    int32_t Iprim1_int = (int)(Iprim1);
    int32_t Isec1_int = (int)(Isec1);

    // 临时缓冲区用于存储每个整数的字符串表示
    //char temp[12]; // 足够存储整数和符号
    int len = 0;
    // 将 Vprim_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Vprim_int, DEBUG_Buffer + len);
    // 添加逗号
    DEBUG_Buffer[len++] = ',';
    // 将 Vsec_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Vsec_int, DEBUG_Buffer + len);
    // 添加逗号
    DEBUG_Buffer[len++] = ',';
    // 将 Iprim1_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Iprim1_int, DEBUG_Buffer + len);
    // 添加逗号
    DEBUG_Buffer[len++] = ',';
    // 将 Isec1_int 转换为字符串并复制到 DEBUG_Buffer
    len += intToStr(Isec1_int, DEBUG_Buffer + len);
    // 添加换行符
    DEBUG_Buffer[len++] = '\n';
    // 添加字符串结束符
    DEBUG_Buffer[len] = '\0';
}

static inline void UARTprintf(const char *pcString)
{
    while (*pcString != '\0')
    {
        SCI_writeCharBlockingFIFO(DEBUG_BASE, *pcString++);
    }
}


#endif // CLLC_HAL_H
