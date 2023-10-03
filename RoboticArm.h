#ifndef ROBOTICARM_H
#define ROBOTICARM_H
#include "DE1SoCfpga.h"
#include <iostream>

class RoboticArm : public DE1SoCfpga {
private:
int servo_pin[5]; // An array of pin numbers corresponding to each servo
int servo_position[5]; // An array of positions the servo is set to be moved
int SetRegisterBit(unsigned int reg_offset, int bitNumber, int state); // Sets specified bit in the given register

// Function prototypes
public:
RoboticArm();
~RoboticArm();
void PinDirectionSetup(int servo_num, int direction);
int setServoPosition(int degrees, int servo_num);
void GeneratePWM(int num_periods, int servo_num);

};

#endif
