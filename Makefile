lab5: main.o DE1SoCfpga.o RoboticArm.o
      g++ main.o DE1SoCfpga.o RoboticArm.o -o lab5
main.o: main.cpp DE1SoCfpga.h RoboticArm.h
      g++ -g -Wall -c main.cpp
DE1SoCfpga.o: DE1SoCfpga.h DE1SoCfpga.cpp
      g++ -g -Wall -c DE1SoCfpga.cpp
RoboticArm.o: RoboticArm.h RoboticArm.cpp
      g++ -g -Wall -c RoboticArm.cpp
clean:
      rm -r *o lab5
