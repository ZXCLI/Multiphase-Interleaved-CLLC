#ifndef MULT_CLLC_H
#define MULT_CLLC_H

#include "Mult_CLLC_user_settings.h"
#include "Mult_CLLC_HAL.h"
#include "emavg.h"

// 时移算法中断所需变量
extern volatile uint16_t CLLC_PRIM_COMPA;
extern volatile uint16_t CLLC_SEC_COMPA;

// 高压侧
extern float32_t MULT_CLLC_iPrimMAINSensed_Amps; // IPRIM1
extern float32_t MULT_CLLC_iPrimMAINSensed_pu;   // IPRIM1
extern float32_t MULT_CLLC_iPrimMAINSensedOffset_pu;
extern float32_t MULT_CLLC_iPrimMAINSensedCalIntercept_pu;
extern float32_t MULT_CLLC_iPrimMAINSensedCalXvariable_pu;
extern EMAVG MULT_CLLC_iPrimMAINSensedAvg_pu;

extern float32_t MULT_CLLC_iPrimSECONDARYSensed_Amps; // IPRIM2
extern float32_t MULT_CLLC_iPrimSECONDARYSensed_pu;   // IPRIM2
extern float32_t MULT_CLLC_iPrimSECONDARYSensedOffset_pu;
extern float32_t MULT_CLLC_iPrimSECONDARYSensedCalIntercept_pu;
extern float32_t MULT_CLLC_iPrimSECONDARYSensedCalXvariable_pu;
extern EMAVG MULT_CLLC_iPrimSECONDARYSensedAvg_pu;

extern float32_t MULT_CLLC_iPrimMAINTankSensedOffset_pu;

extern float32_t MULT_CLLC_iPrimSECONDARYTankSensedOffset_pu;

extern float32_t MULT_CLLC_vPrimSensed_Volts;
extern float32_t MULT_CLLC_vPrimSensed_pu;
extern float32_t MULT_CLLC_vPrimSensedOffset_pu;
extern EMAVG MULT_CLLC_vPrimSensedAvg_pu;

extern float32_t MULT_CLLC_vPrimRef_Volts;
extern float32_t MULT_CLLC_vPrimRef_pu;
extern float32_t MULT_CLLC_vPrimRefSlewed_pu;

extern volatile float32_t MULT_CLLC_pwmDutyPrimRef_pu;
extern float32_t MULT_CLLC_pwmDutyPrim_pu;
extern uint32_t MULT_CLLC_pwmDutyAPrim_ticks;
extern uint32_t MULT_CLLC_pwmDutyBPrim_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandREDPrimRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandREDPrim_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandFEDPrimRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandFEDPrim_ticks;

// 低压侧
extern float32_t MULT_CLLC_iSecMAINSensed_Amps; // ISEC1
extern float32_t MULT_CLLC_iSecMAINSensed_pu;   // ISEC1
extern float32_t MULT_CLLC_iSecMAINSensedOffset_pu;
extern float32_t MULT_CLLC_iSecMAINSensedCalIntercept_pu;
extern float32_t MULT_CLLC_iSecMAINSensedCalXvariable_pu;
extern EMAVG MULT_CLLC_iSecMAINSensedAvg_pu;

extern float32_t MULT_CLLC_iSecSECONDARYSensed_Amps; // ISEC2
extern float32_t MULT_CLLC_iSecSECONDARYSensed_pu;   // ISEC2
extern float32_t MULT_CLLC_iSecSECONDARYSensedOffset_pu;
extern float32_t MULT_CLLC_iSecSECONDARYSensedCalIntercept_pu;
extern float32_t MULT_CLLC_iSecSECONDARYSensedCalXvariable_pu;
extern EMAVG MULT_CLLC_iSecSECONDARYSensedAvg_pu;

extern float32_t MULT_CLLC_iSecMAINTankSensedOffset_pu;

extern float32_t MULT_CLLC_iSecSECONDARYTankSensedOffset_pu;

extern float32_t MULT_CLLC_vSecSensed_Volts;
extern float32_t MULT_CLLC_vSecSensed_pu;
extern float32_t MULT_CLLC_vSecSensedOffset_pu;
extern EMAVG MULT_CLLC_vSecSensedAvg_pu;

extern float32_t MULT_CLLC_vSecRef_Volts;
extern float32_t MULT_CLLC_vSecRef_pu;
extern float32_t MULT_CLLC_vSecRefSlewed_pu;

extern volatile float32_t MULT_CLLC_pwmDutySecRef_pu;
extern float32_t MULT_CLLC_pwmDutySec_pu;
extern uint32_t MULT_CLLC_pwmDutyASec_ticks;
extern uint32_t MULT_CLLC_pwmDutyBSec_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandREDSecRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandREDSec_ticks;

// volatile float32_t MULT_CLLC_pwmDeadBandFEDSecRef_ns;
// uint32_t MULT_CLLC_pwmDeadBandFEDSec_ticks;

void MULT_CLLC_initGlobalVariables(void);//初始化变量

void MULT_CLLC_updateBoardStatus(void);//更新板卡状态
void MULT_CLLC_isBRUSTModeEnabled(void);//判断是否需要进入BRUST模式
void MULT_CLLL_checkPowerFlow(void);//检测功率流向

typedef union
{
    enum
    {
        systemstate_off = 0,
        systemstate_waiteforBUSvoltage = 1,
        systemstte_softstart = 2,
        systemstate_normal = 3,
        systemstate_Brust,
        systemstate_fault,
        systemstaate_CalaOffset
    } MULT_CLLC_SystemState_Enum;
    int32_t pad;
} MULT_CLLC_SystemState_EnumType;//系统工作状态

extern volatile MULT_CLLC_SystemState_EnumType MULT_CLLC_systemState;

typedef struct
{
    uint8_t trip_Phase_MAIN;
    uint8_t trip_Phase_SECONDARY;
    uint8_t trip_PRIM_TANK_MAIN;
    uint8_t trip_PRIM_TANK_SECONDARY;
    uint8_t trip_SEC_TANK_MAIN;
    uint8_t trip_SEC_TANK_SECONDARY;
    //后面的状态是根据读取到的ADC值判断的，并不是硬件跳闸
    uint8_t PrimOverVoltage;
    uint8_t SecOverVoltage;
    uint8_t PrimOverCurrent;
    uint8_t SecOverCurrent;
    uint8_t PrimOverCurrent_phase_MIAN;
    uint8_t PrimOverCurrent_phase_SECONDARY;
    uint8_t SecOverCurrent_phase_MAIN;
    uint8_t SecOverCurrent_phase_SECONDARY;
} MULT_CLLC_TripFlag_StructType;//系统跳闸状态

extern volatile MULT_CLLC_TripFlag_StructType MULT_CLLC_TripFlag;

typedef union
{
    enum
    {
        powerFlow_PrimToSec = MULT_CLLC_POWER_FLOW_PRIM_SEC,
        powerFlow_SecToPrim = MULT_CLLC_POWER_FLOW_SEC_PRIM,
        powerFlow_intermediateState = MULT_CLLC_POWER_FLOW_TRANSITION_STAGE,
    } MULT_CLLC_PowerFlowState_Enum;
    int32_t pad;
} MULT_CLLC_PowerFlowState_EnumType;//功率流向状态

extern volatile MULT_CLLC_PowerFlowState_EnumType MULT_CLLC_powerFlowStateActive,
                                                    MULT_CLLC_powerFlowState;

typedef union
{
    enum
    {
        ac_dc_OFF = 0,
        ac_dc_PFC = 1,
        ac_dc_INV = 2,
    } MULT_CLLC_CommandSentTo_AC_DC_Enum;
    int32_t pad;
} MULT_CLLC_CommandSentTo_AC_DC_EnumType;//发送给AC_DC的命令

extern MULT_CLLC_CommandSentTo_AC_DC_EnumType MULT_CLLC_commandSentTo_AC_DC;

typedef union
{
    enum
    {
        dc_dc_buck = 0,
        dc_dc_boost = 1,
    } MULT_CLLC_CommandSentFrom_DC_DC_Enum;
    int32_t pad;
} MULT_CLLC_CommandSentFrom_DC_DC_EnumType;//从DC_DC接收的命令

extern MULT_CLLC_CommandSentFrom_DC_DC_EnumType MULT_CLLC_commandSentFrom_DC_DC;

//
// the function prototypes
//
//#pragma FUNC_ALWAYS_INLINE(MULT_CLLC_readSensedSignalsPrimToSecPowerFlow)
static inline void MULT_CLLC_readSensedSignals(void)
{
    MULT_CLLC_iPrimMAINSensed_pu = ((float32_t)MULT_CLLC_IPRIM_MAIN_ADCREAD  *
                                            MULT_CLLC_ADC_PU_SCALE_FACTOR  
                                            - MULT_CLLC_iPrimMAINSensedOffset_pu) * 2.0;

    MULT_CLLC_iPrimSECONDARYSensed_pu = ((float32_t)MULT_CLLC_IPRIM_SECONDARY_ADCREAD *
                                            MULT_CLLC_ADC_PU_SCALE_FACTOR 
                                - MULT_CLLC_iPrimSECONDARYSensedOffset_pu) * 2.0;

    MULT_CLLC_iSecMAINSensed_pu = ((float32_t)MULT_CLLC_ISEC_MAIN_ADCREAD *
                                            MULT_CLLC_ADC_PU_SCALE_FACTOR 
                                - MULT_CLLC_iSecMAINSensedOffset_pu) * 2.0;

    MULT_CLLC_iSecSECONDARYSensed_pu = ((float32_t)MULT_CLLC_ISEC_SECONDARY_ADCREAD *
                                            MULT_CLLC_ADC_PU_SCALE_FACTOR 
                                - MULT_CLLC_iSecSECONDARYSensedOffset_pu) * 2.0;

    MULT_CLLC_vPrimSensed_pu = ((float32_t)MULT_CLLC_VPRIM_ADCREAD *
                                            MULT_CLLC_ADC_PU_SCALE_FACTOR
                                - MULT_CLLC_vPrimSensedOffset_pu);

    MULT_CLLC_vSecSensed_pu = ((float32_t)MULT_CLLC_VSEC_ADCREAD *
                                            MULT_CLLC_ADC_PU_SCALE_FACTOR
                                - MULT_CLLC_vSecSensedOffset_pu);

    // MULT_CLLC_vSecSensed_pu = MULT_CLLC_vSecSensed_pu *
    //                       (MULT_CLLC_VSEC_MAX_SENSE_VOLTS / MULT_CLLC_VSEC_OPTIMAL_RANGE_VOLTS);

    // MULT_CLLC_iSecSensed_pu = (MULT_CLLC_iSecSensed_pu *
    //                        MULT_CLLC_iSecSensedCalXvariable_pu) +
    //                       MULT_CLLC_iSecSensedCalIntercept_pu;
    // MULT_CLLC_iPrimSensed_pu = (MULT_CLLC_iPrimSensed_pu *
    //                         MULT_CLLC_iPrimSensedCalXvariable_pu) +
    //                        MULT_CLLC_iPrimSensedCalIntercept_pu;
}

#endif // MULT_CLLC_H
