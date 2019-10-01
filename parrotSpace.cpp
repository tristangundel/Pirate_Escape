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
#include "parrotSpace.hpp"
#include "hint.hpp"
#include "item.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <cctype>
#include <vector>
#include <string>
#include <iostream>

ParrotSpace::ParrotSpace()
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
  setPlayerStatus(false);
  setType("Parrot");
  setActionRequired(true);

  this->setRequiredTool("Yo ho and a bottle of rum");
  Tool* newItem = new Item("Large Key");
  this->setRetrievedTool(newItem);
  this->setMessage("There is an old Parrot perched on the sconce on the wall. It keeps repeating the words 'Speak to me and ye may be free' Maybe one of your hints will let you know what to say to him");
  this->setSuccessMessage("\nThe parrot said, 'Yo ho yo ho' and then revealed a large key from underneath his wing and dropped it in front of you. It has been added to your items list.");
}

void ParrotSpace::spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items)
{
  std::string menuOptions[2];
  menuOptions[0] = "Try to repeat one of your hints to him!";
  menuOptions[1] = "Don't try anything yet";
  Menu investigationMenu(2, &menuOptions[0]);

  displayMessage();
  if (getMessage() != "There is nothing to do in this space")
  {
    investigationMenu.printMenu();
    investigationMenu.makeSelection();
    if (investigationMenu.getSelection() == 1)
    {
      if (!hints.empty())
      {
        std::string choice;
        this->printList(hints);
        std::cin >> choice;
        while (!validateInput(choice, 1, hints.size())){
          std::cout << "That was not a valid option, try again." << std::endl;
          std::cin.clear();
          std::cin >> choice;
        }

        Tool *tempPtr = hints[std::stoi(choice) - 1];
        if (tempPtr->getToolName() == this->getRequiredTool())
        {
          std::cout << this->getSuccessMessage() << std::endl;
          items.push_back(this->getRetrievedTool());
          this->setMessage("There is nothing to do in this space");
        } else {
          std::cout << "This hint does not work here" << std::endl;
        }
      } else {
        std::cout << "You don't have any hints to use." << std::endl;
      }
    }
  }
}

ParrotSpace::~ParrotSpace()
{
  this->setRetrievedTool(nullptr);
  delete this;
}
