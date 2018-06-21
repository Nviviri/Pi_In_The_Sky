#include "clean.h"
#include "pilot.h"
#include "sensor.h"
#include "SerialLink.h"
#include "OpenInterfaceConfig.h"
#include "ParLoop.h"
#include <functional>
extern SerialLink sl;


Clean::Clean(Pilot& pilot, Sensor& sensor):
  matt_{pilot},
  sensor_{sensor},
  basicClean_(std::bind(&Clean::basicClean, this), 3)
{}

void Clean::basicClean()
{
    if (sensor_.wall_ == 0) {
      matt_.drive(200,200);
      sl.write(driveDirect(200,200));
    }
    else {
      matt_.drive(0,200);
      sl.write(driveDirect(0,200));
    }
}
