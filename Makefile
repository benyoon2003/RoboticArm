lab5: ServoSpeed.o DE1SoCfpga.o RoboticArm.o
      g++ ServoSpeed.o DE1SoCfpga.o RoboticArm.o -o lab5
main.o: ServoSpeed.cpp DE1SoCfpga.h RoboticArm.h
      g++ -g -Wall -c ServoSpeed.cpp
DE1SoCfpga.o: DE1SoCfpga.h DE1SoCfpga.cpp
      g++ -g -Wall -c DE1SoCfpga.cpp
RoboticArm.o: RoboticArm.h RoboticArm.cpp
      g++ -g -Wall -c RoboticArm.cpp
clean:
      rm -r *o lab5
