#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor():
   temperatureCelsius_{100.0},
   isRising_{true}
{ }

double TemperatureSensor::getTemperature()
{
   if (isRising_)
   {
      if (temperatureCelsius_ > maxTemperatureCelsius_)
      {
         isRising_ = false;
         temperatureCelsius_ -= 2.25;
      }
      temperatureCelsius_ += 2.25;
   }
   else
   {
      if (temperatureCelsius_ < minTemperatureCelsius_)
      {
         isRising_ = true;
         temperatureCelsius_ += 2.25;
      }
      temperatureCelsius_ -= 2.25;
   }
   return temperatureCelsius_;
}
