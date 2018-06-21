#include "Device.h"
#include "HeaterActuator.h"
#include "Heater.h"
#include "OnOffController.h"
#include "ParLoop.h"
#include "TemperatureSensor.h"
#include <iostream>

Heater::Heater():
   Device{},
   setpoint_{120.5},
   temperatorSensor_{},
   onoffController_{},
   heaterActuator_{},
   control_{std::bind(&Heater::control, this), 1}
{
   onoffController_.setSetPoint(setpoint_);
   start();
}

Heater::~Heater()
{
   shutdown();
}

void Heater::start()
{
   heaterActuator_.start();
}

void Heater::restart()
{
   heaterActuator_.restart();
}

void Heater::shutdown()
{
   heaterActuator_.shutdown();
}

void Heater::switchOn()
{
   std::cerr << "--HW " << __func__ << "\n";
}

void Heater::switchOff()
{
   std::cerr << "--HW " << __func__ << "\n";
}

void Heater::control()
{
   double temperature{temperatorSensor_.getTemperature()};
   std::cerr << "-- Heater " << __func__ << " " << temperature;
   onoffController_.setInput(temperature);
   bool onoff{onoffController_.getOutput()};
   heaterActuator_.switchOnOff(onoff);
   std::cerr << " on/off = " << onoffController_.getOutput() << "\n";
}
