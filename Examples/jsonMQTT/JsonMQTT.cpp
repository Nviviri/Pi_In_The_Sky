#include "AppInfo.h"
#include "JsonMQTT.h"
#include "CommandProcessor.h"
#include "MQTTconfig.h"
#include "ParExe.h"
#include <iostream>
#include <string>

using namespace std;

JsonMQTT::JsonMQTT(const std::string& appname,
                   const std::string& clientname,
                   const std::string& host,
                   int port) :
   CommandProcessor(appname, clientname, host, port),
   mqttID_{HOSTNAME + appname + clientname},
   // Data.
   pi_{3.141},
   happy_{true},
   name_{"Niels"},
   list_{1, 0, 2},
   // Empty json data type.
   jsonData_{}
{
   std::cerr << "---- CTOR jsonMQTT host = '" << host
        << "'  port = " << port
        << "  id = " << mqttID_
        << "  topic root = "<< MQTT_TOPIC_ROOT << std::endl;

   data2json();
   std::cerr << "Data in json format = " << jsonData_ << std::endl;
   json2data();
   std::cerr << "Data = " << pi_ << " " << happy_ << " " << name_
             << std::endl;
   // Commands
   registerCommand("getVersion",
                   bind(&JsonMQTT::getVersion, this, placeholders::_1));
   registerCommand("getData",
                   bind(&JsonMQTT::getData, this, placeholders::_1));
}

void JsonMQTT::data2json()
{
   jsonData_["pi"] = pi_;
   jsonData_["happy"] = happy_;
   jsonData_["name"] = name_;
   jsonData_["list"] = list_;
}

void JsonMQTT::json2data()
{
   pi_ = jsonData_["pi"];
   happy_ = jsonData_["happy"];
   name_ = jsonData_["name"];
   // list_ = jsonData_["list"];  // How to do this??
}

void JsonMQTT::getData(const parameters_t& commandParameters)
{
   if (commandParameters.size() != 0)
   {
      publishError(__func__, "number of parameters != 0");
   }
   else
   {
      data2json();
      publishReturn(__func__, jsonData_.dump(4));
   }
}

void JsonMQTT::getVersion(const parameters_t& commandParameters)
{
   if (commandParameters.size() != 0)
   {
      publishError(__func__, "number of parameters != 0");
   }
   else
   {
      json jversion = {
         {"version",
            {
               {"major", MAJOR_VERSION},
               {"minor", MINOR_VERSION},
               {"revision", REVISION_VERSION}
            }
         }
      };
      publishReturn(__func__, jversion.dump(4));
   }
}
