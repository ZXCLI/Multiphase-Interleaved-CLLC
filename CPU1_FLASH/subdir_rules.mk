################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-78424465: ../CLLC.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.19.0/sysconfig_cli.bat" --script "C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/CLLC.syscfg" -o "syscfg" -s "C:/ti/C2000Ware_5_01_00_00/.metadata/sdk.json" -d "F28004x" --package F28004x_100PZ --part F28004x_100PZ --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-78424465 ../CLLC.syscfg
syscfg/board.h: build-78424465
syscfg/board.cmd.genlibs: build-78424465
syscfg/board.opt: build-78424465
syscfg/pinmux.csv: build-78424465
syscfg/epwm.dot: build-78424465
syscfg/adc.dot: build-78424465
syscfg/c2000ware_libraries.cmd.genlibs: build-78424465
syscfg/c2000ware_libraries.opt: build-78424465
syscfg/c2000ware_libraries.c: build-78424465
syscfg/c2000ware_libraries.h: build-78424465
syscfg/clocktree.h: build-78424465
syscfg: build-78424465

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccstheia140/ccs/tools/compiler/ti-cgt-c2000_22.6.1A23259/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=2 --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB/SFO" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/APP" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/BoardHAL" --include_path="C:/ti/C2000Ware_5_01_00_00" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/device" --include_path="C:/ti/C2000Ware_5_01_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccstheia140/ccs/tools/compiler/ti-cgt-c2000_22.6.1A23259/include" --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/CPU1_FLASH/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccstheia140/ccs/tools/compiler/ti-cgt-c2000_22.6.1A23259/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=2 --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB/SFO" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/APP" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/BoardHAL" --include_path="C:/ti/C2000Ware_5_01_00_00" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/device" --include_path="C:/ti/C2000Ware_5_01_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccstheia140/ccs/tools/compiler/ti-cgt-c2000_22.6.1A23259/include" --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/CPU1_FLASH/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


