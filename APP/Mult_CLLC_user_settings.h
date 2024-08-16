#ifndef MULT_CLLC_USER_SETTINGS_H
#define MULT_CLLC_USER_SETTINGS_H


//
// MULT_CLLC LAB
// Power Flow Prim -> Sec
// 1 -> Open loop check for PWM drivers,
// 2 -> Open loop check for PWM drivers with protection,
// 3 -> Closed loop check with resistive load, voltage loop,
// 4 -> Closed loop check with resistive load, current loop
// 5 -> Closed loop check with battery emulated, current loop
// Power Flow Sec -> Prim
// 6 -> Open loop check for PWM driver,
// 7 -> Open loop check for PWM driver with protection,
// 8 -> Closed loop voltage with resistive load
//

#define MULT_CLLC_LAB 3

#if MULT_CLLC_LAB == 1
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_DISABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
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
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_CURRENT_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_EMULATED_BATTERY
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif

#if MULT_CLLC_LAB == 6
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_DISABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 7
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 8
#define MULT_CLLC_CONTROL_RUNNING_ON 1
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_TEST_SETUP MULT_CLLC_TEST_SETUP_RES_LOAD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif

#endif // MULT_CLLC_USER_SETTINGS_H
