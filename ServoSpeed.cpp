#include <iostream>
#include "RoboticArm.h"
#include "string"

using namespace std;

/**
* getServoNum() receives servo number inputs from user
*
* @param  none
* @return getServoNum() recursively
*/
int getServoNum() {
   int servo_num;

   cout << "Enter the servo motor you would like to control." << endl;
   cout << "Servo 1: Base" << endl;
   cout << "Servo 2: Bicep" << endl;
   cout << "Servo 3: Elbow" << endl;
   cout << "Servo 4: Wrist" << endl;
   cout << "Servo 5: Gripper" << endl;
   
  cin >> servo_num;

   if (servo_num >= 1 && servo_num <= 5) {
      return servo_num;
   } 
  else {
      cout << "Not a valid servo number" << endl;
      return getServoNum();
   }
}

/**
* getStartPosition() receives angle (in degrees) input from user
*
* @param  none
* @return getStartPosition() recursively
*/
int getStartPosition() {
   int angle;

   cout << "Enter the angle you want the selected servo motor to START" << endl;
   cin >> angle;
   
  if (angle >= 20 && angle <= 160){
      return angle;
   }

   else{
      cout << "Not a valid angle" << endl;
      return getStartPosition();
   }  

}

/**
* getEndPosition() receives angle (in degrees) input from user
*
* @param  none
* @return getEndPosition() recursively
*/
int getEndPosition() {
   int angle;

        cout << "Enter the angle you want the selected servo motor to END" << endl;
        cin >> angle;

        if (angle >= 20 && angle <= 160){
                return angle;
        }

        else{
                cout << "Not a valid angle" << endl;
                return getEndPosition();
        }

}

/**
* getRotationalSpeed() receives rotational speed from user
*
* @param  none
* @return speed degrees/second
*/
int getRotationalSpeed() {
   int speed;

   cout << "Enter the rotational speed at which you want the servo to move (degrees/second)" << endl;
   cin >> speed;

   // No defined restraints for entered speed
   return speed;
}


int main()  
{  
  cout << "Program Starting...!" << endl; 
 
// Declare a RoboticArm dynamic object 
  RoboticArm *servo = new RoboticArm;   
 
// Set pin direction to output for all servos (1 = output, 0 = input) 
// Your code here...
    
  // Get information from user
   int servo_num = getServoNum();
    int start_position = getStartPosition();
   int end_position = getEndPosition();
   int speed = getRotationalSpeed();

    // Converts degree to µsec
   int start_pulse = start_position * 10 + 600;
   int end_pulse = end_position * 10 + 600;
   float num_cycles;
   if (start_pulse > end_pulse) {
        // number of periods is frequency multiplied by the difference between start and end position
        // divided by rotational speed
      num_cycles = 50 * ((float) start_position - end_position) / speed;
   } else {
      num_cycles = 50 * ((float) end_position - start_position) / speed;
   }
        int num_periods = (int) num_cycles;

   // Set to initial position and hold for 1 second
   servo->PinDirectionSetup(servo_num, 1);
   servo->setServoPosition(start_position, servo_num);
   servo->GeneratePWM(50, servo_num);

   servo->GenerateVariablePWM(start_pulse, end_pulse, num_periods, servo_num);

// Done  
  delete servo;  
} 

