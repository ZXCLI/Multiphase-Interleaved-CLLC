################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-63614417: ../CLLC.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1240/ccs/utils/sysconfig_1.17.0/sysconfig_cli.bat" -s "C:/ti/C2000Ware_5_01_00_00/.metadata/sdk.json" -d "F28004x" --script "C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/CLLC.syscfg" -o "syscfg" --package F28004x_100PZ --part F28004x_100PZ --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-63614417 ../CLLC.syscfg
syscfg/board.h: build-63614417
syscfg/board.cmd.genlibs: build-63614417
syscfg/board.opt: build-63614417
syscfg/pinmux.csv: build-63614417
syscfg/epwm.dot: build-63614417
syscfg/adc.dot: build-63614417
syscfg/c2000ware_libraries.cmd.genlibs: build-63614417
syscfg/c2000ware_libraries.opt: build-63614417
syscfg/c2000ware_libraries.c: build-63614417
syscfg/c2000ware_libraries.h: build-63614417
syscfg/clocktree.h: build-63614417
syscfg/: build-63614417

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -O3 --opt_for_speed=4 --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/LIB/SFO" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/LIB/DCL" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/LIB/utilities" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/APP" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/BoardHAL" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/APP" --include_path="C:/ti/C2000Ware_5_01_00_00" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/device" --include_path="C:/ti/C2000Ware_5_01_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=_FLASH --c11 --relaxed_ansi --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/CPU1_FLASH/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -O3 --opt_for_speed=4 --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/LIB/SFO" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/LIB/DCL" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/LIB/utilities" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/APP" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/BoardHAL" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/APP" --include_path="C:/ti/C2000Ware_5_01_00_00" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/device" --include_path="C:/ti/C2000Ware_5_01_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=_FLASH --c11 --relaxed_ansi --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/zxc/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC_DEBUG/CPU1_FLASH/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


