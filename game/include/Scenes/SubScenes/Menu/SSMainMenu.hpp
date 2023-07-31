/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SSMainMenu
*/

#pragma once

#include "ASubScene.hpp"
#include "Button.hpp"
#include "Sound.hpp"

namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class SSMainMenu : public MySandBox::Scenes::SubScenes::ASubScene {
            public:
                SSMainMenu(MySandBox::State& state, MySandBox::Game::Game& game);
                ~SSMainMenu();
                void update();
                void display();
                void makeSound();
            protected:
            private:
                MySandBox::Components::Button _play_button;
                MySandBox::Components::Button _settings_button;
                MySandBox::Components::Button _exit_button;
                std::string _map_path;
            };
        }
    };
};