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
#include "actionSpace.hpp"
#include "queue.hpp"
#include "item.hpp"
#include "hint.hpp"
#include "menu.hpp"
#include <string>
#include <iostream>

ActionSpace::ActionSpace()
: Space()
{
  this->requiredTool = "Nothing";
  setActionRequired(true);
  setType("Action");
}

ActionSpace::ActionSpace(int choice)
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
  setPlayerStatus(false);
  setType("Action");
  setActionRequired(true);
  if (choice == 1)
  {
    this->requiredTool = "Small Rusty Tweezers";
    setMessage("There is an old bottle with a message inside of it. You can't get \nthe message with your fingers though. If only you had\nsomething smaller!");
    setSuccessMessage("You were able to retrieve the message in the bottle! It says 'Yo ho and a bottle of rum'");
    this->retrievedTool = new Hint("Yo ho and a bottle of rum");
  }
  else if (choice == 2)
  {
    this->requiredTool = "Fishing Hook and Fishing Line";
    setMessage("There is a strom drain here. There is something shiny down in there.\nIf only you had something to fish it out!");
    setSuccessMessage("You were able to fish out the shiny object from the drain! It's a key!");
    this->retrievedTool = new Item("key");
  }
}

void ActionSpace::spaceFunction(Queue *hints, Queue *items)
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
        if (tempPtr->getToolName() == this->requiredTool)
        {
          std::cout << this->successMessage << std::endl;
          if ((this->retrievedTool)->getIsItem())
          {
            items->addBack(this->retrievedTool);
          }
          else
          {
            hints->addBack(this->retrievedTool);
          }

        }
      }
    }
  }
}

void ActionSpace::setRequiredTool(std::string tool)
{
  this->requiredTool = tool;
}
