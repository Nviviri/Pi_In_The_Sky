#include "sensor.h"
#include "SerialLink.h"
#include "sensor.h"
#include "OpenInterfaceConfig.h"
#include "ParLoop.h"

#include <iostream>

using namespace std;
extern SerialLink sl;

Sensor::Sensor():
  getSensorData_(std::bind(&Sensor::getSensor(), this), 3)
{
  wall_ = 0;
  cliffRight_ = 0;
  cliffFrontLeft_ = 0;
  cliffFrontRight_ = 0;
  charge_ = 0;
  capacity_ = 0;
  distance_ = 0;
  angle_ = 0;
  buttons_ = 0;



}

void Sensor::initialise() 
{
  wall_ = 0;
  cliffLeft_ = 0;
  cliffRight_ = 0;
  cliffFrontLeft_ = 0;
  cliffFrontRight_ = 0;
  charge_ = 0;
  capacity_ = 0;
  distance_ = 0;
  angle_ = 0;
  buttons_ = 0;
  cout << "Sensor Initialised." << endl;
  
  
}

void Sensor::getSensor() 
{
 std::vector<uint8_t> data{};
  data = sl.writeRead(reqAllData(),26);
  wall_ = data[1];
  buttons_ = data[11];
  cliffLeft_ = data[2];
  cliffRight_ = data[5];
  cliffFrontLeft_ = data[3];
  cliffFrontRight_ = data[4];
  distance_ = (uint16_t)data[12] << 8) | data[12];
  angle_ =(uint16_t)data[13] << 8) | data[13];
  charge_ = ((uint16_t)data[22] << 8) | data[23];
  capacity_ = ((uint16_t)data[24] << 8) | data[25];
cout << "Read Sensors" << endl;

}

void Sensor::reset() 
{
  wall_ = 0;
  cliffLeft_ = 0;
  cliffRight_ = 0;
  cliffFrontLeft_ = 0;
  cliffFrontRight_ = 0;
  charge_ = 0;
  capacity_ = 0;
  distance_ = 0;
  angle_ = 0;
  buttons_ = 0;
   cout << "Sensor reset." << endl;
}

void Sensor::shutdown() 
{
  wall_ = 0;
  cliffLeft_ = 0;
  cliffRight_ = 0;
  cliffFrontLeft_ = 0;
  cliffFrontRight_ = 0;
  charge_ = 0;
  capacity_ = 0;
  distance_ = 0;
  angle_ = 0;
  buttons_ = 0;
   cout << "Sensor shutdown." << endl;
}
