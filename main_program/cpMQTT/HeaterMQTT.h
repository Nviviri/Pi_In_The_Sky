#ifndef HEATERMQTT_H
#define HEATERMQTT_H

#include "CommandProcessor.h"

#include <string>
#include <vector>

using parameters_t = std::vector<std::string>;

class HeaterMQTT: public CommandProcessor
{
public:
   HeaterMQTT(const std::string& appname,
           const std::string& clientname,
           const std::string& host,
           int port);
   virtual ~HeaterMQTT() = default;
   // class member functions
   void start(const parameters_t& commandParameters);
   void stop(const parameters_t& commandParameters);
};

#endif // HEATERMQTT_H
