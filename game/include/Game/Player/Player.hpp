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
#include <optional>
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
                void update(const std::vector<sf::FloatRect> &collisionBlocks, const sf::Vector2f &);
                void events(sf::Event&);
                void display(sf::RenderWindow&);
                void ApplyGravity(const std::vector<sf::FloatRect>& collisionBlocks, const sf::Vector2f &);
                void ApplyJump(const std::vector<sf::FloatRect>& collisionBlocks);
                sf::Vector2f getPosition() const;
                PlayerState getState() const;
                PlayerDirection getDirection() const;
                double getGravity() const;
                int getJumpHeight() const;
                float getPlayerHeight() const;
                void setPosition(sf::Vector2f position);
                void setState(MySandBox::Game::PlayerState playerState);
                void setDirection(MySandBox::Game::PlayerDirection playerDirection);
                void setGravity(double gravity);
                void setJumpHeight(int height);
                bool checkEndPointCollision(const sf::FloatRect& endPosition);
                void setTextureSize(float texture_size);
            protected:
            private:
                void computeYMoves(float directionY, const std::vector<sf::FloatRect> &collisionBlocks, const sf::Vector2f &);
                void computeXMoves(float directionX, const std::vector<sf::FloatRect> &collisionBlocks);
                std::optional<sf::FloatRect> checkWallCollisionX(const float future_x, const std::vector<sf::FloatRect>& collisionBlocks);
                std::optional<sf::FloatRect> checkWallCollisionY(const float future_y, const std::vector<sf::FloatRect>& collisionBlocks);
                void setIdleFrame();
                void setWalkingFrame();
                void setJumpingFrame();
                void setFallingFrame();
                void setAttackingFrame();
                void setDeadFrame();

                int _speed;
                double _gravity;
                int _jump_height;
                size_t _jump_frame;
                double _jump_speed;
                size_t _idle_frame;
                double _idle_speed;
                size_t _walk_frame;
                double _walk_speed;
                size_t _attack_frame;
                double _attack_speed;
                size_t _death_frame;
                double _death_speed;
                int _player_width;
                int _player_height;
                float _texture_size;


                std::shared_ptr<MySandBox::Game::Player::Moves::IMoves> _moves;
                sf::Vector2f _position;
                size_t _sprite_index;
                sf::Sprite _player;
                PlayerState _state;
                PlayerDirection _direction;
                LogManager _log_manager;
            };
        }
    }
}

#endif //______PLAYER_HPP___
