/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** GameEntity
*/

#ifndef ______GAMEENTITY_HPP___
#define ______GAMEENTITY_HPP___

#include "GameSpriteObject.hpp"

class GameEntity : GameSpriteObject
{
public:
  virtual void computeYMoves(float directionY) = 0;
  virtual void computeXMoves(float directionX) = 0;
  virtual void ApplyGravity() = 0;
  virtual void ApplyJump() = 0;


};
  

#endif //______GAMEENTITY_HPP___
