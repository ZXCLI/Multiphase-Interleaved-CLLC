################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/%.obj: ../APP/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=2 --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/LIB/SFO" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/APP" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/BoardHAL" --include_path="C:/ti/C2000Ware_5_01_00_00" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/device" --include_path="C:/ti/C2000Ware_5_01_00_00/driverlib/f28004x/driverlib" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="APP/$(basename $(<F)).d_raw" --include_path="C:/Users/ZXC/Documents/mcu project/ti-project/Multiphase-Interleaved-CLLC/CPU1_FLASH/syscfg" --obj_directory="APP" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


