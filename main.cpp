/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 09/19/2019
** Description: This file is one of 19 files that together form a
**              program with the capability of running a sinle player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "board.hpp"
#include "space.hpp"

void introMessage(int);

int main()
{
  //initialize step limit and boolean to indicate the game was won
  int numOfSteps = 30;

  //initialize menu for user options
  std::string userOptions[4];
  userOptions[0] = "Move Up";
  userOptions[1] = "Move Right";
  userOptions[2] = "Move Left";
  userOptions[3] = "Move Down";
  Menu *directionMenuPtr = new Menu(4, &userOptions[0]);

  //initialize containers for items and hints
  std::vector<Tool*> itemList;
  std::vector<Tool*> hintList;

  introMessage(numOfSteps);
  Board gameBoard;
  while(numOfSteps > 0 && !gameBoard.gameWon())
  {
    gameBoard.printBoard();
    Space *currentPlace = gameBoard.findPlayer();
    currentPlace->spaceFunction(hintList, itemList);
    if (!gameBoard.gameWon()){
      gameBoard.movePlayer(directionMenuPtr);
    }
    numOfSteps--;

  }

  if (gameBoard.gameWon())
  {
    std::cout << "\n\nCongratulations matey!" << std::endl;
  }
  else
  {
    std::cout << "\n\nYou failed to escape. I guess it's Davey Jones' locker for ye.\n"
              << "Better luck next time!" << std::endl;
  }

  return 0;
}

//function to display introduction message to the user
//and explain the goal of the game
void introMessage(int num)
{
  Board exampleBoard;
  std::cout << "\nArgh Matey! The authorities have locked ye up and thrown away"
            << " the key! \n(At least one of them, that is) \nIf ye don't get "
            << "out of here before tomorrow ye'll be walking the plank! \n\n"
            << "The brig looks like the map below: " << std::endl;
   exampleBoard.printBoard();

   std::cout << "'X' marks the spot where ye currently be standing. There may\n"
            << "be some things lying around from previous unlucky pirates that\n"
            << "could aid in yer escape, so move around the board and take a\n"
            << "look around. There are two locked doors in between you and yer\n"
            << "freedom, and they're marked with the double lined edge ('||')\n"
            << "Ye have " << num << " moves to escape.\n"
            << "Good luck ye scallywag!\n" << std::endl;

}
