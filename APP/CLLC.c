#include "CLLC.h"



volatile CLLC_SystemState_StructType CLLC_systemState;//系统状态

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

volatile uint16_t CLLC_clooseGvLoop;
volatile uint16_t CLLC_PRIM_TimeShift_ticks;
volatile uint16_t CLLC_SEC_TimeShift_ticks;
volatile uint16_t CLLC_PRIM_TimeShift_ticks_min,
                  CLLC_PRIM_TimeShift_ticks_max;
volatile uint16_t CLLC_SEC_TimeShift_ticks_min,
                  CLLC_SEC_TimeShift_ticks_max;

CLLC_GV CLLC_gvPrim2Sec;
CLLC_GV CLLC_gvSec2Prim;
float32_t CLLC_gvPrim2Sec_out;
float32_t CLLC_gvSec2Prim_out;

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
        CLLC_gvPrim2Sec_out = DCL_runPI_C3(&CLLC_gvPrim2Sec, CLLC_vSecSensed_pu, 
                                           CLLC_vSecRef_pu);
        CLLC_PRIM_COMPA = CLLC_gvPrim2Sec_out * CLLC_MAX_TD_TICKS;
        EPWM_setCounterCompareValue(CLLC_PRIM_LEGB_PWM_BASE,
                                    EPWM_COUNTER_COMPARE_A,CLLC_PRIM_COMPA);
        EPWM_setTimeBasePeriod(CLLC_PRIM_LEGB_PWM_BASE, CLLC_PRIM_COMPA<<1);

    }else if (CLLC_powerFlowState.CLLC_PowerFlowState_Enum == \
              CLLC_POWER_FLOW_SEC_PRIM)
    {
        CLLC_gvSec2Prim_out = DCL_runPI_C3(&CLLC_gvSec2Prim, CLLC_vPrimSensed_pu, 
                                           CLLC_vPrimRef_pu);
    }
    
}

__interrupt void ISR2_TIMER0(void)
{
    // CLLC_PRIM_COMPA = (CLLC_HAL_getTBPRD(CLLC_PRIM_LEGA_PWM_BASE) >> 1);
    // // 获取当前计数器周期值
    // CLLC_SEC_COMPA = (CLLC_HAL_getTBPRD(CLLC_SEC_LEGA_PWM_BASE) >> 1);
    CLLC_readSensedSignals();
    if((CLLC_clooseGvLoop == 1) && (CLLC_systemState.systemstate_normal == 1)){
        CLLC_runVotageLoop();
    }
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1); // timer0要加上清除中断标志
}


void CLLC_initGlobalVariables(void)
{
    // 采样
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

    CLLC_systemState.systemstate_off = 1;
    
    // 环路相关变量
    CLLC_clooseGvLoop = 0;
    CLLC_PRIM_TimeShift_ticks = 0;
    CLLC_SEC_TimeShift_ticks = 0;

    CLLC_vPrimRef_pu = 0.0f;
    CLLC_vSecRef_pu = 0.0f;

    CLLC_PRIM_TimeShift_ticks_min = 300;
    CLLC_SEC_TimeShift_ticks_min = 300;
    CLLC_PRIM_TimeShift_ticks_max = 600;
    CLLC_SEC_TimeShift_ticks_max = 600;

    // 补偿器参数
    CLLC_gvPrim2Sec.Kp = 3.0f;
    CLLC_gvPrim2Sec.Ki = 0.0f;
    CLLC_gvPrim2Sec.Umax = 100.0f;
    CLLC_gvPrim2Sec.Umin = 0.0f;

    CLLC_gvSec2Prim.Kp = 0.0f;
    CLLC_gvSec2Prim.Ki = 0.0f;
    CLLC_gvSec2Prim.Umax = 0.0f;
    CLLC_gvSec2Prim.Umin = 0.0f;

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

void CLLC_updateBoardStatus(void)
{


}


void CLLC_isBRUSTModeEnabled(void)
{



}


void CLLC_isSyncRectificationModeEnabled(void)
{



}


void CLLC_isSecondaryEnabled(void)
{



}


void MULT_CLLL_checkPowerFlow(void)
{
    if(CLLC_systemState.systemstate_normal == 0){ // 初始化时判断功率流向
        CLLC_HAL_ManuallyTriggeredAllADC();
        CLLC_readSensedSignals();
        if((CLLC_vPrimSensed_pu > 0.1f) && (CLLC_vSecSensed_pu > 0.1f)){
            if(CLLC_vPrimSensed_pu > (CLLC_vSecSensed_pu * CLLC_TRANSFORMER_TRUNS_RATIO)){
                CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_PrimToSec;
            }else{
                CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_SecToPrim;
            }
        }else{
            CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_PrimToSec;
        }

        if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == powerFlow_PrimToSec){
            // 正向
            CLLC_HAL_setDeadBand(CLLC_SEC_LEGA_PWM_BASE,2000);
            CLLC_HAL_setDeadBand(CLLC_SEC_LEGB_PWM_BASE,2000);
        }else{
            // 反向
            CLLC_HAL_setDeadBand(CLLC_PRIM_LEGA_PWM_BASE,2000);
            CLLC_HAL_setDeadBand(CLLC_PRIM_LEGB_PWM_BASE,2000);
        }
        // 启动时先关闭第二相
        CLLC_HAL_setDeadBand(CLLC_PRIM_LEGC_PWM_BASE,2000);
        CLLC_HAL_setDeadBand(CLLC_PRIM_LEGD_PWM_BASE,2000);
        CLLC_HAL_setDeadBand(CLLC_SEC_LEGC_PWM_BASE,2000);
        CLLC_HAL_setDeadBand(CLLC_SEC_LEGD_PWM_BASE,2000);
    }else{ // 正常运行时判断功率流向

    }

}

