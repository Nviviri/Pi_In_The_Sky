#ifndef HEATERACTUATOR_H
#define HEATERACTUATOR_H

#include "Device.h"

class HeaterActuator: public Device
{
public:
   HeaterActuator();
   virtual ~HeaterActuator();

   virtual void start() override;
   virtual void restart() override;
   virtual void shutdown() override;
   void switchOnOff(bool isOn);
   
private:
   bool isStarted_;
   bool isOn_;
};

#endif
