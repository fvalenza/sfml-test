#ifndef __SFML_RESOURCE_HOLDER__
#define __SFML_RESOURCE_HOLDER__

#include <iostream>
#include <memory>
#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace Textures
{
  enum ID
  {
    Eagle,
    Raptor,
    Desert,
    TitleScreen,
  };
}

namespace Fonts
{
  enum ID
  {
    Main,
  };
}

namespace SoundEffect
{
  enum ID
  {
    AlliedGunFire,
    EnnemyGunFire,
    // Explosion1,
    // Explosion2,
    LaunchMissile,
    CollectPickup,
    Button,
    StartPlaying,
  };
}

template < typename Resource, typename Identifier>
class ResourceHolder
{
public:

  void load(Identifier id, const std::string& filename)
  {
    std::unique_ptr< Resource > resource (new Resource());
    if(!resource -> loadFromFile(filename))
    {
      throw std::runtime_error( "ResourceHolder::load - Failed to load"
                                + filename);
    }

    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
  }

  template < typename Parameter >
  void load(Identifier id, const std::string& filename, const Parameter& secondParam)
  {
    std::unique_ptr< Resource > resource (new Resource());
    if(!resource -> loadFromFile(filename, secondParam))
    {
      throw std::runtime_error( "ResourceHolder::load - Failed to load"
                                + filename);
    }

    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
  }

  Resource& get(Identifier id)
  {
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    return *found->second;
  }
  const Resource& get(Identifier id) const
  {
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());

    return *found->second;
  }


private:

  
protected:
  std::map< Identifier,
            std::unique_ptr< Resource > > mResourceMap;
  
};

typedef ResourceHolder< sf::Texture ,Textures::ID > TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>     FontHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID>     SoundBufferHolder;

#endif
