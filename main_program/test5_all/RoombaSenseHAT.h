#ifndef RoombaSenseHAT_H
#define RoombaSenseHAT_H

#include "ParLoop.h"
#include "SenseHAT.h"


class RoombaSenseHAT: public SenseHAT
{
public:
	RoombaSenseHAT();
	RoombaSenseHAT(const SenseHAT& other) = delete;
	RoombaSenseHAT& operator=(RoombaSenseHAT& other) = delete;
	virtual ~RoombaSenseHAT() = default;
	
	void displayStatus();
	void getRoombaStatus();
	void getMQTTstatus();
	
protected:
   int x_;
   int y_;
   const int min_x_ = 0;
   const int min_y_ = 0;
   const int max_x_ = 7;
   const int max_y_ = 7;

   uint8_t wall_; //range 0-1
   uint8_t buttons_; //range 0-15
   uint16_t charge_; //range 0-65535
   uint16_t capacity_; //range 0-65535

   // SensorHAT LED matrix display
   void clear(int,int,int);
   void blank();
   void invert();
   void setPixel(int,int,int,int,int);
   void getPixel(int,int);
   void invertPixel(int,int);

   // SensorHAT joystick event handlers
   void jsup();
   void jsdown();
   void jsright();
   void jsleft();
   void jspressed();
   void jsany();

};

#endif
