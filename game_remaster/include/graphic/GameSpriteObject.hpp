#ifndef ______GAMESPRITEOBJECT_HPP___
#define ______GAMESPRITEOBJECT_HPP___

#include <SFML/Graphics/RenderWindow.hpp>

class GameSpriteObject
{

public:
  virtual void display(sf::RenderWindow&) = 0;
  virtual sf::Vector2f getPosition() = 0;
  virtual void setPosition(sf::Vector2f) = 0;

};
#endif //______GAMESPRITEOBJECT_HPP___
