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
// GPIO37 - GPIO Settings
//
#define FAN1_GPIO_PIN_CONFIG GPIO_37_GPIO37
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
// SCIB -> mySCI0 Pinmux
//
//
// SCIB_RX - GPIO Settings
//
#define GPIO_PIN_SCIB_RX 57
#define mySCI0_SCIRX_GPIO 57
#define mySCI0_SCIRX_PIN_CONFIG GPIO_57_SCIB_RX
//
// SCIB_TX - GPIO Settings
//
#define GPIO_PIN_SCIB_TX 56
#define mySCI0_SCITX_GPIO 56
#define mySCI0_SCITX_PIN_CONFIG GPIO_56_SCIB_TX

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define M_ADC_A_BASE ADCA_BASE
#define M_ADC_A_RESULT_BASE ADCARESULT_BASE
#define M_ADC_A_SOC0 ADC_SOC_NUMBER0
#define M_ADC_A_FORCE_SOC0 ADC_FORCE_SOC0
#define M_ADC_A_SAMPLE_WINDOW_SOC0 100
#define M_ADC_A_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_SW_ONLY
#define M_ADC_A_CHANNEL_SOC0 ADC_CH_ADCIN2
#define M_ADC_A_SOC1 ADC_SOC_NUMBER1
#define M_ADC_A_FORCE_SOC1 ADC_FORCE_SOC1
#define M_ADC_A_SAMPLE_WINDOW_SOC1 100
#define M_ADC_A_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_A_CHANNEL_SOC1 ADC_CH_ADCIN3
#define M_ADC_A_SOC2 ADC_SOC_NUMBER2
#define M_ADC_A_FORCE_SOC2 ADC_FORCE_SOC2
#define M_ADC_A_SAMPLE_WINDOW_SOC2 100
#define M_ADC_A_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_A_CHANNEL_SOC2 ADC_CH_ADCIN4
void M_ADC_A_init();

#define M_ADC_B_BASE ADCB_BASE
#define M_ADC_B_RESULT_BASE ADCBRESULT_BASE
#define M_ADC_B_SOC0 ADC_SOC_NUMBER0
#define M_ADC_B_FORCE_SOC0 ADC_FORCE_SOC0
#define M_ADC_B_SAMPLE_WINDOW_SOC0 100
#define M_ADC_B_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_B_CHANNEL_SOC0 ADC_CH_ADCIN0
#define M_ADC_B_SOC1 ADC_SOC_NUMBER1
#define M_ADC_B_FORCE_SOC1 ADC_FORCE_SOC1
#define M_ADC_B_SAMPLE_WINDOW_SOC1 100
#define M_ADC_B_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_SW_ONLY
#define M_ADC_B_CHANNEL_SOC1 ADC_CH_ADCIN1
#define M_ADC_B_SOC2 ADC_SOC_NUMBER2
#define M_ADC_B_FORCE_SOC2 ADC_FORCE_SOC2
#define M_ADC_B_SAMPLE_WINDOW_SOC2 100
#define M_ADC_B_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_SW_ONLY
#define M_ADC_B_CHANNEL_SOC2 ADC_CH_ADCIN2
#define M_ADC_B_SOC3 ADC_SOC_NUMBER3
#define M_ADC_B_FORCE_SOC3 ADC_FORCE_SOC3
#define M_ADC_B_SAMPLE_WINDOW_SOC3 100
#define M_ADC_B_TRIGGER_SOURCE_SOC3 ADC_TRIGGER_SW_ONLY
#define M_ADC_B_CHANNEL_SOC3 ADC_CH_ADCIN3
void M_ADC_B_init();

#define M_ADC_C_BASE ADCC_BASE
#define M_ADC_C_RESULT_BASE ADCCRESULT_BASE
#define M_ADC_C_SOC0 ADC_SOC_NUMBER0
#define M_ADC_C_FORCE_SOC0 ADC_FORCE_SOC0
#define M_ADC_C_SAMPLE_WINDOW_SOC0 500
#define M_ADC_C_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM3_SOCA
#define M_ADC_C_CHANNEL_SOC0 ADC_CH_ADCIN0
#define M_ADC_C_SOC1 ADC_SOC_NUMBER1
#define M_ADC_C_FORCE_SOC1 ADC_FORCE_SOC1
#define M_ADC_C_SAMPLE_WINDOW_SOC1 100
#define M_ADC_C_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_SW_ONLY
#define M_ADC_C_CHANNEL_SOC1 ADC_CH_ADCIN1
#define M_ADC_C_SOC2 ADC_SOC_NUMBER2
#define M_ADC_C_FORCE_SOC2 ADC_FORCE_SOC2
#define M_ADC_C_SAMPLE_WINDOW_SOC2 100
#define M_ADC_C_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_SW_ONLY
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
#define myECAP0_BASE ECAP1_BASE
#define myECAP0_SIGNAL_MUNIT_BASE ECAP1SIGNALMONITORING_BASE
void myECAP0_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define M_EPWM1_BASE EPWM1_BASE
#define M_EPWM1_TBPRD 500
#define M_EPWM1_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM1_TBPHS 0
#define M_EPWM1_CMPA 250
#define M_EPWM1_CMPB 250
#define M_EPWM1_CMPC 0
#define M_EPWM1_CMPD 0
#define M_EPWM1_DBRED 20
#define M_EPWM1_DBFED 20
#define M_EPWM1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM2_BASE EPWM2_BASE
#define M_EPWM2_TBPRD 500
#define M_EPWM2_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM2_TBPHS 0
#define M_EPWM2_CMPA 250
#define M_EPWM2_CMPB 250
#define M_EPWM2_CMPC 0
#define M_EPWM2_CMPD 0
#define M_EPWM2_DBRED 20
#define M_EPWM2_DBFED 20
#define M_EPWM2_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM2_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM3_BASE EPWM3_BASE
#define M_EPWM3_TBPRD 560
#define M_EPWM3_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM3_TBPHS 0
#define M_EPWM3_CMPA 10
#define M_EPWM3_CMPB 250
#define M_EPWM3_CMPC 0
#define M_EPWM3_CMPD 0
#define M_EPWM3_DBRED 80
#define M_EPWM3_DBFED 80
#define M_EPWM3_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM3_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM3_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define M_EPWM4_BASE EPWM4_BASE
#define M_EPWM4_TBPRD 560
#define M_EPWM4_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define M_EPWM4_TBPHS 0
#define M_EPWM4_CMPA 560
#define M_EPWM4_CMPB 250
#define M_EPWM4_CMPC 0
#define M_EPWM4_CMPD 0
#define M_EPWM4_DBRED 80
#define M_EPWM4_DBFED 80
#define M_EPWM4_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define M_EPWM4_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
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
#define FAN1 37
void FAN1_init();
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
#define myINPUTXBARINPUT0_SOURCE 23
#define myINPUTXBARINPUT0_INPUT XBAR_INPUT4
void myINPUTXBARINPUT0_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCPUTIMER0
#define INT_myCPUTIMER0 INT_TIMER0
#define INT_myCPUTIMER0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void ISR1(void);

// Interrupt Settings for INT_myCPUTIMER1
#define INT_myCPUTIMER1 INT_TIMER1
extern __interrupt void ISR2(void);

// Interrupt Settings for INT_myCPUTIMER2
#define INT_myCPUTIMER2 INT_TIMER2
extern __interrupt void ISR3(void);

// Interrupt Settings for INT_PRIM_ZCD1_XINT
#define INT_PRIM_ZCD1_XINT INT_XINT1
#define INT_PRIM_ZCD1_XINT_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void PZCD1_ISR(void);

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
void myPMBUS0_init();

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define mySCI0_BASE SCIB_BASE
#define mySCI0_BAUDRATE 115200
#define mySCI0_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCI0_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCI0_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define mySCI0_FIFO_TX_LVL SCI_FIFO_TX0
#define mySCI0_FIFO_RX_LVL SCI_FIFO_RX0
void mySCI0_init();

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
void	GPIO_init();
void	INPUTXBAR_init();
void	INTERRUPT_init();
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
