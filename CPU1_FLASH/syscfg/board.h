/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> M_EPWM1 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define M_EPWM1_EPWMA_GPIO 0
#define M_EPWM1_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define M_EPWM1_EPWMB_GPIO 1
#define M_EPWM1_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B

//
// EPWM2 -> M_EPWM2 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define M_EPWM2_EPWMA_GPIO 2
#define M_EPWM2_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define M_EPWM2_EPWMB_GPIO 3
#define M_EPWM2_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B

//
// EPWM3 -> M_EPWM3 Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 4
#define M_EPWM3_EPWMA_GPIO 4
#define M_EPWM3_EPWMA_PIN_CONFIG GPIO_4_EPWM3_A
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 5
#define M_EPWM3_EPWMB_GPIO 5
#define M_EPWM3_EPWMB_PIN_CONFIG GPIO_5_EPWM3_B

//
// EPWM4 -> M_EPWM4 Pinmux
//
//
// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 6
#define M_EPWM4_EPWMA_GPIO 6
#define M_EPWM4_EPWMA_PIN_CONFIG GPIO_6_EPWM4_A
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 7
#define M_EPWM4_EPWMB_GPIO 7
#define M_EPWM4_EPWMB_PIN_CONFIG GPIO_7_EPWM4_B

//
// EPWM5 -> M_EPWM5 Pinmux
//
//
// EPWM5_A - GPIO Settings
//
#define GPIO_PIN_EPWM5_A 8
#define M_EPWM5_EPWMA_GPIO 8
#define M_EPWM5_EPWMA_PIN_CONFIG GPIO_8_EPWM5_A
//
// EPWM5_B - GPIO Settings
//
#define GPIO_PIN_EPWM5_B 9
#define M_EPWM5_EPWMB_GPIO 9
#define M_EPWM5_EPWMB_PIN_CONFIG GPIO_9_EPWM5_B

//
// EPWM6 -> M_EPWM6 Pinmux
//
//
// EPWM6_A - GPIO Settings
//
#define GPIO_PIN_EPWM6_A 10
#define M_EPWM6_EPWMA_GPIO 10
#define M_EPWM6_EPWMA_PIN_CONFIG GPIO_10_EPWM6_A
//
// EPWM6_B - GPIO Settings
//
#define GPIO_PIN_EPWM6_B 11
#define M_EPWM6_EPWMB_GPIO 11
#define M_EPWM6_EPWMB_PIN_CONFIG GPIO_11_EPWM6_B

//
// EPWM7 -> M_EPWM7 Pinmux
//
//
// EPWM7_A - GPIO Settings
//
#define GPIO_PIN_EPWM7_A 12
#define M_EPWM7_EPWMA_GPIO 12
#define M_EPWM7_EPWMA_PIN_CONFIG GPIO_12_EPWM7_A
//
// EPWM7_B - GPIO Settings
//
#define GPIO_PIN_EPWM7_B 13
#define M_EPWM7_EPWMB_GPIO 13
#define M_EPWM7_EPWMB_PIN_CONFIG GPIO_13_EPWM7_B

//
// EPWM8 -> M_EPWM8 Pinmux
//
//
// EPWM8_A - GPIO Settings
//
#define GPIO_PIN_EPWM8_A 14
#define M_EPWM8_EPWMA_GPIO 14
#define M_EPWM8_EPWMA_PIN_CONFIG GPIO_14_EPWM8_A
//
// EPWM8_B - GPIO Settings
//
#define GPIO_PIN_EPWM8_B 15
#define M_EPWM8_EPWMB_GPIO 15
#define M_EPWM8_EPWMB_PIN_CONFIG GPIO_15_EPWM8_B
//
// GPIO28 - GPIO Settings
//
#define FAULT_INPUT1_GPIO_PIN_CONFIG GPIO_28_GPIO28
//
// GPIO29 - GPIO Settings
//
#define FAULT_INPUT2_GPIO_PIN_CONFIG GPIO_29_GPIO29
//
// GPIO31 - GPIO Settings
//
#define FAULT_OUTPUT_GPIO_PIN_CONFIG GPIO_31_GPIO31
//
// GPIO30 - GPIO Settings
//
#define DEBUG1_GPIO_PIN_CONFIG GPIO_30_GPIO30
//
// GPIO34 - GPIO Settings
//
#define ACTIVE1_GPIO_PIN_CONFIG GPIO_34_GPIO34
//
// GPIO59 - GPIO Settings
//
#define ACTIVE2_GPIO_PIN_CONFIG GPIO_59_GPIO59
//
// GPIO39 - GPIO Settings
//
#define STATUS1_GPIO_PIN_CONFIG GPIO_39_GPIO39
//
// GPIO40 - GPIO Settings
//
#define STATUS2_GPIO_PIN_CONFIG GPIO_40_GPIO40
//
// GPIO23 - GPIO Settings
//
#define PRIM_ZCD1_GPIO_PIN_CONFIG GPIO_23_GPIO23
//
// GPIO22 - GPIO Settings
//
#define PRIM_ZCD2_GPIO_PIN_CONFIG GPIO_22_GPIO22
//
// GPIO58 - GPIO Settings
//
#define DEBUG2_GPIO_PIN_CONFIG GPIO_58_GPIO58
//
// GPIO35 - GPIO Settings
//
#define FAN2_GPIO_PIN_CONFIG GPIO_35_GPIO35
//
// GPIO33 - GPIO Settings
//
#define SEC_ZCD1_GPIO_PIN_CONFIG GPIO_33_GPIO33
//
// GPIO17 - GPIO Settings
//
#define SEC_ZCD2_GPIO_PIN_CONFIG GPIO_17_GPIO17

//
// OUTPUTXBAR1 -> FAN1 Pinmux
//
//
// OUTPUTXBAR1 - GPIO Settings
//
#define GPIO_PIN_OUTPUTXBAR1 24
#define FAN1_OUTPUTXBAR_GPIO 24
#define FAN1_OUTPUTXBAR_PIN_CONFIG GPIO_24_OUTPUTXBAR1

//
// OUTPUTXBAR2 -> CMPSS1OUT0 Pinmux
//
//
// OUTPUTXBAR2 - GPIO Settings
//
#define GPIO_PIN_OUTPUTXBAR2 37
#define CMPSS1OUT0_OUTPUTXBAR_GPIO 37
#define CMPSS1OUT0_OUTPUTXBAR_PIN_CONFIG GPIO_37_OUTPUTXBAR2

//
// PMBUSA -> myPMBUS0 Pinmux
//
//
// PMBUSA_ALERT - GPIO Settings
//
#define GPIO_PIN_PMBUSA_ALERT 27
#define myPMBUS0_PMBUSALERT_GPIO 27
#define myPMBUS0_PMBUSALERT_PIN_CONFIG GPIO_27_PMBUSA_ALERT
//
// PMBUSA_CTL - GPIO Settings
//
#define GPIO_PIN_PMBUSA_CTL 26
#define myPMBUS0_PMBUSCTL_GPIO 26
#define myPMBUS0_PMBUSCTL_PIN_CONFIG GPIO_26_PMBUSA_CTL
//
// PMBUSA_SCL - GPIO Settings
//
#define GPIO_PIN_PMBUSA_SCL 16
#define myPMBUS0_PMBUSSCL_GPIO 16
#define myPMBUS0_PMBUSSCL_PIN_CONFIG GPIO_16_PMBUSA_SCL
//
// PMBUSA_SDA - GPIO Settings
//
#define GPIO_PIN_PMBUSA_SDA 25
#define myPMBUS0_PMBUSSDA_GPIO 25
#define myPMBUS0_PMBUSSDA_PIN_CONFIG GPIO_25_PMBUSA_SDA

//
// SCIB -> DEBUG Pinmux
//
//
// SCIB_RX - GPIO Settings
//
#define GPIO_PIN_SCIB_RX 57
#define DEBUG_SCIRX_GPIO 57
#define DEBUG_SCIRX_PIN_CONFIG GPIO_57_SCIB_RX
//
// SCIB_TX - GPIO Settings
//
#define GPIO_PIN_SCIB_TX 56
#define DEBUG_SCITX_GPIO 56
#define DEBUG_SCITX_PIN_CONFIG GPIO_56_SCIB_TX

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define M_ADC_A_BASE ADCA_BASE
#define M_ADC_A_RESULT_BASE ADCARESULT_BASE
#define M_ADC_A_SOC0 ADC_SOC_NUMBER0
#define M_ADC_A_FORCE_SOC0 ADC_FORCE_SOC0
#define M_ADC_A_SAMPLE_WINDOW_SOC0 300
#define M_ADC_A_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_SW_ONLY
#define M_ADC_A_CHANNEL_SOC0 ADC_CH_ADCIN2
#define M_ADC_A_SOC1 ADC_SOC_NUMBER1
#define M_ADC_A_FORCE_SOC1 ADC_FORCE_SOC1
#define M_ADC_A_SAMPLE_WINDOW_SOC1 300
#define M_ADC_A_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_A_CHANNEL_SOC1 ADC_CH_ADCIN3
#define M_ADC_A_SOC2 ADC_SOC_NUMBER2
#define M_ADC_A_FORCE_SOC2 ADC_FORCE_SOC2
#define M_ADC_A_SAMPLE_WINDOW_SOC2 300
#define M_ADC_A_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_A_CHANNEL_SOC2 ADC_CH_ADCIN4
void M_ADC_A_init();

#define M_ADC_B_BASE ADCB_BASE
#define M_ADC_B_RESULT_BASE ADCBRESULT_BASE
#define M_ADC_B_SOC0 ADC_SOC_NUMBER0
#define M_ADC_B_FORCE_SOC0 ADC_FORCE_SOC0
#define M_ADC_B_SAMPLE_WINDOW_SOC0 300
#define M_ADC_B_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_B_CHANNEL_SOC0 ADC_CH_ADCIN0
#define M_ADC_B_SOC1 ADC_SOC_NUMBER1
#define M_ADC_B_FORCE_SOC1 ADC_FORCE_SOC1
#define M_ADC_B_SAMPLE_WINDOW_SOC1 300
#define M_ADC_B_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_SW_ONLY
#define M_ADC_B_CHANNEL_SOC1 ADC_CH_ADCIN1
#define M_ADC_B_SOC2 ADC_SOC_NUMBER2
#define M_ADC_B_FORCE_SOC2 ADC_FORCE_SOC2
#define M_ADC_B_SAMPLE_WINDOW_SOC2 300
#define M_ADC_B_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_SW_ONLY
#define M_ADC_B_CHANNEL_SOC2 ADC_CH_ADCIN2
#define M_ADC_B_SOC3 ADC_SOC_NUMBER3
#define M_ADC_B_FORCE_SOC3 ADC_FORCE_SOC3
#define M_ADC_B_SAMPLE_WINDOW_SOC3 300
#define M_ADC_B_TRIGGER_SOURCE_SOC3 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_B_CHANNEL_SOC3 ADC_CH_ADCIN3
void M_ADC_B_init();

#define M_ADC_C_BASE ADCC_BASE
#define M_ADC_C_RESULT_BASE ADCCRESULT_BASE
#define M_ADC_C_SOC0 ADC_SOC_NUMBER0
#define M_ADC_C_FORCE_SOC0 ADC_FORCE_SOC0
#define M_ADC_C_SAMPLE_WINDOW_SOC0 300
#define M_ADC_C_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_C_CHANNEL_SOC0 ADC_CH_ADCIN0
#define M_ADC_C_SOC1 ADC_SOC_NUMBER1
#define M_ADC_C_FORCE_SOC1 ADC_FORCE_SOC1
#define M_ADC_C_SAMPLE_WINDOW_SOC1 300
#define M_ADC_C_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_SW_ONLY
#define M_ADC_C_CHANNEL_SOC1 ADC_CH_ADCIN1
#define M_ADC_C_SOC2 ADC_SOC_NUMBER2
#define M_ADC_C_FORCE_SOC2 ADC_FORCE_SOC2
#define M_ADC_C_SAMPLE_WINDOW_SOC2 300
#define M_ADC_C_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_C_CHANNEL_SOC2 ADC_CH_ADCIN2
void M_ADC_C_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
#define M_CMPSS1_BASE CMPSS1_BASE
#define M_CMPSS1_HIGH_COMP_BASE CMPSS1_BASE    
#define M_CMPSS1_LOW_COMP_BASE CMPSS1_BASE    
void M_CMPSS1_init();
#define M_CMPSS2_BASE CMPSS2_BASE
#define M_CMPSS2_HIGH_COMP_BASE CMPSS2_BASE    
#define M_CMPSS2_LOW_COMP_BASE CMPSS2_BASE    
void M_CMPSS2_init();
#define M_CMPSS3_BASE CMPSS3_BASE
#define M_CMPSS3_HIGH_COMP_BASE CMPSS3_BASE    
#define M_CMPSS3_LOW_COMP_BASE CMPSS3_BASE    
void M_CMPSS3_init();
#define M_CMPSS4_BASE CMPSS7_BASE
#define M_CMPSS4_HIGH_COMP_BASE CMPSS7_BASE    
#define M_CMPSS4_LOW_COMP_BASE CMPSS7_BASE    
void M_CMPSS4_init();

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();
#define myCPUTIMER1_BASE CPUTIMER1_BASE
void myCPUTIMER1_init();
#define myCPUTIMER2_BASE CPUTIMER2_BASE
void myCPUTIMER2_init();

//*****************************************************************************
//
// DAC Configurations
//
//*****************************************************************************
#define myDAC0_BASE DACA_BASE
void myDAC0_init();
#define myDAC1_BASE DACB_BASE
void myDAC1_init();

//*****************************************************************************
//
// ECAP Configurations
//
//*****************************************************************************
#define FAN_PWM_BASE ECAP1_BASE
#define FAN_PWM_SIGNAL_MUNIT_BASE ECAP1SIGNALMONITORING_BASE
void FAN_PWM_init();
#define EPWM3A_ECAP_BASE ECAP6_BASE
#define EPWM3A_ECAP_SIGNAL_MUNIT_BASE ECAP6SIGNALMONITORING_BASE
void EPWM3A_ECAP_init();
#define EPWM1A_ECAP_BASE ECAP7_BASE
#define EPWM1A_ECAP_SIGNAL_MUNIT_BASE ECAP7SIGNALMONITORING_BASE
void EPWM1A_ECAP_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define M_EPWM1_BASE EPWM1_BASE
#define M_EPWM1_TBPRD 1120
#define M_EPWM1_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM1_TBPHS 0
#define M_EPWM1_CMPA 560
#define M_EPWM1_CMPB 250
#define M_EPWM1_CMPC 0
#define M_EPWM1_CMPD 0
#define M_EPWM1_DBRED 20
#define M_EPWM1_DBFED 20
#define M_EPWM1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM2_BASE EPWM2_BASE
#define M_EPWM2_TBPRD 1120
#define M_EPWM2_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM2_TBPHS 0
#define M_EPWM2_CMPA 560
#define M_EPWM2_CMPB 560
#define M_EPWM2_CMPC 0
#define M_EPWM2_CMPD 0
#define M_EPWM2_DBRED 20
#define M_EPWM2_DBFED 20
#define M_EPWM2_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM2_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM3_BASE EPWM3_BASE
#define M_EPWM3_TBPRD 1120
#define M_EPWM3_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM3_TBPHS 0
#define M_EPWM3_CMPA 560
#define M_EPWM3_CMPB 250
#define M_EPWM3_CMPC 448
#define M_EPWM3_CMPD 0
#define M_EPWM3_DBRED 80
#define M_EPWM3_DBFED 80
#define M_EPWM3_TZA_ACTION EPWM_TZ_ACTION_LOW
#define M_EPWM3_TZB_ACTION EPWM_TZ_ACTION_LOW
#define M_EPWM3_CBC_SOURCES EPWM_TZ_SIGNAL_DCAEVT2
#define M_EPWM3_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM4_BASE EPWM4_BASE
#define M_EPWM4_TBPRD 1120
#define M_EPWM4_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM4_TBPHS 0
#define M_EPWM4_CMPA 560
#define M_EPWM4_CMPB 250
#define M_EPWM4_CMPC 0
#define M_EPWM4_CMPD 0
#define M_EPWM4_DBRED 80
#define M_EPWM4_DBFED 80
#define M_EPWM4_TZA_ACTION EPWM_TZ_ACTION_LOW
#define M_EPWM4_TZB_ACTION EPWM_TZ_ACTION_LOW
#define M_EPWM4_CBC_SOURCES EPWM_TZ_SIGNAL_DCAEVT2
#define M_EPWM4_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM5_BASE EPWM5_BASE
#define M_EPWM5_TBPRD 500
#define M_EPWM5_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM5_TBPHS 0
#define M_EPWM5_CMPA 250
#define M_EPWM5_CMPB 250
#define M_EPWM5_CMPC 0
#define M_EPWM5_CMPD 0
#define M_EPWM5_DBRED 20
#define M_EPWM5_DBFED 20
#define M_EPWM5_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM5_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM5_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM6_BASE EPWM6_BASE
#define M_EPWM6_TBPRD 500
#define M_EPWM6_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM6_TBPHS 0
#define M_EPWM6_CMPA 250
#define M_EPWM6_CMPB 250
#define M_EPWM6_CMPC 0
#define M_EPWM6_CMPD 0
#define M_EPWM6_DBRED 20
#define M_EPWM6_DBFED 20
#define M_EPWM6_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM6_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM6_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM7_BASE EPWM7_BASE
#define M_EPWM7_TBPRD 500
#define M_EPWM7_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM7_TBPHS 0
#define M_EPWM7_CMPA 250
#define M_EPWM7_CMPB 250
#define M_EPWM7_CMPC 0
#define M_EPWM7_CMPD 0
#define M_EPWM7_DBRED 20
#define M_EPWM7_DBFED 20
#define M_EPWM7_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM7_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM7_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM8_BASE EPWM8_BASE
#define M_EPWM8_TBPRD 500
#define M_EPWM8_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM8_TBPHS 0
#define M_EPWM8_CMPA 250
#define M_EPWM8_CMPB 250
#define M_EPWM8_CMPC 0
#define M_EPWM8_CMPD 0
#define M_EPWM8_DBRED 20
#define M_EPWM8_DBFED 20
#define M_EPWM8_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM8_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM8_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void CMPSS2OUT_init();
#define CMPSS2OUT XBAR_TRIP5
#define CMPSS2OUT_ENABLED_MUXES (XBAR_MUX02)
void CMPSS3OUT_init();
#define CMPSS3OUT XBAR_TRIP7
#define CMPSS3OUT_ENABLED_MUXES (XBAR_MUX04)
void CMPSS7OUT_init();
#define CMPSS7OUT XBAR_TRIP8
#define CMPSS7OUT_ENABLED_MUXES (XBAR_MUX12)
void CLB1H_init();
#define CLB1H XBAR_TRIP9
#define CLB1H_ENABLED_MUXES (XBAR_MUX01)
void CLB1L_init();
#define CLB1L XBAR_TRIP10
#define CLB1L_ENABLED_MUXES (XBAR_MUX03)
void CLB2H_init();
#define CLB2H XBAR_TRIP11
#define CLB2H_ENABLED_MUXES (XBAR_MUX05)
void CLB2L_init();
#define CLB2L XBAR_TRIP12
#define CLB2L_ENABLED_MUXES (XBAR_MUX07)
void CMPSS1OUT_init();
#define CMPSS1OUT XBAR_TRIP4
#define CMPSS1OUT_ENABLED_MUXES (XBAR_MUX00)

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define FAULT_INPUT1 28
void FAULT_INPUT1_init();
#define FAULT_INPUT2 29
void FAULT_INPUT2_init();
#define FAULT_OUTPUT 31
void FAULT_OUTPUT_init();
#define DEBUG1 30
void DEBUG1_init();
#define ACTIVE1 34
void ACTIVE1_init();
#define ACTIVE2 59
void ACTIVE2_init();
#define STATUS1 39
void STATUS1_init();
#define STATUS2 40
void STATUS2_init();
#define PRIM_ZCD1 23
void PRIM_ZCD1_init();
#define PRIM_ZCD2 22
void PRIM_ZCD2_init();
#define DEBUG2 58
void DEBUG2_init();
#define FAN2 35
void FAN2_init();
#define SEC_ZCD1 33
void SEC_ZCD1_init();
#define SEC_ZCD2 17
void SEC_ZCD2_init();

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
#define PZCD1_SOURCE 23
#define PZCD1_INPUT XBAR_INPUT4
void PZCD1_init();
#define TZ1_SOURCE 28
#define TZ1_INPUT XBAR_INPUT1
void TZ1_init();
#define TZ2_SOURCE 29
#define TZ2_INPUT XBAR_INPUT2
void TZ2_init();
#define EPWM3_CAP_SOURCE 4
#define EPWM3_CAP_INPUT XBAR_INPUT6
void EPWM3_CAP_init();
#define EPWM1_CAP_SOURCE 0
#define EPWM1_CAP_INPUT XBAR_INPUT7
void EPWM1_CAP_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCPUTIMER0
// ISR need to be defined for the registered interrupts
#define INT_myCPUTIMER0 INT_TIMER0
#define INT_myCPUTIMER0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void ISR2_TIMER0(void);

// Interrupt Settings for INT_PRIM_ZCD1_XINT
// ISR need to be defined for the registered interrupts
#define INT_PRIM_ZCD1_XINT INT_XINT1
#define INT_PRIM_ZCD1_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void ISR1_PZCD(void);

//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void FAN1_init();
#define FAN1 XBAR_OUTPUT1
#define FAN1_ENABLED_MUXES (XBAR_MUX00)
void CMPSS1OUT0_init();
#define CMPSS1OUT0 XBAR_OUTPUT2
#define CMPSS1OUT0_ENABLED_MUXES (XBAR_MUX00)

//*****************************************************************************
//
// PMBUS Configurations
//
//*****************************************************************************
#define myPMBUS0_BASE PMBUSA_BASE
#define myPMBUS0_BAUDRATE 10000000
#define myPMBUS0_TARGET_ADDRESS 106
#define myPMBUS0_TARGET_ADDRESS_MASK 127
#define myPMBUS0_OWN_ADDRESS 26
#define myPMBUS0_ENABLE_I2C_MODE false
#define myPMBUS0_CLOCKMODE PMBUS_CLOCKMODE_STANDARD
#define myPMBUS0_GPIO_MAP(gpioNumber, enumValue) do { \
	switch((gpioNumber)) { \
		case 2: 	(enumValue) = 0; break; \
		case 3: 	(enumValue) = 1; break; \
		case 9: 	(enumValue) = 2; break; \
		case 32: 	(enumValue) = 3; break; \
	} \
}while(0)

void myPMBUS0_init();

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define DEBUG_BASE SCIB_BASE
#define DEBUG_BAUDRATE 115200
#define DEBUG_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define DEBUG_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define DEBUG_CONFIG_PAR SCI_CONFIG_PAR_NONE
void DEBUG_init();

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
#define PRIM_ZCD1_XINT GPIO_INT_XINT1
#define PRIM_ZCD1_XINT_TYPE GPIO_INT_TYPE_BOTH_EDGES
void PRIM_ZCD1_XINT_init();

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CMPSS_init();
void	CPUTIMER_init();
void	DAC_init();
void	ECAP_init();
void	EPWM_init();
void	EPWMXBAR_init();
void	GPIO_init();
void	INPUTXBAR_init();
void	INTERRUPT_init();
void	OUTPUTXBAR_init();
void	PMBUS_init();
void	SCI_init();
void	SYNC_init();
void	XINT_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
