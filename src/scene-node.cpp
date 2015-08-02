#include "scene-node.hpp"

SceneNode::SceneNode()
: mChildren(0)
, mParent(nullptr)
{
}

void SceneNode::attachChild(Ptr child)
{
  child->mParent = this;
  mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
  auto found = std::find_if(  mChildren.begin(),
                              mChildren.end(),
                              [&] (Ptr& p) -> bool {return p.get() == &node; }
                              );

  assert (found != mChildren.end() );

  Ptr result = std::move(*found);
  result -> mParent = nullptr;
  mChildren.erase(found);
  return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
  // Apply transform of current node
  states.transform *= getTransform();

  // Draw node and children with changed transform
  drawCurrent(target, states);
  drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
  
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
  for (const Ptr& child : mChildren)
  {
    child->draw(target, states);
  }
}