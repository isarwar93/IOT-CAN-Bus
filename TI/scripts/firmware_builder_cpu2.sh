# /home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -a -sci8 /home/ismail/dual_CPU/sci_ex1_echoback_cpu1/CPU1_FLASH/sci_ex1_echoback_cpu1.out -o /home/ismail/dual_CPU/script/firmware_cpu1.txt
/home/ismail/Downloads/ti-cgt-c2000_22.6.1.LTS/bin/hex2000 -boot -a -sci8 /home/ismail/dual_CPU/sci_ex1_echoback_cpu2/CPU2_FLASH/sci_ex1_echoback_cpu2.out -o /home/ismail/dual_CPU/script/firmware_cpu2.txt

# sudo /home/ismail/ti/serial_flash_programmer_C2000-master/serial_flash_programmer/build/serial_flash_programmer -p /dev/ttyUSB0 -b 115200 -d f2837xD -k F2837xD_sci_flash_kernels_cpu01.txt -a firmware_cpu2.txt -v
