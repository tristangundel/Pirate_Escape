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
#include <string>
#include <iostream>
#include "space.hpp"

//constructor for abstract class
Space::Space()
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
  setMessage("This message will never be seen");
  setType("None");
  setPlayerStatus(false);
}

//set function for top pointer variable
void Space::setTop(Space* topPtr)
{
  this->top = topPtr;
}

//set function for right pointer variable
void Space::setRight(Space* rightPtr)
{
  this->right = rightPtr;
}

//set function for left pointer variable
void Space::setLeft(Space* leftPtr)
{
  this->left = leftPtr;
}

//set function for bottom pointer variable
void Space::setBottom(Space* bottomPtr)
{
  this->bottom = bottomPtr;
}

//get function for top pointer variable
Space* Space::getTop()
{
  return this->top;
}
//get function for right pointer variable
Space* Space::getRight()
{
  return this->right;
}
//get function for left pointer variable
Space* Space::getLeft()
{
  return this->left;
}
//get function for bottom pointer variable
Space* Space::getBottom()
{
  return this->bottom;
}

//set function for message
void Space::setMessage(std::string note)
{
  this->message = note;
}

std::string Space::getMessage()
{
  return this->message;
}

//function to display message
void Space::displayMessage()
{
  std::cout << this->message << std::endl;
}

//method to check if player is in space
bool Space::hasPlayer()
{
  if (this->player)
  {
    return true;
  }
  else
  {
    return false;
  }
}

std::string Space::getSpaceType()
{
  return this->type;
}

void Space::setPlayerStatus(bool status)
{
  this->player = status;
}

void Space::setType(std::string spaceType)
{
  this->type = spaceType;
}

void Space::printSpace()
{
  if (hasPlayer())
  {
    std::cout << "   X   ";
  }
  else
  {
    std::cout << "       ";
  }
}

bool Space::getActionRequired()
{
  return this-> actionRequired;
}

void Space::setActionRequired(bool action)
{
  this->actionRequired = action;
}
