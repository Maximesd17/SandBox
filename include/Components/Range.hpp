/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Range
*/

#pragma once

#include "Button.hpp"
#include <SFML/Graphics/CircleShape.hpp>

namespace MySandBox {
    namespace Component {
        class  Range {
            public:
                Range(
                    std::string text,
                    sf::Vector2i pos,
                    sf::Vector2f size,
                    sf::Vector2u window_origin_size,
                    int min,
                    int max,
                    int value
                );
                ~Range();
                bool check(sf::RenderWindow &window);
                int getValue();
                void display(sf::RenderWindow &window);
            protected:
            private:
                bool isHovered(sf::Vector2i mousePos, sf::Vector2u window_size);
                int _min_value;
                int _max_value;
                sf::RectangleShape _bar;
                sf::CircleShape _cursor;
                sf::Text _text;
                sf::Font _font;
                MySandBox::Component::ButtonState _state;
                std::map<MySandBox::Component::ButtonState, sf::Color> _colors;
                sf::Vector2u _window_origin_size;
        };
    }
};
