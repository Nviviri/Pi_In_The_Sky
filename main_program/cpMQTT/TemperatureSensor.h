#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

/// Simulates a temperature sensor.
class TemperatureSensor
{
public:
   TemperatureSensor();
   ~TemperatureSensor() = default;

   double getTemperature();
private:
   double temperatureCelsius_;
   // Physics
   bool isRising_;
   double maxTemperatureCelsius_ = 140.0;
   double minTemperatureCelsius_ = 95.0;
};

#endif
