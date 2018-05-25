#ifndef ONOFFCONTROLLER_H
#define ONOFFCONTROLLER_H

/// @todo Implement class as functor.
class OnOffController
{
public:
   OnOffController();
   ~OnOffController();
   void setInput(double input);
   void setSetPoint(double setpoint);
   bool getOutput();
private:
   double input_;
   double setpoint_;
   bool output_;
};

#endif
