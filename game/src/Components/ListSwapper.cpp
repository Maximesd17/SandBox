/*
** EPITECH PROJECT, 2023
** SandBox
** File description:
** ListSwapper
*/

#include "ListSwapper.hpp"
#include <iostream>

MySandBox::Components::ListSwapper::ListSwapper(
    std::string text,
    sf::FloatRect rect,
    sf::Vector2u window_origin_size,
    int default_value
) : _window_origin_size(window_origin_size),
_button_left("<", sf::Vector2i(rect.left - rect.width / 2, rect.top), sf::Vector2f(rect.width / 2, rect.height), window_origin_size),
_button_right(">", sf::Vector2i(rect.left + rect.width + rect.width / 2, rect.top), sf::Vector2f(rect.width / 2, rect.height), window_origin_size)
{
    _font.loadFromFile("resources/fonts/button.ttf");
    _text.setFont(_font);
    _text.setString(text);
    _text.setCharacterSize(60);
    _text.setFillColor(sf::Color::White);
    _text.setPosition(rect.left, rect.top);
    _text.setOrigin(_text.getGlobalBounds().width / 2, _text.getGlobalBounds().height / 2);
    _value.setFont(_font);
    _value.setCharacterSize(60);
    _value.setFillColor(sf::Color::White);
    _value.setPosition(rect.left + rect.width, rect.top);
    _value.setOrigin(_value.getGlobalBounds().width / 2, _value.getGlobalBounds().height / 2);
    _state = MySandBox::Components::ButtonState::IDLE;
    _colors[MySandBox::Components::ButtonState::IDLE] = sf::Color(255, 255, 255, 255);
    _colors[MySandBox::Components::ButtonState::HOVER] = sf::Color(255, 255, 255, 255);
    _colors[MySandBox::Components::ButtonState::CLICKED] = sf::Color(255, 255, 255, 255);

}

MySandBox::Components::ListSwapper::~ListSwapper()
{
}

void MySandBox::Components::ListSwapper::setList(std::vector<std::string> &list)
{
    _list = list;
    _current_value = _list[0];
    _value.setString(_current_value);
}

bool MySandBox::Components::ListSwapper::check(sf::RenderWindow& window)
{

    if (_button_left.check(window)) {
        int index = 0;
        for (int i = 0; i < _list.size(); i++) {
            if (_list[i] == _current_value)
                index = i;
        }
        if (index == 0)
            index = _list.size() - 1;
        else
            index--;
        _current_value = _list[index];
        _value.setString(_current_value);
        _value.setOrigin(_value.getGlobalBounds().width / 2, _value.getGlobalBounds().height / 2);
        return true;
    }
    if (_button_right.check(window)) {
        int index = 0;
        for (int i = 0; i < _list.size(); i++) {
            if (_list[i] == _current_value)
                index = i;
        }
        if (index == _list.size() - 1)
            index = 0;
        else
            index++;
        _current_value = _list[index];
        _value.setString(_current_value);
        _value.setOrigin(_value.getGlobalBounds().width / 2, _value.getGlobalBounds().height / 2);
        return true;
    }
    return false;
}

void MySandBox::Components::ListSwapper::display(sf::RenderWindow& window)
{
    std::cout << _current_value << std::endl;
    _button_left.display(window);
    _button_right.display(window);
    window.draw(_text);
    window.draw(_value);
}