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
#include "actionSpace.hpp"
#include "item.hpp"
#include "hint.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <cctype>
#include <vector>
#include <string>
#include <iostream>

// default constructor for ActionSpace objects
ActionSpace::ActionSpace()
: Space()
{
  this->requiredTool = "Nothing";
  setActionRequired(true);
  setType("Action");
}

// constructor to create two distinct ActionSpace objects for this game
ActionSpace::ActionSpace(int choice)
{
  //set space pointers to null upon creation of the object
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);

  // set player status to false because player is not in this space
  setPlayerStatus(false);
  setType("Action");            // set type of space to action
  setActionRequired(true);      // set action required to true

  // conditional statements to create the two disctint action spaces
  if (choice == 1)
  {
    // set required tool and retrieved hint for the space
    this->requiredTool = "Small Rusty Tweezers";
    this->retrievedTool = new Hint("Yo ho and a bottle of rum");

    // set standard message and success message for space
    setMessage("There is an old bottle with a message inside of it. You can't get \nthe message with your fingers though. If only you had\nsomething smaller!");
    this->successMessage = "\nYou were able to retrieve the message in the bottle! It says 'Yo ho and a bottle of rum'";
  }
  else if (choice == 2)
  {
    // set required and retrieved tools for the space
    this->requiredTool = "Fishing Hook and Fishing Line";
    this->retrievedTool = new Item("Small Key");

    // set standard message and success message for space
    setMessage("There is a storm drain here. There is something shiny down in there.\nIf only you had something to fish it out!");
    this->successMessage = "\nYou were able to fish out the shiny object from the drain! It's a key!";
  }
}

// function to print a list of items or hints
void ActionSpace::printList(std::vector<Tool*>tools){
  std::cout << "\nPlease choose from one of your following options:\n" << std::endl;
  int choiceNum;
  for (int i=0; i<tools.size(); i++){
    choiceNum = i + 1;
    std::cout << choiceNum << ". " << tools[i]->getToolName() << std::endl;
  }
}

// function to set private success message variable
void ActionSpace::setSuccessMessage(std::string message){
  this->successMessage = message;
}

// function to return private success message variable
std::string ActionSpace::getSuccessMessage(){
  return this->successMessage;
}

// function to set private required tool variable
void ActionSpace::setRequiredTool(std::string tool){
  this->requiredTool = tool;
}
// function to return private required tool variable
std::string ActionSpace::getRequiredTool(){
  return this->requiredTool;
}
// function to set private retrieved tool variable
void ActionSpace::setRetrievedTool(Tool* tool){
  this->retrievedTool = tool;
}
// function to return private retrieved tool variable
Tool* ActionSpace::getRetrievedTool(){
  return this->retrievedTool;
}

// function to perform what should be done when user lands on this space
void ActionSpace::spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items)
{
  // create menu and options used for user selection in this space
  std::string menuOptions[2];
  menuOptions[0] = "Try to use an item!";
  menuOptions[1] = "Don't try anything yet";
  Menu investigationMenu(2, &menuOptions[0]);

  // display the standard message for the current space
  this->displayMessage();

  // if action has not already been completed
  if (this->getMessage() != "There is nothing to do in this space")
  {
    investigationMenu.printMenu();              // print action space menu and get user selection
    investigationMenu.makeSelection();

    if (investigationMenu.getSelection() == 1)    // if user selects to use an item
    {
      if (!items.empty())                // if user has an item to select
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
        if (tempPtr->getToolName() == this->requiredTool)    // if selected tool is required tool
        {
          std::cout << this->successMessage << std::endl;     // display success message
          if ((this->retrievedTool)->getIsItem())
          {
            items.push_back(this->retrievedTool);             // add retrieved tool to items vector
          }
          else
          {
            hints.push_back(this->retrievedTool);             // add retrieved tool to hints vector
          }

          // set standard message to default so action is not repeated
          this->setMessage("There is nothing to do in this space");

        } else {       // if user selected the wrong tool display this message
          std::cout << "This tool does not work here" << std::endl;
        }

      } else {     // if user doesn't have any items to try and use print message
        std::cout << "You don't have any items to use." << std::endl;
      }
    }
  }
}

// deconstructor for ActionSpace objects to free allocated memory;
ActionSpace::~ActionSpace()
{
  delete retrievedTool;
  delete this;
}
