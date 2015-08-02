#ifndef __SFML_SCENE_NODE__
#define __SFML_SCENE_NODE__

#include <cassert>
#include <memory>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>


class SceneNode
: public sf::Transformable
, public sf::Drawable
, private sf::NonCopyable
{
public:
  typedef std::unique_ptr < SceneNode > Ptr;

public:
  SceneNode();
  void attachChild(Ptr child);
  Ptr detachChild(const SceneNode& node);

private:
  virtual void draw(sf::RenderTarget& target
                    , sf::RenderStates states) const ;
  virtual void drawCurrent(sf::RenderTarget& target
                           , sf::RenderStates states) const;
  void drawChildren(sf::RenderTarget& target
                    , sf::RenderStates states) const;
  std::vector < Ptr > mChildren;
  SceneNode* mParent;
  
protected:
  
};

#endif
