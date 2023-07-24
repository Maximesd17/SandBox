/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** GameEntity
*/

#ifndef ______GAMEENTITY_HPP___
#define ______GAMEENTITY_HPP___

class GameEntity 
{
public:
  virtual void update() = 0;
  virtual void display(sf::RenderWindow&) = 0;
  virtual void computeYMoves(float directionY) = 0;
  virtual void computeXMoves(float directionX) = 0;
  virtual void ApplyGravity() = 0;
  virtual void ApplyJump() = 0;
  virtual sf::Vector2f getPosition() = 0;
  virtual void setPosition(sf::Vector2f position) = 0;


};
  

#endif //______GAMEENTITY_HPP___
