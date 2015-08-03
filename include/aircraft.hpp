#ifndef __SFML_AIRCRAFT__
#define __SFML_AIRCRAFT__

#include <iostream>
#include <memory>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "resource-holder.hpp"

class Aircraft : public Entity
{
public:
  enum Type
  {
    Eagle,
    Raptor,
  };

public:
  explicit Aircraft(Type type, const TextureHolder& textures);
  virtual void drawCurrent(sf::RenderTarget& target
                           , sf::RenderStates states) const;
  unsigned int getCategory() const;
  void accelerate (sf::Vector2f velocityBoost);
  
private:
  Type mType;
  sf::Sprite mSprite;
  
protected:
  
};

#endif
