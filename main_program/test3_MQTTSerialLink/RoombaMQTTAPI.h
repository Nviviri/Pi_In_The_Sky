#ifndef ROOMBAMQTTAPI_H
#define ROOMBAMQTTAPI_H

#include "pilot.h"
#include "sensor.h"
#include <CommandProcessor.h>
#include <functional>
#include <string>
#include <vector>
#include "rs232.h"

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
		 RS232_cputs(16, "goStraight");
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
      }
      else
      {
         commandProcessor_.publishError(__func__, "number of parameters != 0");
      }
   }
};

#endif
