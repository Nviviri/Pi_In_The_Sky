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

RoombaSenseHAT::RoombaSenseHAT() :
   SenseHAT(),
   x_{0},
   y_{0},
   wall_{0},
   buttons_{0},
   charge_{0},
   capacity_{0}
   //publishSensorData_(std::bind(&RoombaSenseHAT::handleSensorData, this), 60)
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

void RoombaSenseHAT::getRoombaStatus()
{
  std::vector<uint8_t> data{};
  data = sl.writeRead(reqAllData(),26);
  wall_ = data[1];
  buttons_ = data[11];
  charge_ = ((uint16_t)data[22] << 8) | data[23];
  capacity_ = ((uint16_t)data[24] << 8) | data[25];
}

void RoombaSenseHAT::displayStatus()
{
  std::cerr << "displaying on sensehat!" << std::endl; 
}
