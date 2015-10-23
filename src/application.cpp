#include "application.hpp"

Application::Application()
: mWindow(sf::VideoMode(640, 480), "SFML Application!", sf::Style::Close)
, mWorld(mWindow)
, mIsPaused(false)
, mFonts()
, mPlayer()
, mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
, mTimePerFrame(sf::seconds(1.f/60.f))
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
  mWindow.setKeyRepeatEnabled(false);

  mFonts.load(Fonts::Main,"../media/Sansation.ttf");
  mTextures.load(Textures::TitleScreen, "../media/Textures/TitleScreen.png");

  mStatisticsText.setFont(mFonts.get(Fonts::Main));
  mStatisticsText.setPosition(5.f, 5.f);
  mStatisticsText.setCharacterSize(10u);

  registerStates();
  mStateStack.pushState(States::Title);
}

void Application::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (mWindow.isOpen())
  {
    sf::Time dt = clock.restart();
    timeSinceLastUpdate += dt;
    while (timeSinceLastUpdate > mTimePerFrame)
    {
      timeSinceLastUpdate -= mTimePerFrame;

      processInput();
      update(mTimePerFrame);

      // Check inside this loop, because stack might be empty before update() call
      if (mStateStack.isEmpty())
        mWindow.close();
    }

    updateStatistics(dt);
    render();
  }
}

void Application::processInput()
{
  sf::Event event;
  while (mWindow.pollEvent(event))
  {
    mStateStack.handleEvent(event);

    if (event.type == sf::Event::Closed)
      mWindow.close();
  }
}

void Application::update(sf::Time dt)
{
  mStateStack.update(dt);
}

void Application::render()
{
  mWindow.clear();
  mStateStack.draw();

  mWindow.setView(mWindow.getDefaultView());
  mWindow.draw(mStatisticsText);

  mWindow.display();
}

void Application::registerStates()
{
  // mStateStack.registerState<TitleState >(States::Title);
  // mStateStack.registerState<MenuState >(States::Menu);
  mStateStack.registerState<GameState >(States::Game);
  // mStateStack.registerState<PauseState >(States::Pause);
}

void Application::updateStatistics(sf::Time dt)
{
  mStatisticsUpdateTime += dt;
  mStatisticsNumFrames += 1;
  if (mStatisticsUpdateTime >= sf::seconds(1.0f))
  {
    mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));

    mStatisticsUpdateTime -= sf::seconds(1.0f);
    mStatisticsNumFrames = 0;
  }
}