#include "Mult_CLLC.h"

volatile MULT_CLLC_SystemState_EnumType MULT_CLLC_systemState;//系统状态

volatile MULT_CLLC_TripFlag_StructType MULT_CLLC_tripFlag;//系统跳闸状态

volatile MULT_CLLC_PowerFlowState_EnumType MULT_CLLC_powerFlowStateActive, 
                                        MULT_CLLC_powerFlowState;//系统功率流向

MULT_CLLC_CommandSentTo_AC_DC_EnumType MULT_CLLC_commandSentTo_AC_DC;
                                                    //发送给前级ACDC的指令

MULT_CLLC_CommandSentFrom_DC_DC_EnumType MULT_CLLC_commandSentFrom_DC_DC;
                                                    //从后级DCDC接收到的指令

//时移算法中断所需变量
volatile uint16_t CLLC_PRIM_COMPA = 560;
volatile uint16_t CLLC_SEC_COMPA = 560;


//高压侧
float32_t MULT_CLLC_iPrimMAINSensed_Amps;// IPRIM1
float32_t MULT_CLLC_iPrimMAINSensed_pu;// IPRIM1
float32_t MULT_CLLC_iPrimMAINSensedOffset_pu;
float32_t MULT_CLLC_iPrimMAINSensedCalIntercept_pu;
float32_t MULT_CLLC_iPrimMAINSensedCalXvariable_pu;
EMAVG MULT_CLLC_iPrimMAINSensedAvg_pu;

float32_t MULT_CLLC_iPrimSECONDARYSensed_Amps;// IPRIM2
float32_t MULT_CLLC_iPrimSECONDARYSensed_pu;// IPRIM2
float32_t MULT_CLLC_iPrimSECONDARYSensedOffset_pu;
float32_t MULT_CLLC_iPrimSECONDARYSensedCalIntercept_pu;
float32_t MULT_CLLC_iPrimSECONDARYSensedCalXvariable_pu;
EMAVG MULT_CLLC_iPrimSECONDARYSensedAvg_pu;

float32_t MULT_CLLC_iPrimMAINTankSensed_Amps;
float32_t MULT_CLLC_iPrimMAINTankSensed_pu;
float32_t MULT_CLLC_iPrimMAINTankSensedOffset_pu;
float32_t MULT_CLLC_iPrimMAINTankSensedCalIntercept_pu;
float32_t MULT_CLLC_iPrimMAINTankSensedCalXvariable_pu;
EMAVG MULT_CLLC_iPrimMAINTankSensedAvg_pu;

float32_t MULT_CLLC_vPrimSensed_Volts;
float32_t MULT_CLLC_vPrimSensed_pu;
float32_t MULT_CLLC_vPrimSensedOffset_pu;
EMAVG MULT_CLLC_vPrimSensedAvg_pu;

float32_t MULT_CLLC_vPrimRef_Volts;
float32_t MULT_CLLC_vPrimRef_pu;
float32_t MULT_CLLC_vPrimRefSlewed_pu;

volatile float32_t MULT_CLLC_pwmDutyPrimRef_pu;
float32_t MULT_CLLC_pwmDutyPrim_pu;
uint32_t MULT_CLLC_pwmDutyAPrim_ticks;
uint32_t MULT_CLLC_pwmDutyBPrim_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandREDPrimRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandREDPrim_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandFEDPrimRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandFEDPrim_ticks;

// 低压侧
float32_t MULT_CLLC_iSecMAINSensed_Amps;// ISEC1
float32_t MULT_CLLC_iSecMAINSensed_pu;// ISEC1
float32_t MULT_CLLC_iSecMAINSensedOffset_pu;
float32_t MULT_CLLC_iSecMAINSensedCalIntercept_pu;
float32_t MULT_CLLC_iSecMAINSensedCalXvariable_pu;
EMAVG MULT_CLLC_iSecMAINSensedAvg_pu;

float32_t MULT_CLLC_iSecSECONDARYSensed_Amps;// ISEC2
float32_t MULT_CLLC_iSecSECONDARYSensed_pu;// ISEC2
float32_t MULT_CLLC_iSecSECONDARYSensedOffset_pu;
float32_t MULT_CLLC_iSecSECONDARYSensedCalIntercept_pu;
float32_t MULT_CLLC_iSecSECONDARYSensedCalXvariable_pu;
EMAVG MULT_CLLC_iSecSECONDARYSensedAvg_pu;

float32_t MULT_CLLC_iSecMAINTankSensed_Amps;
float32_t MULT_CLLC_iSecMAINTankSensed_pu;
float32_t MULT_CLLC_iSecMAINTankSensedOffset_pu;
float32_t MULT_CLLC_iSecMAINTankSensedCalIntercept_pu;
float32_t MULT_CLLC_iSecMAINTankSensedCalXvariable_pu;
EMAVG MULT_CLLC_iSecMAINTankSensedAvg_pu;

float32_t MULT_CLLC_vSecSensed_Volts;
float32_t MULT_CLLC_vSecSensed_pu;
float32_t MULT_CLLC_vSecSensedOffset_pu;
EMAVG MULT_CLLC_vSecSensedAvg_pu;

float32_t MULT_CLLC_vSecRef_Volts;
float32_t MULT_CLLC_vSecRef_pu;
float32_t MULT_CLLC_vSecRefSlewed_pu;

volatile float32_t MULT_CLLC_pwmDutySecRef_pu;
float32_t MULT_CLLC_pwmDutySec_pu;
uint32_t MULT_CLLC_pwmDutyASec_ticks;
uint32_t MULT_CLLC_pwmDutyBSec_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandREDSecRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandREDSec_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandFEDSecRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandFEDSec_ticks;

__interrupt void ISR1_PZCD(void)
{
    uint16_t TB_CTR_NOW = HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR);
    // 获取当前计数器值
    uint16_t PZCD1_state = GPIO_readPin(PRIM_ZCD1);

    // 下面的判断可以防止掉入容性区
    if ((PZCD1_state == 0) && (TB_CTR_NOW < CLLC_PRIM_COMPA)){// 上升沿清零计数值
        HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR) = 3;
        HWREGH(MULT_CLLC_PRIM_LEGB_PWM_BASE + EPWM_O_TBCTR) = 3;
    }else if ((PZCD1_state == 1) && (TB_CTR_NOW > CLLC_PRIM_COMPA)){// 下降沿清零计数值
        HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR) = CLLC_PRIM_COMPA + 3;
        HWREGH(MULT_CLLC_PRIM_LEGB_PWM_BASE + EPWM_O_TBCTR) = CLLC_PRIM_COMPA + 3;
    }
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}


__interrupt void ISR1_SZCD(void)
{
    uint16_t TB_CTR_NOW = HWREGH(MULT_CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBCTR);
    // 获取当前计数器值
    uint16_t SZCD1_state = GPIO_readPin(SEC_ZCD1);

    // 下面的判断可以防止掉入容性区
    if ((SZCD1_state == 0) && (TB_CTR_NOW < CLLC_SEC_COMPA)){// 上升沿清零计数值
        HWREGH(MULT_CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBCTR) = 3;
        HWREGH(MULT_CLLC_SEC_LEGB_PWM_BASE + EPWM_O_TBCTR) = 3;
    }else if ((SZCD1_state == 1) && (TB_CTR_NOW > CLLC_SEC_COMPA)){// 下降沿清零计数值
        HWREGH(MULT_CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBCTR) = CLLC_SEC_COMPA + 3;
        HWREGH(MULT_CLLC_SEC_LEGB_PWM_BASE + EPWM_O_TBCTR) = CLLC_SEC_COMPA + 3;
    }
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}


__interrupt void ISR2_TIMER0(void)
{
    CLLC_PRIM_COMPA = (MULT_CLLC_HAL_getPrimTBPRD() >> 1);// 获取当前计数器周期值
    CLLC_SEC_COMPA = (MULT_CLLC_HAL_getSecTBPRD() >> 1); // 获取当前计数器周期值
    MULT_CLLC_readSensedSignals();
    //run_loop();
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1); // timer0要加上清除中断标志
}

static inline void run_loop(void)
{
    //NOP;
}


void MULT_CLLC_initGlobalVariables(void)
{
    MULT_CLLC_iPrimMAINSensed_pu = 0.0f;
    MULT_CLLC_iPrimSECONDARYSensed_pu = 0.0f;
    MULT_CLLC_iPrimMAINSensedOffset_pu = 0.5f;
    MULT_CLLC_iPrimSECONDARYSensedOffset_pu = 0.5f;

    MULT_CLLC_iSecMAINSensed_pu = 0.0f;
    MULT_CLLC_iSecSECONDARYSensed_pu = 0.0f;
    MULT_CLLC_iSecMAINSensedOffset_pu = 0.5f;
    MULT_CLLC_iSecSECONDARYSensedOffset_pu = 0.5f;

    MULT_CLLC_vPrimSensed_pu = 0.0f;
    MULT_CLLC_vPrimSensedOffset_pu = 0.0f;

    MULT_CLLC_vSecSensed_pu = 0.0f;
    MULT_CLLC_vSecSensedOffset_pu = 0.0f;
}
 