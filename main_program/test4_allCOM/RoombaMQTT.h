#ifndef ROOMBAMQTT_H
#define ROOMBAMQTT_H

#include <CommandProcessor.h>

#include <string>
#include <vector>

using parameters_t = std::vector<std::string>;

class RoombaMQTT: public CommandProcessor
{
public:
   RoombaMQTT(const std::string& appname,
           const std::string& clientname,
           const std::string& host,
           int port);
   virtual ~RoombaMQTT() = default;
   // class member functions
   void spot(const parameters_t& commandParameters);
   void clean(const parameters_t& commandParameters);
};

#endif // ROOMBAMQTT_H