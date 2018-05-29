#ifndef PILOT_H
#define PILOT_H

#include <iostream>
#include "motor.h"
#include "dofxyrz.h"

class Pilot
{
 public:
  Pilot(double x, double y): leftMotor("leftMotor"), rightMotor("rightMotor"), location(x, y) {}
  ~Pilot() {}
  
  void goStraight();
  void goBack();
  void turnleft();
  void turnright();
  
 protected:

 private:
  Motor leftMotor;
  Motor rightMotor;
  DOFxyRz location;
};

#endif // PILOT_H