#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include "device.h"

class Motor: public Device
{
 public:
 Motor(const std::string &id) : Device(id), speed_{0}{}
  virtual ~Motor(){setSpeed(0);}
  virtual void initialise() override; // C++11 override specifier
  virtual void reset() override;
  virtual void shutdown() override;
  void setSpeed(int speed);
  int getSpeed() const;
  void incRpm();
  void decRpm();

 protected:

 private:
  int speed_;
  static const int POSSPD = 9000;
  static const int NEGSPD = -9000;
  static const int VARSPD = 200;
};

#endif
