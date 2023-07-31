/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Button
*/

#include "Button.hpp"
#include <SFML/Window/Mouse.hpp>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Component::Button::Button(std::string text, sf::Vector2i pos, sf::Vector2f size,
    sf::Vector2u window_origin_size)
    : _state(MySandBox::Component::IDLE), _window_origin_size(window_origin_size)
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
    _colors[IDLE] = sf::Color::Blue;
    _colors[HOVER] = sf::Color::Green;
    _colors[CLICKED] = sf::Color::Red;

    hover.loadSound("resources/sounds/hover_sound.wav");
    click.loadSound("resources/sounds/click_sound.wav");
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Component::Button::~Button()
{
}

/*********isHovered*****************************/
/* Check if the button is hovered by the mouse */
/*********isHovered*****************************/
bool MySandBox::Component::Button::isHovered(sf::Vector2i mouse_pos, sf::Vector2u window_size)
{
    sf::Vector2f pos = _rect.getPosition();
    sf::Vector2f size = _rect.getSize();

    pos.x = pos.x * window_size.x / _window_origin_size.x;
    pos.y = pos.y * window_size.y / _window_origin_size.y;
    size.x = size.x * window_size.x / _window_origin_size.x;
    size.y = size.y * window_size.y / _window_origin_size.y;
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.x && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.y)
        return true;
    return false;
}

/*********check************************************************************/
/* Check if the button is clicked or hovered, and update the button state */
/*********check************************************************************/
bool MySandBox::Component::Button::check(sf::RenderWindow& window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    if (_state == CLICKED && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (isHovered(mouse_pos, window.getSize()))
            _state = HOVER;
        else
            _state = IDLE;
        return true;
    }
    else if (isHovered(mouse_pos, window.getSize())) {
        _state = HOVER;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            _state = CLICKED;
    }
    else
        _state = IDLE;
    return false;
}

/*********display********************/
/* Display the button on the window */
/*********display********************/
void MySandBox::Component::Button::display(sf::RenderWindow& window)
{
    _rect.setFillColor(_colors[_state]);
    window.draw(_rect);
    window.draw(_text);
}

/********makeSound********/
/* Enables button sounds */
/********makeSound********/
void MySandBox::Component::Button::makeSound(){

    if (_state == HOVER && hover_isplayed == false){
        hover.playSound();
        hover_isplayed = true;
    }
    else if(_state == CLICKED){
        click.playSound();
    }
    else if(_state == IDLE){
        hover_isplayed = false;
    }
}
