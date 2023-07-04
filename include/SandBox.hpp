/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** MySandBox
*/

#pragma once
#include <memory>
#include "IScene.hpp"
#include "Game.hpp"
#include "State.hpp"
#include "Types.hpp"

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
    };
};