/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Player
*/

#include "Player.hpp"
#include <math.h>
#include <iostream>
#include <cmath>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Game::Player::Player::Player()
{
    _speed = 10;
    _gravity = 9.81;
    _jump_height = 150;
    _position = sf::Vector2f(45, 100);
    _idle_frame = 0;
    _idle_speed = 1 * 60; // 60 = default frame rate
    _jump_frame = 0;
    _jump_speed = 0.1 * 60; // 60 = default frame rate

    _state = PLAYER_IDLE;
    _direction = RIGHT;


    _moves = std::make_shared<Moves::KeyboardMoves>();
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Game::Player::Player::~Player()
{
}

/*********setPlayerSprites*********/
/* Set player sprites function    */
/*********setPlayerSprites*********/
void MySandBox::Game::Player::Player::setPlayerSprites(sf::Texture& sprite_shit)
{
    _player.setTexture(sprite_shit);
}

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Game::Player::Player::events(sf::Event& event)
{
    _moves->events(event);
}

/*********ApplyGravity*********/
/* Apply gravity function     */
/*********ApplyGravity*********/
void MySandBox::Game::Player::Player::ApplyGravity(const std::vector<sf::Vector2f>& collisionPositions)
{
    //_log_manager.addLog("Player", "OK", "gravity fall");
    float future_y = _position.y + _gravity;
    if (checkWallCollisionY(future_y, collisionPositions)) {
        std::cerr << "PLAYER Y: " << _position.y << std::endl;
        _state = PLAYER_IDLE;
        return;
    }
    if (_position.y >= 1080) {
        std::cerr << "OUT OF BOUNDS Y: " << _position.y << std::endl;
        _position.y = 0;
        _state = PLAYER_IDLE;
        return;
    }
    _position.y = future_y;
}

/*********ApplyJump*********/
/* Apply jump function     */
/*********ApplyJump*********/
void MySandBox::Game::Player::Player::ApplyJump(const std::vector<sf::Vector2f>& collisionPositions)
{
    float future_y = _position.y - _jump_height / _jump_speed;
    std::cout << "Player: " << _position.x << ";" << _position.y << std::endl;
    std::cout << "Future Y: " << future_y << std::endl;
    if (checkWallCollisionY(future_y, collisionPositions))
        return;
    if (_jump_frame < _jump_speed) {
        //_log_manager.addLog("Player", "OK", "jump");
        _position.y = future_y;
        _jump_frame++;
    }
    else {
        std::cout << "Time to fall" << std::endl;
        _state = FALLING;
    }
}

/*********computeYMoves***********/
/* Compute Y-axis moves function */
/*********computeYMoves***********/
void MySandBox::Game::Player::Player::computeYMoves(float directionY, const std::vector<sf::Vector2f> &collisionPositions)
{
    float future_y = _state == JUMPING ? (_position.y - _jump_height / _jump_speed) : (_position.y + _gravity);
    //_log_manager.printLogs();
    checkWallCollisionY(future_y, collisionPositions);
    if (directionY < 0 && _state != JUMPING && _state != FALLING) {
        _state = JUMPING;
        _jump_frame = 0;
    }
    switch (_state) {
    case JUMPING:
        ApplyJump(collisionPositions);
        break;
    case FALLING:
        ApplyGravity(collisionPositions);
        break;
    default:
        break;
    }
}

/*********computeXMoves***********/
/* Compute X-axis moves function */
/*********computeXMoves***********/
void MySandBox::Game::Player::Player::computeXMoves(float directionX, const std::vector<sf::Vector2f> &collisionPositions)
{
    float future_x = _position.x + directionX * _speed;
    float future_y_falling = _position.y + _gravity;

    // checkWallCollisionY(future_y_falling, collisionPositions);
    if (checkWallCollisionX(future_x, collisionPositions))
        return;
    _position.x = future_x;
    if (directionX < 0) {
        _direction = LEFT;
        if (_state != JUMPING && _state != FALLING)
            _state = WALKING;
    }
    else if (directionX > 0) {
        _direction = RIGHT;
        if (_state != JUMPING && _state != FALLING)
            _state = WALKING;
    }
    else if (_state != JUMPING && _state != FALLING)
        _state = PLAYER_IDLE;
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Game::Player::Player::update(const std::vector<sf::Vector2f> &collisionPositions)
{
    sf::Vector2f direction = _moves->getLastMove();

    computeXMoves(direction.x, collisionPositions);
    computeYMoves(direction.y, collisionPositions);
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Game::Player::Player::setIdleFrame()
{
    if (_idle_frame >= _idle_speed) _idle_frame = 0;

    const int frame_to_display = floor(4 / _idle_speed * _idle_frame);

    _player.setTextureRect(sf::IntRect(40 * frame_to_display, 0 + 58 * (int)_direction, 40, 58));
    _idle_frame++;
}

void MySandBox::Game::Player::Player::setWalkingFrame()
{
    _player.setTextureRect(sf::IntRect( 0, 0 + 58 * (int)_direction, 40, 58 ));
}

void MySandBox::Game::Player::Player::setJumpingFrame()
{
    const int frame_to_display = floor(4 / _jump_speed * _jump_frame);

    _player.setTextureRect(sf::IntRect(40 * frame_to_display, 116 + 58 * (int)_direction, 40, 58 ));
}

void MySandBox::Game::Player::Player::setFallingFrame()
{
    _player.setTextureRect(sf::IntRect( 120, 116 + 58 * (int)_direction, 40, 58));
}

void MySandBox::Game::Player::Player::setAttackingFrame()
{
    std::cout << "setAttackingFrame" << std::endl;
}

void MySandBox::Game::Player::Player::setDeadFrame()
{
    std::cout << "setDeadFrame" << std::endl;
}

void MySandBox::Game::Player::Player::display(sf::RenderWindow& window)
{
    _sprite_index++;
    switch (_state) {
    case PLAYER_IDLE:
        setIdleFrame();
        break;
    case WALKING:
        setWalkingFrame();
        break;
    case JUMPING:
        setJumpingFrame();
        break;
    case FALLING:
        setFallingFrame();
        break;
    case ATTACKING:
        setAttackingFrame();
        break;
    case DEAD:
        setDeadFrame();
        break;
    default:
        break;
    }
    _player.setPosition(_position);
    _player.setScale(2, 2);
    window.draw(_player);
}


/*********getPosition*********/
/*     _position getter      */
/*********getPosition*********/
sf::Vector2f MySandBox::Game::Player::Player::getPosition() const
{
    return _position;
}

/*********getState*********/
/*     _state getter      */
/*********getState*********/
MySandBox::Game::PlayerState MySandBox::Game::Player::Player::getState() const
{
    return _state;
}

/*********getDirection*********/
/*     _direction getter      */
/*********getDirection*********/
MySandBox::Game::PlayerDirection MySandBox::Game::Player::Player::getDirection() const
{
    return _direction;
}

double MySandBox::Game::Player::Player::getGravity() const
{
    return _gravity;
}

int MySandBox::Game::Player::Player::getJumpHeight() const
{
    return _jump_height;
}

/*********setPosition*********/
/*     _position setter      */
/*********setPosition*********/
void MySandBox::Game::Player::Player::setPosition(sf::Vector2f position)
{
    _position = position;
}

/*********setState*********/
/*     _state setter      */
/*********setState*********/
void MySandBox::Game::Player::Player::setState(MySandBox::Game::PlayerState playerState) {
    _state = playerState;
}

/*********setDirection*********/
/*     _direction setter      */
/*********setDirection*********/
void MySandBox::Game::Player::Player::setDirection(MySandBox::Game::PlayerDirection playerDirection) {
    _direction = playerDirection;
}

void MySandBox::Game::Player::Player::setGravity(double gravity)
{
    _gravity = gravity;
}

void MySandBox::Game::Player::Player::setJumpHeight(int height)
{
    _jump_height = height;
}

bool MySandBox::Game::Player::Player::checkWallCollision(const std::vector<sf::Vector2f>& collisionPositions) const
{
    sf::FloatRect playerBounds = _player.getGlobalBounds();

    for (const sf::Vector2f& wallPosition : collisionPositions) {
        sf::FloatRect wallBounds(wallPosition.x, wallPosition.y, 40, 40);

        if (playerBounds.intersects(wallBounds)) {
            return true;
        }
    }

    return false;
}

bool MySandBox::Game::Player::Player::checkWallCollisionX(float const future_x, const std::vector<sf::Vector2f>& collisionPositions)
{
    sf::Sprite future_player = sf::Sprite(_player);
    future_player.setPosition(sf::Vector2f(future_x, future_player.getPosition().y));
    sf::FloatRect playerBounds = future_player.getGlobalBounds();

    for (const sf::Vector2f& wallPosition : collisionPositions) {
        sf::FloatRect wallBounds(wallPosition.x, wallPosition.y, 40, 40);

        if (playerBounds.intersects(wallBounds)) {
            if (playerBounds.left + playerBounds.width >= wallBounds.left && playerBounds.left <= wallBounds.left + wallBounds.width) {
                return true;
            }
        }
    }

    return false;
}

bool MySandBox::Game::Player::Player::checkWallCollisionY(const float future_y, const std::vector<sf::Vector2f>& collisionPositions)
{
    sf::Sprite future_player = sf::Sprite(_player);
    future_player.setPosition(sf::Vector2f(future_player.getPosition().x, future_y));
    sf::FloatRect playerBounds = future_player.getGlobalBounds();


    for (const sf::Vector2f& wallPosition : collisionPositions) {
        sf::FloatRect wallBounds(wallPosition.x, wallPosition.y, 40, 40);

        if (playerBounds.intersects(wallBounds)) {
            if (playerBounds.top + playerBounds.height > wallBounds.top && playerBounds.top < wallBounds.top + wallBounds.height) {
                _state = PLAYER_IDLE;
                return true;
            }
            
        }
        if (_state == JUMPING)
            return false;
    }
    _state = FALLING;
    return false;
}

bool MySandBox::Game::Player::Player::checkEndPointCollision(const sf::Vector2f& endPosition)
{
    sf::FloatRect playerBounds = _player.getGlobalBounds();
    sf::FloatRect endBounds(endPosition.x,endPosition.y, 40, 40);
    if (playerBounds.intersects(endBounds))
    {
        return true;
    }
    return false;
}
