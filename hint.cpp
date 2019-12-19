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
#include "hint.hpp"

// default constructor to build a Hint object
Hint::Hint()
: Tool()
{
  setIsItem(false);
}

// constructor to build a Hint object with a custom name
Hint::Hint(std::string name)
{
  setToolName(name);
  setIsItem(false);
}
