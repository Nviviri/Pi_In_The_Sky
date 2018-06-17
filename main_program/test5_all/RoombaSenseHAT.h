#ifndef RoombaSenseHAT_H
#define RoombaSenseHAT_H

#include "ParLoop.h"
#include "SenseHAT.h"


class RoombaSenseHAT: public SenseHAT
{
public:
	SenseHAT();
	SenseHAT(const SenseHAT& other) = delete;
	SenseHAT& operator=(SenseHAT& other) = delete;
	virtual ~SenseHAT() = default;
	
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

   // SensorHAT LED matrix display
   void clear();
   void blank();
   void invert();
   void setPixel();
   void getPixel();
   void invertPixel();

   // SensorHAT joystick event handlers
   void jsup();
   void jsdown();
   void jsright();
   void jsleft();
   void jspressed();
   void jsany();

};

#endif
