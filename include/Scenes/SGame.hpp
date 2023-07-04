/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SGame
*/

#ifndef ______SGAME_HPP___
#define ______SGAME_HPP___


#pragma once

#include "ASubScene.hpp"
#include "AScene.hpp"
#include <memory>

namespace MySandBox {
    namespace Scenes {
        class SGame: public MySandBox::Scenes::AScene {
            public:
                SGame(MySandBox::State &state, MySandBox::Game::Game &game);
                ~SGame();
                bool events();
                void update();
                void display();
            protected:
            private:
                std::map<MySandBox::Scenes::Type, std::shared_ptr<MySandBox::Scenes::SubScenes::ISubScene> > _scenes;
        };
    }
};

#endif //______SGAME_HPP___