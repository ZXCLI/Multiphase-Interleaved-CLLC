#ifndef MULT_CLLC_HAL_H
#define MULT_CLLC_HAL_H

#include "device.h"
#include "driverlib.h"
#include "board.h"
#include "Mult_CLLC_settings.h"
#include "Mult_CLLC_user_settings.h"
#include "Mult_CLLC.h"
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

void MULT_CLLC_HAL_DEBUG_Transnit(void);

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
    //Interrupt_enable(INT_PRIM_ZCD1_XINT);

    Interrupt_enable(INT_myCPUTIMER0);//环路中断
    
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

static inline uint16_t MULT_CLLC_HAL_getPrimTBPRD(void)
{
    return (HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBPRD));
}

static inline uint16_t MULT_CLLC_HAL_getSecTBPRD(void)
{
    return (HWREGH(MULT_CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBPRD));
}

// 将整数转换为字符串并返回长度
static int intToStr(int num, char *str)
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

    // 如果是负数，添加负号
    if (isNegative){
        str[i++] = '-';
    }

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

// 将浮点数乘以1000并格式化为字符串
static void formatData(float Vprim, float Vsec, float Iprim1, float Isec1, char *DEBUG_Buffer)
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

static void UARTprintf(const char *pcString)
{
    while (*pcString != '\0')
    {
        SCI_writeCharBlockingFIFO(DEBUG_BASE, *pcString++);
    }
}


#endif // MULT_CLLC_HAL_H
