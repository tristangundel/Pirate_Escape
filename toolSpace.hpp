#ifndef TOOLSPACE_HPP
#define TOOLSPACE_HPP
#include <string>
#include "tool.hpp"
#include "space.hpp"

class ToolSpace : public Space
{
  private:
    Tool *toolInSpace;
    std::string container;
  public:
    ToolSpace();
    ToolSpace(int);
    Tool *getTool();
    void spaceFunction(Queue *hints, Queue *items);
};

#endif
