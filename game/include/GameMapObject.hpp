/*
** EPITECH PROJECT, 2022
** MySandBox
** File description:
** GameMapObject
*/

#ifndef ______GAMEMAPOBJECT_HPP___
#define ______GAMEMAPOBJECT_HPP___

#include "GameSpriteObject.hpp"

namespace SandBox {
  class GameMapObject : GameSpriteObject
  {

  protected:
    virtual bool checkIdentifiers(std::string &line) = 0;
    virtual void keyPoints(std::string &line) = 0;
  public:
    virtual std::string getMapFile() = 0;
    virtual std::vector<std::string> getMap() = 0;
    virtual sf::Vector2f getSpawnPoint() = 0;
    virtual sf::Vector2f getEndPoint() = 0;
    virtual std::vector<sf::Vector2f> getCollisionPositions() = 0;
    virtual bool validateMap(std::vector<std::string> &map) = 0;
    virtual bool isValid() = 0;
    virtual void displayMap(sf::RenderWindow &_window) = 0;
    /*
      public:
      virtual void update() = 0;
      virtual void display(sf::RenderWindow&) = 0;
      virtual sf::Vector2f getPosition() = 0;
      virtual void setPosition(sf::Vector2f position) = 0;

    */
  };
};
#endif //______GAMEMAPOBJECT_HPP___
