/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** SSMainMenu
*/

#pragma once

#include "Range.hpp"
#include "Game.hpp"
#include "ASubScene.hpp"

namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class SSSettingsMenu : public ASubScene {
            public:
                SSSettingsMenu(MySandBox::State& state, MySandBox::Game::Game& game);
                ~SSSettingsMenu();
                void update();
                void display();
            protected:
            private:
                MySandBox::Component::Range _volume_range;
                MySandBox::Component::Button _return_button;
            };
        }
    };
};