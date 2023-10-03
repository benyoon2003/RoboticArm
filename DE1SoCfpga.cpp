#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <bitset>
#include <math.h>
#include "DE1SoCfpga.h"
using namespace std;
// Imported modules and header file

// Class constructor
DE1SoCfpga::DE1SoCfpga()
{
    int *fdp = &fd;
    // Open /dev/mem to give access to physical addresses
    *fdp = open( "/dev/mem", (O_RDWR | O_SYNC));
    if (*fdp == -1)    //  check for errors in opening /dev/mem
    {
        cout << "ERROR: could not open /dev/mem..." << endl;
        exit(1);
    }

    // Get a mapping from physical addresses to virtual addresses
    char *virtual_base = (char *)mmap (NULL, LW_BRIDGE_SPAN, (PROT_READ |
                                                              PROT_WRITE), MAP_SHARED, *fdp, LW_BRIDGE_BASE);
    if (virtual_base == MAP_FAILED)    // check for errors
    {
        cout << "ERROR: mmap() failed..." << endl;
        close (fd);   // close memory before exiting
        exit(1);        // Returns 1 to the operating system;
    }
    pBase = virtual_base;
}

// Class destructor
DE1SoCfpga::~DE1SoCfpga() {
    // Finalize() function goes here
    if (munmap (pBase, LW_BRIDGE_SPAN) != 0)
    {
        cout << "ERROR: munmap() failed..." << endl;
        exit(1);
    }
    close (fd);   // close memory
}

// Writes a value to a specified place in memory
void DE1SoCfpga::RegisterWrite(unsigned int offset, int value) {
    * (volatile unsigned int *)(pBase + offset) = value;
}

// Reads a value from a specified place in memory
int DE1SoCfpga::RegisterRead(unsigned int offset) {
    return * (volatile unsigned int *)(pBase + offset);
}
