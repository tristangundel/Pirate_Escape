/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 09/19/2019
** Description: This file is one of 23 files that together form a
**              program with the capability of running a single player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
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
    void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items);
    virtual ~ToolSpace();
};

#endif
