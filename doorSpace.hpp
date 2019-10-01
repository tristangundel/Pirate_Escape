#ifndef DOORSPACE_HPP
#define DOORSPACE_HPP
#include <string>
#include <vector>
#include "space.hpp"
#include "actionSpace.hpp"

class DoorSpace : public ActionSpace
{
  public:
    DoorSpace();
    DoorSpace(int choice);
    void printSpace();
    void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items);
    virtual ~DoorSpace();
};

#endif
