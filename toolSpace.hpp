#ifndef TOOLSPACE_HPP
#define TOOLSPACE_HPP
#include <string>
#include <vector>
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
    void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items);
    virtual ~ToolSpace();
};

#endif
