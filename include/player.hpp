#ifndef __SFML_PLAYER__
#define __SFML_PLAYER__

#include "command-queue.hpp"
#include "aircraft.hpp"

#include <SFML/Window/Event.hpp>

#include <map>

class Player
{
public:
  enum Action
  {
    MoveLeft,
    MoveRight,
    MoveUp,
    MoveDown,
    ActionCount,
  };
  Player();
  
  void handleEvent( const sf::Event& event
                    , CommandQueue& commands);
  void handleRealTimeInput(CommandQueue& commands);

  void assignKey(Action action, sf::Keyboard::Key key);
  sf::Keyboard::Key getAssignedKey(Action action) const;

private:
  static bool isRealTimeAction(Action action);
  void initializeActions();
private:
  std::map<sf::Keyboard::Key, Action> mKeyBinding;
  std::map<Action, Command > mActionBinding;
  
};

#endif
