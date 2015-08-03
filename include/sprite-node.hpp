#ifndef __SFML_SPRITE_NODE__
#define __SFML_SPRITE_NODE__

#include "scene-node.hpp"

class SpriteNode : public SceneNode
{
public:
  explicit  SpriteNode( const sf::Texture& texture);
            SpriteNode( const sf::Texture& texture
                        , const sf::IntRect& rect
                      );

private:
  virtual void drawCurrent(sf::RenderTarget& target
                           , sf::RenderStates states) const;
  sf::Sprite mSprite;
  
protected:
  
};

#endif
