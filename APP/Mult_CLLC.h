#ifndef MULT_CLLC_H
#define MULT_CLLC_H

#include "Mult_CLLC_settings.h"
#include "Mult_CLLC_HAL.h"

void MULT_CLLC_initGlobalVariables(void);

void MULT_CLLC_updateBoardStatus(void);

typedef union
{
    enum
    {
        noTrip = 0,
        primOverCurrentTrip = 1,
        secOverCurrentTrip = 2,
        primOverVoltageTrip = 3,
        secOverVoltageTrip = 4,
        primTankOverCurrentTrip = 5,
    } MULT_CLLC_TripFlag_Enum;
    int32_t pad;
} MULT_CLLC_TripFlag_EnumType;//系统跳闸状态

extern MULT_CLLC_TripFlag_EnumType MULT_CLLC_TripFlag;

typedef union
{
    enum
    {
        pwmSwState_disabledAll = 0,
        pwmSwState_synchronousRectification_OFF = 1,
        pwmSwState_synchronousRectification_fixedDuty = 2,
        pwmSwState_synchronousRectification_active = 3
    } MULT_CLLC_PwmSwState_Enum;
    int32_t pad;
} MULT_CLLC_PwmSwState_EnumType;//PWM开关状态

extern MULT_CLLC_PwmSwState_EnumType MULT_CLLC_pwmSwStateActive, MULT_CLLC_pwmSwState;

typedef union
{
    enum
    {
        powerFlow_PrimToSec = MULT_CLLC_POWER_FLOW_PRIM_SEC,
        powerFlow_SecToPrim = MULT_CLLC_POWER_FLOW_SEC_PRIM,
        powerFlow_intermediateState = MULT_CLLC_POWER_FLOW_TRANSTION_STAGE,
    } MULT_CLLC_PowerFlowState_Enum;
    int32_t pad;
} MULT_CLLC_PowerFlowState_EnumType;//功率流向状态

extern MULT_CLLC_PowerFlowState_EnumType MULT_CLLC_powerFlowStateActive,
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
