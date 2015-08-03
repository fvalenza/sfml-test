#ifndef __SFML_WORLD__
#define __SFML_WORLD__

#include "scene-node.hpp"
#include "sprite-node.hpp"
#include "resource-holder.hpp"
#include "aircraft.hpp"
#include <array>

// Forward declaration
namespace sf
{
  class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
  explicit  World( sf::RenderWindow& window);
  void update(sf::Time dt);
  void draw();

private:
  void loadTextures();
  void buildScene();

private:
  enum Layer
  {
    Background,
    Air,
    LayerCount,    
  };

private:
  sf::RenderWindow& mWindow;
  sf::View mWorldView;
  TextureHolder mTextures;
  SceneNode mSceneGraph;
  std::array < SceneNode*, LayerCount > mSceneLayers;

  sf::FloatRect mWorldBounds;
  sf::Vector2f mSpawnPosition;
  float mScrollSpeed;
  Aircraft* mPlayerAircraft;
  
protected:
  
};

#endif
