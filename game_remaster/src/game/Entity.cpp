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
    sf::Vector2f pos = this->getPosition();
    // add check of collisions 
    pos.x += x;
    pos.y += y;
    this->setPosition(pos);

}

void Entity::gravity()
{
    this->computeMoves(0, -0.5);
}

void Entity::jump()
{
    //check so it don't just go up infinitly
    this->computeMoves(0, +0.5);
}

unsigned int Entity::getId() const
{
    return this->_entityId;
}
