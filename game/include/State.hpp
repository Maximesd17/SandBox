/*
** EPITECH PROJECT, 2023
** MySandBox
** File description:
** State
*/

#ifndef ______STATE_HPP___
#define ______STATE_HPP___


#pragma once

#include "Types.hpp"

namespace MySandBox {
    class State {
    public:
        State();
        ~State();
        MySandBox::Scenes::Type getScene() const;
        MySandBox::Scenes::Type getSubScene() const;
        void setScene(MySandBox::Scenes::Type scene);
        void setSubScene(MySandBox::Scenes::Type sub_scene);
    protected:
    private:
        MySandBox::Scenes::Type _current_scene;
        MySandBox::Scenes::Type _current_sub_scene;
    };
};

#endif //______STATE_HPP___