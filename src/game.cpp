#include "game.hpp"

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application!", sf::Style::Close)
, mWorld(mWindow)
, mIsPaused(false)
, mPlayer()
, mTimePerFrame(sf::seconds(1.f/60.f))
{
  mWindow.setKeyRepeatEnabled(true);
}

void Game::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (mWindow.isOpen())
  {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;
    while (timeSinceLastUpdate > mTimePerFrame)
    {
      timeSinceLastUpdate -= mTimePerFrame;

      processInput();
      if (!mIsPaused)
      {
        update(mTimePerFrame);
      }
    }
    render();
  }
}

void Game::processInput()
{
  sf::Event event;
  CommandQueue& commands = mWorld.getCommandQueue();
  while (mWindow.pollEvent(event))
  {
    mPlayer.handleEvent(event, commands);
    if(event.type == sf::Event::Closed)
    {
      mWindow.close();
    }
  }
  mPlayer.handleRealTimeInput(commands);
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

