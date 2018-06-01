#include <iostream>
#include <CommandProcessor.h>
#include <dataframe.h>
#include <atomic>
#include "motor.h"
#include "sensor.h"
#include "pilot.h"
#include "AppInfo.h"
#include "RoombaMQTT.h"
#include "RoombaMQTTAPI.h"
#include <MQTTconfig.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <rs232.h>

//parameters for serial link
const int cport_nr = 16;         /* /dev/ttyUSB0 */
const int bdrate = 115200;
const char mode[] = "8N1";

int main()
{   
	try{
		//dataframe
		std::array<uint8_t, 255> data1 ={19, 5, 29, 2, 25, 13, 0};
		Dataframe sampleData(data1);
		
		string mqttBroker{MQTT_LOCAL_BROKER};
		int mqttBrokerPort{MQTT_LOCAL_BROKER_PORT};
		int major{0};
		int minor{0};
		int revision{0};
		cout << "-- MQTT application: " << APPNAME_VERSION << "  ";
		mosqpp::lib_init();
		mosqpp::lib_version(&major, &minor, &revision);
		cout << "uses Mosquitto lib version "
			<< major << '.' << minor << '.' << revision << endl;
			
		if(RS232_OpenComport(cport_nr, bdrate, mode))
		  {
		    std::cout << "Can not open comport\n";
		    return(0);
		  }
	      // First MQTT client.
      //TemperatureConverter tc("Tc", "tc", mqttBroker, mqttBrokerPort);

      // Create devices not dependant on MQTT.
      Pilot goodPilot(0.0, 0.0);
	  Sensor goodSensor("goodsensors");
	  
      // Second MQTT client.
      RoombaMQTT roombaMQTT("client1", "roombaPilot", mqttBroker, mqttBrokerPort);
      RoombaMQTTAPI roombaMQTTapi(roombaMQTT, goodPilot, goodSensor);

      // Checking rc for reconnection, 'clients' is an initializer_list
      auto clients = {static_cast<mosqpp::mosquittopp*>(&roombaMQTT)}; //,
                      //static_cast<mosqpp::mosquittopp*>(&tc)};
					  
	

      while (1)
      {
         for (auto client: clients)
         {
            int rc = client->loop();
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
