#ifndef PILOT_H
#define PILOT_H

#include <iostream>
#include "motor.h"
#include "dofxyrz.h"

class Pilot
{
 public:
  Pilot(int x, int y): leftMotor_("leftMotor"), rightMotor_("rightMotor"), location_(x, y) {}
  ~Pilot() {}
  
  void drive(int leftSpd, int rightSpd);
  
 protected:

 private:
  Motor leftMotor_;
  Motor rightMotor_;
  DOFxyRz location_;
};

#endif // PILOT_H