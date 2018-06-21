#ifndef DEVICE_H
#define DEVICE_H

class Device
{
public:
   Device() = default;
   virtual ~Device() = default;

   virtual void start() = 0;
   virtual void restart() = 0;
   virtual void shutdown() = 0;
};

#endif
