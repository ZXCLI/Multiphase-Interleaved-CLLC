#ifndef MULT_CLLC_USER_SETTINGS_H
#define MULT_CLLC_USER_SETTINGS_H


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
// 7 -> Closed loop voltage with resistive load, time shift control,
//

#define MULT_CLLC_LAB 2

#if MULT_CLLC_LAB == 1
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_DIR_FEEQ_CTRL
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_DISABLED
#define MULT_CLLC_SFRA_TYPE 0
// #define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2 

#endif

#if MULT_CLLC_LAB == 2
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_DIR_FEEQ_CTRL
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 3
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_DIR_FEEQ_CTRL
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif

#if MULT_CLLC_LAB == 4
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_TIME_SHIF_CTRL
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_PRIM_SEC
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_CURRENT_MODE
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif

#if MULT_CLLC_LAB == 5
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_DIR_FEEQ_CTRL
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_DISABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 6
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_DIR_FEEQ_CTRL
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_OPEN_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL2
#endif

#if MULT_CLLC_LAB == 7
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_TIME_SHIF_CTRL
#define MULT_CLLC_POWER_FLOW MULT_CLLC_POWER_FLOW_SEC_PRIM
#define MULT_CLLC_INCR_BUILD MULT_CLLC_CLOSED_LOOP_BUILD
#define MULT_CLLC_CONTROL_MODE MULT_CLLC_VOLTAGE_MODE
#define MULT_CLLC_PROTECTION MULT_CLLC_PROTECTION_ENABLED
#define MULT_CLLC_SFRA_TYPE 0
#define MULT_CLLC_SFRA_AMPLITUDE (float32_t) MULT_CLLC_SFRA_INJECTION_AMPLITUDE_LEVEL1
#endif


//DEBUG
#define DEBUG1_TRACE_IN GPIO_writePin(DEBUG1,1)
#define DEBUG1_TRACE_OUT GPIO_writePin(DEBUG1,0)

#define DEBUG2_TRACE_IN GPIO_writePin(DEBUG2,1)
#define DEBUG2_TRACE_OUT GPIO_writePin(DEBUG2,0)

//第一相
#define MULT_CLLC_PRIM_LEGA_PWM_BASE EPWM4_BASE
#define MULT_CLLC_PRIM_LEGB_PWM_BASE EPWM3_BASE
#define MULT_CLLC_SEC_LEGA_PWM_BASE EPWM2_BASE
#define MULT_CLLC_SEC_LEGB_PWM_BASE EPWM1_BASE

//第二相
#define MULT_CLLC_PRIM_LEGC_PWM_BASE EPWM7_BASE
#define MULT_CLLC_PRIM_LEGD_PWM_BASE EPWM8_BASE
#define MULT_CLLC_SEC_LEGC_PWM_BASE EPWM5_BASE
#define MULT_CLLC_SEC_LEGD_PWM_BASE EPWM6_BASE

#define USE_FAN_AUTO_CONTROL 0  //默认由算法控制风扇


//
// Signals mapped to ADC -A
//
#define MULT_CLLC_IPRIM_TANK_MAIN_ADC_MODULE ADCA_BASE
#define MULT_CLLC_IPRIM_TANK_MAIN_ADC_SOC_NO ADC_SOC_NUMBER0
#define MULT_CLLC_IPRIM_TANK_MAIN_ADCRESULTREGBASE ADCARESULT_BASE // A2-I_PRIM_TANK1

#define MULT_CLLC_ISEC_MAIN_ADC_MODULE  ADCA_BASE
#define MULT_CLLC_ISEC_MAIN_ADC_SOC_NO  ADC_SOC_NUMBER1
#define MULT_CLLC_ISEC_MAIN_ADCRESULTREGBASE ADCARESULT_BASE// A3-I_SEC1

#define MULT_CLLC_IPRIM_MAIN_ADC_MODULE  ADCA_BASE
#define MULT_CLLC_IPRIM_MAIN_ADC_SOC_NO  ADC_SOC_NUMBER2
#define MULT_CLLC_IPRIM_MAIN_ADCRESULTREGBASE ADCARESULT_BASE// A4-I_PRIM

#define MULT_CLLC_IPRIM_MAIN_ADCREAD ADC_readResult(MULT_CLLC_IPRIM_MAIN_ADCRESULTREGBASE, MULT_CLLC_IPRIM_MAIN_ADC_SOC_NO)
#define MULT_CLLC_ISEC_MAIN_ADCREAD ADC_readResult(MULT_CLLC_ISEC_MAIN_ADCRESULTREGBASE, MULT_CLLC_ISEC_MAIN_ADC_SOC_NO)
#define MULT_CLLC_IPRIM_TANK_MAIN_ADCREAD ADC_readResult(MULT_CLLC_IPRIM_TANK_MAIN_ADCRESULTREGBASE, MULT_CLLC_IPRIM_TANK_MAIN_ADC_SOC_NO)


//
// Signals mapped to ADC -B
//
#define MULT_CLLC_VPRIM_ADC_MODULE ADCB_BASE
#define MULT_CLLC_VPRIM_ADC_SOC_NO ADC_SOC_NUMBER0
#define MULT_CLLC_VPRIM_ADCRESULTREGBASE ADCBRESULT_BASE // B0-V_PRIM

#define MULT_CLLC_IPRIM_TANK_SECONDARY_ADC_MODULE ADCB_BASE
#define MULT_CLLC_IPRIM_TANK_SECONDARY_ADC_SOC_NO ADC_SOC_NUMBER1
#define MULT_CLLC_IPRIM_TANK_SECONDARY_ADCRESULTREGBASE ADCBRESULT_BASE // B1-I_PRIM_TANK2

#define MULT_CLLC_ISEC_TANK_MAIN_ADC_MODULE ADCB_BASE
#define MULT_CLLC_ISEC_TANK_MAIN_ADC_SOC_NO ADC_SOC_NUMBER2
#define MULT_CLLC_ISEC_TANK_MAIN_ADCRESULTREGBASE ADCBRESULT_BASE // B2-I_SEC_TANK1

#define MULT_CLLC_IPRIM_SECONDARY_ADC_MODULE ADCB_BASE
#define MULT_CLLC_IPRIM_SECONDARY_ADC_SOC_NO ADC_SOC_NUMBER3
#define MULT_CLLC_IPRIM_SECONDARY_ADCRESULTREGBASE ADCBRESULT_BASE // B3-I_PRIM_TANK2

#define MULT_CLLC_VPRIM_ADCREAD ADC_readResult(MULT_CLLC_VPRIM_ADCRESULTREGBASE, MULT_CLLC_VPRIM_ADC_SOC_NO)
#define MULT_CLLC_IPRIM_TANK_SECONDARY_ADCREAD ADC_readResult(MULT_CLLC_IPRIM_TANK_SECONDARY_ADCRESULTREGBASE, MULT_CLLC_IPRIM_TANK_SECONDARY_ADC_SOC_NO)
#define MULT_CLLC_ISEC_TANK_MAIN_ADCREAD ADC_readResult(MULT_CLLC_ISEC_TANK_MAIN_ADCRESULTREGBASE, MULT_CLLC_ISEC_TANK_MAIN_ADC_SOC_NO)
#define MULT_CLLC_IPRIM_SECONDARY_ADCREAD ADC_readResult(MULT_CLLC_IPRIM_SECONDARY_ADCRESULTREGBASE, MULT_CLLC_IPRIM_SECONDARY_ADC_SOC_NO)

//
// Signals mapped to ADC -C
//
#define MULT_CLLC_VSEC_ADC_MODULE ADCC_BASE
#define MULT_CLLC_VSEC_ADC_SOC_NO ADC_SOC_NUMBER0
#define MULT_CLLC_VSEC_ADCRESULTREGBASE ADCCRESULT_BASE // C0-V_SEC

#define MULT_CLLC_ISEC_TANK_SECONDARY_ADC_MODULE ADCC_BASE
#define MULT_CLLC_ISEC_TANK_SECONDARY_ADC_SOC_NO ADC_SOC_NUMBER1
#define MULT_CLLC_ISEC_TANK_SECONDARY_ADCRESULTREGBASE ADCCRESULT_BASE // C1-I_SEC_TANK2

#define MULT_CLLC_ISEC_SECONDARY_ADC_MODULE ADCC_BASE
#define MULT_CLLC_ISEC_SECONDARY_ADC_SOC_NO ADC_SOC_NUMBER2
#define MULT_CLLC_ISEC_SECONDARY_ADCRESULTREGBASE ADCCRESULT_BASE // C2-I_SEC2

#define MULT_CLLC_VSEC_ADCREAD ADC_readResult(MULT_CLLC_VSEC_ADCRESULTREGBASE, MULT_CLLC_VSEC_ADC_SOC_NO)
#define MULT_CLLC_ISEC_TANK_SECONDARY_ADCREAD ADC_readResult(MULT_CLLC_ISEC_TANK_SECONDARY_ADCRESULTREGBASE, MULT_CLLC_ISEC_TANK_SECONDARY_ADC_SOC_NO)
#define MULT_CLLC_ISEC_SECONDARY_ADCREAD ADC_readResult(MULT_CLLC_ISEC_SECONDARY_ADCRESULTREGBASE, MULT_CLLC_ISEC_SECONDARY_ADC_SOC_NO)

//
// 中断频率定义
//
// #define MULT_CLLC_ISR1_FREQUENCY_HZ  ((float32_t)10000)
// #define MULT_CLLC_ISR2_FREQUENCY_HZ  ((float32_t)10000)
#define MULT_CLLC_ISR2_FREQUENCY_HZ ((float32_t)89000)

//
//CPU time related
//
#define MULT_CLLC_TASKC_CPUTIMER_BASE CPUTIMER0_BASE
#define MULT_CLLC_TASKA_CPUTIMER_BASE CPUTIMER1_BASE
#define MULT_CLLC_TASKB_CPUTIMER_BASE CPUTIMER2_BASE

#define MULT_CLLC_TASKA_FREQ_HZ 1000
#define MULT_CLLC_TASKB_FREQ_HZ 100
#define MULT_CLLC_TASKC_FREQ_HZ MULT_CLLC_ISR2_FREQUENCY_HZ

#define MULT_CLLC_GET_TASKA_TIMER_OVERFLOW_STATUS CPUTimer_getTimerOverflowStatus(MULT_CLLC_TASKA_CPUTIMER_BASE)
#define MULT_CLLC_CLEAR_TASKA_TIMER_OVERFLOW_FLAG CPUTimer_clearOverflowFlag(MULT_CLLC_TASKA_CPUTIMER_BASE)

#define MULT_CLLC_GET_TASKB_TIMER_OVERFLOW_STATUS CPUTimer_getTimerOverflowStatus(MULT_CLLC_TASKB_CPUTIMER_BASE)
#define MULT_CLLC_CLEAR_TASKB_TIMER_OVERFLOW_FLAG CPUTimer_clearOverflowFlag(MULT_CLLC_TASKB_CPUTIMER_BASE)


#endif // MULT_CLLC_USER_SETTINGS_H
