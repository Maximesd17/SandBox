#ifndef ______GAMESPRITE_HPP___
#define ______GAMESPRITE_HPP___

#include "GameSpriteObject.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class GameSprite : GameSpriteObject
{
private:
  sf::Sprite _sprite;

public:
  GameSprite();
  ~GameSprite();
  void display(sf::RenderWindow&);
  sf::Vector2f getPosition() const;
  void setPosition(sf::Vector2f);

};
#endif //______GAMESPRITEOBJECT_HPP___
