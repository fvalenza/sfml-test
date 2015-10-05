#include <SFML/Graphics.hpp>
#include "application.hpp"
#include "resource-holder.hpp"
#include "aircraft.hpp"
#include "scene-node.hpp"
#include <iostream>

int main()
{
  try
  {
    Application app;
    app.run();
  }
  catch ( std::exception& e)
  {
    std::cout << "\nEXCEPTION" << e.what() << std::endl;
  }

    return 0;
}
