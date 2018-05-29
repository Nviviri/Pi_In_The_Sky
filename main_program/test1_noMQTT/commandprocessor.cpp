#include "commandprocessor.h"
#include <iostream>

CommandProcessor::CommandProcessor ():
   commands_{}
{}

void CommandProcessor::executeCommand(const std::string &command)
{
   // p is an iterator
   auto p = commands_.find(command);
   if (p != end(commands_))
   {
      auto commandfunc = (*p).second;
      commandfunc();
   }
   else
   {
      std::cout << "Unknown Command." << std::endl;
   }
}

void CommandProcessor::addCommand(const std::string s, commandfunction c)
{
   //commands_.insert(std::pair<std::string, commandfunction>(s,c));
   commands_[s] = c;
}
