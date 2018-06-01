#ifndef ROOMBAMQTTAPI_H
#define ROOMBAMQTTAPI_H

#include "pilot.h"
#include "sensor.h"
#include <CommandProcessor.h>
#include <functional>
#include <string>
#include <vector>
#include <ParLoop.h>
#include <SenseHAT.h>
#include <Pixel.h>

//register commands to pilot functions
class RoombaMQTTAPI
{
public:
   RoombaMQTTAPI(CommandProcessor& commandProcessor, Pilot& pilot, Sensor& sensor):
      commandProcessor_{commandProcessor},
      matt_{pilot},
	  sensor_{sensor}
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

   void goStraight(const std::vector<std::string>& commandParameters)
   {
      if (commandParameters.size() == 0)
      {
         matt_.goStraight();
	 sensor_.setFrontSensor(1);
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
         matt_.turnleft();
	 sensor_.setFrontSensor(0);
	 senseHAT_.leds.cl ear();
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
};

#endif
