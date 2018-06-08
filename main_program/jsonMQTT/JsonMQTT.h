#ifndef JASONMQTT_H
#define JASONMQTT_H

#include "CommandProcessor.h"
#include "json.hpp"
#include <string>
#include <vector>

using json = nlohmann::json;
using parameters_t = std::vector<std::string>;

/// #JsonMQTT is a MQTT client for showing and creating json messages.
/// @todo Initial version, only shows some json formatted data.
class JsonMQTT: public CommandProcessor
{
public:
   JsonMQTT(const std::string& appname,
            const std::string& clientname,
            const std::string& host,
            int port);
   virtual ~JsonMQTT() = default;
   JsonMQTT(const JsonMQTT &other) = delete;
   JsonMQTT& operator=(const JsonMQTT &other) = delete;

private:
   const std::string mqttID_;
   // Data examples, not in json format.
   double pi_;
   bool happy_;
   std::string name_;
   std::vector<int> list_;
   // json is a first-class data type.
   json jsonData_;

   void data2json();
   void json2data();
   /// MQTT commands
   void getVersion(const parameters_t& commandParameters);
   void getData(const parameters_t& commandParameters);
};

#endif
