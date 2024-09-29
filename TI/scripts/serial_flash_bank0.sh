# Flash bank 0
/home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -a -sci8 /home/ismail/IOT-CANBus/TI/FLASH_BANK_0/SCI_CAN_Interfaces_CPU1/CPU1_FLASH/SCI_CAN_Interfaces_CPU1.out -o /home/ismail/IOT-CANBus/TI/scripts/firmware_cpu1.txt

sudo /home/ismail/IOT-CANBus/TI/serial_flash_programmer_C2000/serial_flash_programmer/build/serial_flash_programmer -p /dev/ttyUSB1 -b 115200 -d f2837xD -a firmware_cpu1.txt -k F2837xD_sci_flash_kernels_cpu01.txt -m F2837xD_sci_flash_kernels_cpu02.txt -n firmware_cpu2.txt -v
