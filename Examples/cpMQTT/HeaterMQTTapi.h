#ifndef HEATERMQTTAPI_H
#define HEATERMQTTAPI_H

#include "Heater.h"
#include "CommandProcessor.h"
#include <functional>
#include <string>
#include <vector>

class HeaterMQTTapi
{
public:
   HeaterMQTTapi(CommandProcessor& commandProcessor, Heater& heater):
      commandProcessor_{commandProcessor},
      heater_{heater}
   {
      commandProcessor_.registerCommand("heaterON",
                                        std::bind(&HeaterMQTTapi::switchOn,
                                                  this,
                                                  std::placeholders::_1)
                                       );
      commandProcessor_.registerCommand("heaterOFF",
                                        std::bind(&HeaterMQTTapi::switchOff,
                                                  this,
                                                  std::placeholders::_1)
                                       );
   }
private:
   CommandProcessor& commandProcessor_;
   Heater& heater_;

   void switchOn(const std::vector<std::string>& commandParameters)
   {
      if (commandParameters.size() == 0)
      {
         heater_.switchOn();
      }
      else
      {
         commandProcessor_.publishError(__func__, "number of parameters != 0");
      }
   }
   void switchOff(const std::vector<std::string>& commandParameters)
   {
      if (commandParameters.size() == 0)
      {
         heater_.switchOff();
      }
      else
      {
         commandProcessor_.publishError(__func__, "number of parameters != 0");
      }
   }
};

#endif
