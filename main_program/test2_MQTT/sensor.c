#include "sensor.h"
#include <iostream>

using namespace std;

void Sensor::initialise() 
{
	frontSensor_ = 0;
	backSensor_ = 0;
	leftSensor_ = 0;
	rightSensor_ = 0;
   cout << "Sensor init." << endl;
}

void Sensor::reset() 
{
	frontSensor_ = 0;
	backSensor_ = 0;
	leftSensor_ = 0;
	rightSensor_ = 0;
   cout << "Sensor reset." << endl;
}

void Sensor::shutdown() 
{
 	frontSensor_ = 0;
	backSensor_ = 0;
	leftSensor_ = 0;
	rightSensor_ = 0;
   cout << "Sensor shutdown." << endl;
}

void Sensor::setFrontSensor(int reading)
{
	frontSensor_ = reading;
  cout << "reading sensor from roomba: " << reading << endl;
}

void Sensor::setBackSensor(int reading)
{
	backSensor_ = reading;
  cout << "reading sensor from roomba: " << reading << endl;
}

void Sensor::setLeftSensor(int reading)
{
	leftSensor_ = reading;
  cout << "reading sensor from roomba: " << reading << endl;
}

void Sensor::setRightSensor(int reading)
{
	rightSensor_ = reading;
  cout << "reading sensor from roomba: " << reading << endl;
}
