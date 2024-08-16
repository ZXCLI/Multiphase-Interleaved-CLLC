#ifndef MULT_CLLC_SETTINGS_H
#define MULT_CLLC_SETTINGS_H

//#############################################################################
//
// Includes
//
//#############################################################################
#include <stdint.h>

//#############################################################################
//
// Macro Definitions
//
//#############################################################################
#ifndef C2000_IEEE754_TYPES
    #define C2000_IEEE754_TYPES
    #ifdef __TI_EABI__
        typedef float         float32_t;
        typedef double        float64_t;
    #else // TI COFF
        typedef float         float32_t;
        typedef long double   float64_t;
    #endif // __TI_EABI__
#endif // C2000_IEEE754_TYPES

//
// CPU相关定义
//
#define MULT_CLLC_CPU_SYS_CLOCK_FREQ_HZ ((float32_t)100 * 1000000)
#define MULT_CLLC_PWMSYSCLOCK_FREQ_HZ ((float32_t)100 * 1000000)

//
// 控制模式，电压或者电流
// 1 -> Voltage
// 2 -> Current
//
#define MULT_CLLC_VOLTAGE_MODE 1
#define MULT_CLLC_CURRENT_MODE 2

//
// 功率流向
// 1 -> PRIM to SEC
// 2 -> SEC to PRIM
//
#define MULT_CLLC_POWER_FLOW_PRIM_SEC 1
#define MULT_CLLC_POWER_FLOW_SEC_PRIM 2
#define MULT_CLLC_POWER_FLOW_TRANSTION_STAGE 3

//
// 构建模式，开环或者闭环
// 1 ->  Open Loop Check
// 2 ->  Closed Loop Check
//
#define MULT_CLLC_OPEN_LOOP_BUILD 1
#define MULT_CLLC_CLOSED_LOOP_BUILD 2

//
// 中断频率定义
//
#define MULT_CLLC_ISR1_FREQUENCY_HZ  ((float32_t)10000)
#define MULT_CLLC_ISR2_FREQUENCY_HZ  ((float32_t)10000)
#define MULT_CLLC_ISR3_FREQUENCY_HZ  ((float32_t)10000)

//
// 功率级相关定义
//
#define CLLLC_NOMINAL_PWM_SWITCHING_FREQUENCY_HZ  ((float32_t)89.13*1000)
#define CLLLC_MAX_PWM_SWITCHING_FREQUENCY_HZ ((float32_t)160*1000)
#define CLLLC_MIN_PWM_SWITCHING_FREQUENCY_HZ ((float32_t)50*1000)

// #define CLLLC_PRIM_PWM_DEADBAND_RED_NS ((float32_t)102.3)
// #define CLLLC_PRIM_PWM_DEADBAND_FED_NS ((float32_t)102.3)
// #define CLLLC_SEC_PWM_DEADBAND_RED_NS  ((float32_t)102)
// #define CLLLC_SEC_PWM_DEADBAND_FED_NS  ((float32_t)102)

#define CLLLC_VPRIM_MAX_SENSE_VOLTS    ((float32_t)420)
#define CLLLC_VSEC_MAX_SENSE_VOLTS     ((float32_t)110)
#define CLLLC_VSEC_OPTIMAL_RANGE_VOLTS ((float32_t)450)
#define CLLLC_IPRIM_MAX_SENSE_AMPS    ((float32_t)34.375)
#define CLLLC_ISEC_MAX_SENSE_AMPS     ((float32_t)42.438)
#define CLLLC_IPRIM_TANK_MAX_SENSE_AMPS ((float32_t)34.375)
#define CLLLC_ISEC_TANK_MAX_SENSE_AMPS ((float32_t)42.375)

#define CLLLC_VSEC_NOMINAL_VOLTS ((float32_t)300)
#define CLLLC_VPRIM_NOMINAL_VOLTS ((float32_t)400)

#define CLLLC_IPRIM_TRIP_LIMIT_AMPS ((float32_t)30)
#define CLLLC_ISEC_TRIP_LIMIT_AMPS  ((float32_t)40)
#define CLLLC_IPRIM_TANK_TRIP_LIMIT_AMPS ((float32_t)30)
#define CLLLC_ISEC_TANK_TRIP_LIMIT_AMPS  ((float32_t)40)

#endif  // MULT_CLLC_SETTINGS_H
