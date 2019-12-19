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
#include "doorSpace.hpp"
#include <iostream>
#include <vector>
#include <cctype>
#include "inputValidation.hpp"
#include "tool.hpp"
#include "item.hpp"
#include "menu.hpp"

// default constructor for a DoorSpace object
DoorSpace::DoorSpace()
: ActionSpace()
{
  setActionRequired(true);
  setMessage("There be a gate here, but its locked and ye need a key to open it");
  setType("Door");
  this->setRequiredTool("Key");
}

// constructor to create 2 distinct DoorSpace objects needed for the game
DoorSpace::DoorSpace(int choice)
: ActionSpace()
{
  this->setActionRequired(true);   // set action required variable to be true
  this->setType("Door");

  // conditional statements for the two different doors in the game board
  if (choice == 1)
  {
    // set standard message to be displayed when user is on space
    this->setMessage("There be a gate here, but its locked and ye need a key to open it");

    // set required tool and success message variables
    this->setRequiredTool("Small Key");
    this->setSuccessMessage("\nThe key fit, ye were able to open the gate! Make yer way down the hallway");

  } else {
    // set standard message to be displayed when user is on space
    this->setMessage("There be another gate here, but its locked and ye need a key to open it");

    // set required tool and success message variables
    this->setRequiredTool("Large Key");
    this->setSuccessMessage("\nYou did it! You escaped the brig!");
  }
}

// function to print door spaces on game board
void DoorSpace::printSpace()
{
  if (this->hasPlayer())       // conditionally print X if user is currently in space
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
  // create menu and options used for user selection in this space
  std::string menuOptions[2];
  menuOptions[0] = "Try to use an item!";
  menuOptions[1] = "Don't try anything yet";
  Menu investigationMenu(2, &menuOptions[0]);

  // display the standard message for the current space
  displayMessage();

  // if action has not already been completed
  if (getMessage() != "There is nothing to do in this space")
  {
    investigationMenu.printMenu();              // print door space menu and get user selection
    investigationMenu.makeSelection();

    if (investigationMenu.getSelection() == 1)    // if user selects to use an item
    {
      if (!items.empty())      // if user has an item to select
      {
        // declare variable choice to store user selection, and print their list of available items to choose
        std::string choice;
        this->printList(items);

        // get user selection, and loop until a valid option is selected
        std::cin >> choice;
        while (!validateInput(choice, 1, items.size())){
          std::cout << "That was not a valid option, try again." << std::endl;
          std::cin.clear();
          std::cin >> choice;
        }

        // declare temporary pointer to hold selected tool
        Tool *tempPtr = items[std::stoi(choice) - 1];
        if (tempPtr->getToolName() == this->getRequiredTool())    // if selected tool is required tool
        {
          std::cout << this->getSuccessMessage() << std::endl;     // display success message
          this->setActionRequired(false);                     // set action required to false
          this->setMessage("There is nothing to do in this space");   // change standard message

          // else if user has not tools to use, display this message
        } else {
          std::cout << "This tool does not work here" << std::endl;
        }
      }
    }
  }
}

// deconstructor for DoorSpace objects to free dynamically allocated memory
DoorSpace::~DoorSpace()
{
  delete this;
}
