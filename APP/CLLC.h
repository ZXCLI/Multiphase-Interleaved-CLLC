#ifndef CLLC_H
#define CLLC_H

#include "CLLC_user_settings.h"
#include "CLLC_HAL.h"
#include "emavg.h"


#define CLLC_GV  DCL_PI


// 时移算法中断所需变量
extern volatile uint16_t CLLC_PRIM_COMPA;
extern volatile uint16_t CLLC_SEC_COMPA;

// flage and status
extern volatile uint16_t CLLC_clooseGvLoop;
extern volatile uint16_t CLLC_SencondaryEabled;
extern volatile uint16_t CLLC_PRIM_TimeShift_ticks;
extern volatile uint16_t CLLC_SEC_TimeShift_ticks;
extern volatile uint16_t CLLC_PRIM_TimeShift_ticks_min,
                         CLLC_PRIM_TimeShift_ticks_max;
extern volatile uint16_t CLLC_SEC_TimeShift_ticks_min,
                         CLLC_SEC_TimeShift_ticks_max;
// extern volatile uint16_t CLLC_PRIM_TimeShiftPrev_ticks;
// extern volatile uint16_t CLLC_SEC_TimeShiftPrev_ticks;

// LOOP
extern CLLC_GV CLLC_gvPrim2Sec;
extern CLLC_GV CLLC_gvSec2Prim;
extern float32_t CLLC_gvPrim2Sec_out;
extern float32_t CLLC_gvSec2Prim_out;

// 高压侧
//SI unit
extern float32_t CLLC_iPrimMAINSensed_Amps; // IPRIM1
extern float32_t CLLC_iPrimSECONDARYSensed_Amps; // IPRIM2
extern float32_t CLLC_vPrimSensed_Volts;
extern float32_t CLLC_vPrimRef_Volts;
//PU unit
extern float32_t CLLC_iPrimMAINSensed_pu;   // IPRIM1
extern float32_t CLLC_iPrimSECONDARYSensed_pu;// IPRIM2
extern float32_t CLLC_vPrimSensed_pu;
extern float32_t CLLC_vPrimRef_pu;
extern float32_t CLLC_vPrimRefSlewed_pu; // 可能不需要斜坡?
//OFFSET
extern float32_t CLLC_iPrimMAINSensedOffset_pu;
extern float32_t CLLC_iPrimSECONDARYSensedOffset_pu;
extern float32_t CLLC_vPrimSensedOffset_pu;
extern float32_t CLLC_iPrimMAINTankSensedOffset_pu;
extern float32_t CLLC_iPrimSECONDARYTankSensedOffset_pu;
//AVG
extern EMAVG CLLC_iPrimMAINSensedAvg_pu;
extern EMAVG CLLC_iPrimSECONDARYSensedAvg_pu;
extern EMAVG CLLC_vPrimSensedAvg_pu;


// 低压侧
//SI unit
extern float32_t CLLC_iSecMAINSensed_Amps; // IPRIM1
extern float32_t CLLC_iSecSECONDARYSensed_Amps; // IPRIM2
extern float32_t CLLC_vSecSensed_Volts;
extern float32_t CLLC_vSecRef_Volts;
//PU unit
extern float32_t CLLC_iSecMAINSensed_pu;   // IPRIM1
extern float32_t CLLC_iSecSECONDARYSensed_pu;// IPRIM2
extern float32_t CLLC_vSecSensed_pu;
extern float32_t CLLC_vSecRef_pu;
extern float32_t CLLC_vSecRefSlewed_pu; // 可能不需要斜坡?
// OFFSET
extern float32_t CLLC_iSecMAINSensedOffset_pu;
extern float32_t CLLC_iSecSECONDARYSensedOffset_pu;
extern float32_t CLLC_vSecSensedOffset_pu;
extern float32_t CLLC_iSecMAINTankSensedOffset_pu;
extern float32_t CLLC_iSecSECONDARYTankSensedOffset_pu;
//AVG
extern EMAVG CLLC_iSecMAINSensedAvg_pu;
extern EMAVG CLLC_iSecSECONDARYSensedAvg_pu;
extern EMAVG CLLC_vSecSensedAvg_pu;



void CLLC_initGlobalVariables(void);//初始化变量

void CLLC_updateBoardStatus(void);//更新板卡状态
void CLLC_isBRUSTModeEnabled(void);//判断是否需要进入BRUST模式
void CLLC_isSyncRectificationModeEnabled(void);//判断是否需要进入同步整流模式
void CLLC_isSecondaryEnabled(void);//判断是否需要开启第二相
void MULT_CLLL_checkPowerFlow(void);//检测功率流向

typedef struct
{
    uint16_t systemstate_off;
    uint16_t systemstate_fault;
    uint16_t systemstate_waiteforBUSvoltage;
    uint16_t systemstte_softstart;
    uint16_t systemstate_normal;
    uint16_t systemstate_SyncRectification;
    uint16_t systemstate_Brust;
} CLLC_SystemState_StructType;//系统工作状态

extern volatile CLLC_SystemState_StructType CLLC_systemState;

typedef struct
{
    uint8_t trip_MAIN;
    uint8_t trip_SECONDARY;
    uint8_t trip_PRIM_TANK_MAIN;
    uint8_t trip_PRIM_TANK_SECONDARY;
    uint8_t trip_SEC_TANK_MAIN;
    uint8_t trip_SEC_TANK_SECONDARY;
    //后面的状态是根据读取到的ADC值判断的，并不是硬件跳闸
    uint8_t PrimOverVoltage;
    uint8_t SecOverVoltage;
    uint8_t PrimOverCurrent;
    uint8_t SecOverCurrent;
    uint8_t PrimOverCurrent_MIAN;
    uint8_t PrimOverCurrent_SECONDARY;
    uint8_t SecOverCurrent__MAIN;
    uint8_t SecOverCurrent_SECONDARY;
} CLLC_TripFlag_StructType;//系统跳闸状态

extern volatile CLLC_TripFlag_StructType CLLC_TripFlag;

typedef union
{
    enum
    {
        powerFlow_PrimToSec = CLLC_POWER_FLOW_PRIM_SEC,
        powerFlow_SecToPrim = CLLC_POWER_FLOW_SEC_PRIM,
        powerFlow_intermediateState = CLLC_POWER_FLOW_TRANSITION_STAGE,
    } CLLC_PowerFlowState_Enum;
    int32_t pad;
} CLLC_PowerFlowState_EnumType;//功率流向状态

extern volatile CLLC_PowerFlowState_EnumType CLLC_powerFlowStateActive,
                                                    CLLC_powerFlowState;

typedef union
{
    enum
    {
        ac_dc_OFF = 0,
        ac_dc_PFC = 1,
        ac_dc_INV = 2,
    } CLLC_CommandSentTo_AC_DC_Enum;
    int32_t pad;
} CLLC_CommandSentTo_AC_DC_EnumType;//发送给AC_DC的命令

extern CLLC_CommandSentTo_AC_DC_EnumType CLLC_commandSentTo_AC_DC;

typedef union
{
    enum
    {
        dc_dc_buck = 0,
        dc_dc_boost = 1,
    } CLLC_CommandSentFrom_DC_DC_Enum;
    int32_t pad;
} CLLC_CommandSentFrom_DC_DC_EnumType;//从DC_DC接收的命令

extern CLLC_CommandSentFrom_DC_DC_EnumType CLLC_commandSentFrom_DC_DC;

typedef struct test
{
    uint32_t PWM_preiod_ticks;
    uint32_t PWM_deadBand_ticks;
}MAINEPWM_StructType;

extern MAINEPWM_StructType CLLC_PRIMPWM,CLLC_SECPWM;


//#pragma FUNC_ALWAYS_INLINE(CLLC_readSensedSignalsPrimToSecPowerFlow)
static inline void CLLC_readSensedSignals(void)
{
    CLLC_iPrimMAINSensed_pu = ((float32_t)CLLC_IPRIM_MAIN_ADCREAD  *
                                            CLLC_ADC_PU_SCALE_FACTOR  
                                            - CLLC_iPrimMAINSensedOffset_pu) * 2.0;

    CLLC_iPrimSECONDARYSensed_pu = ((float32_t)CLLC_IPRIM_SECONDARY_ADCREAD *
                                            CLLC_ADC_PU_SCALE_FACTOR 
                                - CLLC_iPrimSECONDARYSensedOffset_pu) * 2.0;

    CLLC_iSecMAINSensed_pu = ((float32_t)CLLC_ISEC_MAIN_ADCREAD *
                                            CLLC_ADC_PU_SCALE_FACTOR 
                                - CLLC_iSecMAINSensedOffset_pu) * 2.0;

    CLLC_iSecSECONDARYSensed_pu = ((float32_t)CLLC_ISEC_SECONDARY_ADCREAD *
                                            CLLC_ADC_PU_SCALE_FACTOR 
                                - CLLC_iSecSECONDARYSensedOffset_pu) * 2.0;

    CLLC_vPrimSensed_pu = ((float32_t)CLLC_VPRIM_ADCREAD *
                                            CLLC_ADC_PU_SCALE_FACTOR
                                - CLLC_vPrimSensedOffset_pu);

    CLLC_vSecSensed_pu = ((float32_t)CLLC_VSEC_ADCREAD *
                                            CLLC_ADC_PU_SCALE_FACTOR
                                - CLLC_vSecSensedOffset_pu);
}

#endif // CLLC_H
