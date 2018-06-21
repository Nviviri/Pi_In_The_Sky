#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <atomic>
#include "CommandProcessor.h"
#include "dataframe.h"
#include "motor.h"
#include "sensor.h"
#include "pilot.h"
#include "AppInfo.h"
#include "RoombaMQTT.h"
#include "RoombaMQTTAPI.h"
#include "MQTTconfig.h"
#include "SerialLink.h"
#include "OpenInterfaceConfig.h"
#include "RoombaSenseHAT.h"
#include "clean.h"

SerialLink sl{"/dev/ttyUSB0", static_cast<unsigned int>(Baud::ROOMBA_DEFAULT)};
int mqttStatus = 1;

int main(int argc, char *argv[])
{   
  try{
    //dataframe
    //std::array<uint8_t, 255> data1 ={19, 5, 29, 2, 25, 13, 0};
    //Dataframe sampleData(data1);
		
    string mqttBroker{MQTT_LOCAL_BROKER};
    int mqttBrokerPort{MQTT_LOCAL_BROKER_PORT};
    
	/// @warning
    /// No syntax checking implemented.
    switch (argc)
    {
		case 1:
         // Using MQTT_LOCAL_BROKER and MQTT_LOCAL_BROKER_PORT
         break;
		 
		case 2:
         // Using MQTT_LOCAL_BROKER_PORT
         mqttBroker = string(argv[1]);
         break;
		 
		case 3:
         mqttBroker = string(argv[1]);
         mqttBrokerPort = stoi(argv[2]);
         break;
		 
		default:
         cerr << endl << "ERROR command line arguments: "
                         "MQTT <URL broker> <broker port>" << endl;
         exit(EXIT_FAILURE);
      }
    int major{0};
    int minor{0};
    int revision{0};
    cout << "-- MQTT application: " << APPNAME_VERSION << "  ";
    mosqpp::lib_init();
    mosqpp::lib_version(&major, &minor, &revision);
    cout << "uses Mosquitto lib version "
	 << major << '.' << minor << '.' << revision << endl;
	 
	// start serial com control on roomba
    sl.write(startSafe());
	  
    // Create devices not dependant on MQTT.
    Pilot goodPilot(0, 0);
    Sensor goodSensor("goodsensors");
	RoombaSenseHAT goodHat(goodSensor);
	Clean cleaner(goodPilot,goodSensor);
	
    //MQTT client.
    RoombaMQTT roombaMQTT("RM", "rm1", mqttBroker, mqttBrokerPort);
    RoombaMQTTAPI roombaMQTTapi(roombaMQTT, goodPilot, goodSensor);

    // Checking rc for reconnection, 'clients' is an initializer_list
    auto clients = {static_cast<mosqpp::mosquittopp*>(&roombaMQTT)};
    //static_cast<mosqpp::mosquittopp*>(&tc)};
					  

    while (1)
      {
	for (auto client: clients)
	  {
            int rc = client->loop();
	    mqttStatus = rc; 
            if (rc)
	      {
		cerr << "-- MQTT reconnect" << endl;
		client->reconnect();
	      }
	  }
      }
  } //end of try{}
	
  catch(invalid_argument& e)
    {
      cerr << "Exception invalid argument: " << e.what() << std::endl;
    }
  catch(exception& e)
    {
      cerr << "Exception: " << e.what() << std::endl;
    }
  /// @note catch(...): ... ellipsis, catches all unhandled unexpected 
  /// exceptions.
  catch(...)
    {
      cerr << "UNKNOWN EXCEPTION \n";
    }

  cout << "-- MQTT application: " << APPNAME_VERSION << " stopped"
       << endl << endl;
  mosqpp::lib_cleanup();

  return 0;
}	
