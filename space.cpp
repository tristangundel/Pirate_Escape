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
#include <vector>
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

//function to check if player is in space
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

// function to return type of Space object
std::string Space::getSpaceType()
{
  return this->type;
}

// function to set the player boolean variable
void Space::setPlayerStatus(bool status)
{
  this->player = status;
}

// public function for objects to set their type variable
void Space::setType(std::string spaceType)
{
  this->type = spaceType;
}

// function to print space (used in Board Class' print function)
void Space::printSpace()
{
  // conditional print an X if space is user's current location
  if (hasPlayer())
  {
    std::cout << "   X   ";
  }
  else
  {
    std::cout << "       ";
  }
}

// function to return action required variable;
bool Space::getActionRequired()
{
  return this-> actionRequired;
}

void Space::setActionRequired(bool action)
{
  this->actionRequired = action;
  if (!action) {
    setMessage("There is nothing to do in this space");
  }
}

//empty virtual destructor
Space::~Space()
{
  //empty virtual destructor
}
