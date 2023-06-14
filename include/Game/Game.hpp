/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Game
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "Player.hpp"

namespace MySandBox {
    enum Sprite {
        NONE,
        WALL,
        SPIKE,
        PLAYER,
        END
    };
    class Game {
        public:
            Game(sf::RenderWindow &window);
            ~Game();
            void init();
            void reset();
            void displayMap();
            void displayPlayer();
            sf::RenderWindow &getWindow() const;
            sf::Vector2u getWindowOriginSize() const;
        protected:
        private:
            sf::RenderWindow &_window;
            sf::Vector2u _window_origin_size;
            sf::Texture _t_wall;
            std::vector<sf::Texture> _t_player;
            sf::Sprite _s_wall;
            MySandBox::Component::Player _player;

    };
};