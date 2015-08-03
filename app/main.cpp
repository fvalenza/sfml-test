#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "resource-holder.hpp"
#include "aircraft.hpp"
#include "scene-node.hpp"
#include <iostream>

int main()
{
  try
  {
    Game game;
    game.run();
  }
  catch ( std::exception& e)
  {
    std::cout << "\nEXCEPTION" << e.what() << std::endl;
  }

    return 0;
}
