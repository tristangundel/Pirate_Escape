#ifndef ITEM_HPP
#define ITEM_HPP
#include "tool.hpp"
#include <string>

class Item : public Tool
{
  public:
    Item();
    Item(std::string);
};

#endif
