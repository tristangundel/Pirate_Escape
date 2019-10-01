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
    virtual void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items) = 0;
    void printList(std::vector<Tool*> list);
    virtual ~Space() = 0;
};

#endif
