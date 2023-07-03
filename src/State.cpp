/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** State
*/

#include "State.hpp"

/*********Constructor*********/
/* init state of the game    */
/*********Constructor*********/
MySandBox::State::State()
{
    _current_scene = MySandBox::Scenes::MENU;
    _current_sub_scene = MySandBox::Scenes::SETTINGS;
}

/*********Destructor*********/
/* This destroy the object  */
/*********Destructor*********/
MySandBox::State::~State()
{
}

/*********getScene*********/
/* Getter for the current */
/*********getScene*********/
MySandBox::Scenes::Type MySandBox::State::getScene() const
{
    return _current_scene;
}

/*************getSubScene************/
/* Getter for the current sub-scene */
/*************getSubScene************/
MySandBox::Scenes::Type MySandBox::State::getSubScene() const
{
    return _current_sub_scene;
}

/************setScene************/
/* Setter for the current scene */
/************setScene************/
void MySandBox::State::setScene(MySandBox::Scenes::Type scene)
{
    _current_scene = scene;
    _current_sub_scene = MySandBox::Scenes::MAIN;
}

/*************setSubScene************/
/* Setter for the current sub-scene */
/*************setSubScene************/
void MySandBox::State::setSubScene(MySandBox::Scenes::Type sub_scene)
{
    _current_sub_scene = sub_scene;
}
