#ifndef __SFML_COMMAND_QUEUE__
#define __SFML_COMMAND_QUEUE__

#include "command.hpp"
#include <queue>

class CommandQueue
{
public:
  // CommandQueue();
  void push(const Command& command);
  Command pop();
  bool isEmpty() const;

private:
  std::queue <Command > mQueue;
  
};

#endif
