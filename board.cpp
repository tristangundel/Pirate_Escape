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
#include "actionSpace.hpp"
#include "doorSpace.hpp"
#include "toolSpace.hpp"

Board::Board()
{
  theBoard[0][0] = new ToolSpace(toolSpace1);
  theBoard[0][1] = new ToolSpace(toolSpace2);
  theBoard[0][2] = new ToolSpace(toolSpace3);
  theBoard[0][3] = new DoorSpace(doorSpace);
  (theBoard[0][3])->changePlayerStatus(true);
  theBoard[0][4] = new ToolSpace(toolSpace4);
  theBoard[0][5] = new ParrotSpace(parrotSpace);
  theBoard[0][6] = new DoorSpace(doorSpace);
  theBoard[1][0] = new ActionSpace(actionSpace1);
  theBoard[1][1] = new ToolSpace(toolSpace5);
  theBoard[1][2] = new ToolSpace(toolSpace6);
  theBoard[1][3] = new ActionSpace(actionSpace2);

  (theBoard[0][0])->setRight(theBoard[0][1]);
  (theBoard[0][0])->setBottom(theBoard[1][0]);
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
      (theBoard[0][c])->setRight(theBoard[0][c+1]);
    }
    if (c != 0)
    {
      (theBoard[0][c])->setLeft(theBoard[0][c-1]);
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
    //Space* tempPointer = theBoard[0][c];
    //tempPointer->printBoard
    std::cout << "       ";
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
    //Space* tempPointer = theBoard[0][c];
    //tempPointer->printBoard
    std::cout << "       ";
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

bool Board::gameOver()
{
  bool isOver = true;
  for (int c=0; c<7; c++)
  {
      Space* tempPtr = theBoard[0][c];
      if (tempPtr->getSpaceType() == "Door")
      {
        DoorSpace tempDoorPtr = tempPtr;
        if (tempDoorPtr->getLocked())
        {
          isOver = false;
        }
      }
  }
  return isOver;
}

Board::~Board()
{
  for (int r=0; r<2; r++)
  {
    for (int c=0; c<7; c++)
    {
      if (theBoard[r][c] != nullptr)
      {
        delete theBoard[r][c];
      }
    }
  }

}
