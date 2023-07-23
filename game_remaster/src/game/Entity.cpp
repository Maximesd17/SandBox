#include "Entity.hpp"

int Entity::_nextId = 1;

Entity::Entity()
: _entityId(_nextId++)
{

}

Entity::~Entity()
{
}

void Entity::computeMoves(double x, double y)
{
}

void Entity::gravity()
{
}

void Entity::jump()
{
}

unsigned int Entity::getId() const
{
    return this->_entityId;
}
