/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** GameMapObject
*/

#ifndef ______GAMESPRITEOBJECT_HPP___
#define ______GAMESPRITEOBJECT_HPP___

class GameSpriteObject
{
public:
  virtual void update() = 0;
  virtual void display(sf::RenderWindow&) = 0;
  virtual sf::Vector2f getPosition() = 0;
  virtual void setPosition(sf::Vector2f position) = 0;


};
  

#endif //______GAMESPRITEOBJECT_HPP___
