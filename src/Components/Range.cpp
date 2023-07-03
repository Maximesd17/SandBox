/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** Range
*/

#include "Range.hpp"
#include <SFML/Window/Mouse.hpp>

/*********Constructor*********/
/* This build the object     */
/*********Constructor*********/
MySandBox::Component::Range::Range(std::string text, sf::Vector2i pos, sf::Vector2f size,
    sf::Vector2u window_origin_size, int min, int max, int value)
    : _state(MySandBox::Component::IDLE), _window_origin_size(window_origin_size)
{
    _min_value = min;
    _max_value = max;
    _bar.setPosition(pos.x, pos.y);
    _bar.setSize(sf::Vector2f(size.x, size.y / 4));
    _bar.setFillColor(sf::Color::Blue);
    _cursor.setRadius(size.y / 2);
    _cursor.setFillColor(sf::Color::White);
    _cursor.setPosition(
        pos.x - size.y / 2 + (size.x / max * value),
        pos.y + size.y / 8 - size.y / 2
    );
    _cursor.setPointCount(100);
    // _font.loadFromFile("resources/fonts/button.ttf");
    // _text.setFont(_font);
    // _text.setString(text);
    // _text.setCharacterSize(size.y / 2);
    // _text.setFillColor(sf::Color::Black);
    sf::Vector2f text_size = sf::Vector2f(_text.getLocalBounds().width, _text.getLocalBounds().height);
    // _text.setPosition(pos.x + size.x / 2 - text_size.x / 2, pos.y + size.y / 2 - text_size.y / 2);
    _colors[IDLE] = sf::Color::Blue;
    _colors[HOVER] = sf::Color::Green;
    _colors[CLICKED] = sf::Color::Red;
}

/*********Destructor*********/
/* This destroy the sandbox */
/*********Destructor*********/
MySandBox::Component::Range::~Range()
{
}

/*********isHovered*****************************/
/* Check if the button is hovered by the mouse */
/*********isHovered*****************************/
bool MySandBox::Component::Range::isHovered(sf::Vector2i mouse_pos, sf::Vector2u window_size)
{
    sf::Vector2f pos = _cursor.getPosition();
    float size = _cursor.getRadius();

    pos.x = pos.x * window_size.x / _window_origin_size.x;
    pos.y = pos.y * window_size.y / _window_origin_size.y;
    size = size * window_size.x / _window_origin_size.x * 2;
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size)
        return true;
    return false;
}

/*********check************************************************************/
/* Check if the cursor is clicked or hovered, and update his state and his pos */
/*********check************************************************************/
bool MySandBox::Component::Range::check(sf::RenderWindow& window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    if (_state == CLICKED && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f pos = _cursor.getPosition();
        float size = _cursor.getRadius();

        pos.x = mouse_pos.x - size;
        if (pos.x < _bar.getPosition().x - size)
            pos.x = _bar.getPosition().x - size;
        else if (pos.x > _bar.getPosition().x + _bar.getSize().x - size)
            pos.x = _bar.getPosition().x + _bar.getSize().x - size;
        _cursor.setPosition(pos);
        return true;
    } else if (_state == CLICKED && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (isHovered(mouse_pos, window.getSize()))
            _state = HOVER;
        else
            _state = IDLE;
        return true;
    } else if (isHovered(mouse_pos, window.getSize())) {
        _state = HOVER;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            _state = CLICKED;
    } else
        _state = IDLE;
    return false;
}

/*********getValue*******************/
/* Return the value of the range   */
/*********getValue*******************/
int MySandBox::Component::Range::getValue()
{
    sf::Vector2f pos = _cursor.getPosition();
    float size = _cursor.getRadius();

    pos.x = pos.x + size;
    pos.x = pos.x - _bar.getPosition().x;
    pos.x = pos.x / _bar.getSize().x;
    pos.x = pos.x * (_max_value - _min_value);
    pos.x = pos.x + _min_value;
    return pos.x;
}


/*********display********************/
/* Display the button on the window */
/*********display********************/
void MySandBox::Component::Range::display(sf::RenderWindow& window)
{
    _cursor.setFillColor(_colors[_state]);
    window.draw(_bar);
    window.draw(_cursor);
}
