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
