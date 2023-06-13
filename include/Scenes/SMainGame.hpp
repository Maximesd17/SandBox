/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** SMainGame
*/

#pragma once

#include "SGame.hpp"

namespace MySandBox {
    namespace Scenes {
        class SMainGame: public MySandBox::Scenes::AScene {
            public:
                SMainGame(MySandBox::State &state, MySandBox::Game &game);
                ~SMainGame();
                void update();
                void display();
            protected:
            private:
        };
    };
};
