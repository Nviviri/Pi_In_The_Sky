#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include "device.h"

class Sensor: public Device
{
 public:
 Sensor(const std::string &id) : Device(id), {}
  virtual ~Sensor(){}
  virtual void initialise() override; // C++11 override specifier
  void getSensor();
  virtual void reset() override;
  virtual void shutdown() override;


 protected:
  uint8_t wall_;
  uint8_t cliffRight_;
  uint8_t cliffFrontLeft_;
  uint8_t cliffFrontRight_;
  uint16_t charge_;
  uint16_t capacity_;
  uint16_t distance_;
  uint16_t angle_;
  uint8_t buttons_;

 private:

  
};

#endif // Motor_H
