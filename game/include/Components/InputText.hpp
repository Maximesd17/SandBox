/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** InputText
*/
#ifndef INPUT_TEXT_HPP
#define INPUT_TEXT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

namespace MySandBox {
    namespace Components {
        class InputText {
        public:
            InputText(std::string text, sf::Vector2i pos, sf::Vector2f size, sf::Vector2u window_origin_size);
            ~InputText();
            void handleEvent(const sf::Event& event);
            void update();
            void display(sf::RenderWindow& window);
            std::string getText() const;
            sf::RectangleShape getRect() const;
            bool isSelected() const;
            void setSelected(bool isSelected);
            void clearText();
        private:
            sf::Vector2u _window_origin_size;
            sf::RectangleShape _rect;
            sf::Text _text;
            sf::Font _font;
            bool _isSelected;
        };
    }
}

#endif // INPUT_TEXT_HPP
