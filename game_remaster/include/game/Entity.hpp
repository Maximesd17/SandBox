#ifndef ______ENTITY_HPP___
#define ______ENTITY_HPP___

#include "GameEntity.hpp"

class Entity : public GameEntity
{
private:
  static int _nextId;
  unsigned int _entityId;

public:
  Entity();
  ~Entity();
  void computeMoves(double, double);
  void gravity();
  void jump();
  unsigned int getId() const;
  using GameEntity::setSprite;
  using GameEntity::getSprite;
};
  

#endif //______GAMEENTITY_HPP___
