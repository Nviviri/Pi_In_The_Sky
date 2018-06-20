#include "RoombaSenseHAT.h"
#include "ParWait.h"
#include "Pixel.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include "SerialLink.h"
#include "OpenInterfaceConfig.h"

using namespace std;
extern SerialLink sl;
extern mqttStatus; 

RoombaSenseHAT::RoombaSenseHAT(Sensor& sensor) :
   SenseHAT(),
   x_{0},
   y_{0},
   wall_{0},
   buttons_{0},
   charge_{0},
   capacity_{0},
   sensor_{sensor}
   displayStatus_(std::bind(&RoombaSenseHAT::displayStatus, this), 10)
{
   leds.clear(Pixel{0, 50, 0});
   
   stick.directionUP = std::bind(&RoombaSenseHAT::jsup, this);
   stick.directionDOWN = std::bind(&RoombaSenseHAT::jsdown, this);
   stick.directionLEFT = std::bind(&RoombaSenseHAT::jsleft, this);
   stick.directionRIGHT = std::bind(&RoombaSenseHAT::jsright, this);
   stick.directionPRESSED = std::bind(&RoombaSenseHAT::jspressed, this);
   stick.directionANY = std::bind(&RoombaSenseHAT::jsany, this);

   leds.setPixel(x_, y_, Pixel{200, 100, 100});
}

void RoombaSenseHAT::blank()
{
    leds.clear();
}

void RoombaSenseHAT::clear(int r, int g, int b)
{
    leds.clear(Pixel(r, g, b));
}

void RoombaSenseHAT::invert()
{
   leds.invert();
}

void RoombaSenseHAT::setPixel(int x, int y, int r, int g, int b)
{
   leds.setPixel(x, y, Pixel(r, g, b));
}

void RoombaSenseHAT::getPixel(int x, int y)
{
      Pixel pixel = leds.getPixel(x, y);
      std::cerr <<  std::to_string(pixel[Pixel::RGB::R])
                                << " " + std::to_string(pixel[Pixel::RGB::G])
                                << " " + std::to_string(pixel[Pixel::RGB::B]) << std::endl;
}

void RoombaSenseHAT::invertPixel(int x, int y)
{
      Pixel pixel{leds.getPixel(x, y)};
      pixel.invert();
      leds.setPixel(x, y, pixel);
}

void RoombaSenseHAT::jsup()
{
   if (y_ > 0)  {
      --y_;
   }
   sl.write(driveDirect(200,200));
   std::cerr << "joy up" << std::endl;
}

void RoombaSenseHAT::jsdown()
{
   if (y_ < max_y_)  {
      ++y_;
   }
   std::cerr << "joy down" << std::endl;
}

void RoombaSenseHAT::jsright()
{
   if (x_ < max_x_) {
      ++x_;
   }
   std::cerr << "joy right" << std::endl;
}

void RoombaSenseHAT::jsleft()
{
   if (x_ > 0) {
      --x_;
   }
   sl.write(driveDirect(0,200));
   std::cerr << "joy left" << std::endl;
}

void RoombaSenseHAT::jspressed()
{
   x_ = 0;
   y_ = 0;
   std::cerr << "joy" << std::endl;
}

void RoombaSenseHAT::jsany()
{
   leds.clear();
   leds.setPixel(x_, y_, Pixel{100, 100, 200});
   std::cerr << "joy any" << std::endl;
}
 

void RoombaSenseHAT::displayStatus()
{
  leds.clear();
  
  if (sensor_.charge_ < 16000){
    leds.setPixel(0,0, Pixel{255, 0, 0});
  }
  else if (sensor_.charge_ < 32000){
    leds.setPixel(0,0, Pixel{255, 0, 0});
    leds.setPixel(0,1, Pixel{255, 0, 0});
  }
  else if (sensor_.charge_ < 48000){
    leds.setPixel(0,0, Pixel{255, 0, 0});
    leds.setPixel(0,1, Pixel{255, 0, 0});
    leds.setPixel(0,2, Pixel{255, 0, 0});
  }
  else{
    leds.setPixel(0,0, Pixel{255, 0, 0});
    leds.setPixel(0,1, Pixel{255, 0, 0});
    leds.setPixel(0,2, Pixel{255, 0, 0});
    leds.setPixel(0,3, Pixel{255, 0, 0});
  }

  if (sensor_.wall_ == 1){
    leds.setPixel(7,7, Pixel{0, 0, 255});
  }
  if (mqttStatus == 0){
    leds.setPixel(0,7, Pixel{0, 255, 0});
  }
  switch (sensor_.buttons_) {
  case 1:
      leds.setPixel(1,7, Pixel{70,130,215});
  case 2:
      leds.setPixel(1,6, Pixel{70,130,215});
  case 4:
      leds.setPixel(1,5, Pixel{70,130,215});
  case 8:
      leds.setPixel(1,4, Pixel{70,130,215});
    }
  
  std::cerr << "displaying on sensehat!" << std::endl; 
}
