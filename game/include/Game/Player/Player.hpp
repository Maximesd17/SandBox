/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Player
*/

#ifndef ______PLAYER_HPP___
#define ______PLAYER_HPP___

#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "KeyboardMoves.hpp"
#include "ControllerMoves.hpp"
#include "LogManager.hpp"
#include "Entity.hpp"

namespace MySandBox {
    namespace Game {
        enum PlayerState {
            PLAYER_IDLE,
            WALKING,
            JUMPING,
            FALLING,
            ATTACKING,
            DEAD
        };
        enum PlayerDirection {
            RIGHT,
            LEFT,
        };
        namespace Player {
            class Player {
            public:
                Player();
                ~Player();
                void setPlayerSprites(sf::Texture&);
                void update(const std::vector<sf::Vector2f> &collisionPositions);
                void events(sf::Event&);
                void display(sf::RenderWindow&);
                void ApplyGravity(const std::vector<sf::Vector2f>& collisionPositions);
                void ApplyJump(const std::vector<sf::Vector2f>& collisionPositions);
                sf::Vector2f getPosition() const;
                PlayerState getState() const;
                PlayerDirection getDirection() const;
                double getGravity() const;
                int getJumpHeight() const;
                void setPosition(sf::Vector2f position);
                void setState(MySandBox::Game::PlayerState playerState);
                void setDirection(MySandBox::Game::PlayerDirection playerDirection);
                void setGravity(double gravity);
                void setJumpHeight(int height);
                bool checkEndPointCollision(const sf::Vector2f& endPosition);
            protected:
            private:
                void computeYMoves(float directionY, const std::vector<sf::Vector2f> &collisionPositions);
                void computeXMoves(float directionX, const std::vector<sf::Vector2f> &collisionPositions);
                bool checkWallCollision(const std::vector<sf::Vector2f>& wallPositions) const;
                bool checkWallCollisionX(const float future_x, const std::vector<sf::Vector2f>& collisionPositions);
                bool checkWallCollisionY(const float future_y, const std::vector<sf::Vector2f>& collisionPositions);
                void setIdleFrame();
                void setWalkingFrame();
                void setJumpingFrame();
                void setFallingFrame();
                void setAttackingFrame();
                void setDeadFrame();
                std::shared_ptr<MySandBox::Game::Player::Moves::IMoves> _moves;
                sf::Vector2f _position;
                size_t _sprite_index;
                sf::Sprite _player;
                PlayerState _state;
                PlayerDirection _direction;
                LogManager _log_manager;
                int _speed;
                double _gravity;
                int _jump_height;
                size_t _jump_frame;
                double _jump_speed;
                size_t _idle_frame;
                double _idle_speed;
            };
        }
    }
}

#endif //______PLAYER_HPP___
