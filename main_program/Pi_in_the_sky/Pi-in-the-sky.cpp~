#include <iostream>
#include <array>
#include <vector>
#include "device.h"
#include "nulldevice.h"
#include "motor.h"
#include "dataframe.h"
#include "dofxyrz.h"
#include "commandprocessor.h"

const double PI{3.14159265358979323846};
const double DELTA_t_sec{0.1};
const double MAX_t_sec{10.0};
double velocity{0.2}; // m/sec
double angular_velocity{0.25 * PI}; // rad/sec
double t_sec = 0.0;

int main()
{   
	//dataframe
	std::array<uint8_t, 255> data1 ={19, 5, 29, 2, 25, 13, 0};
	Dataframe sampleData(data1);
   
	//map 
	DOFxyRz roomba;
	/*
	ofstream myfile;
	myfile.open ("movement.csv");
	myfile << "This is the first cell in the first column.\n";

	while (t_sec <= MAX_t_sec)
	{
		cout << "t = " << t_sec << " " << roomba;
		myfile << t_sec << "," << roomba.getX() << "," << roomba.getY() <<"\n";
		// Calculate rotation
		roomba += angular_velocity * DELTA_t_sec;
		// Calculate translation
		CartVec2D delta_heading =  roomba.heading() * velocity * DELTA_t_sec;
		roomba += delta_heading;
		t_sec += DELTA_t_sec;
	}
	myfile.close();
	*/
	
	//motors & commandprocessor
    Motor m1("motor1");
    Motor m2("motor2");
	commandfunction c_getSpeed = std::bind(&Motor::getSpeed, &m1);
	commandfunction c_start = std::bind(&Motor::initialise,&m1);
	commandfunction c_shutdown =std::bind(&Motor::shutdown,&m1);
	commandfunction c_reset = std::bind(&Motor::reset,&m1);
	commandfunction c_incRPM = std::bind(&Motor::incRpm,&m1);
	commandfunction c_decRPM = std::bind(&Motor::decRpm,&m1);
	CommandProcessor cmd1;

	cmd1.addCommand("getspeed", c_getSpeed);
	cmd1.addCommand("start", c_start);
	cmd1.addCommand("shutdown", c_shutdown);
	cmd1.addCommand("reset", c_reset);
	cmd1.addCommand("incRPM", c_incRPM);
	cmd1.addCommand("decRPM", c_decRPM);

	//devices
	std::vector<Device*> devices{&m1,&m2};
	for(auto e: devices)
    {
        std::cout << e -> getID() << std::endl;
        e -> reset();
    }
	
	cout << "Motor Control Console" << endl << "Please type your command\n" << endl;
	cout << "#getspeed\n"
           "#start\n"
           "#shutdown\n"
           "#reset\n"
           "#incRPM\n"
           "#decRPM\n"
            <<endl;

	std::string userInput;
	while(1)
	{
		std::cin >> userInput;
		cmd1.executeCommand(userInput);
	}

}
