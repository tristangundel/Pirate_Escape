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
#include "toolSpace.hpp"
#include "tool.hpp"
#include "item.hpp"
#include "hint.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <vector>
#include <string>
#include <iostream>

ToolSpace::ToolSpace()
: Space()
{
  this->toolInSpace = nullptr;
  setType("Tool");
}

ToolSpace::ToolSpace(int choice)
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
  setType("Tool");
  setPlayerStatus(false);
  if (choice == 1)
  {
    this->toolInSpace = new Item("Fishing Hook and Fishing Line");
    this->container = "under the floorboard";
    setMessage("There seems to be a squeaky floorboard here. Maybe it's loose?");
  }
  if (choice == 2)
  {
    this->toolInSpace = new Item("MonoScope");
    this->container = "inside of the chest";
    setMessage("There is a small chest here on the ground");
  }
  if (choice == 3)
  {
    this->toolInSpace = new Hint("Reading will keep you sane... - Captain Barbosa");
    this->container = "carved into the wall";
    setMessage("There is something carved into the wall here");
  }
  if (choice == 4)
  {
    this->toolInSpace = nullptr;
    this->container = "Nothing";
    setMessage("There is nothing to do in this space");
  }
  if (choice == 5)
  {
    this->toolInSpace = new Item("Small Rusty Tweezers");
    this->container = "inside of the book";
    setMessage("There is a shelf here with a large book on it. The book is written by Jack Sparrow.");
  }
  if (choice == 6)
  {
    this->toolInSpace = new Hint("Day 104");
    this->container = "carved into the wall";
    setMessage("There is a carving here on the wall.");
  }
}

Tool *ToolSpace::getTool()
{
  return this->toolInSpace;
}

void ToolSpace::spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items)
{
  std::string menuOptions[2];
  menuOptions[0] = "Investigate it!";
  menuOptions[1] = "Don't investigate it";
  Menu investigationMenu(2, &menuOptions[0]);

  displayMessage();
  if (getMessage() != "There is nothing to do in this space")
  {
    investigationMenu.printMenu();
    investigationMenu.makeSelection();
    if (investigationMenu.getSelection() == 1)
    {
      if (!(this->toolInSpace)->getIsItem())
      {
        std::cout << "\nThe words " << (this->toolInSpace)->getToolName()
                  << " were " << this->container << "\nThis message was added to "
                  << "your Hints container." << std::endl;
        hints.push_back(this->toolInSpace);
        this->setMessage("There is nothing to do in this space");
      }
      else if ((this->toolInSpace)->getIsItem())
      {
        std::cout << "\nYou found a " << (this->toolInSpace)->getToolName()
                  << " in the " << this->container << "\n This item was added to "
                  << "your item container." << std::endl;
        items.push_back(this->toolInSpace);
        this->setMessage("There is nothing to do in this space");
      }
    }
  }

}

ToolSpace::~ToolSpace()
{
  toolInSpace = nullptr;
  delete this;
}
