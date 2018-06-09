#ifndef ROOMBAMQTT_H
#define ROOMBAMQTT_H

#include "CommandProcessor.h"
#include "json.hpp"
#include "ParLoop.h"
#include <string>
#include <vector>

using json = nlohmann::json;
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
   
protected:
   ParLoop publishHeartBeat_;   
   void pubHeartData();
   
private:
   // json is a first-class data type.
   json jsonData_;
   void data2json();
};

#endif // ROOMBAMQTT_H
