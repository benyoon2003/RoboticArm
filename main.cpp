#include <iostream>
#include "RoboticArm.h"
#include "string"

using namespace std;


int main()  
{  
  cout << "Program Starting...!" << endl; 
 
// Declare a RoboticArm dynamic object 
  RoboticArm *servo = new RoboticArm;   
 
// Set pin direction to output for all servos (1 = output, 0 = input) 
// Your code here... 
  for(int i=1; i<6; i++){
      servo->PinDirectionSetup(i, 1);
      servo->setServoPosition(90, i);
      servo->GeneratePWM(50, i);
   }
 
// Done  
  delete servo;  
} 
