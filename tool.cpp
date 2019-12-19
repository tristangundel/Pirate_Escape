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
#include <string>
#include <iostream>
#include "tool.hpp"

// default constructor for Tool objects
Tool::Tool()
{
  this->toolName = "Useless Tool";
  this->isItem = false;
}

// function to return Tool object's name variable
std::string Tool::getToolName()
{
  return this->toolName;
}

// function to set Tool object's name variable
void Tool::setToolName(std::string name)
{
  this->toolName = name;
}

// function to set boolean variable indicating tool is an item
void Tool::setIsItem(bool item)
{
  this->isItem = item;
}

// function to retrieve boolean variable indicating tool is an item
bool Tool::getIsItem()
{
  return this->isItem;
}
