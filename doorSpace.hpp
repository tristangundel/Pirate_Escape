#ifndef DOORSPACE_HPP
#define DOORSPACE_HPP
#include <string>
#include "space.hpp"
#include "actionSpace.hpp"

class DoorSpace : public ActionSpace
{
  public:
    DoorSpace();
    void printSpace();
    void spaceFunction(Queue *hints, Queue *items);
};

#endif
