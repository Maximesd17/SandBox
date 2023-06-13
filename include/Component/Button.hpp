/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Button
*/

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace MySandBox {
    namespace Component {
        enum ButtonState {
            IDLE,
            HOVER,
            CLICKED
        };
        class Button {
            public:
                Button(std::string text, sf::Vector2i pos, sf::Vector2f size, sf::Vector2u window_origin_size);
                ~Button();
                bool check(sf::RenderWindow &window);
                void display(sf::RenderWindow &window);
            protected:
            private:
                bool isHovered(sf::Vector2i mousePos, sf::Vector2u window_size);
                sf::RectangleShape _rect;
                sf::Text _text;
                sf::Font _font;
                MySandBox::Component::ButtonState _state;
                std::map<MySandBox::Component::ButtonState, sf::Color> _colors;
                sf::Vector2u _window_origin_size;
        };
    }
};
