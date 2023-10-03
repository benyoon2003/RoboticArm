#ifndef DE1SOCFPGA_H
#define DE1SOCFPGA_H

// Physical base address of FPGA Devices
const unsigned int LW_BRIDGE_BASE   = 0xFF200000;  // Base offset
// Length of memory-mapped IO window
const unsigned int LW_BRIDGE_SPAN   = 0x00005000;  // Address map size
const unsigned int LEDR_BASE    = 0x00000000;  // Leds offset
const unsigned int SW_BASE     = 0x00000040;  // Switches offset
const unsigned int KEY_BASE     = 0x00000050;  // Push buttons offset

const unsigned int JP2_BASE = 0x00000070;  // J2 Data register
const unsigned int JP2_DDR = 0x00000074; // Data direction


const unsigned int HEX3_HEX0_BASE = 0x00000020; // HEX Reg1 Offset
const unsigned int HEX5_HEX4_BASE = 0x00000030; // HEX Reg2 offset

class DE1SoCfpga {

    char *pBase;
    int fd;

public:
// Function prototypes
    DE1SoCfpga();

    ~DE1SoCfpga();

    void RegisterWrite(unsigned int offset, int value);

    int RegisterRead(unsigned int offset);

};
#endif
