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
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <vector>
#include "tool.hpp"

class Space
{
  private:
    Space *top;
    Space *right;
    Space *left;
    Space *bottom;
    std::string type;
    std::string message;
    bool player;
    bool actionRequired;
  public:
    Space();
    void setTop(Space*);
    void setRight(Space*);
    void setLeft(Space*);
    void setBottom(Space*);
    Space* getTop();
    Space* getRight();
    Space* getLeft();
    Space* getBottom();
    std::string getSpaceType();
    void setMessage(std::string);
    std::string getMessage();
    void displayMessage();
    bool hasPlayer();
    void setPlayerStatus(bool);
    void setType(std::string);
    virtual void printSpace();
    bool getActionRequired();
    void setActionRequired(bool);
    // virtual function and deconstructor for the abstract class
    virtual void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items) = 0;
    virtual ~Space() = 0;
};

#endif
