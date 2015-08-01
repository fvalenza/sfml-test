#include "game.hpp"

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application!")
, mPlayer(40.f)
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingLeft(false)
, mIsMovingRight(false)
, mPlayerSpeed(100.)
, mTimePerFrame(sf::seconds(1.f/60.f))
{
  mPlayer.setFillColor(sf::Color::Green);
  mPlayer.setPosition(100.f, 100.f);

}

void Game::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (mWindow.isOpen())
  {
    processEvents();
    timeSinceLastUpdate += clock.restart();
    // think it about frequencies : while we are updating at a rate superior to 60 Hz, we wait
    // When 60 Hz is reached, we render
    while(timeSinceLastUpdate > mTimePerFrame)
    {                                           
      timeSinceLastUpdate -= mTimePerFrame;
      processEvents();
      update(mTimePerFrame);
    }
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

void Game::update(sf::Time dt)
{
  sf::Vector2f movement(0.f, 0.f);
  if (mIsMovingUp)
    movement.y -= mPlayerSpeed;
  if (mIsMovingDown)
    movement.y += mPlayerSpeed;
  if (mIsMovingLeft)
    movement.x -= mPlayerSpeed;
  if (mIsMovingRight)
    movement.x += mPlayerSpeed;

  mPlayer.move(movement * dt.asSeconds());
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
