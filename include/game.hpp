#ifndef __SFML_GAME__
#define __SFML_GAME__

#include <iostream>
#include <SFML/Graphics.hpp>
#include "world.hpp"
#include "player.hpp"

class Game : private sf::NonCopyable
{
public:
  Game();
  // ~Game();
  void run();

private:
  void processInput();
  void update(sf::Time dt);
  void render();
  
protected:
  sf::RenderWindow mWindow;
  World mWorld;
  bool mIsPaused;
  Player mPlayer;


  sf::Time mTimePerFrame;
  
};
#endif
