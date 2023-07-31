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
#include "JsonData.hpp"
#include "JsonParser.hpp"
#include "GameMap.hpp"


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
  std::map<const std::string, sf::Texture> _textures;
  GameMap _map;

public:
  SandBox();
  ~SandBox();
  void loop();
  void start();
  void set_map(GameMap);
  GameMap getMap() const;

  void display_map();
};

#endif //______MYSANDBOX_HPP___
