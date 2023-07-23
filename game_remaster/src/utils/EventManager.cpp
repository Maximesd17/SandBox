#include "EventManager.hpp"

EventManager::EventManager(sf::RenderWindow &window, GameCamera &camera, std::map<const std::string, GameEntity&> &entities)
:_window(window), _camera(camera), _entities(entities)
{
}

EventManager::~EventManager()
{
}


bool EventManager::fetch_event()
{
    sf::Event event;
    sf::RenderWindow& window = _window;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            window.close();
            return true;
        }
    }
    return false;
}