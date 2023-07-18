/*
** EPITECH PROJECT, 2023
** final-project
** File description:
** AScrollableView
*/

#include "AScrollableView.hpp"
#include <iostream>

MySandBox::Components::AScrollableView::AScrollableView(sf::FloatRect size) :
    _view(size)
{
    _view.setViewport(sf::FloatRect(0.1, 0.1, 0.8, 0.8));
    _height = 3800;
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
        if (event.mouseWheelScroll.delta > 0) {
            _view.move(0, -50);
        } else if (event.mouseWheelScroll.delta < 0) {
            _view.move(0, 50);
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
    if (_view.getCenter().y + _view.getSize().y / 2 > _height) {
        _view.setCenter(_view.getCenter().x, _height - _view.getSize().y / 2);
    }
}