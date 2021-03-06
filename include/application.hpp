#ifndef __SFML_APPLICATION__
#define __SFML_APPLICATION__

#include <iostream>
#include "utility.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

#include "world.hpp"
#include "player.hpp"
#include "state-stack.hpp"
#include "game-state.hpp"
#include "title-state.hpp"
#include "menu-state.hpp"
#include "pause-state.hpp"
#include "music-player.hpp"
#include "sound-player.hpp"

class Application : private sf::NonCopyable
{
public:
  Application();
  // ~Application();
  void run();

private:
  void processInput();
  void update(sf::Time dt);
  void render();
  void registerStates();
  void updateStatistics(sf::Time dt);
  
protected:
  sf::RenderWindow mWindow;
  TextureHolder     mTextures;
  World mWorld;
  bool mIsPaused;
  FontHolder        mFonts;
  MusicPlayer mMusic;
  SoundPlayer mSounds;
  Player mPlayer;
  StateStack mStateStack;


  sf::Time mTimePerFrame;
  sf::Text        mStatisticsText;
  sf::Time        mStatisticsUpdateTime;
  std::size_t       mStatisticsNumFrames;
  
};
#endif
