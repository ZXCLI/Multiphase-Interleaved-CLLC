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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	INPUTXBAR_init();
	SYNC_init();
	ASYSCTL_init();
	ADC_init();
	CMPSS_init();
	CPUTIMER_init();
	DAC_init();
	ECAP_init();
	EPWM_init();
	EPWMXBAR_init();
	GPIO_init();
	OUTPUTXBAR_init();
	PMBUS_init();
	SCI_init();
	XINT_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// EPWM1 -> M_EPWM1 Pinmux
	//
	GPIO_setPinConfig(M_EPWM1_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM1_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM1_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM1_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM1_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM1_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM2 -> M_EPWM2 Pinmux
	//
	GPIO_setPinConfig(M_EPWM2_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM2_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM2_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM2_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM2_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM2_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM3 -> M_EPWM3 Pinmux
	//
	GPIO_setPinConfig(M_EPWM3_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM3_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM3_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM3_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM3_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM3_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM4 -> M_EPWM4 Pinmux
	//
	GPIO_setPinConfig(M_EPWM4_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM4_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM4_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM4_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM4_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM4_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM5 -> M_EPWM5 Pinmux
	//
	GPIO_setPinConfig(M_EPWM5_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM5_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM5_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM5_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM5_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM5_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM6 -> M_EPWM6 Pinmux
	//
	GPIO_setPinConfig(M_EPWM6_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM6_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM6_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM6_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM6_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM6_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM7 -> M_EPWM7 Pinmux
	//
	GPIO_setPinConfig(M_EPWM7_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM7_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM7_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM7_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM7_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM7_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM8 -> M_EPWM8 Pinmux
	//
	GPIO_setPinConfig(M_EPWM8_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM8_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM8_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(M_EPWM8_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(M_EPWM8_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(M_EPWM8_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// GPIO28 -> FAULT_INPUT1 Pinmux
	GPIO_setPinConfig(GPIO_28_GPIO28);
	// GPIO29 -> FAULT_INPUT2 Pinmux
	GPIO_setPinConfig(GPIO_29_GPIO29);
	// GPIO31 -> FAULT_OUTPUT Pinmux
	GPIO_setPinConfig(GPIO_31_GPIO31);
	// GPIO30 -> DEBUG1 Pinmux
	GPIO_setPinConfig(GPIO_30_GPIO30);
	// GPIO34 -> ACTIVE1 Pinmux
	GPIO_setPinConfig(GPIO_34_GPIO34);
	// GPIO59 -> ACTIVE2 Pinmux
	GPIO_setPinConfig(GPIO_59_GPIO59);
	// GPIO39 -> STATUS1 Pinmux
	GPIO_setPinConfig(GPIO_39_GPIO39);
	// GPIO40 -> STATUS2 Pinmux
	GPIO_setPinConfig(GPIO_40_GPIO40);
	// GPIO23_VSW -> PRIM_ZCD1 Pinmux
	GPIO_setPinConfig(GPIO_23_GPIO23);
	// GPIO22_VFBSW -> PRIM_ZCD2 Pinmux
	GPIO_setPinConfig(GPIO_22_GPIO22);
	// GPIO58 -> DEBUG2 Pinmux
	GPIO_setPinConfig(GPIO_58_GPIO58);
	// GPIO35/TDI -> FAN2 Pinmux
	GPIO_setPinConfig(GPIO_35_GPIO35);
	// GPIO33 -> SEC_ZCD1 Pinmux
	GPIO_setPinConfig(GPIO_33_GPIO33);
	// GPIO17 -> SEC_ZCD2 Pinmux
	GPIO_setPinConfig(GPIO_17_GPIO17);
	//
	// OUTPUTXBAR1 -> FAN1 Pinmux
	//
	GPIO_setPinConfig(FAN1_OUTPUTXBAR_PIN_CONFIG);
	//
	// OUTPUTXBAR2 -> CMPSS1OUT0 Pinmux
	//
	GPIO_setPinConfig(CMPSS1OUT0_OUTPUTXBAR_PIN_CONFIG);
	//
	// PMBUSA -> myPMBUS0 Pinmux
	//
	GPIO_setPinConfig(myPMBUS0_PMBUSALERT_PIN_CONFIG);
	GPIO_setPadConfig(myPMBUS0_PMBUSALERT_GPIO, GPIO_PIN_TYPE_OD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(myPMBUS0_PMBUSALERT_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(myPMBUS0_PMBUSCTL_PIN_CONFIG);
	GPIO_setPadConfig(myPMBUS0_PMBUSCTL_GPIO, GPIO_PIN_TYPE_OD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(myPMBUS0_PMBUSCTL_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(myPMBUS0_PMBUSSCL_PIN_CONFIG);
	GPIO_setPadConfig(myPMBUS0_PMBUSSCL_GPIO, GPIO_PIN_TYPE_OD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(myPMBUS0_PMBUSSCL_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(myPMBUS0_PMBUSSDA_PIN_CONFIG);
	GPIO_setPadConfig(myPMBUS0_PMBUSSDA_GPIO, GPIO_PIN_TYPE_OD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(myPMBUS0_PMBUSSDA_GPIO, GPIO_QUAL_ASYNC);

	//
	// SCIB -> DEBUG Pinmux
	//
	GPIO_setPinConfig(DEBUG_SCIRX_PIN_CONFIG);
	GPIO_setPadConfig(DEBUG_SCIRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(DEBUG_SCIRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(DEBUG_SCITX_PIN_CONFIG);
	GPIO_setPadConfig(DEBUG_SCITX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(DEBUG_SCITX_GPIO, GPIO_QUAL_ASYNC);


}

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	M_ADC_A_init();
	M_ADC_B_init();
	M_ADC_C_init();
}

void M_ADC_A_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(M_ADC_A_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(M_ADC_A_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(M_ADC_A_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(M_ADC_A_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(M_ADC_A_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(5000);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(M_ADC_A_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(M_ADC_A_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_SW_ONLY
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_A_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN2, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_A_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN3
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_A_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN3, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_A_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN4
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_A_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN4, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_A_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
}

void M_ADC_B_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(M_ADC_B_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(M_ADC_B_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(M_ADC_B_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(M_ADC_B_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(M_ADC_B_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(5000);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(M_ADC_B_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(M_ADC_B_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_B_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_B_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_SW_ONLY
	//	  	Channel			: ADC_CH_ADCIN1
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_B_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN1, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_B_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_SW_ONLY
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_B_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN2, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_B_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN3
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_B_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN3, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_B_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
}

void M_ADC_C_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(M_ADC_C_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(M_ADC_C_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(M_ADC_C_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(M_ADC_C_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(M_ADC_C_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(5000);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(M_ADC_C_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(M_ADC_C_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_C_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN0, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_C_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_SW_ONLY
	//	  	Channel			: ADC_CH_ADCIN1
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_C_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_SW_ONLY, ADC_CH_ADCIN1, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_C_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM3_SOCA
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 30 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(M_ADC_C_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM3_SOCA, ADC_CH_ADCIN2, 30U);
	ADC_setInterruptSOCTrigger(M_ADC_C_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
}


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to internal.
	//
	ASysCtl_setAnalogReferenceInternal( ASYSCTL_VREFHIA | ASYSCTL_VREFHIB | ASYSCTL_VREFHIC );
	//
	// Set the internal analog voltage reference selection to 1.65V.
	//
	ASysCtl_setAnalogReference1P65( ASYSCTL_VREFHIA | ASYSCTL_VREFHIB | ASYSCTL_VREFHIC );
}

//*****************************************************************************
//
// CMPSS Configurations
//
//*****************************************************************************
void CMPSS_init(){
	M_CMPSS1_init();
	M_CMPSS2_init();
	M_CMPSS3_init();
	M_CMPSS4_init();
}

void M_CMPSS1_init(){
    //
    // Select the value for CMP1HPMXSEL.
    //
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_1,0U);
    //
    // Select the value for CMP1LPMXSEL.
    //
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_1,0U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSS_configHighComparator(M_CMPSS1_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSS_configLowComparator(M_CMPSS1_BASE,(CMPSS_INSRC_DAC | CMPSS_INV_INVERTED));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSS_configDAC(M_CMPSS1_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSS_setDACValueHigh(M_CMPSS1_BASE,2800U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSS_setDACValueLow(M_CMPSS1_BASE,1000U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSS_configFilterHigh(M_CMPSS1_BASE, 0U, 10U, 8U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSS_configFilterLow(M_CMPSS1_BASE, 0U, 1U, 1U);
    //
    // Sets the output signal configuration for the high comparator.
    //
    CMPSS_configOutputsHigh(M_CMPSS1_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the output signal configuration for the low comparator.
    //
    CMPSS_configOutputsLow(M_CMPSS1_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSS_setHysteresis(M_CMPSS1_BASE,0U);
    //
    // Configures the comparator subsystem's ramp generator.
    //
    CMPSS_configRamp(M_CMPSS1_BASE,0U,0U,0U,1U,true);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCHigh(M_CMPSS1_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCLow(M_CMPSS1_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSS_configBlanking(M_CMPSS1_BASE,3U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSS_disableBlanking(M_CMPSS1_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSS_configLatchOnPWMSYNC(M_CMPSS1_BASE,false,false);
    //
    // Disables the CMPSS module.
    //
    CMPSS_disableModule(M_CMPSS1_BASE);

    //
    // Delay for CMPSS DAC to power up.
    //
    DEVICE_DELAY_US(500);
}
void M_CMPSS2_init(){
    //
    // Select the value for CMP2HPMXSEL.
    //
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_2,1U);
    //
    // Select the value for CMP2LPMXSEL.
    //
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_2,0U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSS_configHighComparator(M_CMPSS2_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSS_configLowComparator(M_CMPSS2_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSS_configDAC(M_CMPSS2_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSS_setDACValueHigh(M_CMPSS2_BASE,0U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSS_setDACValueLow(M_CMPSS2_BASE,0U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSS_configFilterHigh(M_CMPSS2_BASE, 0U, 1U, 1U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSS_configFilterLow(M_CMPSS2_BASE, 0U, 1U, 1U);
    //
    // Sets the output signal configuration for the high comparator.
    //
    CMPSS_configOutputsHigh(M_CMPSS2_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the output signal configuration for the low comparator.
    //
    CMPSS_configOutputsLow(M_CMPSS2_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSS_setHysteresis(M_CMPSS2_BASE,0U);
    //
    // Configures the comparator subsystem's ramp generator.
    //
    CMPSS_configRamp(M_CMPSS2_BASE,0U,0U,0U,1U,true);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCHigh(M_CMPSS2_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCLow(M_CMPSS2_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSS_configBlanking(M_CMPSS2_BASE,1U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSS_disableBlanking(M_CMPSS2_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSS_configLatchOnPWMSYNC(M_CMPSS2_BASE,false,false);
    //
    // Disables the CMPSS module.
    //
    CMPSS_disableModule(M_CMPSS2_BASE);

    //
    // Delay for CMPSS DAC to power up.
    //
    DEVICE_DELAY_US(500);
}
void M_CMPSS3_init(){
    //
    // Select the value for CMP3HPMXSEL.
    //
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_3,0U);
    //
    // Select the value for CMP3LPMXSEL.
    //
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_3,0U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSS_configHighComparator(M_CMPSS3_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSS_configLowComparator(M_CMPSS3_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSS_configDAC(M_CMPSS3_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSS_setDACValueHigh(M_CMPSS3_BASE,0U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSS_setDACValueLow(M_CMPSS3_BASE,0U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSS_configFilterHigh(M_CMPSS3_BASE, 0U, 1U, 1U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSS_configFilterLow(M_CMPSS3_BASE, 0U, 1U, 1U);
    //
    // Sets the output signal configuration for the high comparator.
    //
    CMPSS_configOutputsHigh(M_CMPSS3_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the output signal configuration for the low comparator.
    //
    CMPSS_configOutputsLow(M_CMPSS3_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSS_setHysteresis(M_CMPSS3_BASE,0U);
    //
    // Configures the comparator subsystem's ramp generator.
    //
    CMPSS_configRamp(M_CMPSS3_BASE,0U,0U,0U,1U,true);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCHigh(M_CMPSS3_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCLow(M_CMPSS3_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSS_configBlanking(M_CMPSS3_BASE,1U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSS_disableBlanking(M_CMPSS3_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSS_configLatchOnPWMSYNC(M_CMPSS3_BASE,false,false);
    //
    // Disables the CMPSS module.
    //
    CMPSS_disableModule(M_CMPSS3_BASE);

    //
    // Delay for CMPSS DAC to power up.
    //
    DEVICE_DELAY_US(500);
}
void M_CMPSS4_init(){
    //
    // Select the value for CMP7HPMXSEL.
    //
    ASysCtl_selectCMPHPMux(ASYSCTL_CMPHPMUX_SELECT_7,0U);
    //
    // Select the value for CMP7LPMXSEL.
    //
    ASysCtl_selectCMPLPMux(ASYSCTL_CMPLPMUX_SELECT_7,0U);
    //
    // Sets the configuration for the high comparator.
    //
    CMPSS_configHighComparator(M_CMPSS4_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the low comparator.
    //
    CMPSS_configLowComparator(M_CMPSS4_BASE,(CMPSS_INSRC_DAC));
    //
    // Sets the configuration for the internal comparator DACs.
    //
    CMPSS_configDAC(M_CMPSS4_BASE,(CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));
    //
    // Sets the value of the internal DAC of the high comparator.
    //
    CMPSS_setDACValueHigh(M_CMPSS4_BASE,0U);
    //
    // Sets the value of the internal DAC of the low comparator.
    //
    CMPSS_setDACValueLow(M_CMPSS4_BASE,0U);
    //
    //  Configures the digital filter of the high comparator.
    //
    CMPSS_configFilterHigh(M_CMPSS4_BASE, 0U, 1U, 1U);
    //
    // Configures the digital filter of the low comparator.
    //
    CMPSS_configFilterLow(M_CMPSS4_BASE, 0U, 1U, 1U);
    //
    // Sets the output signal configuration for the high comparator.
    //
    CMPSS_configOutputsHigh(M_CMPSS4_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the output signal configuration for the low comparator.
    //
    CMPSS_configOutputsLow(M_CMPSS4_BASE,(CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));
    //
    // Sets the comparator hysteresis settings.
    //
    CMPSS_setHysteresis(M_CMPSS4_BASE,0U);
    //
    // Configures the comparator subsystem's ramp generator.
    //
    CMPSS_configRamp(M_CMPSS4_BASE,0U,0U,0U,1U,true);
    //
    // Disables reset of HIGH comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCHigh(M_CMPSS4_BASE);
    //
    // Disables reset of LOW comparator digital filter output latch on PWMSYNC
    //
    CMPSS_disableLatchResetOnPWMSYNCLow(M_CMPSS4_BASE);
    //
    // Sets the ePWM module blanking signal that holds trip in reset.
    //
    CMPSS_configBlanking(M_CMPSS4_BASE,1U);
    //
    // Disables an ePWM blanking signal from holding trip in reset.
    //
    CMPSS_disableBlanking(M_CMPSS4_BASE);
    //
    // Configures whether or not the digital filter latches are reset by PWMSYNC
    //
    CMPSS_configLatchOnPWMSYNC(M_CMPSS4_BASE,false,false);
    //
    // Disables the CMPSS module.
    //
    CMPSS_disableModule(M_CMPSS4_BASE);

    //
    // Delay for CMPSS DAC to power up.
    //
    DEVICE_DELAY_US(500);
}

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
	myCPUTIMER0_init();
	myCPUTIMER1_init();
	myCPUTIMER2_init();
}

void myCPUTIMER0_init(){
	CPUTimer_setEmulationMode(myCPUTIMER0_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER0_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER0_BASE, 1200U);
	CPUTimer_enableInterrupt(myCPUTIMER0_BASE);
	CPUTimer_stopTimer(myCPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER0_BASE);
}
void myCPUTIMER1_init(){
	CPUTimer_setEmulationMode(myCPUTIMER1_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER1_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER1_BASE, 10000U);
	CPUTimer_disableInterrupt(myCPUTIMER1_BASE);
	CPUTimer_stopTimer(myCPUTIMER1_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER1_BASE);
}
void myCPUTIMER2_init(){
	CPUTimer_setEmulationMode(myCPUTIMER2_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_selectClockSource(myCPUTIMER2_BASE, CPUTIMER_CLOCK_SOURCE_SYS, CPUTIMER_CLOCK_PRESCALER_1);
	CPUTimer_setPreScaler(myCPUTIMER2_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER2_BASE, 100000U);
	CPUTimer_disableInterrupt(myCPUTIMER2_BASE);
	CPUTimer_stopTimer(myCPUTIMER2_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER2_BASE);
}

//*****************************************************************************
//
// DAC Configurations
//
//*****************************************************************************
void DAC_init(){
	myDAC0_init();
	myDAC1_init();
}

void myDAC0_init(){
	//
	// Set DAC reference voltage.
	//
	DAC_setReferenceVoltage(myDAC0_BASE, DAC_REF_ADC_VREFHI);
	//
	// Set DAC gain mode.
	//
	DAC_setGainMode(myDAC0_BASE, DAC_GAIN_TWO);
	//
	// Set DAC load mode.
	//
	DAC_setLoadMode(myDAC0_BASE, DAC_LOAD_SYSCLK);
	//
	// Enable the DAC output
	//
	DAC_enableOutput(myDAC0_BASE);
	//
	// Set the DAC shadow output
	//
	DAC_setShadowValue(myDAC0_BASE, 555U);

	//
	// Delay for buffered DAC to power up.
	//
	DEVICE_DELAY_US(5000);
}
void myDAC1_init(){
	//
	// Set DAC reference voltage.
	//
	DAC_setReferenceVoltage(myDAC1_BASE, DAC_REF_ADC_VREFHI);
	//
	// Set DAC gain mode.
	//
	DAC_setGainMode(myDAC1_BASE, DAC_GAIN_TWO);
	//
	// Set DAC load mode.
	//
	DAC_setLoadMode(myDAC1_BASE, DAC_LOAD_SYSCLK);
	//
	// Enable the DAC output
	//
	DAC_enableOutput(myDAC1_BASE);
	//
	// Set the DAC shadow output
	//
	DAC_setShadowValue(myDAC1_BASE, 555U);

	//
	// Delay for buffered DAC to power up.
	//
	DEVICE_DELAY_US(5000);
}

//*****************************************************************************
//
// ECAP Configurations
//
//*****************************************************************************
void ECAP_init(){
	FAN_PWM_init();
	EPWM3A_ECAP_init();
	EPWM1A_ECAP_init();
}

void FAN_PWM_init(){
	//
	// Stops Time stamp counter.
	//
	ECAP_stopCounter(FAN_PWM_BASE);
	//
	// Sets eCAP in APWM mode.
	//
	ECAP_enableAPWMMode(FAN_PWM_BASE);
	//
	// Set eCAP APWM period.
	//
	ECAP_setAPWMPeriod(FAN_PWM_BASE,100000U);
	//
	// Set eCAP APWM on or off time count.
	//
	ECAP_setAPWMCompare(FAN_PWM_BASE,50000U);
	//
	// Set eCAP APWM polarity.
	//
	ECAP_setAPWMPolarity(FAN_PWM_BASE,ECAP_APWM_ACTIVE_HIGH);
	//
	// Sets a phase shift value count.
	//
	ECAP_setPhaseShiftCount(FAN_PWM_BASE,0U);
	//
	// Disable counter loading with phase shift value.
	//
	ECAP_disableLoadCounter(FAN_PWM_BASE);
	//
	// Configures Sync out signal mode.
	//
	ECAP_setSyncOutMode(FAN_PWM_BASE,ECAP_SYNC_OUT_SYNCI);
	//
	// Configures emulation mode.
	//
	ECAP_setEmulationMode(FAN_PWM_BASE,ECAP_EMULATION_STOP);
	//
	// Starts Time stamp counter for FAN_PWM.
	//
	ECAP_startCounter(FAN_PWM_BASE);

    //-----------------Signal Monitoring--------------------//
}
void EPWM3A_ECAP_init(){
	//
	// Disables time stamp capture.
	//
	ECAP_disableTimeStampCapture(EPWM3A_ECAP_BASE);
	//
	// Stops Time stamp counter.
	//
	ECAP_stopCounter(EPWM3A_ECAP_BASE);
	//
	// Sets eCAP in Capture mode.
	//
	ECAP_enableCaptureMode(EPWM3A_ECAP_BASE);
	//
	// Sets the capture mode.
	//
	ECAP_setCaptureMode(EPWM3A_ECAP_BASE,ECAP_CONTINUOUS_CAPTURE_MODE,ECAP_EVENT_4);
	//
	// Sets the Capture event prescaler.
	//
	ECAP_setEventPrescaler(EPWM3A_ECAP_BASE, 0U);
	//
	// Sets the Capture event polarity.
	//
	ECAP_setEventPolarity(EPWM3A_ECAP_BASE,ECAP_EVENT_1,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(EPWM3A_ECAP_BASE,ECAP_EVENT_2,ECAP_EVNT_FALLING_EDGE);
	ECAP_setEventPolarity(EPWM3A_ECAP_BASE,ECAP_EVENT_3,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(EPWM3A_ECAP_BASE,ECAP_EVENT_4,ECAP_EVNT_FALLING_EDGE);
	//
	// Configure counter reset on events
	//
	ECAP_disableCounterResetOnEvent(EPWM3A_ECAP_BASE,ECAP_EVENT_1);
	ECAP_disableCounterResetOnEvent(EPWM3A_ECAP_BASE,ECAP_EVENT_2);
	ECAP_disableCounterResetOnEvent(EPWM3A_ECAP_BASE,ECAP_EVENT_3);
	ECAP_enableCounterResetOnEvent(EPWM3A_ECAP_BASE,ECAP_EVENT_4);	
	//
	// Select eCAP input.
	//
	ECAP_selectECAPInput(EPWM3A_ECAP_BASE,ECAP_INPUT_INPUTXBAR6);
	//
	// Sets a phase shift value count.
	//
	ECAP_setPhaseShiftCount(EPWM3A_ECAP_BASE,0U);
	//
	// Disable counter loading with phase shift value.
	//
	ECAP_disableLoadCounter(EPWM3A_ECAP_BASE);
	//
	// Configures Sync out signal mode.
	//
	ECAP_setSyncOutMode(EPWM3A_ECAP_BASE,ECAP_SYNC_OUT_SYNCI);
	//
	// Configures emulation mode.
	//
	ECAP_setEmulationMode(EPWM3A_ECAP_BASE,ECAP_EMULATION_STOP);
	//
	// Starts Time stamp counter for EPWM3A_ECAP.
	//
	ECAP_startCounter(EPWM3A_ECAP_BASE);
	//
	// Enables time stamp capture for EPWM3A_ECAP.
	//
	ECAP_enableTimeStampCapture(EPWM3A_ECAP_BASE);
	//
	// Re-arms the eCAP module for EPWM3A_ECAP.
	//
	ECAP_reArm(EPWM3A_ECAP_BASE);

    //-----------------Signal Monitoring--------------------//
}
void EPWM1A_ECAP_init(){
	//
	// Disables time stamp capture.
	//
	ECAP_disableTimeStampCapture(EPWM1A_ECAP_BASE);
	//
	// Stops Time stamp counter.
	//
	ECAP_stopCounter(EPWM1A_ECAP_BASE);
	//
	// Sets eCAP in Capture mode.
	//
	ECAP_enableCaptureMode(EPWM1A_ECAP_BASE);
	//
	// Sets the capture mode.
	//
	ECAP_setCaptureMode(EPWM1A_ECAP_BASE,ECAP_CONTINUOUS_CAPTURE_MODE,ECAP_EVENT_4);
	//
	// Sets the Capture event prescaler.
	//
	ECAP_setEventPrescaler(EPWM1A_ECAP_BASE, 0U);
	//
	// Sets the Capture event polarity.
	//
	ECAP_setEventPolarity(EPWM1A_ECAP_BASE,ECAP_EVENT_1,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(EPWM1A_ECAP_BASE,ECAP_EVENT_2,ECAP_EVNT_FALLING_EDGE);
	ECAP_setEventPolarity(EPWM1A_ECAP_BASE,ECAP_EVENT_3,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(EPWM1A_ECAP_BASE,ECAP_EVENT_4,ECAP_EVNT_FALLING_EDGE);
	//
	// Configure counter reset on events
	//
	ECAP_disableCounterResetOnEvent(EPWM1A_ECAP_BASE,ECAP_EVENT_1);
	ECAP_disableCounterResetOnEvent(EPWM1A_ECAP_BASE,ECAP_EVENT_2);
	ECAP_disableCounterResetOnEvent(EPWM1A_ECAP_BASE,ECAP_EVENT_3);
	ECAP_disableCounterResetOnEvent(EPWM1A_ECAP_BASE,ECAP_EVENT_4);
	//
	// Select eCAP input.
	//
	ECAP_selectECAPInput(EPWM1A_ECAP_BASE,ECAP_INPUT_INPUTXBAR7);
	//
	// Sets a phase shift value count.
	//
	ECAP_setPhaseShiftCount(EPWM1A_ECAP_BASE,0U);
	//
	// Disable counter loading with phase shift value.
	//
	ECAP_disableLoadCounter(EPWM1A_ECAP_BASE);
	//
	// Configures Sync out signal mode.
	//
	ECAP_setSyncOutMode(EPWM1A_ECAP_BASE,ECAP_SYNC_OUT_SYNCI);
	//
	// Configures emulation mode.
	//
	ECAP_setEmulationMode(EPWM1A_ECAP_BASE,ECAP_EMULATION_STOP);
	//
	// Starts Time stamp counter for EPWM1A_ECAP.
	//
	ECAP_startCounter(EPWM1A_ECAP_BASE);
	//
	// Enables time stamp capture for EPWM1A_ECAP.
	//
	ECAP_enableTimeStampCapture(EPWM1A_ECAP_BASE);
	//
	// Re-arms the eCAP module for EPWM1A_ECAP.
	//
	ECAP_reArm(EPWM1A_ECAP_BASE);

    //-----------------Signal Monitoring--------------------//
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(M_EPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM1_BASE, 1120);	
    EPWM_setTimeBaseCounter(M_EPWM1_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM1_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM1_BASE);	
    EPWM_setPhaseShift(M_EPWM1_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 560);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM1_BASE, EPWM_COUNTER_COMPARE_B, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM1_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM1_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM1_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM1_BASE, 20);	
    EPWM_setDeadBandDelayMode(M_EPWM1_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM1_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM1_BASE, 20);	
    EPWM_setDeadBandCounterClock(M_EPWM1_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM1_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM1_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_setClockPrescaler(M_EPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM2_BASE, 1120);	
    EPWM_setTimeBaseCounter(M_EPWM2_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM2_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM2_BASE);	
    EPWM_setPhaseShift(M_EPWM2_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM2_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(M_EPWM2_BASE, EPWM_COUNTER_COMPARE_A, 560);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM2_BASE, EPWM_COUNTER_COMPARE_B, 560);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM2_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM2_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM2_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM2_BASE, 20);	
    EPWM_setDeadBandDelayMode(M_EPWM2_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM2_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM2_BASE, 20);	
    EPWM_setDeadBandCounterClock(M_EPWM2_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM2_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_setClockPrescaler(M_EPWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM3_BASE, 1120);	
    EPWM_setTimeBaseCounter(M_EPWM3_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM3_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM3_BASE);	
    EPWM_setPhaseShift(M_EPWM3_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM3_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(M_EPWM3_BASE, EPWM_COUNTER_COMPARE_A, 560);	
    EPWM_enableGlobalLoadRegisters(M_EPWM3_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM3_BASE, EPWM_COUNTER_COMPARE_B, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM3_BASE, EPWM_COUNTER_COMPARE_C, 448);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM3_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM3_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM3_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM3_BASE, 80);	
    EPWM_setDeadBandDelayMode(M_EPWM3_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM3_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM3_BASE, 80);	
    EPWM_setDeadBandCounterClock(M_EPWM3_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM3_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM3_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_enableTripZoneSignals(M_EPWM3_BASE, EPWM_TZ_SIGNAL_DCAEVT2);	
    EPWM_selectCycleByCycleTripZoneClearEvent(M_EPWM3_BASE, EPWM_TZ_CBC_PULSE_CLR_CNTR_PERIOD);	
    EPWM_selectDigitalCompareTripInput(M_EPWM3_BASE, EPWM_DC_TRIP_TRIPIN4, EPWM_DC_TYPE_DCAH);	
    EPWM_selectDigitalCompareTripInput(M_EPWM3_BASE, EPWM_DC_TRIP_TRIPIN15, EPWM_DC_TYPE_DCAL);	
    EPWM_setTripZoneDigitalCompareEventCondition(M_EPWM3_BASE, EPWM_TZ_DC_OUTPUT_A2, EPWM_TZ_EVENT_DCXH_HIGH);	
    EPWM_selectDigitalCompareTripInput(M_EPWM3_BASE, EPWM_DC_TRIP_TRIPIN4, EPWM_DC_TYPE_DCBH);	
    EPWM_selectDigitalCompareTripInput(M_EPWM3_BASE, EPWM_DC_TRIP_TRIPIN15, EPWM_DC_TYPE_DCBL);	
    EPWM_setTripZoneDigitalCompareEventCondition(M_EPWM3_BASE, EPWM_TZ_DC_OUTPUT_B2, EPWM_TZ_EVENT_DCXH_HIGH);	
    EPWM_enableADCTrigger(M_EPWM3_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(M_EPWM3_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_U_CMPC);	
    EPWM_setADCTriggerEventPrescale(M_EPWM3_BASE, EPWM_SOC_A, 1);	
    EPWM_enableGlobalLoad(M_EPWM4_BASE);	
    EPWM_setGlobalLoadTrigger(M_EPWM4_BASE, EPWM_GL_LOAD_PULSE_CNTR_ZERO_PERIOD);	
    EPWM_setGlobalLoadEventPrescale(M_EPWM4_BASE, 1);	
    EPWM_enableGlobalLoadOneShotMode(M_EPWM4_BASE);	
    EPWM_setGlobalLoadOneShotLatch(M_EPWM4_BASE);	
    EPWM_setupEPWMLinks(M_EPWM4_BASE, EPWM_LINK_WITH_EPWM_3, EPWM_LINK_GLDCTL2);	
    EPWM_setClockPrescaler(M_EPWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM4_BASE, 1120);	
    EPWM_setupEPWMLinks(M_EPWM4_BASE, EPWM_LINK_WITH_EPWM_3, EPWM_LINK_TBPRD);	
    EPWM_setTimeBaseCounter(M_EPWM4_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM4_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM4_BASE);	
    EPWM_setPhaseShift(M_EPWM4_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM4_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(M_EPWM4_BASE, EPWM_COUNTER_COMPARE_A, 560);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setupEPWMLinks(M_EPWM4_BASE, EPWM_LINK_WITH_EPWM_3, EPWM_LINK_COMP_A);	
    EPWM_setCounterCompareValue(M_EPWM4_BASE, EPWM_COUNTER_COMPARE_B, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setupEPWMLinks(M_EPWM4_BASE, EPWM_LINK_WITH_EPWM_3, EPWM_LINK_COMP_B);	
    EPWM_setupEPWMLinks(M_EPWM4_BASE, EPWM_LINK_WITH_EPWM_3, EPWM_LINK_COMP_C);	
    EPWM_setActionQualifierContSWForceShadowMode(M_EPWM4_BASE, EPWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO_PERIOD);	
    EPWM_enableGlobalLoadRegisters(M_EPWM4_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierShadowLoadMode(M_EPWM4_BASE, EPWM_ACTION_QUALIFIER_A, EPWM_AQ_LOAD_ON_CNTR_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_enableGlobalLoadRegisters(M_EPWM4_BASE, EPWM_GL_REGISTER_AQCTLB_AQCTLB2);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM4_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM4_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM4_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM4_BASE, 80);	
    EPWM_setDeadBandDelayMode(M_EPWM4_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM4_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM4_BASE, 80);	
    EPWM_setDeadBandCounterClock(M_EPWM4_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM4_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM4_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_enableTripZoneSignals(M_EPWM4_BASE, EPWM_TZ_SIGNAL_DCAEVT2);	
    EPWM_selectDigitalCompareTripInput(M_EPWM4_BASE, EPWM_DC_TRIP_TRIPIN4, EPWM_DC_TYPE_DCAH);	
    EPWM_selectDigitalCompareTripInput(M_EPWM4_BASE, EPWM_DC_TRIP_TRIPIN15, EPWM_DC_TYPE_DCAL);	
    EPWM_setTripZoneDigitalCompareEventCondition(M_EPWM4_BASE, EPWM_TZ_DC_OUTPUT_A2, EPWM_TZ_EVENT_DCXH_HIGH);	
    EPWM_selectDigitalCompareTripInput(M_EPWM4_BASE, EPWM_DC_TRIP_TRIPIN15, EPWM_DC_TYPE_DCBH);	
    EPWM_selectDigitalCompareTripInput(M_EPWM4_BASE, EPWM_DC_TRIP_TRIPIN15, EPWM_DC_TYPE_DCBL);	
    EPWM_setClockPrescaler(M_EPWM5_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM5_BASE, 500);	
    EPWM_setTimeBaseCounter(M_EPWM5_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM5_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM5_BASE);	
    EPWM_setPhaseShift(M_EPWM5_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM5_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(M_EPWM5_BASE, EPWM_COUNTER_COMPARE_A, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM5_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM5_BASE, EPWM_COUNTER_COMPARE_B, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM5_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM5_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM5_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM5_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM5_BASE, 20);	
    EPWM_setDeadBandDelayMode(M_EPWM5_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM5_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM5_BASE, 20);	
    EPWM_setDeadBandCounterClock(M_EPWM5_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM5_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM5_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_setClockPrescaler(M_EPWM6_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM6_BASE, 500);	
    EPWM_setTimeBaseCounter(M_EPWM6_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM6_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM6_BASE);	
    EPWM_setPhaseShift(M_EPWM6_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM6_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(M_EPWM6_BASE, EPWM_COUNTER_COMPARE_A, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM6_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM6_BASE, EPWM_COUNTER_COMPARE_B, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM6_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM6_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM6_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM6_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM6_BASE, 20);	
    EPWM_setDeadBandDelayMode(M_EPWM6_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM6_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM6_BASE, 20);	
    EPWM_setDeadBandCounterClock(M_EPWM6_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM6_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM6_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_setClockPrescaler(M_EPWM7_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM7_BASE, 500);	
    EPWM_setTimeBaseCounter(M_EPWM7_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM7_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM7_BASE);	
    EPWM_setPhaseShift(M_EPWM7_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM7_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(M_EPWM7_BASE, EPWM_COUNTER_COMPARE_A, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM7_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM7_BASE, EPWM_COUNTER_COMPARE_B, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM7_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM7_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM7_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM7_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM7_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM7_BASE, 20);	
    EPWM_setDeadBandDelayMode(M_EPWM7_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM7_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM7_BASE, 20);	
    EPWM_setDeadBandCounterClock(M_EPWM7_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM7_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM7_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
    EPWM_setClockPrescaler(M_EPWM8_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(M_EPWM8_BASE, 500);	
    EPWM_setTimeBaseCounter(M_EPWM8_BASE, 0);	
    EPWM_setTimeBaseCounterMode(M_EPWM8_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(M_EPWM8_BASE);	
    EPWM_setPhaseShift(M_EPWM8_BASE, 0);	
    EPWM_setSyncOutPulseMode(M_EPWM8_BASE, EPWM_SYNC_OUT_PULSE_ON_EPWMxSYNCIN);	
    EPWM_setCounterCompareValue(M_EPWM8_BASE, EPWM_COUNTER_COMPARE_A, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM8_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(M_EPWM8_BASE, EPWM_COUNTER_COMPARE_B, 250);	
    EPWM_setCounterCompareShadowLoadMode(M_EPWM8_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(M_EPWM8_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(M_EPWM8_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(M_EPWM8_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(M_EPWM8_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_setRisingEdgeDelayCount(M_EPWM8_BASE, 20);	
    EPWM_setDeadBandDelayMode(M_EPWM8_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(M_EPWM8_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_setFallingEdgeDelayCount(M_EPWM8_BASE, 20);	
    EPWM_setDeadBandCounterClock(M_EPWM8_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    EPWM_setTripZoneAction(M_EPWM8_BASE, EPWM_TZ_ACTION_EVENT_TZA, EPWM_TZ_ACTION_LOW);	
    EPWM_setTripZoneAction(M_EPWM8_BASE, EPWM_TZ_ACTION_EVENT_TZB, EPWM_TZ_ACTION_LOW);	
}

//*****************************************************************************
//
// EPWMXBAR Configurations
//
//*****************************************************************************
void EPWMXBAR_init(){
	CMPSS2OUT_init();
	CMPSS3OUT_init();
	CMPSS7OUT_init();
	CLB1H_init();
	CLB1L_init();
	CLB2H_init();
	CLB2L_init();
	CMPSS1OUT_init();
}

void CMPSS2OUT_init(){
		
	XBAR_setEPWMMuxConfig(CMPSS2OUT, XBAR_EPWM_MUX02_CMPSS2_CTRIPH_OR_L);
	XBAR_enableEPWMMux(CMPSS2OUT, XBAR_MUX02);
}
void CMPSS3OUT_init(){
		
	XBAR_setEPWMMuxConfig(CMPSS3OUT, XBAR_EPWM_MUX04_CMPSS3_CTRIPH_OR_L);
	XBAR_enableEPWMMux(CMPSS3OUT, XBAR_MUX04);
}
void CMPSS7OUT_init(){
		
	XBAR_setEPWMMuxConfig(CMPSS7OUT, XBAR_EPWM_MUX12_CMPSS7_CTRIPH_OR_L);
	XBAR_enableEPWMMux(CMPSS7OUT, XBAR_MUX12);
}
void CLB1H_init(){
		
	XBAR_setEPWMMuxConfig(CLB1H, XBAR_EPWM_MUX01_CLB1_OUT4);
	XBAR_enableEPWMMux(CLB1H, XBAR_MUX01);
}
void CLB1L_init(){
		
	XBAR_setEPWMMuxConfig(CLB1L, XBAR_EPWM_MUX03_CLB1_OUT5);
	XBAR_enableEPWMMux(CLB1L, XBAR_MUX03);
}
void CLB2H_init(){
		
	XBAR_setEPWMMuxConfig(CLB2H, XBAR_EPWM_MUX05_CLB2_OUT4);
	XBAR_enableEPWMMux(CLB2H, XBAR_MUX05);
}
void CLB2L_init(){
		
	XBAR_setEPWMMuxConfig(CLB2L, XBAR_EPWM_MUX07_CLB2_OUT5);
	XBAR_enableEPWMMux(CLB2L, XBAR_MUX07);
}
void CMPSS1OUT_init(){
		
	XBAR_setEPWMMuxConfig(CMPSS1OUT, XBAR_EPWM_MUX00_CMPSS1_CTRIPH_OR_L);
	XBAR_enableEPWMMux(CMPSS1OUT, XBAR_MUX00);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	FAULT_INPUT1_init();
	FAULT_INPUT2_init();
	FAULT_OUTPUT_init();
	DEBUG1_init();
	ACTIVE1_init();
	ACTIVE2_init();
	STATUS1_init();
	STATUS2_init();
	PRIM_ZCD1_init();
	PRIM_ZCD2_init();
	DEBUG2_init();
	FAN2_init();
	SEC_ZCD1_init();
	SEC_ZCD2_init();
}

void FAULT_INPUT1_init(){
	GPIO_setPadConfig(FAULT_INPUT1, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(FAULT_INPUT1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(FAULT_INPUT1, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(FAULT_INPUT1, GPIO_CORE_CPU1);
}
void FAULT_INPUT2_init(){
	GPIO_setPadConfig(FAULT_INPUT2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(FAULT_INPUT2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(FAULT_INPUT2, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(FAULT_INPUT2, GPIO_CORE_CPU1);
}
void FAULT_OUTPUT_init(){
	GPIO_setPadConfig(FAULT_OUTPUT, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(FAULT_OUTPUT, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(FAULT_OUTPUT, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(FAULT_OUTPUT, GPIO_CORE_CPU1);
}
void DEBUG1_init(){
	GPIO_setPadConfig(DEBUG1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(DEBUG1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(DEBUG1, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(DEBUG1, GPIO_CORE_CPU1);
}
void ACTIVE1_init(){
	GPIO_setPadConfig(ACTIVE1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ACTIVE1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(ACTIVE1, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(ACTIVE1, GPIO_CORE_CPU1);
}
void ACTIVE2_init(){
	GPIO_setPadConfig(ACTIVE2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(ACTIVE2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(ACTIVE2, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(ACTIVE2, GPIO_CORE_CPU1);
}
void STATUS1_init(){
	GPIO_writePin(STATUS1, 1);
	GPIO_setPadConfig(STATUS1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(STATUS1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(STATUS1, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(STATUS1, GPIO_CORE_CPU1);
}
void STATUS2_init(){
	GPIO_writePin(STATUS2, 1);
	GPIO_setPadConfig(STATUS2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(STATUS2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(STATUS2, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(STATUS2, GPIO_CORE_CPU1);
}
void PRIM_ZCD1_init(){
	GPIO_setPadConfig(PRIM_ZCD1, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(PRIM_ZCD1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(PRIM_ZCD1, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(PRIM_ZCD1, GPIO_CORE_CPU1);
}
void PRIM_ZCD2_init(){
	GPIO_setPadConfig(PRIM_ZCD2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(PRIM_ZCD2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(PRIM_ZCD2, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(PRIM_ZCD2, GPIO_CORE_CPU1);
}
void DEBUG2_init(){
	GPIO_setPadConfig(DEBUG2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(DEBUG2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(DEBUG2, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(DEBUG2, GPIO_CORE_CPU1);
}
void FAN2_init(){
	GPIO_setPadConfig(FAN2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(FAN2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(FAN2, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(FAN2, GPIO_CORE_CPU1);
}
void SEC_ZCD1_init(){
	GPIO_setPadConfig(SEC_ZCD1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(SEC_ZCD1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(SEC_ZCD1, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(SEC_ZCD1, GPIO_CORE_CPU1);
}
void SEC_ZCD2_init(){
	GPIO_setPadConfig(SEC_ZCD2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(SEC_ZCD2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(SEC_ZCD2, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(SEC_ZCD2, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
	PZCD1_init();
	TZ1_init();
	TZ2_init();
	EPWM3_CAP_init();
	EPWM1_CAP_init();
}

void PZCD1_init(){
	XBAR_setInputPin(PZCD1_INPUT, PZCD1_SOURCE);
}
void TZ1_init(){
	XBAR_setInputPin(TZ1_INPUT, TZ1_SOURCE);
}
void TZ2_init(){
	XBAR_setInputPin(TZ2_INPUT, TZ2_SOURCE);
}
void EPWM3_CAP_init(){
	XBAR_setInputPin(EPWM3_CAP_INPUT, EPWM3_CAP_SOURCE);
}
void EPWM1_CAP_init(){
	XBAR_setInputPin(EPWM1_CAP_INPUT, EPWM1_CAP_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_myCPUTIMER0
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCPUTIMER0, &ISR2_TIMER0);
	Interrupt_disable(INT_myCPUTIMER0);
	
	// Interrupt Settings for INT_PRIM_ZCD1_XINT
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_PRIM_ZCD1_XINT, &ISR1_PZCD);
	Interrupt_disable(INT_PRIM_ZCD1_XINT);
}
//*****************************************************************************
//
// OUTPUTXBAR Configurations
//
//*****************************************************************************
void OUTPUTXBAR_init(){
	FAN1_init();
	CMPSS1OUT0_init();
}

void FAN1_init(){
	XBAR_setOutputLatchMode(FAN1, false);
	XBAR_invertOutputSignal(FAN1, false);
		
	//
	//Mux configuration
	//
	XBAR_setOutputMuxConfig(FAN1, XBAR_OUT_MUX00_ECAP1_OUT);
	XBAR_enableOutputMux(FAN1, XBAR_MUX00);
}
void CMPSS1OUT0_init(){
	XBAR_setOutputLatchMode(CMPSS1OUT0, false);
	XBAR_invertOutputSignal(CMPSS1OUT0, false);
		
	//
	//Mux configuration
	//
	XBAR_setOutputMuxConfig(CMPSS1OUT0, XBAR_OUT_MUX00_CMPSS1_CTRIPOUTH_OR_L);
	XBAR_enableOutputMux(CMPSS1OUT0, XBAR_MUX00);
}

//*****************************************************************************
//
// PMBUS Configurations
//
//*****************************************************************************
void PMBUS_init(){
	myPMBUS0_init();
}

void myPMBUS0_init(){
		uint32_t moduleFreq = 0U;
		PMBus_disableModule(myPMBUS0_BASE);
		PMBus_disableI2CMode(myPMBUS0_BASE);	
		PMBus_deassertAlertLine(myPMBUS0_BASE);	
		PMBus_setOwnAddress(myPMBUS0_BASE, myPMBUS0_OWN_ADDRESS);
		moduleFreq = PMBus_configModuleClock(myPMBUS0_BASE, myPMBUS0_BAUDRATE, DEVICE_SYSCLK_FREQ);
		PMBus_configBusClock(myPMBUS0_BASE, myPMBUS0_CLOCKMODE, moduleFreq);

		PMBus_initControllerMode(myPMBUS0_BASE);
		//
		// config target address 
		//
		PMBus_setTargetAddress(myPMBUS0_BASE, myPMBUS0_TARGET_ADDRESS);
		PMBus_enableModule(myPMBUS0_BASE);
}

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
void SCI_init(){
	DEBUG_init();
}

void DEBUG_init(){
	SCI_clearInterruptStatus(DEBUG_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(DEBUG_BASE);
	SCI_resetTxFIFO(DEBUG_BASE);
	SCI_resetRxFIFO(DEBUG_BASE);
	SCI_resetChannels(DEBUG_BASE);
	SCI_setConfig(DEBUG_BASE, DEVICE_LSPCLK_FREQ, DEBUG_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_disableLoopback(DEBUG_BASE);
	SCI_performSoftwareReset(DEBUG_BASE);
	SCI_enableFIFO(DEBUG_BASE);
	SCI_enableModule(DEBUG_BASE);
}

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// For EPWM1, the sync input is: SYSCTL_SYNC_IN_SRC_EXTSYNCIN1
	//
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM4, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_EPWM7, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP1, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP4, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	SysCtl_setSyncInputConfig(SYSCTL_SYNC_IN_ECAP6, SYSCTL_SYNC_IN_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
//*****************************************************************************
//
// XINT Configurations
//
//*****************************************************************************
void XINT_init(){
	PRIM_ZCD1_XINT_init();
}

void PRIM_ZCD1_XINT_init(){
	GPIO_setInterruptType(PRIM_ZCD1_XINT, GPIO_INT_TYPE_BOTH_EDGES);
	GPIO_setInterruptPin(PRIM_ZCD1, PRIM_ZCD1_XINT);
	GPIO_enableInterrupt(PRIM_ZCD1_XINT);
}

