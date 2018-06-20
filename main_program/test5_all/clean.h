#ifndef CLEAN_H
#define CLEAN_H

#include "ParLoop.h"
#include "pilot.h"
#include "sensor.h"
#include "SerialLink.h"
#include "OpenInterfaceConfig.h"
#include "ParLoop.h"

class Clean
{
public:
   Clean(Pilot& pilot, Sensor& sensor);

private:
   Pilot& matt_;
   Sensor& sensor_;

protected:
   ParLoop basicClean_;
   void basicClean();
};

#endif
