#include "pilot.h"
#include <iostream>

void Pilot::drive(int leftSpd, int rightSpd)
{
	leftMotor_.setSpeed(leftSpd);
	rightMotor_.setSpeed(rightSpd);
	std::cout << "drive motors... Left Motor: " << leftSpd << " Right Motor: " << rightSpd << std::endl;
}
