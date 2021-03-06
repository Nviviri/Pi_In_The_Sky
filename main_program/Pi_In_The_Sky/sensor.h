#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include "device.h"
#include "ParLoop.h"

class Sensor: public Device
{
 public:
  Sensor(const std::string &id);
  virtual ~Sensor(){}
  virtual void initialise() override; // C++11 override specifier
  virtual void reset() override;
  virtual void shutdown() override;

  uint8_t wall_;
  uint8_t cliffLeft_;
  uint8_t cliffRight_;
  uint8_t cliffFrontLeft_;
  uint8_t cliffFrontRight_;
  uint16_t charge_;
  uint16_t capacity_;
  uint16_t distance_;
  uint16_t angle_;
  uint8_t buttons_;
  
  void getSensor();
  
 protected:
  ParLoop getSensorData_;
  
 private:

};

#endif // Motor_H
