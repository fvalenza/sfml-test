#ifndef __SFML_STATE__
#define __SFML_STATE__

#include "resource-holder.hpp"
// #include "state-stack.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>

namespace sf
{
  class RenderWindow;
}

class StateStack;
class Player;
class MusicPlayer;
class SoundPlayer;

namespace States
{
  enum ID
  {
    None,
    Title,
    Menu,
    Game,
    Loading,
    Pause
  };
}

class State
{
public:
  typedef std::unique_ptr<State > Ptr;
  struct Context
  {
    Context(sf::RenderWindow& window,
            TextureHolder& textures,
            FontHolder& fonts,
            Player& player,
            MusicPlayer& music,
            SoundPlayer& sounds);

    sf::RenderWindow* window;
    TextureHolder* textures;
    FontHolder* fonts;
    Player* player;
    MusicPlayer* music;
    SoundPlayer* sounds;
  };

public:
  State(StateStack& stack, Context context);
  virtual ~State();

  virtual void draw() = 0;
  virtual bool update (sf::Time dt) = 0;
  virtual bool handleEvent(const sf::Event& event) = 0;

protected:
  void requestStackPush(States::ID stateID);
  void requestStackPop();
  void requestStateClear();

  Context getContext() const;

private:
  StateStack* mStack;
  Context mContext;
};
#endif
