#include <iostream>
#include <array>
#include <vector>
#include <device.h>
#include <dofxyrz.h>
#include <CommandProcessor.h>
#include <dataframe.h>
#include <rs232.h>
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

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"


void rx()
{
  int i = 0;
  //const int cport_nr = 0;        /* /dev/ttyS0 (COM1 on windows) */
  const int cport_nr = 16;         /* /dev/ttyUSB0 */
  const int bdrate = 9600;         /* 9600 baud */
  const char mode[] = "8N1";

  const char str[2][512] = {
     {"The quick brown fox jumped over the lazy grey dog.\n"},
     {"Happy serial programming!\n"}
  };

  if(RS232_OpenComport(cport_nr, bdrate, mode))
  {
    printf("Can not open comport\n");
    exit(0);
  }

  while(1)
  {
    RS232_cputs(cport_nr, str[i]);

    printf("sent: %s\n", str[i]);

#ifdef _WIN32
    Sleep(1000);
#else
    usleep(1000000);  /* sleep for 1 Second */
#endif

    i++;
    i %= 2;
  }

  return;
}


int main()
{
  rx();
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
