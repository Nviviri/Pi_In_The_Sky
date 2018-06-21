#include "AppInfo.h"
#include "RandomWalk.h"
#include "SenseHAT.h"

#include <iostream>
#include <iomanip>
#include <string>

/// Shows 3 pixels doing a random walk, and the measured pressure and huminity
/// value.
/// @bug Writing to pixels to the led matrix is not thread safe.
int main(int argc, char *argv[])
{
   try
   {
      std::cout << "-- Application: " << APPNAME_VERSION << " started\n\n"; 
      
      SenseHAT sensehat;

      sensehat.leds.clear();

      RandomWalk rw1{sensehat.leds, Pixel{200, 0, 0}};
      RandomWalk rw2{sensehat.leds, Pixel{0, 200, 0}};
      RandomWalk rw3{sensehat.leds, Pixel{200, 0, 200}};
      RandomWalk rw4{sensehat.leds, Pixel::GREY};
      
      std::cout << "-- Pressure    = " 
                << sensehat.get_pressure() << std::endl;
      std::cout << "-- Humidity    = " 
                << sensehat.get_humidity() << std::endl;
      std::cout << "-- Temperature = " 
                << sensehat.get_temperature_from_humidity() << std::endl;
      std::cout << "-- Temperature = " 
                << sensehat.get_temperature_from_pressure() << std::endl;
      std::cout << "-- Temperature = " 
                << sensehat.get_temperature() << std::endl;
      
      std::cout << "-- Press a key ...";
      std::cin.get();
   }
   catch(std::exception& e)
   {
      std::cerr << "-- Exception " << e.what() << std::endl;
   }
   catch(...)
   {
      std::cerr << "-- UNKNOWN EXCEPTION\n";
   }

   std::cout << "\n-- Application: " << APPNAME_VERSION << " stopped"
             << std::endl << std::endl;

   return 0;
}

