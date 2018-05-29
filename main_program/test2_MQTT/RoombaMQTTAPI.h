#ifndef ROOMBAMQTTAPI_H
#define ROOMBAMQTTAPI_H

#include "pilot.h"
#include <CommandProcessor.h>
#include <functional>
#include <string>
#include <vector>

//register commands to pilot functions
class RoombaMQTTAPI
{
public:
   RoombaMQTTAPI(CommandProcessor& commandProcessor, Pilot& pilot):
      commandProcessor_{commandProcessor},
      matt_{pilot}
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

   void goStraight(const std::vector<std::string>& commandParameters)
   {
      if (commandParameters.size() == 0)
      {
         matt_.goStraight();
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
      }
      else
      {
         commandProcessor_.publishError(__func__, "number of parameters != 0");
      }
   }
};

#endif
