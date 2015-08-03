#ifndef __SFML_PLAYER__
#define __SFML_PLAYER__

#include "command-queue.hpp"
#include "aircraft.hpp"

#include <SFML/Window/Event.hpp>

#include <map>

class Player
{
public:
  Player();
  
  void handleEvent( const sf::Event& event
                    , CommandQueue& commands);
  void handleRealTimeInput(CommandQueue& commands);

private:

  
};

#endif
