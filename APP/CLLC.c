#include "CLLC.h"



volatile CLLC_SystemState_EnumType CLLC_systemState;//系统状态

volatile CLLC_TripFlag_StructType CLLC_tripFlag;//系统跳闸状态

volatile CLLC_PowerFlowState_EnumType CLLC_powerFlowStateActive, 
                                        CLLC_powerFlowState;//系统功率流向

CLLC_CommandSentTo_AC_DC_EnumType CLLC_commandSentTo_AC_DC;
                                                    //发送给前级ACDC的指令

CLLC_CommandSentFrom_DC_DC_EnumType CLLC_commandSentFrom_DC_DC;
                                                    //从后级DCDC接收到的指令

MAINEPWM_StructType CLLC_PRIMPWM,CLLC_SECPWM;



//时移算法中断所需变量
volatile uint16_t CLLC_PRIM_COMPA = 560;
volatile uint16_t CLLC_SEC_COMPA = 560;

CLLC_GV CLLC_gvPrim2Sec;
CLLC_GV CLLC_gvSec2Prim;

// 高压侧
//SI unit
float32_t CLLC_iPrimMAINSensed_Amps; // IPRIM1
float32_t CLLC_iPrimSECONDARYSensed_Amps; // IPRIM2
float32_t CLLC_vPrimSensed_Volts;
float32_t CLLC_vPrimRef_Volts;
//PU unit
float32_t CLLC_iPrimMAINSensed_pu;   // IPRIM1
float32_t CLLC_iPrimSECONDARYSensed_pu;// IPRIM2
float32_t CLLC_vPrimSensed_pu;
float32_t CLLC_vPrimRef_pu;
float32_t CLLC_vPrimRefSlewed_pu;

// volatile float32_t CLLC_pwmDutyPrimRef_pu;
// float32_t CLLC_pwmDutyPrim_pu;
// uint32_t CLLC_pwmDutyAPrim_ticks;
// uint32_t CLLC_pwmDutyBPrim_ticks;

// volatile float32_t CLLC_pwmDeadBandREDPrimRef_ns;
// uint32_t CLLC_pwmDeadBandREDPrim_ticks;

// volatile float32_t CLLC_pwmDeadBandFEDPrimRef_ns;
// uint32_t CLLC_pwmDeadBandFEDPrim_ticks;
//OFFSET
float32_t CLLC_iPrimMAINSensedOffset_pu;
float32_t CLLC_iPrimSECONDARYSensedOffset_pu;
float32_t CLLC_vPrimSensedOffset_pu;
float32_t CLLC_iPrimMAINTankSensedOffset_pu;
float32_t CLLC_iPrimSECONDARYTankSensedOffset_pu;
//AVG
EMAVG CLLC_iPrimMAINSensedAvg_pu;
EMAVG CLLC_iPrimSECONDARYSensedAvg_pu;
EMAVG CLLC_vPrimSensedAvg_pu;


// 低压侧
//SI unit
float32_t CLLC_iSecMAINSensed_Amps; // ISEC1
float32_t CLLC_iSecSECONDARYSensed_Amps; // ISEC2
float32_t CLLC_vSecSensed_Volts;
float32_t CLLC_vSecRef_Volts;
//PU unit
float32_t CLLC_iSecMAINSensed_pu;   // ISEC1
float32_t CLLC_iSecSECONDARYSensed_pu;// ISEC2
float32_t CLLC_vSecSensed_pu;
float32_t CLLC_vSecRef_pu;
float32_t CLLC_vSecRefSlewed_pu;

// volatile float32_t CLLC_pwmDutySecRef_pu;
// float32_t CLLC_pwmDutySec_pu;
// uint32_t CLLC_pwmDutyASec_ticks;
// uint32_t CLLC_pwmDutyBSec_ticks;

// volatile float32_t CLLC_pwmDeadBandREDSecRef_ns;
// uint32_t CLLC_pwmDeadBandREDSec_ticks;

// volatile float32_t CLLC_pwmDeadBandFEDSecRef_ns;
// uint32_t CLLC_pwmDeadBandFEDSec_ticks;
//OFFSET
float32_t CLLC_iSecMAINSensedOffset_pu;
float32_t CLLC_iSecSECONDARYSensedOffset_pu;
float32_t CLLC_vSecSensedOffset_pu;
float32_t CLLC_iSecMAINTankSensedOffset_pu;
float32_t CLLC_iSecSECONDARYTankSensedOffset_pu;
//AVG
EMAVG CLLC_iSecMAINSensedAvg_pu;
EMAVG CLLC_iSecSECONDARYSensedAvg_pu;
EMAVG CLLC_vSecSensedAvg_pu;


__interrupt void ISR1_PZCD(void)
{
    uint16_t TB_CTR_NOW = HWREGH(CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR);
    // 获取当前计数器值
    uint16_t PZCD1_state = GPIO_readPin(PRIM_ZCD1);

    // 下面的判断可以防止掉入容性区
    if ((PZCD1_state == 0) && (TB_CTR_NOW < CLLC_PRIM_COMPA)){// 上升沿清零计数值
        HWREGH(CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR) = 3;
        HWREGH(CLLC_PRIM_LEGB_PWM_BASE + EPWM_O_TBCTR) = 3;
    }else if ((PZCD1_state == 1) && (TB_CTR_NOW > CLLC_PRIM_COMPA)){// 下降沿清零计数值
        HWREGH(CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR) = CLLC_PRIM_COMPA + 3;
        HWREGH(CLLC_PRIM_LEGB_PWM_BASE + EPWM_O_TBCTR) = CLLC_PRIM_COMPA + 3;
    }
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}


__interrupt void ISR1_SZCD(void)
{
    uint16_t TB_CTR_NOW = HWREGH(CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBCTR);
    // 获取当前计数器值
    uint16_t SZCD1_state = GPIO_readPin(SEC_ZCD1);

    // 下面的判断可以防止掉入容性区
    if ((SZCD1_state == 0) && (TB_CTR_NOW < CLLC_SEC_COMPA)){// 上升沿清零计数值
        HWREGH(CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBCTR) = 3;
        HWREGH(CLLC_SEC_LEGB_PWM_BASE + EPWM_O_TBCTR) = 3;
    }else if ((SZCD1_state == 1) && (TB_CTR_NOW > CLLC_SEC_COMPA)){// 下降沿清零计数值
        HWREGH(CLLC_SEC_LEGA_PWM_BASE + EPWM_O_TBCTR) = CLLC_SEC_COMPA + 3;
        HWREGH(CLLC_SEC_LEGB_PWM_BASE + EPWM_O_TBCTR) = CLLC_SEC_COMPA + 3;
    }
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

static inline void CLLC_runVotageLoop(void)
{
    if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == \
      CLLC_POWER_FLOW_PRIM_SEC)
    {
        
    }else if (CLLC_powerFlowState.CLLC_PowerFlowState_Enum == \
              CLLC_POWER_FLOW_SEC_PRIM)
    {
        
    }
    
}

__interrupt void ISR2_TIMER0(void)
{
    CLLC_PRIM_COMPA = (CLLC_HAL_getPrimTBPRD() >> 1);// 获取当前计数器周期值
    CLLC_SEC_COMPA = (CLLC_HAL_getSecTBPRD() >> 1); // 获取当前计数器周期值
    CLLC_readSensedSignals();
    CLLC_runVotageLoop();
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1); // timer0要加上清除中断标志
}


void CLLC_initGlobalVariables(void)
{
    CLLC_iPrimMAINSensed_pu = 0.0f;
    CLLC_iPrimSECONDARYSensed_pu = 0.0f;
    CLLC_iPrimMAINSensedOffset_pu = 0.5f;
    CLLC_iPrimSECONDARYSensedOffset_pu = 0.5f;

    CLLC_iPrimMAINTankSensedOffset_pu = 0.5f;
    CLLC_iPrimSECONDARYTankSensedOffset_pu = 0.5f;// 初级，电流

    CLLC_iSecMAINSensed_pu = 0.0f;
    CLLC_iSecSECONDARYSensed_pu = 0.0f;
    CLLC_iSecMAINSensedOffset_pu = 0.5f;
    CLLC_iSecSECONDARYSensedOffset_pu = 0.5f;

    CLLC_iSecMAINTankSensedOffset_pu = 0.5f;
    CLLC_iSecSECONDARYTankSensedOffset_pu = 0.5f; // 次级，电流

    CLLC_vPrimSensed_pu = 0.0f;
    CLLC_vPrimSensedOffset_pu = 0.0f;

    CLLC_vSecSensed_pu = 0.0f;
    CLLC_vSecSensedOffset_pu = 0.0f;

    EMAVG_reset(&CLLC_iPrimMAINSensedAvg_pu);
    EMAVG_config(&CLLC_iPrimMAINSensedAvg_pu, 0.01f);

    EMAVG_reset(&CLLC_iPrimSECONDARYSensedAvg_pu);
    EMAVG_config(&CLLC_iPrimSECONDARYSensedAvg_pu, 0.01f);// 初级，电流

    EMAVG_reset(&CLLC_iSecMAINSensedAvg_pu);
    EMAVG_config(&CLLC_iSecMAINSensedAvg_pu, 0.01f);

    EMAVG_reset(&CLLC_iSecSECONDARYSensedAvg_pu);
    EMAVG_config(&CLLC_iSecSECONDARYSensedAvg_pu, 0.01f);// 次级，电流

    EMAVG_reset(&CLLC_vPrimSensedAvg_pu);
    EMAVG_config(&CLLC_vPrimSensedAvg_pu, 0.01f);

    EMAVG_reset(&CLLC_vSecSensedAvg_pu);
    EMAVG_config(&CLLC_vSecSensedAvg_pu, 0.01f);// 两个电压
}
