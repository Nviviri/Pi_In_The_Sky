#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <map>
#include <functional>

using commandfunction = std::function<void()>;

class CommandProcessor
{
public:
   CommandProcessor();
   void executeCommand(const std::string &command);
   void addCommand(const std::string s, commandfunction c);

private:
   std::map<std::string, commandfunction> commands_;
};

#endif // COMMANDPROCESSOR_H
