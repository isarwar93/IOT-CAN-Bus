################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
assembly/%.obj: ../assembly/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/home/ismail/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="/home/ismail/IOT-CAN-Bus/TI/FLASH_BANK_0/SCI_CAN_Interfaces_CPU2/assembly" --include_path="/home/ismail/IOT-CAN-Bus/TI/FLASH_BANK_0/SCI_CAN_Interfaces_CPU2/headers" --include_path="/home/ismail/IOT-CAN-Bus/TI/FLASH_BANK_0/SCI_CAN_Interfaces_CPU1/linker" --include_path="/home/ismail/IOT-CAN-Bus/TI/FLASH_BANK_0/SCI_CAN_Interfaces_CPU2/src" --include_path="/home/ismail/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/headers/include" --include_path="/home/ismail/ti/C2000Ware_5_02_00_00/libraries/flash_api/f2837xd/include" --include_path="/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/include" --advice:performance=all --define=_DUAL_HEADERS --define=_LAUNCHXL_F28379D --define=_STANDALONE --define=CPU2 --define=_FLASH -g --diag_warning=225 --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="assembly/$(basename $(<F)).d_raw" --obj_directory="assembly" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


