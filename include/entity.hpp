#ifndef __SFML_ENTITY__
#define __SFML_ENTITY__

#include <iostream>
#include <memory>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "scene-node.hpp"

class Entity : public SceneNode
{
public:
  void setVelocity(sf::Vector2f velocity);
  void setVelocity(float vx, float vy);
  sf::Vector2f getVelocity() const;

private:
  virtual void updateCurrent(sf::Time dt);
  sf::Vector2f mVelocity;
  
protected:
  
};

#endif
