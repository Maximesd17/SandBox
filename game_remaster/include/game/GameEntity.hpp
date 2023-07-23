#ifndef ______GAMEENTITY_HPP___
#define ______GAMEENTITY_HPP___

#include "GameSprite.hpp"

class GameEntity : GameSprite
{
public:
  virtual void computeMoves(double, double) = 0;
  virtual void gravity() = 0;
  virtual void jump() = 0;


};
  

#endif //______GAMEENTITY_HPP___
