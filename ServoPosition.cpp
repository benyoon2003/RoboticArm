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
* getServoPosition() receives angle (in degrees) inputs from user
*
* @param  none
* @return getServoPosition() recursively
*/
int getServoPosition() {
   int angle;

   cout << "Enter the angle you want the selected servo motor to move" << endl;
   cin >> angle;

    // In order to reduce servo damage risk
   if (angle >= 20 && angle <= 160){
      return angle;
   }

   else{
      cout << "Not a valid angle" << endl;
      return getServoPosition();
   }  

}

int main()  
{  
  cout << "Program Starting...!" << endl; 
 
// Declare a RoboticArm dynamic object 
  RoboticArm *servo = new RoboticArm;   

   
  int servo_num = getServoNum();
        int servo_position = getServoPosition();

   servo->PinDirectionSetup(servo_num, 1);
   servo->setServoPosition(servo_position, servo_num);
   servo->GeneratePWM(50, servo_num);

// Done
   delete servo;  
} 

