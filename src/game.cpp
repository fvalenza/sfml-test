#include "game.hpp"

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application!")
, mWorld(mWindow)
, mIsPaused(false)
, mTimePerFrame(sf::seconds(1.f/60.f))
{
  
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
      if (!mIsPaused)
      {
        update(mTimePerFrame);
      }
    }
    render();
  }
}

void Game::processEvents()
{
  sf::Event event;
  while (mWindow.pollEvent(event))
  {
    if(event.type == sf::Event::GainedFocus)
    {
      mIsPaused = false;
    }
    else if (event.type == sf::Event::LostFocus)
    {
      mIsPaused = true;
    }

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
  mWorld.update(dt);
}

void Game::render()
{
  mWindow.clear();
  mWorld.draw();

  mWindow.setView(mWindow.getDefaultView());
  mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
  // if (key == sf::Keyboard::Z)
  //   mIsMovingUp = isPressed;
  // else if (key == sf::Keyboard::S)
  //   mIsMovingDown = isPressed;
  // else if (key == sf::Keyboard::Q)
  //   mIsMovingLeft = isPressed;
  // else if (key == sf::Keyboard::D)
  //   mIsMovingRight = isPressed;
}
