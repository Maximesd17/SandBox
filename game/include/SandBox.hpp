/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** MySandBox
*/

#ifndef ______MYSANDBOX_HPP___
#define ______MYSANDBOX_HPP___


#pragma once
#include <memory>
#include "IScene.hpp"
#include "Game.hpp"
#include "State.hpp"
#include "Types.hpp"


#define getStevensMode sf::VideoMode::getDesktopMode() // Because Stevens is the reason for life =)

namespace MySandBox {
    class SandBox {
    public:
        SandBox();
        ~SandBox();
        int loop();
        bool checkElapsedTime();
        

    protected:
    private:
        int _framerate;
        sf::RenderWindow _window;
        sf::Clock _deltaTime;
        std::map<MySandBox::Scenes::Type, std::shared_ptr<MySandBox::Scenes::IScene> > _scenes;
        MySandBox::Game::Game _game;
        MySandBox::State _state;
        sf::VideoMode _window_size;
    };
};

#endif //______MYSANDBOX_HPP___