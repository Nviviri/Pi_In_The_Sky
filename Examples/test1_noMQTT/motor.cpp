#include "motor.h"
#include <iostream>

using namespace std;

void Motor::initialise() 
{
   speed_ = 0;
   cout << "motor init." << endl;
}

void Motor::reset() 
{
   speed_ = 0;
   cout << "motor reset." << endl;
}

void Motor::shutdown() 
{
   speed_ = 0;
   cout << "motor shutdown." << endl;
}

void Motor::setSpeed(double speed)
{
    speed_=speed;
}

double Motor::getSpeed() const
{
  cout << speed_  <<endl;
  return speed_;
}

void Motor::incRpm()
{
  cout << "Increasing speed by 200 rpm." << endl;
   int tempSPD = speed_;
   tempSPD += VARSPD;
   if(tempSPD > POSSPD)
   {
      speed_ = POSSPD;
   }
   else
      speed_ = tempSPD;
}

void Motor::decRpm()
{
   cout << "Decreasing speed by 200 rpm." << endl;
   int tempSPD = speed_;
   tempSPD -= VARSPD;
   if(tempSPD < NEGSPD)
   {
      speed_ = NEGSPD;
   }
   else
      speed_ = tempSPD;
}
