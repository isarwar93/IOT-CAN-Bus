//###########################################################################
//
// FILE:   F2837xD_sci_flash_kernels_cpu01.c
//
// TITLE:  Flash Programming Solution using SCI for F2837xD.
//
//! \addtogroup dual_example_list
//! <h1>Flash Programming Solution SCI for Single or Dual Core</h1>
//!
//! In this example, we set up a UART connection with a host using SCI, receive
//! commands for CPU1 to perform which then sends ACK, NAK, and status packets
//! back to the host after receiving and completing the tasks.  This kernel has
//! the ability to program, verify, unlock, reset, run, and boot CPU2 to SCI
//! boot loader.  Each command either expects no data from the command packet
//! or specific data relative to the command.
//!
//! In this example, we set up a UART connection with a host using SCI, receive
//! an application for CPU01 in -sci8 ascii format to run on the device and
//! program it into Flash.
//
//###########################################################################
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
#include "c1_bootrom.h"
#include "F021_F2837xD_C28x.h"

#include "F2837xD_cputimervars.h"

#include "config.h"

//#include "Types.h"
//#include "driverlib.h"
//#include "device.h"


// Defines
//#define C1C2_BROM_IPC_EXECUTE_BOOTMODE_CMD    0x00000013
//#define C1C2_BROM_BOOTMODE_BOOT_FROM_SCI      0x00000001
//#define C1C2_BROM_BOOTMODE_BOOT_FROM_RAM      0x0000000A
//#define C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH    0x0000000B


// Function Prototypes
void Example_Error(Fapi_StatusType status);
void Init_Flash_Sectors(void);
extern Uint32 SCI_GetFunction(Uint32  BootMode);

//
// Defines
//
#define CPU_FREQ        200E6
#define LSPCLK_FREQ     CPU_FREQ/4
#define SCI_FREQ        115200
#define SCI_PRD         ((LSPCLK_FREQ/(SCI_FREQ*8))-1)

//
// Globals
//
uint16_t Send_SCI_Buf[20];    // Send data for SCI-B
uint16_t Receive_SCI_Buf[20];    // Received data for SCI-B

uint16_t Rx_Receive_Byte_Counter;


uint32_t start_time;
uint32_t end_time;



interrupt void scibRxFifoIsr(void);
void scib_fifo_init(void);

//CPUTIMER_VARS CpuTimer0;
void InitCPUTimer0(void)
{
    InitCpuTimers();          // Initialize all CPU timers to a known state
    ConfigCpuTimer(&CpuTimer0, 200, 1000000);  // Initialize CPU Timer 0
    // 200 = System clock in MHz
    // 1000000 = 1 second period (you can adjust this as needed)

    CpuTimer0Regs.TCR.bit.TSS = 0;  // Start CPU Timer 0
}

uint32_t GetElapsedTime(void)
{
    return CpuTimer0Regs.TIM.all;  // Read current value of the timer (decreasing)
}



void scibSendStringM(char *str)
{
    while(*str != '\0')  // Continue until null terminator is encountered
    {
        // Wait until the TX buffer is ready
        while(ScibRegs.SCICTL2.bit.TXRDY == 0);

        // Write data to the TX buffer
        ScibRegs.SCITXBUF.all = *str;

        // Move to the next character
        str++;
    }
}




void scibReceiveStringM(char *buffer, uint16_t length)
{
    uint16_t i;

    for(i = 0; i < length; i++)
    {
        // Wait until the RX buffer has received data
        while(ScibRegs.SCIRXST.bit.RXRDY == 0);

        // Read the received data and store it in the buffer
        buffer[i] = ScibRegs.SCIRXBUF.all;
    }

    // Null-terminate the received string
    buffer[length] = '\0';
}
void clearRAM(void)
{
    Uint32 *ramStart = (Uint32 *)0x00008000;  // Start of RAM
    Uint32 size = (0x0003FFFF - 0x00008000);  // RAM size in bytes

    memset(ramStart, 0x00, size);  // Set all memory to 0x00
}

uint32_t main(void)
{


    // SCIB Flush
    while(!ScibRegs.SCICTL2.bit.TXEMPTY)
    {
    }

    // Step 1. Initialize System Control:
    // Enable Peripheral Clocks
    // This example function is found in the F2837xD_SysCtrl.c file.
    InitSysCtrl(); //PLL activates and copy code from FLASH to RAM
//    clearRAM();      // Call the function to clear RAM

    InitCPUTimer0();        // Initialize and start the timer

    start_time = GetElapsedTime();   // Get the starting time


    // Step 2. Initialize GPIO:
    // This example function is found in the F2837xD_Gpio.c file and
    // illustrates how to set the GPIO to it's default state.
    InitGpio();

    // Blue LED initialization
    GPIO_SetupPinMux(BLUE_LED, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(BLUE_LED, GPIO_OUTPUT, GPIO_PUSHPULL);
    int i = 0;
    for(i=0;i < 5;i++)
    {
        GPIO_WritePin(BLUE_LED, 0);
        DELAY_US(50*1000);
        GPIO_WritePin(BLUE_LED, 1);
        DELAY_US(50*1000);
    }

    // Red LED initialization
    GPIO_SetupPinMux(RED_LED, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(RED_LED, GPIO_OUTPUT, GPIO_PUSHPULL);
    GPIO_WritePin(RED_LED, 1); // Turn off Red LED


    // Initialize GPIO pins for SCI-B
    // 18 -> Tx for SCI-B, 19 -> Rx for SCI-B
    EALLOW;
    GPIO_SetupPinOptions(SCI_B_TX_PIN, GPIO_OUTPUT, GPIO_ASYNC);
    GPIO_SetupPinMux(SCI_B_TX_PIN,GPIO_MUX_CPU1,2);
    GPIO_SetupPinOptions(SCI_B_RX_PIN, GPIO_INPUT, GPIO_PUSHPULL);
    GPIO_SetupPinMux(SCI_B_RX_PIN,GPIO_MUX_CPU1,2);
    EDIS;

    // Step 3. Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    DINT;

    // Initialize PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags
    // are cleared.
    // This function is found in the F2837xD_PieCtrl.c file.
    InitPieCtrl();

    // Disable CPU interrupts and clear all CPU interrupt flags
    IER = 0x0000;
    IFR = 0x0000;

    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    // This will populate the entire table, even if the interrupt
    // is not used in this example.  This is useful for debug purposes.
    // The shell ISR routines are found in F2837xD_DefaultIsr.c.
    // This function is found in F2837xD_PieVect.c.
    InitPieVectTable();

    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.SCIB_RX_INT = &scibRxFifoIsr;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    // Step 4. Initialize the Device Peripherals:
    scib_fifo_init();  // Init SCI-B



    memcpy(Send_SCI_Buf,const_info,4);
    memcpy(Send_SCI_Buf+4,revision_number,5);


    // Enable required  interrupts
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
    PieCtrlRegs.PIEIER9.bit.INTx3 = 1;   // PIE Group 9, INT3 (RX)// from the above vector table sci-b is 9.3 and 9.4
    IER |= M_INT9;                       // Enable CPU INT9
    EINT;


    while(true)
    {
        end_time = GetElapsedTime();     // Get the time after execution

        // Timer is going inverse, so end_time is after
        uint32_t elapsed_time = start_time - end_time;  // Calculate the elapsed time

        // elapsed_time will be in terms of CPU timer ticks
        float elapsed_time_div = (float)elapsed_time / 200.0f;  // For a 200 MHz clock
        if (elapsed_time_div > 3500.0) // -> gives nearly 10 seconds
        {
            Rx_Receive_Byte_Counter = 0;
            memset(Receive_SCI_Buf,0,20);
            for(i=0;i < 5;i++)
            {
                GPIO_WritePin(BLUE_LED, 0);
                DELAY_US(1000*3);
                GPIO_WritePin(BLUE_LED, 1);
                DELAY_US(1000*50);

            }
            start_time = GetElapsedTime();
        }
        DELAY_US(1000*2000);

        if (Receive_SCI_Buf[0] == 0xf0)
        {
            start_time = GetElapsedTime(); // To reset Rx_Receive_Byte_Counter in 10 seconds
            uint16_t counter_flasher = 0;
            counter_flasher++;
            // if 2nd byte 0x0f then flash command is expected
            if (Receive_SCI_Buf[1] == 0x0f)
            {
                for (i = 1; i<8;i++)
                {
                    if (Receive_SCI_Buf[i] == 0x0f)
                    {
                       counter_flasher++;
                    }
                }
                memcpy(Send_SCI_Buf,const_info,4);
                memcpy(Send_SCI_Buf+4,revision_number,5);
                for(i=0; i < 10; i++)
                {
                    // Wait until the TX buffer is ready
                    while(ScibRegs.SCICTL2.bit.TXRDY == 0);
                    ScibRegs.SCITXBUF.all=Send_SCI_Buf[i];  // Send data
                }
                if (counter_flasher == 8) break; // break the loop and wait for the flash instructions
            }
            // if 2nd byte 0x1f then return 10 bytes with the information of current flash bank number
            if (Receive_SCI_Buf[1] == 0x1f)
            {
                memset(Receive_SCI_Buf,0,20);
                memset(Send_SCI_Buf,0,20);
                memcpy(Send_SCI_Buf,const_info,4);
            }
            // if 2nd byte 0x2f then return 10 bytes with the information of current revision number
            if (Receive_SCI_Buf[1] == 0x2f)
            {
                memset(Receive_SCI_Buf,0,20);
                memset(Send_SCI_Buf,0,20);
                memcpy(Send_SCI_Buf,revision_number,5);
            }
            // if 2nd byte 0x3f then go to other flash bank, which is flash bank 1
            if (Receive_SCI_Buf[1] == 0x3f)
            {
                memset(Receive_SCI_Buf,0,20);
                return (uint32_t)0xA0000;
            }
        }

        for(i=0; i < 10; i++)
        {
            // Wait until the TX buffer is ready
            while(ScibRegs.SCICTL2.bit.TXRDY == 0);
            ScibRegs.SCITXBUF.all=Send_SCI_Buf[i];  // Send data
        }
    }
    memset(Receive_SCI_Buf,0,20);
    memset(Send_SCI_Buf,0,20);

    InitIpc();
    InitFlash();

    // Gain pump semaphore
    SeizeFlashPump();
    Init_Flash_Sectors();

    uint32_t EntryAddr;

    for(i=0;i < 3;i++)
    {
        GPIO_WritePin(BLUE_LED, 0);
        DELAY_US(1000*500);
        GPIO_WritePin(BLUE_LED, 1);
        DELAY_US(1000*500);
    }
    EntryAddr = SCI_GetFunction(SCI_BOOT);
    return(EntryAddr);
}


// Init_Flash_Sectors - Initialize flash API and active flash bank sectors
void Init_Flash_Sectors(void)
{
    EALLOW;
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
    EDIS;
}


// sciaRxFifoIsr - SCIB Receive FIFO ISR
interrupt void scibRxFifoIsr(void)
{

    Receive_SCI_Buf[Rx_Receive_Byte_Counter]=(uint16_t)ScibRegs.SCIRXBUF.all;  // Read data
    Rx_Receive_Byte_Counter++;
    // 8 Bytes are required atleast to do some other functionality
    if (Rx_Receive_Byte_Counter == 8) Rx_Receive_Byte_Counter = 0;


    ScibRegs.SCIFFRX.bit.RXFFOVRCLR=1;   // Clear Overflow flag
    ScibRegs.SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag

    PieCtrlRegs.PIEACK.all |= 0x100;       // Issue PIE ack
}


// scib_fifo_init - Configure SCIA FIFO
void scib_fifo_init()
{
    // Enable the SCI-B clocks
    EALLOW;

    // Step 1: Reset SCI-B before configuration
    ScibRegs.SCICTL1.bit.SWRESET = 0;  // Put SCI-B in reset

    CpuSysRegs.PCLKCR7.bit.SCI_B = 1;
    ClkCfgRegs.LOSPCP.all = 0x0007;
    ScibRegs.SCIFFTX.all = 0x8000;

    // 13 -> works for 115200 Baud
    // 26 -> works for 57600 Baud
    // 52 -> works for 38400 Baud
    // Step 2: Configure baud rate
    // Use the calculated SCI_PRD value (26 for 115200 baud)
    ScibRegs.SCIHBAUD.all = (13 >> 8) & 0xFF;  // High byte of the baud register
    ScibRegs.SCILBAUD.all = 15 & 0xFF;         // Low byte of the baud register

    // Step 3: Configure SCI control registers
    ScibRegs.SCICCR.bit.STOPBITS = 0;  // 1 stop bit
    ScibRegs.SCICCR.bit.PARITY = 0;    // No parity
    ScibRegs.SCICCR.bit.PARITYENA = 0; // Disable parity check
    ScibRegs.SCICCR.bit.SCICHAR = 7;   // 8-bit character length

    // Step 4: Enable transmitter and receiver
    ScibRegs.SCICTL1.bit.TXENA = 1;    // Enable transmitter
    ScibRegs.SCICTL1.bit.RXENA = 1;    // Enable receiver

    //interrupt when the SCI receives a new character or detects a Break Condition
    ScibRegs.SCICTL2.bit.RXBKINTENA = 1;

//    SciaRegs.SCIFFTX.all = 0xC022;
    //    ScibRegs.SCIFFRX.all = 0x002
//    ScibRegs.SCIFFRX.bit.RXFFIL = 4;//4->RX FIFO interrupt level set to 4 words before triggering;
//    ScibRegs.SCIFFRX.bit.RXFFIENA = 1; // Enable RX FIFO interrupt

    ScibRegs.SCIFFCT.all = 0x00;

    // Step 6: Clear FIFO flags
    ScibRegs.SCIFFRX.bit.RXFFINTCLR = 1;   // Clear RX FIFO interrupt flag

    // Step 7: Release SCI from reset
    ScibRegs.SCICTL1.bit.SWRESET = 1;      // Release from reset

    EDIS;
}

//
// Example_Error - For this example, if an error is found just stop here
//
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
    // Error code will be in the status parameter
    //
    __asm("    ESTOP0");
}



