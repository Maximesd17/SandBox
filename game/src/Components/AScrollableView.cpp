/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** AScrollableView
*/

#include "Components/AScrollableView.hpp"
#include <iostream>

MySandBox::Components::AScrollableView::AScrollableView(
    sf::Vector2f size,
    sf::Vector2u window_size,
    bool is_scrollable
) :
    _view(sf::FloatRect(0, 0, window_size.x, window_size.y))
{
    _view.setViewport(sf::FloatRect(0.1, 0.1, 0.8, 0.8));
    _size = size;

    _scrollbar_track.setSize(sf::Vector2f(20, window_size.y));
    _scrollbar_track.setFillColor(sf::Color(255, 255, 255, 0));
    _scrollbar_track.setPosition(window_size.x - 20, 0);

    _scrollbar.setSize(sf::Vector2f(20, window_size.y));
    _scrollbar.setFillColor(sf::Color(255, 255, 255, 100));
    _scrollbar.setPosition(window_size.x - 20, 0);
    _scrollbar.setScale(1, _view.getSize().y / _size.y);

    _is_scrollable = is_scrollable;
    _window_size = window_size;
}

MySandBox::Components::AScrollableView::~AScrollableView()
{
}

void MySandBox::Components::AScrollableView::setView(sf::RenderWindow& window)
{
    window.setView(_view);
}

void MySandBox::Components::AScrollableView::events(sf::Event& event)
{
    if (!_is_scrollable) return;
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            _view.move(0, -50);
        } else if (event.mouseWheelScroll.delta < 0) {
            _view.move(0, 50);
        }
    }
}
bool isMouseOverRect(sf::RectangleShape rect, sf::Vector2i mousePos)
{
    if (mousePos.x > rect.getPosition().x && mousePos.x < rect.getPosition().x + rect.getSize().x) {
        if (mousePos.y > rect.getPosition().y && mousePos.y < rect.getPosition().y + rect.getSize().y) {
            return true;
        }
    }
    return false;
}

void MySandBox::Components::AScrollableView::checkScrollbar(sf::Vector2i mouse_pos)
{
    if (!_is_scrollable) return;
    if (isMouseOverRect(_scrollbar_track, mouse_pos) || _scrollbar_clicked) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _scrollbar_clicked = true;
            _view.setCenter(_view.getCenter().x, mouse_pos.y / _scrollbar.getScale().y);
        } else {
            _scrollbar_clicked = false;
        }
    }
}

void MySandBox::Components::AScrollableView::display(sf::RenderWindow& window)
{
    if (!_is_scrollable) return;
    window.draw(_scrollbar_track);
    window.draw(_scrollbar);
}

void MySandBox::Components::AScrollableView::update()
{
    if (!_is_scrollable) return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _view.move(0, -50);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _view.move(0, 50);
    }
    if (_view.getCenter().y - _view.getSize().y / 2 < 0) {
        _view.setCenter(_view.getCenter().x, _view.getSize().y / 2);
    }
    if (_view.getCenter().y + _view.getSize().y / 2 > _size.y) {
        _view.setCenter(_view.getCenter().x, _size.y - _view.getSize().y / 2);
    }
    _scrollbar.setPosition(
        _window_size.x - 20,
        (_view.getCenter().y - _view.getSize().y / 2) * _scrollbar.getScale().y
    );
}