#ifndef ______MYSANDBOX_HPP___
#define ______MYSANDBOX_HPP___

#include <map>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameEntity.hpp"
#include "GameSpriteObject.hpp"
#include "GameSoundObject.hpp"
#include "GameMapObject.hpp"
#include "GameCamera.hpp"
#include "EventManager.hpp"


class SandBox 
{
private:
  unsigned int _framerate;
  sf::RenderWindow _window;
  sf::VideoMode _window_size;
  GameCamera _camera;
  EventManager _event_manager;
  std::map<const std::string, GameEntity&> _entities;
  std::map<const std::string, GameSpriteObject&> _sprites;
  std::map<const std::string, GameSoundObject&> _sounds;
  std::map<const int, GameMapObject&> _map_data;
  

public:
  SandBox();
  ~SandBox();
  void loop();
  void start();

};

#endif //______MYSANDBOX_HPP___
