#ifndef MULT_CLLC_H
#define MULT_CLLC_H

#include "Mult_CLLC_settings.h"
#include "Mult_CLLC_HAL.h"

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
        systemstate_fault = 4,
        systemstaate_CalaOffset
    } MULT_CLLC_SystemState_Enum;
    int32_t pad;
} MULT_CLLC_SystemState_EnumType;//系统工作状态

extern __volatile MULT_CLLC_SystemState_EnumType MULT_CLLC_systemState;

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

extern __volatile MULT_CLLC_TripFlag_StructType MULT_CLLC_TripFlag;

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

extern __volatile MULT_CLLC_PowerFlowState_EnumType MULT_CLLC_powerFlowStateActive,
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

#endif // MULT_CLLC_H
