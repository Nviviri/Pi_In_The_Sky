#ifndef ROOMBAMQTTAPI_H
#define ROOMBAMQTTAPI_H

#include "pilot.h"
#include "sensor.h"
#include "CommandProcessor.h"
#include <functional>
#include <string>
#include <vector>
#include <SenseHAT.h>
#include <Pixel.h>
#include "SerialLink.h"
#include "OpenInterfaceConfig.h"

extern SerialLink sl;

//register commands to pilot and sensor functions
class RoombaMQTTAPI
{
public:
 RoombaMQTTAPI(CommandProcessor& commandProcessor, Pilot& pilot, Sensor& sensor):
  commandProcessor_{commandProcessor},
    matt_{pilot},
      sensor_{sensor},
	senseHAT_{}	     
    {
      commandProcessor_.registerCommand("goStraight",
                                        std::bind(&RoombaMQTTAPI::goStraight,
                                                  this,
                                                  std::placeholders::_1)
                                       );
      commandProcessor_.registerCommand("goLeft",
                                        std::bind(&RoombaMQTTAPI::goLeft,
                                                  this,
                                                  std::placeholders::_1)
                                       );
   }
private:
   CommandProcessor& commandProcessor_;
   Pilot& matt_;
   Sensor& sensor_;
   SenseHAT senseHAT_;
   
   void goStraight(const std::vector<std::string>& commandParameters)
   {
      if (commandParameters.size() == 0)
      {
	 matt_.drive(200,200);
	 sl.write(driveDirect(200,200));
	 senseHAT_.leds.clear();
	 senseHAT_.leds.setPixel(2, 1, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(1, 2, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(2, 2, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(3, 2, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(2, 3, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(2, 4, Pixel(100,100,200));
      }
      else
      {
         commandProcessor_.publishError(__func__, "number of parameters != 0");
      }
   }
   void goLeft(const std::vector<std::string>& commandParameters)
   {
      if (commandParameters.size() == 0)
      {
	 matt_.drive(0,200);
	 sl.write(driveDirect(0,200));
	 //sensor_.setFrontSensor(0);
	 senseHAT_.leds.clear();
	 senseHAT_.leds.setPixel(0, 3, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(1, 3, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(1, 2, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(1, 4, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(2, 3, Pixel(100,100,200));
	 senseHAT_.leds.setPixel(3, 3, Pixel(100,100,200));
      }
      else
      {
         commandProcessor_.publishError(__func__, "number of parameters != 0");
      }
   }
};

#endif
