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
#include "toolSpace.hpp"
#include "tool.hpp"
#include "item.hpp"
#include "hint.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <vector>
#include <string>
#include <iostream>

// default constructor for creating a ToolSpace object
ToolSpace::ToolSpace()
: Space()
{
  this->toolInSpace = nullptr;
  setType("Tool");
}

// constructor to create the 6 distinct ToolSpace objects needed for the game
ToolSpace::ToolSpace(int choice)
{
  //set space pointers to null upon creation of the object
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);

  // set  player status to false because player is not in this space
  setPlayerStatus(false);

  // set Space type variable to Tool
  setType("Tool");

  // conditional statements to make 6 different ToolSpace objects for the game board
  if (choice == 1)
  {
    // set Tool in space variables, and the container it is in
    this->toolInSpace = new Item("Fishing Hook and Fishing Line");
    this->container = "under the floorboard";

    // set standard message to be displayed
    setMessage("There seems to be a squeaky floorboard here. Maybe it's loose?");
  }
  if (choice == 2)
  {
    // set Tool in space variables, and the container it is in
    this->toolInSpace = new Item("MonoScope");
    this->container = "inside of the chest";

    // set standard message to be displayed
    setMessage("There is a small chest here on the ground");
  }
  if (choice == 3)
  {
    // set Tool in space variables, and the container it is in
    this->toolInSpace = new Hint("Reading will keep you sane... - Captain Barbosa");
    this->container = "carved into the wall";

    // set standard message to be displayed
    setMessage("There is something carved into the wall here");
  }
  if (choice == 4)
  {
    // set Tool in space variables, and the container it is in
    this->toolInSpace = nullptr;
    this->container = "Nothing";

    // set standard message to be displayed
    setMessage("There is nothing to do in this space");
  }
  if (choice == 5)
  {
    // set Tool in space variables, and the container it is in
    this->toolInSpace = new Item("Small Rusty Tweezers");
    this->container = "inside of the book";

    // set standard message to be displayed
    setMessage("There is a shelf here with a large book on it. The book is written by Jack Sparrow.");
  }
  if (choice == 6)
  {
    // set Tool in space variables, and the container it is in
    this->toolInSpace = new Hint("Day 104");
    this->container = "carved into the wall";

    // set standard message to be displayed
    setMessage("There is a carving here on the wall.");
  }
}

// function to implement what will happen when user lands on this space
void ToolSpace::spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items)
{
  // create menu and options used for user selection in this space
  std::string menuOptions[2];
  menuOptions[0] = "Investigate it!";
  menuOptions[1] = "Don't investigate it";
  Menu investigationMenu(2, &menuOptions[0]);

  // display the standard message for the current space
  this->displayMessage();

  // if action has not already been completed
  if (this->getMessage() != "There is nothing to do in this space")
  {
    // print menu options and get user selection
    investigationMenu.printMenu();
    investigationMenu.makeSelection();

    // conditional statements if user selects to investigate it
    if (investigationMenu.getSelection() == 1)
    {
      // if tool in the space is not an item
      if (!(this->toolInSpace)->getIsItem())
      {
        std::cout << "\nThe words " << (this->toolInSpace)->getToolName()
                  << " were " << this->container << "\nThis message was added to "
                  << "your Hints container." << std::endl;
        hints.push_back(this->toolInSpace);       // add hint to hints vector
      }
      // else if tool in space is an item
      else if ((this->toolInSpace)->getIsItem())
      {
        std::cout << "\nYou found a " << (this->toolInSpace)->getToolName()
                  << " in the " << this->container << "\n This item was added to "
                  << "your item container." << std::endl;
        items.push_back(this->toolInSpace);
      }
      // set standard message to default so space action isn't repeated
      this->setMessage("There is nothing to do in this space");
    }
  }

}

// deconstructor to free dynamically allocated memory
ToolSpace::~ToolSpace()
{
  toolInSpace = nullptr;
  delete this;
}
