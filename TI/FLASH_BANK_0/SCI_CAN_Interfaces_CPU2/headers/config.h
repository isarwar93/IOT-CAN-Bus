#ifndef _CONFIG_H
#define _CONFIG_H

#include "Types.h"
// Total 8 bytes are required to get information about the firmware
// Last byte: -> telling the info about flash bank 0 or 1 in CAA0
// fixed bytes: 0xBBCABBCABBCABB -> 7 bytes
//#pragma DATA_SECTION(const_info, "CONST_INFO")
//extern const uint16 const_info [4];
//
//// 3. Revision information: {2bytes:Major,0:(as comma),2Bytes:Minor,0:(as comma),2bytes:subminor} -> 8 bytes
//#pragma DATA_SECTION(revision_number, "REV_INFO")
//
//extern const uint16 revision_number[5];



#define SCI_B_TX_PIN 18
#define SCI_B_RX_PIN 19

#define BLUE_LED 31
#define RED_LED 34

#endif
