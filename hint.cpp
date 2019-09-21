/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 12/04/2018
** Description: This file is one of 21 files that together form a
**              program with the capability of running a sinle player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
#include "hint.hpp"

Hint::Hint()
: Tool()
{
  setIsItem(false);
}

Hint::Hint(std::string name)
{
  setToolName(name);
  setIsItem(false);
}
