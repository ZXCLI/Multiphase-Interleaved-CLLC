################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
LIB/DCL/%.obj: ../LIB/DCL/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccstheia140/ccs/tools/compiler/ti-cgt-c2000_22.6.1A23259/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=2 --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC" --include_path="C:/ti/C2000Ware_5_01_00_00" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/device" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB" --include_path="C:/ti/C2000Ware_5_01_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccstheia140/ccs/tools/compiler/ti-cgt-c2000_22.6.1A23259/include" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB/utilities" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB/DCL" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB/SFO" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB/sfra" --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="LIB/DCL/$(basename $(<F)).d_raw" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/CPU1_RAM/syscfg" --obj_directory="LIB/DCL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


