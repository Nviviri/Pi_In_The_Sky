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
  virtual void reset() override;
  virtual void shutdown() override;
  void setFrontSensor(int reading);
  void setBackSensor(int reading);
  void setLeftSensor(int reading);
  void setRightSensor(int reading);
  int getFrontSensor() const {return frontSensor_};
  int getBackSensor() const{return backSensor_};
  int getLeftSensor() const{return leftSensor_};
  int getRighttSensor() const{return rightSensor_};

 protected:

 private:
  int frontSensor_;
  int backSensor_;
  int leftSensor_;
  int rightSensor_;
};

#endif // Motor_H
