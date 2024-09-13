#ifndef CLLC_SETTINGS_H
#define CLLC_SETTINGS_H

#warning // Modify parameters here to suit your system


#include "DCLF32.h"

//
// CPU相关定义
//
#define CLLC_CPU_SYS_CLOCK_FREQ_HZ ((float32_t)100 * 1000000)
#define CLLC_PWMSYSCLOCK_FREQ_HZ ((float32_t)100 * 1000000)

//
// 控制模式，直接频率控制或者时移控制
// 1 -> direct frequency control
// 2 -> time shift control
//
#define CLLC_DIR_FEEQ_CTRL 1
#define CLLC_TIME_SHIF_CTRL 2

//
// 功率流向
// 1 -> PRIM to SEC
// 2 -> SEC to PRIM
//
#define CLLC_POWER_FLOW_PRIM_SEC 1
#define CLLC_POWER_FLOW_SEC_PRIM 2
#define CLLC_POWER_FLOW_TRANSITION_STAGE 3

//
// 保护开关
// 0 -> DISABLED
// 1 -> ENABLED
//
#define CLLC_PROTECTION_ENABLED 1
#define CLLC_PROTECTION_DISABLED 0

//
// 构建模式，开环或者闭环
// 1 ->  Open Loop Check
// 2 ->  Closed Loop Check
//
#define CLLC_OPEN_LOOP_BUILD 1
#define CLLC_CLOSED_LOOP_BUILD 2

//
// 功率级相关定义
//
#define CLLC_NOMINAL_PWM_SWITCHING_FREQUENCY_HZ    ((float32_t)89.13*1000)
                                                                    //谐振频率
#define CLLC_MAX_PWM_SWITCHING_FREQUENCY_HZ        ((float32_t)160*1000)
#define CLLC_MIN_PWM_SWITCHING_FREQUENCY_HZ        ((float32_t)50*1000)

#define CLLC_VPRIM_MAX_SENSE_VOLTS         ((float32_t)470.423) //初级母线最大电压
#define CLLC_VSEC_MAX_SENSE_VOLTS          ((float32_t)112.448) //次级母线最大电压
#define CLLC_VSEC_OPTIMAL_RANGE_VOLTS      ((float32_t)100)
// #define CLLC_IPRIM_MAX_SENSE_AMPS          ((float32_t)8)      //初级母线最大电流
// #define CLLC_ISEC_MAX_SENSE_AMPS           ((float32_t)55)     //次级母线最大电流
#define CLLC_IPRIM_MAX_BRANCH_SENSE_AMPS   ((float32_t)13.013)      //初级母线最大支路电流
#define CLLC_ISEC_MAX_BRACH_SENSE_AMPS     ((float32_t)43.086)     //次级母线最大支路电流
//#define CLLC_IPRIM_TANK_MAX_SENSE_AMPS ((float32_t)34.375)
//#define CLLC_ISEC_TANK_MAX_SENSE_AMPS ((float32_t)42.375)

#define CLLC_VSEC_NOMINAL_VOLTS    ((float32_t)100)
#define CLLC_VPRIM_NOMINAL_VOLTS   ((float32_t)400)

// #define CLLC_IPRIM_TRIP_LIMIT_AMPS ((float32_t)30)
// #define CLLC_ISEC_TRIP_LIMIT_AMPS ((float32_t)40)
#define CLLC_IPRIM_TANK_TRIP_LIMIT_AMPS_PEAK   ((float32_t)10)
#define CLLC_ISEC_TANK_TRIP_LIMIT_AMPS_PEAK    ((float32_t)40)

//
// 根据实际调整 
//
#define CLLC_IPRIM_TANK_DACHVAL 2150
#define CLLC_IPRIM_TANK_DACLVAL 1950
#define CLLC_ISEC_TANK_DACHVAL 2150
#define CLLC_ISEC_TANK_DACLVAL 1950

// 用于计算的常量
#define PI_VALUE ((float32_t)3.141592653589)
#define CLLC_ADC_PU_SCALE_FACTOR ((float32_t)( 1.0f / (1 << 12) )) // 12bit

//
// 环路相关参数
//
#define CLLC_GV_RUN DCL_runPI_C3

#define CLLC_MAX_TD_STEP_PU ((float32_t)0.05) // 电荷积分TD的最大调整步长

#endif // CLLC_SETTINGS_H
