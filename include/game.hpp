#ifndef __SFML_GAME__
#define __SFML_GAME__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "world.hpp"
#include "player.hpp"

class Game
{
public:
  Game();
  // ~Game();
  void run();

private:
  void processEvents();
  void processInput();
  void update(sf::Time dt);
  void render();
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
  
protected:
  sf::RenderWindow mWindow;
  World mWorld;
  bool mIsPaused;
  Player mPlayer;


  sf::Time mTimePerFrame;
  
};
#endif
