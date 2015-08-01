#include "game.hpp"

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application!")
, mPlayer(40.f)
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingLeft(false)
, mIsMovingRight(false)
{
  mPlayer.setFillColor(sf::Color::Green);
  mPlayer.setPosition(100.f, 100.f);

}

void Game::run()
{
  while (mWindow.isOpen())
  {
    processEvents();
    update();
    render();
  }
}

void Game::processEvents()
{
  sf::Event event;
  while (mWindow.pollEvent(event))
  {
    switch(event.type)
    {
      case sf::Event::KeyPressed:
        handlePlayerInput(event.key.code, true);
        break;
      case sf::Event::KeyReleased:
        handlePlayerInput(event.key.code, false);
        break;
      case sf::Event::Closed:
        mWindow.close();
        break;
      // default:
      //   break;
    }
  }
}

void Game::update()
{
  sf::Vector2f movement(0.f, 0.f);
  if (mIsMovingUp)
    movement.y -= 1.f;
  if (mIsMovingDown)
    movement.y += 1.f;
  if (mIsMovingLeft)
    movement.x -= 1.f;
  if (mIsMovingRight)
    movement.x += 1.f;

  mPlayer.move(movement);
}

void Game::render()
{
  mWindow.clear();
  mWindow.draw(mPlayer);
  mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
  if (key == sf::Keyboard::Z)
    mIsMovingUp = isPressed;
  else if (key == sf::Keyboard::S)
    mIsMovingDown = isPressed;
  else if (key == sf::Keyboard::Q)
    mIsMovingLeft = isPressed;
  else if (key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
}
