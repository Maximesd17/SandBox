/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** IScene
*/

#ifndef ______ISCENE_HPP___
#define ______ISCENE_HPP___


#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace MySandBox {
    namespace Scenes {
        class IScene {
            public:
                virtual ~IScene() {};
                virtual bool events() = 0;
                virtual void update() = 0;
                virtual void display() = 0;
            protected:
            private:
        };
    };
};

#endif //______ISCENE_HPP___