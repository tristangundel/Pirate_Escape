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
#include "parrotSpace.hpp"
#include "hint.hpp"
#include "item.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <cctype>
#include <vector>
#include <string>
#include <iostream>

// default constructor for ParrotSpace objects
ParrotSpace::ParrotSpace()
{
  //set space pointers to null upon creation of the object
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);

  // set player status to false because player is not in this space
  setPlayerStatus(false);
  setType("Parrot");            // set type of space to action
  setActionRequired(true);      // set action required to true

  // set required Tool variable with correct message needed
  this->setRequiredTool("Yo ho and a bottle of rum");

  // declare new Item (key) and set as the retrieved Tool
  Tool* newItem = new Item("Large Key");
  this->setRetrievedTool(newItem);

  // set standard message to be displayed when user
  this->setMessage("There is an old Parrot perched on the sconce on the wall. It keeps repeating the words 'Speak to me and ye may be free' Maybe one of your hints will let you know what to say to him");

  // set displayed message to be displayed when user is successful
  this->setSuccessMessage("\nThe parrot said, 'Yo ho yo ho' and then revealed a large key from underneath his wing and dropped it in front of you. It has been added to your items list.");
}

// function to perform what should be done when user lands on this space
void ParrotSpace::spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items)
{
  // create menu and options used for user selection in this space
  std::string menuOptions[2];
  menuOptions[0] = "Try to repeat one of your hints to him!";
  menuOptions[1] = "Don't try anything yet";
  Menu investigationMenu(2, &menuOptions[0]);

  // display the standard message for the current space
  displayMessage();

  // if action has not already been completed
  if (getMessage() != "There is nothing to do in this space")
  {
    investigationMenu.printMenu();       // print parrot space menu and get user selection
    investigationMenu.makeSelection();


    if (investigationMenu.getSelection() == 1)        // if user selects to repeat a hint
    {
      if (!hints.empty())       // if user's Hints vector is not empty
      {
        // declare variable to store user's choice, and print list of Hints in vector
        std::string choice;
        this->printList(hints);

        // get user choice and loop until a valid choice was made
        std::cin >> choice;
        while (!validateInput(choice, 1, hints.size())){
          std::cout << "That was not a valid option, try again." << std::endl;
          std::cin.clear();
          std::cin >> choice;
        }

        // create temporary tool pointer to store hint slection in
        Tool *tempPtr = hints[std::stoi(choice) - 1];
        if (tempPtr->getToolName() == this->getRequiredTool())    // if user selected the correct hint
        {
          std::cout << this->getSuccessMessage() << std::endl;   // display success message
          items.push_back(this->getRetrievedTool());         // add retrieved tool to item vector
          this->setMessage("There is nothing to do in this space");

          // else if user did not select the correct hint display this message
        } else {
          std::cout << "This hint does not work here" << std::endl;
        }
        // else if user's Hints vector is empty display this message
      } else {
        std::cout << "You don't have any hints to use." << std::endl;
      }
    }
  }
}

// deconstructor to delete dynamically allocated memory in object
ParrotSpace::~ParrotSpace()
{
  delete this->getRetrievedTool();
  delete this;
}
