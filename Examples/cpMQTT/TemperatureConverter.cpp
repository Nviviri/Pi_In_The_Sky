#include "MQTTconfig.h"
#include "TemperatureConverter.h"
#include "Topic.h"
#include <string>
#include <iostream>

#define CERR std::cerr << className_ << "::" << __func__ << "()\n   "

TemperatureConverter::TemperatureConverter(const std::string& appname,
                                           const std::string& clientname,
                                           const std::string& host,
                                           int port):
   CommandProcessor(appname, clientname, host, port),
   className_{__func__},
   mqttID_{HOSTNAME + appname + clientname}
{
   CERR << " connect() host = '" << host
        << "'  port = " << port
        << "  id = " << mqttID_
        << "  topic root = "<< MQTT_TOPIC_ROOT << std::endl;
   registerCommand("c2f", std::bind(&TemperatureConverter::c2f, this,
                                    std::placeholders::_1));
}

void TemperatureConverter::c2f(const std::vector<std::string>& commandParameters)
{
   // for (auto cmd: commandParameters)
   //     std::cerr << "### "<< cmd << std::endl;
   if (commandParameters.size() == 1)
   {
      double temp_celsius{std::stod(commandParameters[0])};
      std::string temp_fahrenheit {
         std::to_string(temp_celsius * 9.0 / 5.0 + 32.0)};
      publishReturn("c2f", temp_fahrenheit);
   }
   else
   {
      publishError("c2f", "number of parameters != 1");
   }
}
