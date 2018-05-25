#ifndef TEMPERATURE_CONVERTER_H
#define TEMPERATURE_CONVERTER_H

#include "CommandProcessor.h"
#include <string>
#include <vector>

class TemperatureConverter : public CommandProcessor
{
public:
   TemperatureConverter(const std::string& appname,
                        const std::string& clientname,
                        const std::string& host,
                        int port);
   virtual ~TemperatureConverter() = default;
private:
   const std::string className_;
   const std::string mqttID_;
   void c2f(const std::vector<std::string>& commandParameters);
};

#endif
