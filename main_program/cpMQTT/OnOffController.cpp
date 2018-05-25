#include "OnOffController.h"

OnOffController::OnOffController():
   input_{100.0},
   setpoint_{100.0},
   output_{ getOutput() }
{}

OnOffController::~OnOffController()
{
   output_ = 0.0;
}

void OnOffController::setInput(double input)
{
   input_ = input;
}

void OnOffController::setSetPoint(double setpoint)
{
   setpoint_ = setpoint;
}

bool OnOffController::getOutput()
{
   output_ = input_ < setpoint_;
   return output_;
}
