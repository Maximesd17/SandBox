#ifndef ______MYSANDBOX_HPP___
#define ______MYSANDBOX_HPP___

#include <map>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameEntity.hpp"
#include "Entity.hpp"
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
  std::vector<Entity> _entities;
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
  void set_sprite_textures();

  void display_map();
  void display_entity();

  #define SCALE_H(obj_height, real_size) ((_window_size.height / static_cast<double>(obj_height)) / real_size)
  #define SCALE_W(obj_width, real_size) ((_window_size.width / static_cast<double>(obj_width)) / real_size)

  #define SCALE_BY_HEIGHT(obj_height) (static_cast<double>(obj_height) / _window_size.height)
  #define SCALE_BY_WIDTH(obj_width) (static_cast<double>(obj_width) / _window_size.width)



};

#endif //______MYSANDBOX_HPP___
