#ifndef CONFIG_H
#define CONFIG_H

#include "MQTTconfig.h"

#include <string>

///subscribe to GOSTRAIGHT_Q (quiestion)
const std::string MQTT_TOPIC_GOSTRAIGHT_Q{MQTT_TOPIC_ROOT + "/goStraightQ"};
///publish GOSTRAIGHT_A in response to the question (for testing purpose)
const std::string MQTT_TOPIC_GOSTRAIGHT_A{MQTT_TOPIC_ROOT + "/goStraightA"};

///subscribe to GOLEFT_Q (quiestion)
const std::string MQTT_TOPIC_GOLEFT_Q{MQTT_TOPIC_ROOT + "/goLeftQ"};
///publish GOLEFT_A in response to the question (for testing purpose)
const std::string MQTT_TOPIC_GOLEFT_A{MQTT_TOPIC_ROOT + "/goLeftA"};

#endif
