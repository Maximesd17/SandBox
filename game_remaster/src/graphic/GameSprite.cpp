#include "GameSprite.hpp"

GameSprite::GameSprite()
{
}

GameSprite::~GameSprite()
{
}

void GameSprite::display(sf::RenderWindow &window)
{
}

sf::Vector2f GameSprite::getPosition() const
{
    return _sprite.getPosition();
}

void GameSprite::setPosition(sf::Vector2f position)
{
    _sprite.setPosition(position);
}

sf::Sprite GameSprite::getSprite() const
{
    return _sprite;
}

void GameSprite::setSprite(sf::Texture &texture)
{
    this->_sprite.setTexture(texture);
}