#include "RoboticArm.h"
#include <iostream>
#include "string"
// Imported header file and modules

using namespace std;

/**
* RoboticArm() sets array values that were created in the header file
*
* @param  none
* @return none
*/
RoboticArm::RoboticArm(){
   servo_pin[0] = 29;
   servo_pin[1] = 27;
   servo_pin[2] = 25;
   servo_pin[3] = 23;
   servo_pin[4] = 28;
   servo_position[0] = 1500;
   servo_position[1] = 1500;
   servo_position[2] = 1500;
   servo_position[3] = 1500;
   servo_position[4] = 1500;
 
}

// Destructor that outputs a message
RoboticArm::~RoboticArm(){
   cout << "Terminating Robotic Arm operation" << endl;
}

/**
* SetRegisterBit() sets the bit to a value depending on state in a specified memory location
*
* @param  dataValue binary number
* @param  index of the binary number
* @param  state 0 or 1
* @return dataValue
*/
int RoboticArm::SetRegisterBit(unsigned int dataValue, int index, int state){
    int mask = (1 << index);
    if (state == 1) {
        dataValue = dataValue | mask;
    }
    else {
        dataValue = dataValue & ~mask;
    }
    return dataValue;
}

/**
* PinDirectionSetup() sets the servo pin to be either an input or output
*
* @param  servo_num positive integer [1,5]
* @param  direction 0 or 1
* @return none
*/
void RoboticArm::PinDirectionSetup(int servo_num, int direction){
   int in_out_state = RegisterRead(JP2_BASE);
   in_out_state = SetRegisterBit(in_out_state, servo_pin[servo_num-1], direction);
   RegisterWrite(JP2_BASE, in_out_state);
}

/**
* setServoPosition() Converts the degrees [0 to 180] to position in μsec [600 to 2400] for the
* specified servo and updates the servo_position array for that servo
*
* @param  degrees positive integer
* @param  servo_num positive integer [1,5]
* @return dCycle a pulse in μsec
*/
int RoboticArm::setServoPosition(int degrees, int servo_num){
   int dCycle;
    // Converts degrees to μsec
   dCycle = (degrees*10) + 600;
   servo_position[servo_num-1] = dCycle;
   return dCycle;
}

/**
* GeneratePWM() generates PWM signal
*
* @param  num_periods positive integer
* @param  servo_num positive integer [1,5]
* @return none
*/
void RoboticArm::GeneratePWM(int num_periods, int servo_num){
   int DirBit;
   for(int i=0; i <= num_periods; i++){
      DirBit = RegisterRead(JP2_DDR);
      DirBit = SetRegisterBit(DirBit, servo_pin[servo_num -1], 1);
      RegisterWrite(JP2_DDR, DirBit);
        // The duty cycle is determined by usleep
      usleep(servo_position[servo_num-1]);
      DirBit = SetRegisterBit(DirBit, servo_pin[servo_num -1], 0);
                RegisterWrite(JP2_DDR, DirBit);
      usleep(20000 - servo_position[servo_num-1]);
   }  
}
