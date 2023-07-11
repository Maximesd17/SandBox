/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** AScrollableView
*/

#include "AScrollableView.hpp"

MySandBox::Components::AScrollableView::AScrollableView(sf::FloatRect size):
    _view(size)
{
    _view.setViewport(sf::FloatRect(0, 0.1, 1, 1));
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
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
            if (event.mouseWheelScroll.delta > 0) {
                _view.move(0, -50);
            } else {
                _view.move(0, 50);
            }
        }
    }
}

void MySandBox::Components::AScrollableView::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _view.move(0, -50);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _view.move(0, 50);
    }
    if (_view.getCenter().y - _view.getSize().y / 2 < 0) {
        _view.setCenter(_view.getCenter().x, _view.getSize().y / 2);
    }
    if (_view.getCenter().y + _view.getSize().y / 2 > 1000) {
        _view.setCenter(_view.getCenter().x, 1000 - _view.getSize().y / 2);
    }
}