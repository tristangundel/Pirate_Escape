#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "queue.hpp"

class Space
{
  private:
    Space *top;
    Space *right;
    Space* left;
    Space* bottom;
    std::string type;
    std::string message;
    bool player;
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
    void displayMessage();
    bool hasPlayer();
    void changePlayerStatus(bool);
    virtual void printSpace();
    virtual void spaceFunction(Queue &hints, Queue &items) = 0;
};

#endif
