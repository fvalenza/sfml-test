#ifndef __SFML_TEXTURE_HOLDER__
#define __SFML_TEXTURE_HOLDER__

#include <iostream>
#include <memory>
#include <cassert>
#include <SFML/Graphics.hpp>

namespace Textures
{
  enum ID { Landscape
            , Airplane
            , Missile
          };
}

class TextureHolder
{
public:
  TextureHolder();
  const sf::Texture& get(Textures::ID id) const;
  sf::Texture& get(Textures::ID id) ;


private:
  void load(Textures::ID id, const std::string& filename);

  
protected:
  std::map< Textures::ID,
            std::unique_ptr< sf::Texture > > mTextureMap;
  
};

#endif
