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
  void update(sf::Time dt);
  sf::Transform getWorldTransform() const;
  sf::Vector2f getWorldPosition() const;

private:
  virtual void draw(sf::RenderTarget& target
                    , sf::RenderStates states) const ;
  virtual void drawCurrent(sf::RenderTarget& target
                           , sf::RenderStates states) const;
  void drawChildren(sf::RenderTarget& target
                    , sf::RenderStates states) const;
  virtual void updateCurrent(sf::Time dt);
  void updateChildren(sf::Time dt);



  std::vector < Ptr > mChildren;
  SceneNode* mParent;
  
protected:
  
};

#endif
