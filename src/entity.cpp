#include "entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity)
{
  mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
  mVelocity = sf::Vector2f(vx, vy);
}

sf::Vector2f Entity::getVelocity() const
{
  return mVelocity;
}
