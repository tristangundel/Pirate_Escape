#ifndef BOARD_HPP
#define BOARD_HPP
#include "space.hpp"

class Board
{
  private:
    Space* theBoard[2][7];
  public:
    Board();
    Space* findPlayer();
    void movePlayer(int);
    void printBoard();
    bool gameOver();
    ~Board();
};
#endif
