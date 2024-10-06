################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./assembly/F2837xD_usDelay.obj" \
"./assembly/fwupgradec2_start.obj" \
"./src/F2837xD_DefaultISR.obj" \
"./src/F2837xD_GlobalVariableDefs.obj" \
"./src/F2837xD_Gpio.obj" \
"./src/F2837xD_Ipc.obj" \
"./src/F2837xD_Ipc_Driver_Util.obj" \
"./src/F2837xD_PieCtrl.obj" \
"./src/F2837xD_PieVect.obj" \
"./src/F2837xD_SysCtrl.obj" \
"./src/Fapi_UserDefinedFunctions.obj" \
"./src/SCI_Boot.obj" \
"./src/SCI_GetFunction.obj" \
"./src/Shared_Boot.obj" \
"./src/Shared_Erase.obj" \
"./src/Shared_Verify.obj" \
"./src/config.obj" \
"./src/main_cpu02.obj" \
"../F021_API_F2837xD_FPU32.lib" \
"../c2bootROM_BootROMSymbols_fpu32.lib" \
"../linkers/2837xD_FLASH_lnk_cpu2.cmd" \
"../linkers/F2837xD_Headers_nonBIOS_cpu2.cmd" \
"../linkers/flash_programming_cpu2_RAM.cmd" \
$(GEN_CMDS__FLAG) \
-lrts2800_fpu32.lib \
-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include assembly/subdir_vars.mk
-include linkers/subdir_vars.mk
-include src/subdir_vars.mk
-include subdir_rules.mk
-include assembly/subdir_rules.mk
-include linkers/subdir_rules.mk
-include src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
SCI_CAN_Interfaces_CPU2.out 

EXE_OUTPUTS__QUOTED += \
"SCI_CAN_Interfaces_CPU2.out" 


# All Target
all: SCI_CAN_Interfaces_CPU2.out

# Tool invocations
SCI_CAN_Interfaces_CPU2.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"/home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --advice:performance=all --define=_DUAL_HEADERS --define=_LAUNCHXL_F28379D --define=_STANDALONE --define=CPU2 --define=_FLASH -g --diag_warning=225 --display_error_number --abi=coffabi -z -m"SCI_CAN_Interfaces_CPU2.map" --heap_size=0x400 --stack_size=0x3F8 --warn_sections -i"/home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/lib" -i"/home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" -i"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/cmd" -i"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/headers/cmd" --reread_libs --display_error_number --xml_link_info="SCI_CAN_Interfaces_CPU2_linkInfo.xml" --rom_model -o "SCI_CAN_Interfaces_CPU2.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "assembly/F2837xD_usDelay.obj" "assembly/fwupgradec2_start.obj" "src/F2837xD_DefaultISR.obj" "src/F2837xD_GlobalVariableDefs.obj" "src/F2837xD_Gpio.obj" "src/F2837xD_Ipc.obj" "src/F2837xD_Ipc_Driver_Util.obj" "src/F2837xD_PieCtrl.obj" "src/F2837xD_PieVect.obj" "src/F2837xD_SysCtrl.obj" "src/Fapi_UserDefinedFunctions.obj" "src/SCI_Boot.obj" "src/SCI_GetFunction.obj" "src/Shared_Boot.obj" "src/Shared_Erase.obj" "src/Shared_Verify.obj" "src/config.obj" "src/main_cpu02.obj" 
	-$(RM) "src/F2837xD_DefaultISR.d" "src/F2837xD_GlobalVariableDefs.d" "src/F2837xD_Gpio.d" "src/F2837xD_Ipc.d" "src/F2837xD_Ipc_Driver_Util.d" "src/F2837xD_PieCtrl.d" "src/F2837xD_PieVect.d" "src/F2837xD_SysCtrl.d" "src/Fapi_UserDefinedFunctions.d" "src/SCI_Boot.d" "src/SCI_GetFunction.d" "src/Shared_Boot.d" "src/Shared_Erase.d" "src/Shared_Verify.d" "src/config.d" "src/main_cpu02.d" 
	-$(RM) "assembly/F2837xD_usDelay.d" "assembly/fwupgradec2_start.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

