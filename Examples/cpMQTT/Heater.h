#ifndef HEATER_H
#define HEATER_H

#include "Device.h"
#include "HeaterActuator.h"
#include "OnOffController.h"
#include "ParLoop.h"
#include "TemperatureSensor.h"

/// Heater is an active class and IS-A Device containing a TemperatureSensor,
/// OnOffController and a HeaterActuator. 
class Heater: public Device
{
public:
   Heater();
   virtual ~Heater();

   virtual void start() override;
   virtual void restart() override;
   virtual void shutdown() override;

   void switchOn();
   void switchOff();

private:
   double setpoint_;
   TemperatureSensor temperatorSensor_;
   OnOffController onoffController_;
   HeaterActuator heaterActuator_;
   ParLoop control_;

   void control();
};

#endif
