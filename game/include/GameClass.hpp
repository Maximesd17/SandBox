/*
** EPITECH PROJECT, 2022
** SandBox
** File description:
** SandBox
*/

#ifndef ______GAMECLASS_HPP___
#define ______GAMECLASS_HPP___


#pragma once
#include <memory>
#include "IScene.hpp"
#include "Game.hpp"
#include "State.hpp"
#include "Types.hpp"

namespace MySandBox {
    class GameClass {
    public:
        GameClass();
        ~GameClass();
        int loop();
    protected:
    private:
        sf::RenderWindow _window;
        std::map<SandBox::Scenes::Type, std::shared_ptr<SandBox::Scenes::IScene> > _scenes;
        SandBox::Game _game;
        SandBox::State _state;
    };
};

#endif //______GAMECLASS_HPP___