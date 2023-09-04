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
#include <iostream>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Game::Player::Player::Player()
{
    _speed = 8;
    _gravity = 9.81;
    _jump_height = 150;
    _position = sf::Vector2f(45, 100);
    _idle_frame = 0;
    _idle_speed = 1 * 60; // 60 = default frame rate
    _jump_frame = 0;
    _jump_speed = 0.1 * 60; // 60 = default frame rate
    _walk_frame = 0;
    _walk_speed = 1 * 60; // 60 = default frame rate

    _attack_speed = 0.7 * 60; // 60 = default frame rate
    _attack_frame = 0;

    _death_speed = 1 * 60; // 60 = default frame rate
    _death_frame = 0;

    _state = PLAYER_IDLE;
    _direction = PlayerDirection::RIGHT;
    _player_width = 32;
    _player_height = 32;
    _texture_size = 40;

    _controlled_by = KEYBOARD;
    _is_moves_manual_changed = false;
    _moves[JOYSTICK] = std::make_shared<Moves::ControllerMoves>();
    _moves[KEYBOARD] = std::make_shared<Moves::KeyboardMoves>();

    walking_sf.loadSound("resources/sounds/footsteps.wav");
    walking_sf.loopSetter(true);
    jumping_sf.loadSound("resources/sounds/jump.wav");
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
    setIdleFrame();
    _player.setScale(2 + _texture_size / 40, 2 + _texture_size / 40);
}

/*********setTextureSize*********/
/* Set the size of the player   */
/*********setTextureSize*********/
void MySandBox::Game::Player::Player::setTextureSize(float size)
{
    _texture_size = size;
    _jump_height = _jump_height * _texture_size / 40;
}

/*********events************/
/* Event handling function */
/*********events************/
void MySandBox::Game::Player::Player::events(sf::Event& event)
{
    if (sf::Joystick::isConnected(0) && !_is_moves_manual_changed) {
        std::cout << "GAMEPAD CONNECTED" << std::endl;
        _controlled_by = JOYSTICK;
    } else {
        std::cout << "GAMEPAD DISCONNECTED" << std::endl;
        _controlled_by = KEYBOARD;
    }
    _moves[_controlled_by]->events(event);
}

/*********ApplyGravity*********/
/* Apply gravity function     */
/*********ApplyGravity*********/
void MySandBox::Game::Player::Player::ApplyGravity(
    const std::vector<sf::FloatRect>& collisionBlocks,
    const sf::Vector2f& map_size
)
{
    //_log_manager.addLog("Player", "OK", "gravity fall");
    float future_y = _position.y + _gravity;
    std::optional<sf::FloatRect> result = checkWallCollisionY(future_y, collisionBlocks);

    if (result) {
        sf::FloatRect rect = *result;

        _position.y = rect.top - _player.getGlobalBounds().height;
        _state = PLAYER_IDLE;
        return;
    }
    if (_position.y >= map_size.y) {
        _position.y = 0;
        _state = PLAYER_IDLE;
        return;
    }
    _position.y = future_y;
}

/*********ApplyJump*********/
/* Apply jump function     */
/*********ApplyJump*********/
void MySandBox::Game::Player::Player::ApplyJump(const std::vector<sf::FloatRect>& collisionBlocks)
{
    float future_y = _position.y - _jump_height / _jump_speed;

    std::optional<sf::FloatRect> result = checkWallCollisionY(future_y, collisionBlocks);

    if (result) {
        sf::FloatRect rect = *result;

        future_y = rect.top + rect.height;
        _state = PLAYER_IDLE;
    }
    if (_jump_frame < _jump_speed) {
        //_log_manager.addLog("Player", "OK", "jump");
        _position.y = future_y;
        _jump_frame++;
    } else {
        _state = FALLING;
    }
}

/*********computeYMoves***********/
/* Compute Y-axis moves function */
/*********computeYMoves***********/
void MySandBox::Game::Player::Player::computeYMoves(
    float directionY,
    const std::vector<sf::FloatRect>& collisionBlocks,
    const sf::Vector2f& map_size
)
{
    float future_y = _state == JUMPING ? (_position.y - _jump_height / _jump_speed) : (_position.y + _gravity);
    //_log_manager.printLogs();
    checkWallCollisionY(future_y, collisionBlocks);
    if (directionY < 0 && _state != JUMPING && _state != FALLING) {
        _state = JUMPING;
        _jump_frame = 0;
    }
    switch (_state) {
    case JUMPING:
        ApplyJump(collisionBlocks);
        break;
    case FALLING:
        ApplyGravity(collisionBlocks, map_size);
        break;
    default:
        break;
    }
}

/*********computeXMoves***********/
/* Compute X-axis moves function */
/*********computeXMoves***********/
void MySandBox::Game::Player::Player::computeXMoves(float directionX, const std::vector<sf::FloatRect>& collisionBlocks)
{
    float future_x = _position.x + directionX * _speed;
    std::optional<sf::FloatRect> result = checkWallCollisionX(future_x, collisionBlocks);

    if (result) {
        sf::FloatRect rect = *result;

        if (directionX < 0) {
            _position.x = rect.left + rect.width;
        } else if (directionX > 0) {
            _position.x = rect.left - _player.getGlobalBounds().width;
        }
        return;
    }
    _position.x = future_x;
    if (directionX < 0) {
        _direction = LEFT;
        if (_state != JUMPING && _state != FALLING)
            _state = WALKING;
    } else if (directionX > 0) {
        _direction = RIGHT;
        if (_state != JUMPING && _state != FALLING)
            _state = WALKING;
    } else {
        _state = _state != JUMPING && _state != FALLING ? PLAYER_IDLE : _state;
    }
}

/*********update*********/
/* Update function      */
/*********update*********/
void MySandBox::Game::Player::Player::update(const std::vector<sf::FloatRect>& collisionBlocks, const sf::Vector2f& map_size)
{
    sf::Vector2f direction = _moves[_controlled_by]->getLastMove();

    computeXMoves(direction.x, collisionBlocks);
    computeYMoves(direction.y, collisionBlocks, map_size);
}

/*********setIdleFrame*********/
/* setIdleFrame function      */
/*********setIdleFrame*********/
void MySandBox::Game::Player::Player::setIdleFrame()
{
    if (_idle_frame >= _idle_speed) _idle_frame = 0;

    const int frame_to_display = floor(2 / _idle_speed * _idle_frame);

    _player.setTextureRect(sf::IntRect(
        _player_width * frame_to_display,
        0 + _player_height * (int)_direction,
        _player_width,
        _player_height
    ));
    _idle_frame++;
}

/*********setWalkingFrame*********/
/* setWalkingFrame function      */
/*********setWalkingFrame*********/
void MySandBox::Game::Player::Player::setWalkingFrame()
{
    if (_walk_frame >= _walk_speed) _walk_frame = 0;
    const int frame_to_display = floor(8 / _walk_speed * _walk_frame);
    _player.setTextureRect(sf::IntRect(
        _player_width * frame_to_display,
        64 + _player_height * (int)_direction,
        _player_width,
        _player_height
    ));
    _walk_frame++;
}

/*********setJumpingFrame*********/
/* setJumpingFrame function      */
/*********setJumpingFrame*********/
void MySandBox::Game::Player::Player::setJumpingFrame()
{
    const int frame_to_display = floor(4 / _jump_speed * _jump_frame);

    _player.setTextureRect(sf::IntRect(
        _player_width * frame_to_display,
        128 + _player_height * (int)_direction,
        _player_width,
        _player_height
    ));
}

/*********setFallingFrame*********/
/* setFallingFrame function      */
/*********setFallingFrame*********/
void MySandBox::Game::Player::Player::setFallingFrame()
{
    _player.setTextureRect(sf::IntRect(132, 128 + _player_height * (int)_direction, _player_width, _player_height));
}

/*********setAttackingFrame*********/
/* setAttackingFrame function      */
/*********setAttackingFrame*********/
void MySandBox::Game::Player::Player::setAttackingFrame()
{
    //TODO mettre les _attack_frame et _attack_speed
    if (_attack_frame >= _attack_speed) _attack_frame = 0;
    const int frame_to_display = floor(8 / _attack_speed * _attack_frame);
    _player.setTextureRect(sf::IntRect(
        _player_width * frame_to_display,
        256 + _player_height * (int)_direction,
        _player_width,
        _player_height
    ));
    _attack_frame++;
}


/*********setDeadFrame*********/
/* setDeadFrame function      */
/*********setDeadFrame*********/
void MySandBox::Game::Player::Player::setDeadFrame()
{
    //TODO mettre les _death_frame et _death_speed
    if (_death_frame >= _death_speed) _death_frame = 0;
    const int frame_to_display = floor(8 / _death_speed * _death_frame);
    _player.setTextureRect(sf::IntRect(
        _player_width * frame_to_display,
        192 + _player_height * (int)_direction,
        _player_width,
        _player_height
    ));
    _death_frame++;
}

/*********display*********/
/* Display function      */
/*********display*********/
void MySandBox::Game::Player::Player::display(sf::RenderWindow& window)
{
    _sprite_index++;
    // std::cout << _state << std::endl;
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

    sf::RectangleShape rect(sf::Vector2f(_player.getGlobalBounds().width, _player.getGlobalBounds().height));
    rect.setPosition(_player.getPosition());
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(1);
    window.draw(rect);

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

/*********getGravity*********/
/*     _gravity getter      */
/*********getGravity*********/
double MySandBox::Game::Player::Player::getGravity() const
{
    return _gravity;
}

/*********getJumpHeight*********/
/*     _jumpHeight getter      */
/*********getJumpHeight*********/
int MySandBox::Game::Player::Player::getJumpHeight() const
{
    return _jump_height;
}

float MySandBox::Game::Player::Player::getPlayerHeight() const
{
    return _player.getGlobalBounds().height;
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
void MySandBox::Game::Player::Player::setState(MySandBox::Game::PlayerState playerState)
{
    _state = playerState;
}

/*********setDirection*********/
/*     _direction setter      */
/*********setDirection*********/
void MySandBox::Game::Player::Player::setDirection(MySandBox::Game::PlayerDirection playerDirection)
{
    _direction = playerDirection;
}

/*********setGravity*********/
/*     _gravity setter      */
/*********setGravity*********/
void MySandBox::Game::Player::Player::setGravity(double gravity)
{
    _gravity = gravity;
}

/*********setJumpHeight*********/
/*     _jumpHeight setter      */
/*********setJumpHeight*********/
void MySandBox::Game::Player::Player::setJumpHeight(int height)
{
    _jump_height = height;
}

/*********checkWallCollisionX*********/
/* checkWallCollision on X axis      */
/*********checkWallCollisionX*********/
std::optional<sf::FloatRect> MySandBox::Game::Player::Player::checkWallCollisionX(
    float const future_x,
    const std::vector<sf::FloatRect>& collisionBlocks
)
{
    sf::Sprite future_player = sf::Sprite(_player);

    future_player.setPosition(sf::Vector2f(future_x, future_player.getPosition().y));

    for (const sf::FloatRect& wall : collisionBlocks) {
        if (future_player.getGlobalBounds().intersects(wall)) return wall;
    }
    return std::nullopt;

}

/*********checkWallCollisionY*********/
/* checkWallCollision on Y axis      */
/*********checkWallCollisionY*********/
std::optional<sf::FloatRect> MySandBox::Game::Player::Player::checkWallCollisionY(
    const float future_y, const std::vector<sf::FloatRect>& collisionBlocks
)
{
    sf::Sprite future_player = sf::Sprite(_player);
    sf::FloatRect playerBounds = sf::FloatRect(0, 0, 0, 0);

    future_player.setPosition(sf::Vector2f(future_player.getPosition().x, future_y));
    playerBounds = future_player.getGlobalBounds();

    for (const sf::FloatRect& wall : collisionBlocks) {
        if (playerBounds.intersects(wall)) return wall;
    }
    if (_state != JUMPING)
        _state = FALLING;
    return std::nullopt;
}

/*********checkEndPointCollision*********/
/* checkEndPointCollision function      */
/*********checkEndPointCollision*********/
bool MySandBox::Game::Player::Player::checkEndPointCollision(const sf::FloatRect& endPosition)
{
    sf::FloatRect playerBounds = _player.getGlobalBounds();


    if (playerBounds.intersects(endPosition))return true;
    return false;
}
/********makeSound********/
/* Enables player sounds */
/********makeSound********/
void MySandBox::Game::Player::Player::makeSound(){
    if (_state == JUMPING)
        jumping_sf.playSound();
    if (_state == WALKING && walking_is_played == false){
        walking_sf.playSound();
        walking_is_played = true;
    }
    if (_state == PLAYER_IDLE)
        walking_sf.stopSound();
        walking_is_played = false;
}