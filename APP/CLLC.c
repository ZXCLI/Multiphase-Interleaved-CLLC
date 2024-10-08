#include "CLLC.h"
#include "inc/hw_types.h"



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
        CLLC_gvPrim2Sec_out = DCL_runPI_C2(&CLLC_gvPrim2Sec, CLLC_vSecSensed_pu, 
                                           CLLC_vSecRef_pu);
        
        CLLC_PRIM_TimeShift_ticks = (uint16_t)(CLLC_gvPrim2Sec_out * CLLC_MAX_TD_TICKS);
        CLLC_PRIM_TimeShift_ticks = (CLLC_PRIM_TimeShift_ticks > CLLC_PRIM_TimeShift_ticks_max) ? \
                        CLLC_PRIM_TimeShift_ticks_max : CLLC_PRIM_TimeShift_ticks;
        CLLC_PRIM_TimeShift_ticks = (CLLC_PRIM_TimeShift_ticks < CLLC_PRIM_TimeShift_ticks_min) ? \
                        CLLC_PRIM_TimeShift_ticks_min : CLLC_PRIM_TimeShift_ticks;

        CLLC_PRIM_TimeShift_ticks = CLLC_MAX_TD_TICKS - CLLC_PRIM_TimeShift_ticks;

        EPWM_setCounterCompareValue(CLLC_PRIM_LEGB_PWM_BASE,
                                  EPWM_COUNTER_COMPARE_A,CLLC_PRIM_TimeShift_ticks);
        EPWM_setTimeBasePeriod(CLLC_PRIM_LEGB_PWM_BASE, CLLC_PRIM_TimeShift_ticks<<1);

        CLLC_PRIM_COMPA = CLLC_PRIM_TimeShift_ticks;

        return;
    }
    else if (CLLC_powerFlowState.CLLC_PowerFlowState_Enum == \
              CLLC_POWER_FLOW_SEC_PRIM)
    {
        CLLC_gvSec2Prim_out = DCL_runPI_C3(&CLLC_gvSec2Prim, CLLC_vPrimSensed_pu, 
                                           CLLC_vPrimRef_pu);
    }

    // EPWM_setCounterCompareValue(CLLC_PRIM_LEGB_PWM_BASE,
    //                           EPWM_COUNTER_COMPARE_A,CLLC_PRIM_COMPA);
    // EPWM_setTimeBasePeriod(CLLC_PRIM_LEGB_PWM_BASE, CLLC_PRIM_COMPA<<1);
}

__interrupt void ISR2_TIMER0(void)
{
    CLLC_softStart();
    CLLC_readSensedSignals();
#if CLLC_INCR_BUILD == CLLC_CLOSED_LOOP_BUILD

    if((CLLC_clooseGvLoop == 1) && (CLLC_systemState.systemstate_normal == 1)){
        CLLC_runVotageLoop();
    }
    
#endif
    CLLC_runEMAVG();// TODO:先放在中断里面，看看后面中断的占用率
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
    CLLC_clooseGvLoop = 1;
    CLLC_PRIM_TimeShift_ticks = 0;
    CLLC_SEC_TimeShift_ticks = 0;

    CLLC_vPrimRef_pu = 0.1f;
    CLLC_vSecRef_pu = 0.15f;

    CLLC_PRIM_TimeShift_ticks_min = CLLC_PWMSYSCLOCK_FREQ_HZ /
                                    (4 * CLLC_MAX_PWM_SWITCHING_FREQUENCY_HZ);
    CLLC_SEC_TimeShift_ticks_min = CLLC_PWMSYSCLOCK_FREQ_HZ /
                                    (4 * CLLC_MAX_PWM_SWITCHING_FREQUENCY_HZ);

    // 注意：分母上的系数应该大于2，最好上机实测调整                                
    CLLC_PRIM_TimeShift_ticks_max = CLLC_PWMSYSCLOCK_FREQ_HZ /
                                    (2.3f * CLLC_MIN_PWM_SWITCHING_FREQUENCY_HZ);
    CLLC_SEC_TimeShift_ticks_max = CLLC_PWMSYSCLOCK_FREQ_HZ /
                                    (2.3f * CLLC_MIN_PWM_SWITCHING_FREQUENCY_HZ);

    // 补偿器参数
    DCL_resetPI(&CLLC_gvPrim2Sec);
    CLLC_gvPrim2Sec.Kp = 3.0f;
    CLLC_gvPrim2Sec.Ki = 1.0f;
    CLLC_gvPrim2Sec.Umax = 100.0f;
    CLLC_gvPrim2Sec.Umin = -100.0f;

    DCL_resetPI(&CLLC_gvSec2Prim);
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

void CLLC_softStart(void)
{
    if((CLLC_systemState.systemstate_off == 1) || 
       (CLLC_systemState.systemstte_softstart == 1))
    {
        if(CLLC_systemState.systemstate_off == 1){
            CLLC_systemState.systemstate_off = 0;
            CLLC_systemState.systemstte_softstart = 1;
        }

        static float32_t softstart_counter = 0;
        softstart_counter += 0.03f;
        uint16_t softTBPRD = (uint16_t)((CLLC_PWMSYSCLOCK_FREQ_HZ/ \
                             CLLC_NOMINAL_PWM_SWITCHING_FREQUENCY_HZ) / \
                             (3.8702f - 0.1365f * softstart_counter \
                             +0.00257f * softstart_counter * softstart_counter \
                             -0.00001803f * softstart_counter* \
                             softstart_counter * softstart_counter)); 
        // 三阶多项式拟合，指数衰减从4到1，对应频率从4倍谐振频率下降到1倍谐振频率
        if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == 
            powerFlow_PrimToSec)
        {
            CLLC_HAL_setTBPRDandCMPA(CLLC_PRIM_LEGB_PWM_BASE, softTBPRD);
        }else if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == 
            powerFlow_SecToPrim)
        {
            CLLC_HAL_setTBPRDandCMPA(CLLC_PRIM_LEGD_PWM_BASE, softTBPRD);
        }
        // 软启动完成
        if(softstart_counter > 60.0f){
            CLLC_systemState.systemstte_softstart = 0;
            CLLC_systemState.systemstate_normal = 1;

            EALLOW;
        #if CLLC_PROTECTION == CLLC_PROTECTION_ENABLED 

            // 软启动完成再开启CBC和OSHT保护
            // TODO:硬件全部调试正常后记得取消注释
            // CMPSS_enableModule(M_CMPSS1_BASE);
            // CMPSS_enableModule(M_CMPSS2_BASE);
            // CMPSS_enableModule(M_CMPSS3_BASE);
            // CMPSS_enableModule(M_CMPSS4_BASE);
            // CLLC_HAL_enableCPMSSXBAR();
            CLLC_HAL_enableAllTripZoneSignals();
            CLLC_HAL_clearAllTripZoneFlag();
            
            GPIO_writePin(DEBUG2,1);
            
        #endif  

    #if CLLC_CONTROL_MODE == CLLC_TIME_SHIF_CTRL

        if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == \
            powerFlow_PrimToSec)
            {CLLC_enablePRIM_TD_INT();} // 只有时移控制需要开启中断
        else if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == \
            powerFlow_SecToPrim)
            //{Interrupt_enable(INT_SEC_ZCD1_XINT); } 

    #endif
            EDIS;
        }
    }
}

void CLLC_updateBoardStatus(void)
{
    CLLC_tripFlag.trip_MAIN = 
                    EPWM_getTripZoneFlagStatus(CLLC_PRIM_LEGB_PWM_BASE);
    CLLC_tripFlag.trip_SECONDARY = 
                    EPWM_getTripZoneFlagStatus(CLLC_PRIM_LEGD_PWM_BASE);
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


void CLLL_checkPowerFlow(void)
{
    if(CLLC_systemState.systemstate_off == 1){ // 初始化时判断功率流向
        CLLC_HAL_ManuallyTriggeredAllADC();
        CLLC_readSensedSignals();
        if((CLLC_vPrimSensed_pu > 0.1f) || (CLLC_vSecSensed_pu > 0.1f)){
            if ((CLLC_vPrimSensed_pu * CLLC_VPRIM_MAX_SENSE_VOLTS) > 
            ((CLLC_vSecSensed_pu * CLLC_VSEC_MAX_SENSE_VOLTS) 
            * CLLC_TRANSFORMER_TRUNS_RATIO))
            {
                CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_PrimToSec;
            }
            else
            {
                CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_SecToPrim;
            }
        }else{ // 在两边都没有母线的时候，默认按照LAB中的设定功率流向
            #if CLLC_POWER_FLOW == CLLC_POWER_FLOW_PRIM_SEC
            CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_PrimToSec;
            #elif CLLC_POWER_FLOW == CLLC_POWER_FLOW_SEC_PRIM
            CLLC_powerFlowState.CLLC_PowerFlowState_Enum = powerFlow_SecToPrim;
            #endif
        }
        // 启机的时候先关闭同步整流和第二相
        if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == powerFlow_PrimToSec){
            CLLC_HAL_disableSECmainEPWM();
            CLLC_HAL_setTBPRDandCMPA(CLLC_PRIM_LEGA_PWM_BASE, 290);
            CLLC_HAL_setTBPRDandCMPA(CLLC_PRIM_LEGB_PWM_BASE, 290);
        }else if(CLLC_powerFlowState.CLLC_PowerFlowState_Enum == powerFlow_SecToPrim){
            CLLC_HAL_disableSECmainEPWM();
            CLLC_HAL_setTBPRDandCMPA(CLLC_SEC_LEGA_PWM_BASE, 290);
            CLLC_HAL_setTBPRDandCMPA(CLLC_SEC_LEGB_PWM_BASE, 290);
        }
        // 关闭同步整流的信号
        CLLC_HAL_disableCLBXBAR(); // 关闭CLB输出到EPWMXBAR的信号
        // 关闭第二相
        CLLC_HAL_disablePRIMsecondaryEPWM();
        CLLC_HAL_disableSECsecondaryEPWM();
    }else{ // 正常运行时判断功率流向
        // CLLC_runEMAVG();
    }
}
