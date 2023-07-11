/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** IScene
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace MySandBox {
    namespace Scenes {
        namespace SubScenes {
            class ISubScene {
            public:
                virtual ~ISubScene() {};
                virtual void events(sf::Event&) = 0;
                virtual void update() = 0;
                virtual void display() = 0;
            protected:
            private:
            };
        }
    };
};
