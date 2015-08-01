#ifndef __SFML_GAME__
#define __SFML_GAME__

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
public:
  Game();
  // ~Game();
  void run();

private:
  void processEvents();
  void update();
  void render();
  
protected:
  sf::RenderWindow mWindow;
  sf::CircleShape mPlayer;
  
};
#endif
