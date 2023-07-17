/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Range
*/

#pragma once

#include "Button.hpp"
#include <SFML/Graphics/CircleShape.hpp>

namespace MySandBox {
    namespace Components {
        class  Range {
            public:
                Range(
                    std::string text,
                    sf::Vector2i pos,
                    sf::Vector2f size,
                    sf::Vector2u window_origin_size,
                    int min,
                    int max,
                    int value,
                    bool show_value = true
                );
                ~Range();
                bool check(sf::RenderWindow &window);
                int getValue();
                void display(sf::RenderWindow &window);
            protected:
            private:
                bool isCursorHovered(sf::Vector2f mousePos, sf::Vector2u window_size);
                bool isBarHovered(sf::Vector2f mousePos, sf::Vector2u window_size);
                bool _show_value;
                int _min_value;
                int _max_value;
                sf::RectangleShape _bar;
                sf::CircleShape _cursor;
                sf::Text _text;
                sf::Text _value;
                sf::Font _font;
                MySandBox::Components::ButtonState _state;
                std::map<MySandBox::Components::ButtonState, sf::Color> _colors;
                sf::Vector2u _window_origin_size;
        };
    }
};
