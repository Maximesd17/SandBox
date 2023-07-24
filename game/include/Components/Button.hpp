/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** Button
*/
#ifndef ______BUTTON_HPP___
#define ______BUTTON_HPP___

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace MySandBox {
    namespace Components {
        enum ButtonState {
            IDLE,
            HOVER,
            CLICKED
        };
        class Button {
        public:
            Button(std::string text, sf::Vector2i pos, sf::Vector2f size, sf::Vector2u window_origin_size);
            ~Button();
            bool check(sf::RenderWindow& window);
            void display(sf::RenderWindow& window);
        protected:
        private:
            bool isHovered(sf::Vector2f mousePos, sf::Vector2u window_size);
            bool _is_clicked;
            sf::RectangleShape _rect;
            sf::Text _text;
            sf::Font _font;
            MySandBox::Components::ButtonState _state;
            std::map<MySandBox::Components::ButtonState, sf::Color> _colors;
            sf::Vector2u _window_origin_size;
        };
    }
};

#endif //______BUTTON_HPP___