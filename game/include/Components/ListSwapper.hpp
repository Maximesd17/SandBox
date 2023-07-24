/*
** EPITECH PROJECT, 2023
** SandBox
** File description:
** ListSwapper
*/

#ifndef LISTSWAPPER_HPP_
#define LISTSWAPPER_HPP_

#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include "Button.hpp"

namespace MySandBox {
    namespace Components {
        class ListSwapper {
        public:
            ListSwapper(
                std::string text,
                sf::FloatRect rect,
                sf::Vector2u window_origin_size,
                int default_value = 0
            );
            ~ListSwapper();
            void display(sf::RenderWindow& window);
            bool check(sf::RenderWindow& window);
            void setList(std::vector<std::string> &list);
            std::string getValue();
        protected:
        private:
            std::vector<std::string> _list;
            std::string _current_value;
            sf::Text _text;
            sf::Text _value;
            sf::Font _font;
            MySandBox::Components::ButtonState _state;
            std::map<MySandBox::Components::ButtonState, sf::Color> _colors;
            sf::Vector2u _window_origin_size;
            Button _button_left;
            Button _button_right;
        };
    }
}

#endif /* !LISTSWAPPER_HPP_ */
