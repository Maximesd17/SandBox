/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Game
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

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
            sf::RenderWindow &getWindow() const;
            sf::Vector2u getWindowOriginSize() const;
            void setMapPath(std::string &path);
        protected:
        private:
            sf::RenderWindow &_window;
            sf::Vector2u _window_origin_size;
            std::string _map_path;
            std::vector<std::string> _map;
            std::vector<std::shared_ptr<sf::Texture> > _textures;
            std::vector<std::shared_ptr<sf::Sprite> > _sprites;
            sf::Texture _t_wall;
            sf::Texture _t_spike;
            sf::Texture _t_player;
            sf::Sprite _s_wall;
            sf::Sprite _s_spike;
            sf::Sprite _s_player;

    };
};