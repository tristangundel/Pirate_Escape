/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 12/04/2018
** Description: This file is one of 19 files that together form a
**              program with the capability of running a sinle player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
#include <string>
#include <iostream>
#include "tool.hpp"

Tool::Tool()
{
  this->toolName = "Useless Tool";
  this->isItem = false;
}

Tool::Tool(std::string name)
{
  this->toolName = name;
}

std::string Tool::getToolName()
{
  return this->toolName;
}
