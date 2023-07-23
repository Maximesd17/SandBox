#ifndef ______EVENTMANAGER_HPP______
#define ______EVENTMANAGER_HPP______
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <memory>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "GameCamera.hpp"
#include "GameEntity.hpp"

class EventManager
{
private:
    sf::RenderWindow &_window;
    GameCamera &_camera;
    std::map<const std::string, GameEntity&> &_entities;

public:
    EventManager(sf::RenderWindow &, GameCamera &, std::map<const std::string, GameEntity&> &);
    ~EventManager();

    bool fetch_event();

};
#endif //______EVENTMANAGER_HPP______
