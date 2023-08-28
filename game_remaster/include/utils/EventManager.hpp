#ifndef ______EVENTMANAGER_HPP______
#define ______EVENTMANAGER_HPP______

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <memory>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "GameCamera.hpp"
#include "Entity.hpp"

class EventManager
{
private:
    sf::RenderWindow &_window;
    GameCamera &_camera;
    std::vector<Entity> &_entities;

public:
    EventManager(sf::RenderWindow &, GameCamera &, std::vector<Entity> &);
    ~EventManager();

    bool fetchEvent();

};
#endif //______EVENTMANAGER_HPP______
