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
#ifndef BOARD_HPP
#define BOARD_HPP
#include "space.hpp"
#include "menu.hpp"

class Board
{
  private:
    Space* theBoard[2][7];
  public:
    Board();
    Space* findPlayer();
    void movePlayer(Menu *movingMenu);
    void printBoard();
    bool gameWon();
    //~Board();
};
#endif
