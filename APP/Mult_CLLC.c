#include "Mult_CLLC.h"

__volatile MULT_CLLC_SystemState_EnumType MULT_CLLC_systemState;//系统状态

__volatile MULT_CLLC_TripFlag_StructType MULT_CLLC_tripFlag;//系统跳闸状态

__volatile MULT_CLLC_PowerFlowState_EnumType MULT_CLLC_powerFlowStateActive, 
                                        MULT_CLLC_powerFlowState;//系统功率流向

MULT_CLLC_CommandSentTo_AC_DC_EnumType MULT_CLLC_commandSentTo_AC_DC;
                                                    //发送给前级ACDC的指令

MULT_CLLC_CommandSentFrom_DC_DC_EnumType MULT_CLLC_commandSentFrom_DC_DC;
                                                    //从后级DCDC接收到的指令


volatile uint16_t CLLC_PRIM_COMPA = 560;




__interrupt void ISR1_PZCD(void)
{
    uint16_t TB_CTR_NOW = HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR);//获取当前计数器值
    uint16_t PZCD1_state = GPIO_readPin(PRIM_ZCD1);

    if ((PZCD1_state == 0) && (TB_CTR_NOW < CLLC_PRIM_COMPA)){//上升沿清零计数值
        HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR) = 3;
        HWREGH(MULT_CLLC_PRIM_LEGB_PWM_BASE + EPWM_O_TBCTR) = 3;
    }else if ((PZCD1_state == 1) && (TB_CTR_NOW > CLLC_PRIM_COMPA)){//下降沿清零计数值
        HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBCTR) = CLLC_PRIM_COMPA + 3;
        HWREGH(MULT_CLLC_PRIM_LEGB_PWM_BASE + EPWM_O_TBCTR) = CLLC_PRIM_COMPA + 3;
    }
    
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

__interrupt void ISR2_TIMER0(void)
{
    CLLC_PRIM_COMPA = ((HWREGH(MULT_CLLC_PRIM_LEGA_PWM_BASE + EPWM_O_TBPRD)) >> 1);
    //获取当前计数器周期值
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1); // timer0要加上清除中断标志位这句话
}