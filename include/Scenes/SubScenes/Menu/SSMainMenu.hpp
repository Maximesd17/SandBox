/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SSMainMenu
*/

#pragma once

#include "ASubScene.hpp"
#include "Button.hpp"

namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class SSMainMenu : public MySandBox::Scenes::SubScenes::ASubScene {
            public:
                SSMainMenu(MySandBox::State& state, MySandBox::Game::Game& game);
                ~SSMainMenu();
                void update();
                void display();
            protected:
            private:
                MySandBox::Component::Button _play_button;
                MySandBox::Component::Button _settings_button;
                MySandBox::Component::Button _exit_button;
                std::string _map_path;
            };
        }
    };
};