#ifndef __SFML_SCENE_NODE__
#define __SFML_SCENE_NODE__

#include <cassert>
#include <memory>
#include <algorithm>
#include <vector>

class SceneNode 
{
public:
  typedef std::unique_ptr < SceneNode > Ptr;

public:
  SceneNode();
  void attachChild(Ptr child);
  Ptr detachChild(const SceneNode& node);

private:
  std::vector < Ptr > mChildren;
  SceneNode* mParent;
  
protected:
  
};

#endif
