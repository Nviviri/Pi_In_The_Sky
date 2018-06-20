#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include "device.h"

class Sensor: public Device
{
 public:
 Sensor(const std::string &id) : Device(id), frontSensor_{0}, backSensor_{0}, leftSensor_{0}, rightSensor_{0}{}
  virtual ~Sensor(){}
  virtual void initialise() override; // C++11 override specifier
  virtual void getSensor() override;
  virtual void reset() override;
  virtual void shutdown() override;


 protected:
  uint8_t wall_ = 0;
  uint8_t cliffRight_ = 0;
  uint8_t cliffFrontLeft_ = 0;
  uint8_t cliffFrontRight_ = 0;
  uint16_t charge_ = 0;
  uint16_t capacity_ = 0;
  uint16_t distance_ = 0;
  uint16_t angle_ = 0;
  uint8_t buttons_ = 0;

 private:

  
};

#endif // Motor_H
