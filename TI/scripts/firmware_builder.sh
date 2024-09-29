#/home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -sci8 -a -o /home/ismail/dual_CPU/script/firmware_cpu1.txt /home/ismail/14_sep_dual_cpu/blinky_dc_cpu01/CPU1_FLASH_STANDALONE/blinky_dc_cpu01.out
# /home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -a -sci8 /home/ismail/dual_CPU/sci_ex1_echoback_cpu2/CPU2_FLASH/sci_ex1_echoback_cpu2.out -o /home/ismail/dual_CPU/script/firmware_cpu2.txt

#sudo /home/ismail/ti/serial_flash_programmer_C2000-master/serial_flash_programmer/build/serial_flash_programmer -p /dev/ttyUSB0 -b 115200 -d f2837xD -k F2837xD_sci_flash_kernels_cpu01.txt -a firmware_cpu1.txt -v
# /home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -a -sci8 /home/ismail/TI_mikrokontrollern/sci_flash_kernel/ccs/CPU1_RAM/sci_flash_kernel.out -o /home/ismail/dual_CPU/script/cpu1_kernal.txt
# /home/ismail/ti/C2000Ware_5_02_00_00/device_support/f2837xd/examples/dual/F2837xD_sci_flash_kernels/cpu02/ccs/sci_flash_kernel.out -o /home/ismail/dual_CPU/script/cpu2_kernal.txt



# /home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -sci8 -e 0x082ee7 -a -o /home/ismail/dual_CPU/script/firmware_cpu1.txt /home/ismail/14_sep_dual_cpu/blinky_dc_cpu01/CPU1_FLASH_DEBUG/blinky_dc_cpu01.out

#/home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -sci8  -a -o /home/ismail/dual_CPU/script/firmware_cpu1.txt /home/ismail/dual_CPU/sci_ex1_echoback_cpu1/CPU1_FLASH/sci_ex1_echoback_cpu1.out
#/home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -sci8  -a -o /home/ismail/dual_CPU/script/firmware_cpu2.txt /home/ismail/dual_CPU/sci_ex1_echoback_cpu2/CPU2_FLASH/sci_ex1_echoback_cpu2.out

# /home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -sci8  -a -o /home/ismail/dual_CPU/script/firmware_cpu1.txt /home/ismail/dual_CPU/sci_ex1_echoback_cpu1/CPU1_FLASH/sci_ex1_echoback_cpu1.out

#/home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -sci8 -e 0x080000 -a -o  /home/ismail/dual_CPU/script/firmware_cpu1.txt /home/ismail/live_dfu/sci_flash_kernels/CPU1_FLASH/sci_flash_kernels.out

# Flash bank 0
/home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -a -sci8 /home/ismail/IOT-CANBus/TI/FLASH_BANK_0/SCI_CAN_Interfaces_CPU1/CPU1_FLASH/SCI_CAN_Interfaces_CPU1.out -o /home/ismail/IOT-CANBus/TI/scripts/firmware_cpu1.txt
# Flash bank 1
# /home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -a -sci8 /home/ismail/IOT-CANBus/TI/FLASH_BANK_1/SCI_CAN_Interfaces_CPU1/CPU1_FLASH/SCI_CAN_Interfaces_CPU1.out -o /home/ismail/IOT-CANBus/TI/scripts/firmware_cpu1.txt