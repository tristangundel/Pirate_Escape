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
#ifndef DOORSPACE_HPP
#define DOORSPACE_HPP
#include <string>
#include <vector>
#include "space.hpp"
#include "actionSpace.hpp"

class DoorSpace : public ActionSpace
{
  public:
    DoorSpace();
    DoorSpace(int choice);
    void printSpace();
    void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items);
    virtual ~DoorSpace();
};

#endif
