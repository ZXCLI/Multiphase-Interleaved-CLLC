#include "Mult_CLLC.h"

__volatile MULT_CLLC_SystemState_EnumType MULT_CLLC_systemState;//系统状态

__volatile MULT_CLLC_TripFlag_StructType MULT_CLLC_tripFlag;//系统跳闸状态

__volatile MULT_CLLC_PowerFlowState_EnumType MULT_CLLC_powerFlowStateActive, 
                                        MULT_CLLC_powerFlowState;//系统功率流向

MULT_CLLC_CommandSentTo_AC_DC_EnumType MULT_CLLC_commandSentTo_AC_DC;
                                                    //发送给前级ACDC的指令

MULT_CLLC_CommandSentFrom_DC_DC_EnumType MULT_CLLC_commandSentFrom_DC_DC;
                                                    //从后级DCDC接收到的指令
