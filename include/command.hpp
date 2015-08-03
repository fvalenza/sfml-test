#ifndef __SFML_COMMAND__
#define __SFML_COMMAND__

#include "category.hpp"
#include <SFML/System/Time.hpp>
#include <functional>



class SceneNode;

struct Command
{
  Command();

  std::function<void(SceneNode&, sf::Time) > action;
  unsigned int category;
};

#endif
