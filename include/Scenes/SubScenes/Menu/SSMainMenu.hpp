/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SSMainMenu
*/

#pragma once

#include "AScene.hpp"
#include "Button.hpp"

namespace MySandBox {
    namespace Scenes {
        class SSMainMenu: public MySandBox::Scenes::AScene {
            public:
                SSMainMenu(MySandBox::State &state, MySandBox::Game::Game &game);
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
    };
};