#ifndef DOORSPACE_HPP
#define DOORSPACE_HPP
#include <string>
#include "space.hpp"

class DoorSpace : public Space
{
  private:
    bool locked;
  public:
    DoorSpace();
    virtual void printBoard();
    void setLocked();
    bool getLocked();
    void unLockDoor(std::string);
    void spaceFunction(Queue &hints, Queue &items);
};

#endif
