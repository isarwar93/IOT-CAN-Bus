//###########################################################################
//
// FILE:   F2837xD_sci_flash_kernels_cpu01.c
//
// TITLE:  Flash Programming Solution using SCI for F2837xD.
//
//###########################################################################
//
// $Release Date:  $
// $Copyright:
// Copyright (C) 2013-2024 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include "F28x_Project.h"
#include "F2837xD_Ipc_drivers.h"
#include "Shared_Erase.h"
#include <string.h>
#include "flash_programming_c28.h" // Flash API example header file
#include "c2_bootrom.h"
#include "F021_F2837xD_C28x.h"

#include "config.h"

//
// Function Prototypes
//
extern void Example_Error(Fapi_StatusType status);
extern Uint32 SCI_GetFunction(void);
extern SignalCPU1(void);
void Init_Flash_Sectors(void);

#ifdef _FLASH
//
// These are defined by the linker (see device linker command file)
//
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadSize;
extern Uint16 RamfuncsRunStart;
#endif


#define CPU02TOCPU01_PASSMSG  0x0003FBF4    // Used by CPU02 to pass address
                                            // of local variables to perform
                                            // actions on
// At least 1 volatile global tIpcController instance is required when using
// IPC API Drivers.
volatile tIpcController g_sIpcController1;
volatile tIpcController g_sIpcController2;

volatile uint16_t ErrorFlag;
volatile uint32_t FnCallStatus;

//
// Global variables used in this example to read/write data passed between
// CPU01 and CPU02
//
uint16_t usWWord16;
uint32_t ulWWord32;
uint16_t usCPU02Buffer[256];

//
// Function Prototypes
//
__interrupt void CPU01toCPU02IPC0IntHandler(void);
__interrupt void CPU01toCPU02IPC1IntHandler(void);
void FunctionCall(void);
void FunctionCallParam(uint32_t ulParam);
void Error (void);


uint32_t main(void)
{
    //
    //SCIB Flush
    //
//    while(!ScibRegs.SCICTL2.bit.TXEMPTY)
//    {
//    }
    uint32_t *pulMsgRam;
    uint16_t counter;

    //
    // Copy time critical code and Flash setup code to RAM
    // This includes InitFlash(), Flash API functions and any functions that are
    // assigned to ramfuncs section.
    // The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
    // symbols are created by the linker. Refer to the device .cmd file.
    //
//    #ifdef _FLASH
//      memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
//    #endif

    //
    // Step 1. Initialize System Control:
    // PLL, WatchDog, enable Peripheral Clocks
    // This example function is found in the F2837xD_SysCtrl.c file.
    InitSysCtrl();

    //
    // Call Flash Initialization to setup flash waitstates
    // This function must reside in RAM
//    #ifdef _FLASH
//       InitFlash();
//    #endif

//
// Step 2. Initialize GPIO:
// This example function is found in the F2837xD_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
//
    //InitGpio();

//
// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
//
    DINT;

//
// Initialize the PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.
// This function is found in the F2837xD_PieCtrl.c file.
//
    InitPieCtrl();

//
// Disable CPU interrupts and clear all CPU interrupt flags:
//
    IER = 0x0000;
    IFR = 0x0000;

//
// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in F2837xD_DefaultIsr.c.
// This function is found in F2837xD_PieVect.c.
//
    InitPieVectTable();

        //GPIO_SetupPinMux(31, GPIO_MUX_CPU2, 0);
        //sGPIO_SetupPinOptions(31, GPIO_OUTPUT, GPIO_PUSHPULL);
    int i = 0;
    for(i=0;i < 5;i++)
    {
        GPIO_WritePin(RED_LED, 0);
        DELAY_US(1000*100);
        GPIO_WritePin(RED_LED, 1);
        DELAY_US(1000*300);
    }


    Uint16 x = 0;
    for(x = 0; x < 32676; x++){}
    for(x = 0; x < 32676; x++){}

    IpcRegs.IPCBOOTSTS = C2_BOOTROM_BOOTSTS_SYSTEM_READY;

    while(IpcRegs.IPCBOOTMODE != C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH){}

    EINT; //enable global interrupt INTM
    ERTM; //enable global realtime interrupt




    //
    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.IPC0_INT = &CPU01toCPU02IPC0IntHandler;
    PieVectTable.IPC1_INT = &CPU01toCPU02IPC1IntHandler;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    //
    // Step 4. Initialize the Device Peripherals:
    IPCInitialize(&g_sIpcController1, IPC_INT0, IPC_INT0);
    IPCInitialize(&g_sIpcController2, IPC_INT1, IPC_INT1);

    //
    // Step 5. User specific code, enable interrupts:

    // Enable CPU INT1 which is connected to Upper PIE IPC INT0-3
    IER |= M_INT1;

    // Enable CPU01 to CPU02 INTn in the PIE: Group 11 interrupts
    PieCtrlRegs.PIEIER1.bit.INTx13 = 1;   // CPU1 to CPU2 INT0
    PieCtrlRegs.PIEIER1.bit.INTx14 = 1;   // CPU1 to CPU2 INT1

    //
    // Enable global Interrupts and higher priority real-time debug events:
    //
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM

    ErrorFlag = 0;
    FnCallStatus = 0;
    usWWord16 = 0;
    ulWWord32 = 0;
    for(counter = 0; counter < 256; counter++)
    {
        usCPU02Buffer[counter] = 0;
    }

    // Point array to address in CPU02 TO CPU01 MSGRAM for passing
    // variable locations
    pulMsgRam = (void *)CPU02TOCPU01_PASSMSG;

    // Write addresses of variables where words should be written to pulMsgRam
    // array.
    // 0 = Address of 16-bit word to write to.
    // 1 = Address of 32-bit word to write to.
    // 2 = Address of buffer to block write to.
    // 3 = Address of FunctionCall() function to call.
    // 4 = Address of FunctionCallParam() function to call.
    // 5 = Address of 32-bit FnCallStatus variable to check function call executed
    pulMsgRam[0] = (uint32_t)&usWWord16;
    pulMsgRam[1] = (uint32_t)&ulWWord32;
    pulMsgRam[2] = (uint32_t)&usCPU02Buffer[0];
    pulMsgRam[3] = (uint32_t)&FunctionCall;
    pulMsgRam[4] = (uint32_t)&FunctionCallParam;
    pulMsgRam[5] = (uint32_t)&FnCallStatus;

    // Flag to CPU01 that the variables are ready in MSG RAM with CPU02 TO
    // CPU01 IPC Flag 17
    IpcRegs.IPCSET.bit.IPC17 = 1;

    while(true)
    {
//        for(i=0;i < 3;i++)
//        {
//            GPIO_WritePin(RED_LED, 0);
//            DELAY_US(1000*600);
//            GPIO_WritePin(RED_LED, 1);
//            DELAY_US(1000*100);
//        }
//        DELAY_US(1000*5000);
//        for(i=0;i < IpcRegs.IPCBOOTMODE;i++)
//        {
//            GPIO_WritePin(RED_LED, 0);
//            DELAY_US(1000*500);
//            GPIO_WritePin(RED_LED, 1);
//            DELAY_US(1000*500);
//        }
       DELAY_US(1000*4000);
//
//       GPIO_SetupPinMux(RED_LED, GPIO_MUX_CPU2, 0);
//       GPIO_SetupPinOptions(RED_LED, GPIO_OUTPUT, GPIO_PUSHPULL);
       int i = 0;
       for(i=0;i < 3;i++)
       {
           GPIO_WritePin(RED_LED, 0);
           DELAY_US(1000*200);
           GPIO_WritePin(RED_LED, 1);
           DELAY_US(1000*300);
       }

    }


    // Gain pump semaphore
    // Flash pump is only 1, use either by CPU1 or CPU2
    SeizeFlashPump();
    Init_Flash_Sectors();
    //put GetFunction here
    uint32_t EntryAddr = SCI_GetFunction();

    // Leave control over flash pump
    SignalCPU1();
    return EntryAddr; //load entry address of application into
                      //RPC: return program counter
}


// Init_Flash_Sectors - Initialize Flash Sectors
void Init_Flash_Sectors(void)
{
    EALLOW;
    Flash0EccRegs.ECC_ENABLE.bit.ENABLE = 0x0;
    Fapi_StatusType oReturnCheck;
    oReturnCheck = Fapi_initializeAPI(F021_CPU0_BASE_ADDRESS, 150);

    if(oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }

    oReturnCheck = Fapi_setActiveFlashBank(Fapi_FlashBank0);

    if(oReturnCheck != Fapi_Status_Success)
    {
        Example_Error(oReturnCheck);
    }
    Flash0EccRegs.ECC_ENABLE.bit.ENABLE = 0xA;
    EDIS;
}

// FunctionCall - Function run by IPC_FUNC_CALL command
void FunctionCall(void)
{
    FnCallStatus = 1;
}

// FunctionCallParam - Set the call status param
void FunctionCallParam(uint32_t ulParam)
{
    FnCallStatus = ulParam;
}

// Error - Function to Indicate an Error has Occurred
//         (Invalid Command Received).
void Error(void)
{
    // An error has occurred (invalid command received). Loop forever.
    for (;;)
    {
        int i;
        for(i=0;i < 5;i++)
       {
           GPIO_WritePin(RED_LED, 0);
           DELAY_US(1000*10);
           GPIO_WritePin(RED_LED, 1);
           DELAY_US(1000*30);
       }

    }
}


// CPU01toCPU02IPC0IntHandler - Handles Data Word Reads/Writes
__interrupt void CPU01toCPU02IPC0IntHandler (void)
{
    tIpcMessage sMessage;

//    GPIO_WritePin(RED_LED, !GPIO_ReadPin(RED_LED));
    // Continue processing messages as long as CPU01toCPU02 GetBuffer1 is full
    while(IpcGet(&g_sIpcController1, &sMessage,DISABLE_BLOCKING)!= STATUS_FAIL)
    {
        switch (sMessage.ulcommand)
        {
            case IPC_SET_BITS:
                 //IPCRtoLSetBits(&sMessage);
                 break;
            case IPC_CLEAR_BITS:
                //IPCRtoLClearBits(&sMessage);
                break;
            case IPC_DATA_WRITE:
//                IPCRtoLDataWrite(&sMessage);
                break;
            case IPC_DATA_READ:
//                IPCRtoLDataRead(&g_sIpcController1, &sMessage,
//                                ENABLE_BLOCKING);
                break;
            case IPC_FUNC_CALL:
//                IPCRtoLFunctionCall(&sMessage);
                break;
            default:
                ErrorFlag = 1;
                break;
        }
    }
    // Acknowledge IPC INT0 Flag and PIE to receive more interrupts
    IpcRegs.IPCACK.bit.IPC0 = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

// CPU01toCPU02IPC1IntHandler - Handles Data Block Reads/Writes
__interrupt void CPU01toCPU02IPC1IntHandler (void)
{
    tIpcMessage sMessage;

//    GPIO_WritePin(RED_LED, !GPIO_ReadPin(RED_LED));
    // Continue processing messages as long as CPU01toCPU02 GetBuffer2 is full
    while(IpcGet(&g_sIpcController2, &sMessage,DISABLE_BLOCKING)!= STATUS_FAIL)
    {
        switch (sMessage.ulcommand)
        {
            case IPC_BLOCK_WRITE:
                //sMessage.uldataw2 = sMessage.uldataw2*2;
//                GPIO_WritePin(RED_LED, !GPIO_ReadPin(RED_LED));
                //IPCRtoLBlockWrite(&sMessage);
                break;
            case IPC_BLOCK_READ:
//                GPIO_WritePin(RED_LED, !GPIO_ReadPin(RED_LED));
                //IPCRtoLBlockRead(&sMessage);
                break;
            default:
                ErrorFlag = 1;
                break;
        }
    }

    // Acknowledge IPC INT1 Flag and PIE to receive more interrupts
    IpcRegs.IPCACK.bit.IPC1 = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}


//
// Example_Error - For this example, if an error is found just stop here
#ifdef __TI_COMPILER_VERSION__
    #if __TI_COMPILER_VERSION__ >= 15009000
        #pragma CODE_SECTION(Example_Error,".TI.ramfunc");
    #else
        #pragma CODE_SECTION(Example_Error,"ramfuncs");
    #endif
#endif
void Example_Error(Fapi_StatusType status)
{
    //
    //  Error code will be in the status parameter
    __asm("    ESTOP0");
}
