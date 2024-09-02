#ifndef MULT_CLLC_USER_SETTINGS_H
#define MULT_CLLC_USER_SETTINGS_H

#include "Mult_CLLC.h"

//
// MULT_CLLC LAB
// Power Flow Prim -> Sec
// 1 -> Open loop check for PWM drivers,
// 2 -> Open loop check for PWM drivers with protection,
// 3 -> Closed loop check with resistive load, direct frequency control,
// 4 -> Closed loop check with resistive load, time shift control,
// Power Flow Sec -> Prim
// 5 -> Open loop check for PWM driver,
// 6 -> Open loop check for PWM driver with protection,
// 7 -> Closed loop voltage with resistive load
//

#define MULT_CLLC_LAB 1

#if MULT_CLLC_LAB == 1
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
// #define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
// #define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_DISABLED
#define MULT_CLLC_SFRA_TYPE 0
//#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 2
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 3
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif

#if MULT_CLLC_LAB == 4
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_CURRENT_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif

#if MULT_CLLC_LAB == 5
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_DISABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 6
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 7
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif

//
// PWM pin, ADC, SDFM, Relay Selection related variables
//

#define MULT_CLLC_PRIM_LEGA_PWM_BASE EPWM4_BASE
#define MULT_CLLC_PRIM_LEGB_PWM_BASE EPWM3_BASE
#define MULT_CLLC_SEC_LEGA_PWM_BASE EPWM2_BASE
#define MULT_CLLC_SEC_LEGB_PWM_BASE EPWM1_BASE


#define MULT_CLLC_PRIM_LEGC_PWM_BASE EPWM7_BASE
#define MULT_CLLC_PRIM_LEGD_PWM_BASE EPWM8_BASE
#define MULT_CLLC_SEC_LEGC_PWM_BASE EPWM5_BASE
#define MULT_CLLC_SEC_LEGD_PWM_BASE EPWM6_BASE

#endif // MULT_CLLC_USER_SETTINGS_H
