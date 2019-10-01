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
#include <iostream>
#include <string>
#include "board.hpp"
#include "space.hpp"
#include "actionSpace.hpp"
#include "doorSpace.hpp"
#include "toolSpace.hpp"
#include "parrotSpace.hpp"

Board::Board()
{
  for (int r=0; r<2; r++)
  {
    for (int c=0; c<7; c++)
    {
      theBoard[r][c] = nullptr;
    }
  }

  theBoard[0][0] = new ToolSpace(1);
  theBoard[0][1] = new ToolSpace(2);
  theBoard[0][2] = new ToolSpace(3);
  theBoard[0][3] = new DoorSpace(1);
  (theBoard[0][3])->setPlayerStatus(true);
  theBoard[0][4] = new ToolSpace(4);
  theBoard[0][5] = new ParrotSpace();
  theBoard[0][6] = new DoorSpace(2);
  theBoard[1][0] = new ActionSpace(1);
  theBoard[1][1] = new ToolSpace(5);
  theBoard[1][2] = new ToolSpace(6);
  theBoard[1][3] = new ActionSpace(2);

  //set up linked structure
  for (int c=0; c<7; c++)
  {
    if (c != 6)
    {
      (theBoard[0][c])->setRight(theBoard[0][c+1]);
    }
    if (c != 0)
    {
      (theBoard[0][c])->setLeft(theBoard[0][c-1]);
    }
  }
  for (int c=0; c<4; c++)
  {
    (theBoard[0][c])->setBottom(theBoard[1][c]);
    (theBoard[1][c])->setTop(theBoard[0][c]);
    if (c != 4)
    {
      (theBoard[1][c])->setRight(theBoard[1][c+1]);
    }
    if (c != 0)
    {
      (theBoard[1][c])->setLeft(theBoard[1][c-1]);
    }
  }
}

void Board::movePlayer(Menu *movingMenu)
{
  bool hasMoved = false;
  Space* currentPlace = findPlayer();
  while (!hasMoved)
  {
    movingMenu->printMenu();
    movingMenu->makeSelection();
    int direction = movingMenu->getSelection();

    //move up
    if (direction == 1 && currentPlace->getTop() != nullptr)
    {
      (currentPlace->getTop())->setPlayerStatus(true);
      currentPlace->setPlayerStatus(false);
      hasMoved = true;
    }
    //move right
    else if (direction == 2 && currentPlace->getRight() != nullptr)
    {
      if (currentPlace->getSpaceType() != "Door")
      {
        (currentPlace->getRight())->setPlayerStatus(true);
        currentPlace->setPlayerStatus(false);
        hasMoved = true;
      }
      else
      {
        if (currentPlace->getActionRequired())
        {
          std::cout << "That was not a valid move, please try again." << std::endl;
        }
        else
        {
          (currentPlace->getRight())->setPlayerStatus(true);
          currentPlace->setPlayerStatus(false);
          hasMoved = true;
        }
      }
    }
    //move left
    else if (direction == 3 && currentPlace->getLeft() != nullptr)
    {
      (currentPlace->getLeft())->setPlayerStatus(true);
      currentPlace->setPlayerStatus(false);
      hasMoved = true;
    }
    //move down
    else if (direction == 4 && currentPlace->getBottom() != nullptr)
    {
      (currentPlace->getBottom())->setPlayerStatus(true);
      currentPlace->setPlayerStatus(false);
      hasMoved = true;
    }
    else
    {
      std::cout << "That was not a valid move, please try again." << std::endl;
    }
  }
}

Space* Board::findPlayer()
{
  Space* tempPointer;
  for (int r=0; r<2; r++)
  {
    for (int c=0; c<7; c++)
    {
      tempPointer = theBoard[r][c];
      if (tempPointer->hasPlayer())
      {
        return tempPointer;
      }
    }
  }
  return nullptr;
}

void Board::printBoard()
{
  std::cout << "\n-";
  for (int c=0; c<7; c++)
  {
    std::cout << "--------";
  }
  std::cout << std::endl;
  std::cout << "|       |       |       |       |       |       |       |" << std::endl;
  for (int c=0; c<7; c++)
  {
    std::cout << "|";
    (theBoard[0][c])->printSpace();
  }
  std::cout << "|" << std::endl;
  std::cout << "|       |       |       |       |       |       |       |" << std::endl;
  std::cout << "-";
  for (int c=0; c<7; c++)
  {
    std::cout << "--------";
  }
  std::cout << std::endl;
  std::cout << "|       |       |       |       |" << std::endl;
  for (int c=0; c<4; c++)
  {
    std::cout << "|";
    (theBoard[1][c])->printSpace();
  }
  std::cout << "|" << std::endl;
  std::cout << "|       |       |       |       |" << std::endl;
  std::cout << "-";
  for (int c=0; c<4; c++)
  {
    std::cout << "--------";
  }
  std::cout << "\n" << std::endl;
}

bool Board::gameWon()
{
  bool isOver = true;
  for (int c=0; c<7; c++)
  {
    Space* tempPtr = theBoard[0][c];
    if (tempPtr->getSpaceType() == "Door")
    {
      if (tempPtr->getActionRequired())
      {
        isOver = false;
      }
    }
  }
  return isOver;
}
