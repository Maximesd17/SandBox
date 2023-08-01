/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** InputText
*/

#include "Components/InputText.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace MySandBox {
    namespace Components {
        InputText::InputText(std::string text, sf::Vector2i pos, sf::Vector2f size, sf::Vector2u window_origin_size)
            :_isSelected(false),  _window_origin_size(window_origin_size)
        {
        _rect.setPosition(pos.x, pos.y);
        _rect.setSize(size);
        _font.loadFromFile("resources/fonts/button.ttf");
        _text.setFont(_font);
        _text.setString(text);
        _text.setCharacterSize(size.y / 2);
        _text.setFillColor(sf::Color::Black);
        sf::Vector2f text_size = sf::Vector2f(_text.getLocalBounds().width, _text.getLocalBounds().height);
        _text.setPosition(pos.x + size.x / 2 - text_size.x / 2, pos.y + size.y / 2 - text_size.y / 2);
        }

        InputText::~InputText()
        {
        }

        void InputText::handleEvent(const sf::Event& event)
        {

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                if (_rect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    clearText();
                    _isSelected = true;
                } else {
                    _isSelected = false;
                }
            } else if (event.type == sf::Event::TextEntered && _isSelected) {
                if (event.text.unicode == 8 && !_text.getString().isEmpty()) {
                    std::string currentText = _text.getString();
                    currentText.pop_back();
                    _text.setString(currentText);
                } else if (event.text.unicode >= 32 && event.text.unicode < 128) {
                    std::string currentText = _text.getString();
                    currentText += static_cast<char>(event.text.unicode);
                    _text.setString(currentText);
                }
            }
        }

        void InputText::update()
        {
        }

        void InputText::display(sf::RenderWindow& window)
        {
            window.draw(_rect);
            window.draw(_text);
        }

        std::string InputText::getText() const
        {
            return _text.getString();
        }

        void InputText::clearText()
        {
            _text.setString("");
        }

        sf::RectangleShape InputText::getRect() const
        {
            return _rect;
        }

        bool InputText::isSelected() const
        {
            return _isSelected;
        }

        void InputText::setSelected(bool isSelected)
        {
            _isSelected = isSelected;
        }

    }
}
