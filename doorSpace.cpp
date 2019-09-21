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
#include "doorSpace.hpp"
#include <iostream>
#include "tool.hpp"
#include "item.hpp"
#include "menu.hpp"


DoorSpace::DoorSpace()
: ActionSpace()
{
  setActionRequired(true);
  setMessage("There be a gate here, but its locked and ye need a key to open it");
  setType("Door");
  Tool* key = new Item("Key");
  setRequiredTool(key->getToolName());
}

void DoorSpace::printSpace()
{
  if (this->hasPlayer())
  {
    std::cout << "   X  |";
  }
  else
  {
    std::cout << "      |";
  }
}

void DoorSpace::spaceFunction(Queue *hints, Queue *items)
{
  std::string menuOptions[2];
  menuOptions[0] = "Try to use an item!";
  menuOptions[1] = "Don't try anything yet";
  Menu investigationMenu(2, &menuOptions[0]);
  displayMessage();
  if (getMessage() != "There is nothing to do in this space")
  {
    investigationMenu.printMenu();
    investigationMenu.makeSelection();
    if (investigationMenu.getSelection() == 1)
    {
      if (!items->isEmpty())
      {
        int choice;
        int count;
        items->printQueue();
        std::cin >> choice;
        while (count < choice)
        {
          items->advanceHead();
        }
        Tool *tempPtr = items->getFront();
        if (tempPtr->getToolName() == getRequiredTool());
        {
          std::cout << "You did it! You escaped the brig!"
          << std::endl;
          this->setActionRequired(false);
        }
      }
    }
  }
}
