/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Game
*/
#ifndef ______GAME_HPP___
#define ______GAME_HPP___


#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <math.h>
#include "MapGenerator.hpp"
#include "Player.hpp"

namespace MySandBox {
    namespace Game {
        enum Sprite {
            EMPTY,
            WALL,
            SPIKE,
            SPAWN,
            END
        };
        enum State {
            PENDING,
            START,
            PLAY,
            PAUSE,
            LOST,
            WIN,
        };
        class Game {
        public:
            Game(sf::RenderWindow& window);
            ~Game();
            void init();
            void reset();
            void events(sf::Event &event);
            void update();
            void display();
            void setGameState(State &game_state);

            sf::RenderWindow& getWindow() const;
            sf::Vector2u getWindowOriginSize() const;

            State getGameState() const;
            void setGameState(State game_state);
        protected:
        private:
            void updateViewPosition();
            void displayMap();
            void displayPlayer();

            int _default_texture_size = 40;
            int _texture_size;

            sf::RenderWindow& _window;
            sf::Vector2u _window_origin_size;
            sf::Texture _t_wall;
            sf::Texture _sprite_shit;
            sf::Sprite _s_wall;
            sf::View _game_view;

            MySandBox::Game::Player::Player _player;
            SandBox::MapGenerator _mapGenerator;
            State _game_state = PENDING;
        };
    }
};

#endif //______GAME_HPP___