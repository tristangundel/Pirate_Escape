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
#include <vector>
#include <cctype>
#include "inputValidation.hpp"
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

DoorSpace::DoorSpace(int choice)
: ActionSpace()
{
  this->setActionRequired(true);
  if (choice == 1)
  {
    this->setMessage("There be a gate here, but its locked and ye need a key to open it");
    this->setType("Door");
    Tool* key = new Item("Small Key");
    this->setRequiredTool(key->getToolName());
    this->setSuccessMessage("\nThe key fit, ye were able to open the gate! Make yer way down the hallway");
  } else {
    this->setMessage("There be another gate here, but its locked and ye need a key to open it");
    this->setType("Door");
    Tool* key = new Item("Large Key");
    this->setRequiredTool(key->getToolName());
    this->setSuccessMessage("\nYou did it! You escaped the brig!");
  }
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

void DoorSpace::spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items)
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
      if (!items.empty())
      {
        std::string choice;
        this->printList(items);
        std::cin >> choice;
        while (!validateInput(choice, 1, items.size())){
          std::cout << "That was not a valid option, try again." << std::endl;
          std::cin.clear();
          std::cin >> choice;
        }

        Tool *tempPtr = items[std::stoi(choice) - 1];
        if (tempPtr->getToolName() == this->getRequiredTool())
        {
          std::cout << this->getSuccessMessage() << std::endl;
          this->setActionRequired(false);
          this->setMessage("There is nothing to do in this space");
        } else {
          std::cout << "This tool does not work here" << std::endl;
        }
      }
    }
  }
}

DoorSpace::~DoorSpace()
{
  delete this;
}
