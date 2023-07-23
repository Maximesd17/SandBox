
#ifndef __MAP_OBJECT_HPP__
#define __MAP_OBJECT_HPP__

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameMapObject.hpp"


namespace SandBox {
  class MapObject : GameMapObject
  {
  private:
    std::string _value;    

  protected:

  public:
    void	set_value(std::string);
    std::string	get_value() constexpr;
  };
};
#endif //__MAP_OBJECT_HPP__
