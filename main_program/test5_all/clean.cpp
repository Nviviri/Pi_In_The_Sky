#include "sensor.h"
#include "pilot.h"
#include "motor.h"


#include <iostream>



Clean::Clean():
     basicClean_(std::bind(&Clean::basicClean, this), 1)
{


}

void Clean::basicClean()
{
  while(1){
    
   matt_.drive(200,200);
   sl.write(driveDirect(200,200));

  }

}

