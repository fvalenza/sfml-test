#ifndef __SFML_AIRCRAFT__
#define __SFML_AIRCRAFT__

#include <iostream>
#include <memory>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Aircraft : public Entity
{
public:
  enum Type
  {
    Eagle,
    Raptor,
  };

public:
  explicit Aircraft(Type type);

private:
  Type mType;
  
protected:
  
};

#endif
