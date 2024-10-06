################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F2837xD_DefaultISR.obj" \
"./F2837xD_GlobalVariableDefs.obj" \
"./F2837xD_Gpio.obj" \
"./F2837xD_Ipc.obj" \
"./F2837xD_Ipc_Driver.obj" \
"./F2837xD_Ipc_Driver_Util.obj" \
"./F2837xD_PieCtrl.obj" \
"./F2837xD_PieVect.obj" \
"./F2837xD_SysCtrl.obj" \
"./F2837xD_sci_flash_kernels_cpu02.obj" \
"./F2837xD_usDelay.obj" \
"./Fapi_UserDefinedFunctions.obj" \
"./SCI_Boot.obj" \
"./SCI_GetFunction.obj" \
"./Shared_Boot.obj" \
"./Shared_Erase.obj" \
"./Shared_Verify.obj" \
"./fwupgradec2_start.obj" \
"/home/ismail/ti/C2000Ware_5_02_00_00/libraries/flash_api/f2837xd/lib/F021_API_F2837xD_FPU32.lib" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/c2bootROM_BootROMSymbols_fpu32.lib" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/flash_programming_cpu2_RAM.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-lrts2800_fpu32.lib \
-lF2837xD_Headers_nonBIOS_cpu2.cmd \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
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
F2837xD_sci_flash_kernels_cpu02.out 

EXE_OUTPUTS__QUOTED += \
"F2837xD_sci_flash_kernels_cpu02.out" 


# All Target
all: F2837xD_sci_flash_kernels_cpu02.out

# Tool invocations
F2837xD_sci_flash_kernels_cpu02.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"/home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --cla_support=cla1 --tmu_support=tmu0 --vcu_support=vcu2 -g --gcc --define=CPU2 --display_error_number --diag_suppress=10063 --diag_warning=225 -z -m"F2837xD_sci_flash_kernels_cpu02.map" --stack_size=0x100 --warn_sections -i"/home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/lib" -i"/home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" -i"/home/ismail/ti/C2000Ware_5_02_00_00/libraries/flash_api/f2837xd/lib" -i"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/cmd" -i"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/headers/cmd" --reread_libs --display_error_number --xml_link_info="F2837xD_sci_flash_kernels_cpu02_linkInfo.xml" --entry_point=code_start --rom_model -o "F2837xD_sci_flash_kernels_cpu02.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "F2837xD_DefaultISR.obj" "F2837xD_GlobalVariableDefs.obj" "F2837xD_Gpio.obj" "F2837xD_Ipc.obj" "F2837xD_Ipc_Driver.obj" "F2837xD_Ipc_Driver_Util.obj" "F2837xD_PieCtrl.obj" "F2837xD_PieVect.obj" "F2837xD_SysCtrl.obj" "F2837xD_sci_flash_kernels_cpu02.obj" "F2837xD_usDelay.obj" "Fapi_UserDefinedFunctions.obj" "SCI_Boot.obj" "SCI_GetFunction.obj" "Shared_Boot.obj" "Shared_Erase.obj" "Shared_Verify.obj" "fwupgradec2_start.obj" 
	-$(RM) "F2837xD_DefaultISR.d" "F2837xD_GlobalVariableDefs.d" "F2837xD_Gpio.d" "F2837xD_Ipc.d" "F2837xD_Ipc_Driver.d" "F2837xD_Ipc_Driver_Util.d" "F2837xD_PieCtrl.d" "F2837xD_PieVect.d" "F2837xD_SysCtrl.d" "F2837xD_sci_flash_kernels_cpu02.d" "Fapi_UserDefinedFunctions.d" "SCI_Boot.d" "SCI_GetFunction.d" "Shared_Boot.d" "Shared_Erase.d" "Shared_Verify.d" 
	-$(RM) "F2837xD_usDelay.d" "fwupgradec2_start.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-@echo 'Create kernel.txt'
	-"/home/ismail/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/hex2000" "F2837xD_sci_flash_kernels_cpu02.out" -boot -sci8 -a -o "F2837xD_sci_flash_kernels_cpu02.txt"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

