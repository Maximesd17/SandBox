/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** State
*/

#include "State.hpp"

MySandBox::State::State()
{
    _current_scene = MySandBox::Scenes::MENU;
    _current_sub_scene = MySandBox::Scenes::MAIN;
}

MySandBox::State::~State()
{
}

MySandBox::Scenes::Type MySandBox::State::getScene() const
{
    return _current_scene;
}

MySandBox::Scenes::Type MySandBox::State::getSubScene() const
{
    return _current_sub_scene;
}

void MySandBox::State::setScene(MySandBox::Scenes::Type scene)
{
    _current_scene = scene;
    _current_sub_scene = MySandBox::Scenes::MAIN;
}

void MySandBox::State::setSubScene(MySandBox::Scenes::Type sub_scene)
{
    _current_sub_scene = sub_scene;
}