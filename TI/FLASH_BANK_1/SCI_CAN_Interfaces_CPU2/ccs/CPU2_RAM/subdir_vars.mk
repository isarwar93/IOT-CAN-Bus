################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/flash_programming_cpu2_RAM.cmd 

LIB_SRCS += \
/home/ismail/ti/C2000Ware_5_02_00_00/libraries/flash_api/f2837xd/lib/F021_API_F2837xD_FPU32.lib \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/c2bootROM_BootROMSymbols_fpu32.lib 

ASM_SRCS += \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/F2837xD_usDelay.asm \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/fwupgradec2_start.asm 

C_SRCS += \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Ipc.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver_Util.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/F2837xD_sci_flash_kernels_cpu02.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Fapi_UserDefinedFunctions.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/SCI_Boot.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/SCI_GetFunction.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Shared_Boot.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Shared_Erase.c \
/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Shared_Verify.c 

C_DEPS += \
./F2837xD_DefaultISR.d \
./F2837xD_GlobalVariableDefs.d \
./F2837xD_Gpio.d \
./F2837xD_Ipc.d \
./F2837xD_Ipc_Driver.d \
./F2837xD_Ipc_Driver_Util.d \
./F2837xD_PieCtrl.d \
./F2837xD_PieVect.d \
./F2837xD_SysCtrl.d \
./F2837xD_sci_flash_kernels_cpu02.d \
./Fapi_UserDefinedFunctions.d \
./SCI_Boot.d \
./SCI_GetFunction.d \
./Shared_Boot.d \
./Shared_Erase.d \
./Shared_Verify.d 

OBJS += \
./F2837xD_DefaultISR.obj \
./F2837xD_GlobalVariableDefs.obj \
./F2837xD_Gpio.obj \
./F2837xD_Ipc.obj \
./F2837xD_Ipc_Driver.obj \
./F2837xD_Ipc_Driver_Util.obj \
./F2837xD_PieCtrl.obj \
./F2837xD_PieVect.obj \
./F2837xD_SysCtrl.obj \
./F2837xD_sci_flash_kernels_cpu02.obj \
./F2837xD_usDelay.obj \
./Fapi_UserDefinedFunctions.obj \
./SCI_Boot.obj \
./SCI_GetFunction.obj \
./Shared_Boot.obj \
./Shared_Erase.obj \
./Shared_Verify.obj \
./fwupgradec2_start.obj 

ASM_DEPS += \
./F2837xD_usDelay.d \
./fwupgradec2_start.d 

OBJS__QUOTED += \
"F2837xD_DefaultISR.obj" \
"F2837xD_GlobalVariableDefs.obj" \
"F2837xD_Gpio.obj" \
"F2837xD_Ipc.obj" \
"F2837xD_Ipc_Driver.obj" \
"F2837xD_Ipc_Driver_Util.obj" \
"F2837xD_PieCtrl.obj" \
"F2837xD_PieVect.obj" \
"F2837xD_SysCtrl.obj" \
"F2837xD_sci_flash_kernels_cpu02.obj" \
"F2837xD_usDelay.obj" \
"Fapi_UserDefinedFunctions.obj" \
"SCI_Boot.obj" \
"SCI_GetFunction.obj" \
"Shared_Boot.obj" \
"Shared_Erase.obj" \
"Shared_Verify.obj" \
"fwupgradec2_start.obj" 

C_DEPS__QUOTED += \
"F2837xD_DefaultISR.d" \
"F2837xD_GlobalVariableDefs.d" \
"F2837xD_Gpio.d" \
"F2837xD_Ipc.d" \
"F2837xD_Ipc_Driver.d" \
"F2837xD_Ipc_Driver_Util.d" \
"F2837xD_PieCtrl.d" \
"F2837xD_PieVect.d" \
"F2837xD_SysCtrl.d" \
"F2837xD_sci_flash_kernels_cpu02.d" \
"Fapi_UserDefinedFunctions.d" \
"SCI_Boot.d" \
"SCI_GetFunction.d" \
"Shared_Boot.d" \
"Shared_Erase.d" \
"Shared_Verify.d" 

ASM_DEPS__QUOTED += \
"F2837xD_usDelay.d" \
"fwupgradec2_start.d" 

C_SRCS__QUOTED += \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_DefaultISR.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/headers/source/F2837xD_GlobalVariableDefs.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Gpio.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Ipc.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_Ipc_Driver_Util.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_PieCtrl.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_PieVect.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/common/source/F2837xD_SysCtrl.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/F2837xD_sci_flash_kernels_cpu02.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Fapi_UserDefinedFunctions.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/SCI_Boot.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/SCI_GetFunction.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Shared_Boot.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Shared_Erase.c" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/Shared_Verify.c" 

ASM_SRCS__QUOTED += \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/F2837xD_usDelay.asm" \
"/home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/fwupgradec2_start.asm" 


