#include "RoombaMQTT.h"
#include <iostream>

//RoombaMQTT is derived from CommandProcessor
RoombaMQTT::RoombaMQTT(const std::string& appname,
                 const std::string& clientname,
                 const std::string& host,
                 int port):
   CommandProcessor(appname, clientname, host, port)
{
   // Register C++-functions by MQTT topics/messages.
   // C++11 bind(): binds one or more arguments to a function object.
   // C++11 std::placeholders::_N placeholder object N is stored in the
   // generated function object, an argument with placeholders::_1 is replaced
   // by the first argument in the call.
   registerCommand("start",
                   bind(&RoombaMQTT::start, this, std::placeholders::_1));
   registerCommand("stop",
                   bind(&RoombaMQTT::stop, this, std::placeholders::_1));
}

// Class member function
void RoombaMQTT::start(const parameters_t& commandParameters)
{
   if (commandParameters.size() != 0)
   {
      publishError(__func__, "number of parameters != 0");
   }
   else
   {
      std::cerr << "RoombaMQTT::start() " ;
      for (const auto& s: commandParameters)
      {
         std::cerr << s << " ";
      }
      std::cerr << std::endl;
   }
}

// Class member function
void RoombaMQTT::stop(const parameters_t& commandParameters)
{
   if (commandParameters.size() != 0)
   {
      publishError("stop", "number of parameters != 0");
   }
   else
   {
      std::cerr << "RoombaMQTT::stop() ";
      for (const auto& s: commandParameters)
      {
         std::cerr << s << " ";
      }
      std::cerr << std::endl;
   }
}
