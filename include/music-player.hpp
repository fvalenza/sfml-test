#ifndef SFML_MUSICPLAYER_HPP
#define SFML_MUSICPLAYER_HPP

#include <resource-holder.hpp>
// #include <ressource-ientifiers.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>

namespace Music
{
  enum ID
  {
    MenuTheme,
    MissionTheme,
  };
}

class MusicPlayer : private sf::NonCopyable
{
  public:
                  MusicPlayer();

    void            play(Music::ID theme);
    void            stop();

    void            setPaused(bool paused);
    void            setVolume(float volume);


  private:
    sf::Music             mMusic;
    std::map<Music::ID, std::string>  mFilenames;
    float               mVolume;
};

#endif // SFML_MUSICPLAYER_HPP
