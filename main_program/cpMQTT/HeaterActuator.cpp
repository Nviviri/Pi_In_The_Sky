#include "HeaterActuator.h"

HeaterActuator::HeaterActuator():
   Device{},
   isStarted_{false},
   isOn_{false}
{}

HeaterActuator::~HeaterActuator()
{
   switchOnOff(false);
}

void HeaterActuator::start()
{
   isStarted_ = true;
}

void HeaterActuator::restart()
{
   start();
}

void HeaterActuator::shutdown()
{
   isStarted_ = false;
}

void HeaterActuator::switchOnOff(bool isOn)
{
   if (isStarted_)
   {
      isOn_ = isOn;
   }
   else
   {
      isOn_ = false;
   }
}
