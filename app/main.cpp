#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>

int main()
{
  Game game;
  game.run();
  
  // sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application!");
  // sf::CircleShape shape(40.f);
  // shape.setFillColor(sf::Color::Green);
  // shape.setPosition(100.f, 100.f);

  // while (window.isOpen())
  // {
  //   sf::Event event;
  //   while (window.pollEvent(event))
  //   {
  //       if (event.type == sf::Event::Closed)
  //           window.close();
  //   }

  //   window.clear();
  //   window.draw(shape);
  //   window.display();
  // }

    return 0;
}